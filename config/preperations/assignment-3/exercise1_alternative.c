#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

int magic_function() {
    // Defined volatile to stop them from being optimized out.
    volatile uint64_t a = 0x0011223344556677;
    volatile uint64_t b = 0x8899aabbccddeeff;
    volatile uint64_t c = 0;
    volatile uint64_t d = 0;
    volatile char buffer[4096] = {0};

    return a + b + c + d;
}

__attribute__((__noreturn__))
void fail(const char* msg) {
    printf("%s failed: %s\n", msg, strerror(errno));

    exit(EXIT_FAILURE);
}

uint64_t get_stack_base() {
    char buffer[4096];
    FILE* fp;

    // Build command that returns the stack base of current process.
    sprintf(buffer, "cat /proc/%d/maps | grep stack | awk -F'-' '{print $1}'", getpid());

    // Execute command.
    if(!(fp = popen(buffer, "r"))) {
        fail("popen");
    }

    // Read command output.
    if(!fgets(buffer, 4096, fp)) {
        fail("fgets");
    }

    pclose(fp);

    // Parse output (hex address).
    errno = 0;
    uint64_t result = strtoull(buffer, NULL, 16);
    if(errno) {
        fail("strtoull");
    }

    return result;
}

void* checked_malloc(size_t size) {
    void* result = malloc(size);

    if(!result) {
        fail("malloc");
    }

    return result;
}

int main(int argc, char** argv) {
    uint64_t rsp;
    uint64_t rbp;

    // Grab content of rsp & rbp registers.
    __asm__ ("movq %%rsp, %0" : "=r" (rsp) );
    __asm__ ("movq %%rbp, %0" : "=r" (rbp) );

    // sp points to the first qword below our stack frame.
    uint64_t* sp = (uint64_t*)(rsp - 8);

    // Get stack base address, and compute how much memory is below us.
    uint64_t diff = rsp - get_stack_base();
    uint64_t copy_size = argc >= 2 ? atoi(argv[1]) : diff / 8;

    // Validate user size is within the stack.
    if(copy_size < 0 || copy_size > diff / 8) {
        printf("error: bad copy size (must be between 0 and %lu inclusive)\n", diff / 8);
        exit(EXIT_FAILURE);
    }

    // Allocate buffers to hold stack memory.
    uint64_t* mem_before = checked_malloc(copy_size * 8);
    uint64_t* mem_after = checked_malloc(copy_size * 8);

    // Copy stack memory before invocation.
    for(int i = 0; i < copy_size; ++i) {
        mem_before[i] = *(sp - i);
    }

    // NOTE: Assuming the function is a leaf call.
    magic_function();

    // Copy stack memory after invocation.
    for(int i = 0; i < copy_size; ++i) {
        mem_after[i] = *(sp - i);
    }

    printf("offset | address        | before             | after              | changed\n");
    printf("-------|----------------|--------------------|--------------------|--------\n");

    int last_change = 0;
    for(int i = 0; i < copy_size; ++i) {
        bool changed = mem_before[i] != mem_after[i];

        printf("%6d | %p | 0x%016lx | 0x%016lx | %s\n", i+1, sp - i, mem_before[i], mem_after[i], changed ? "yes" : "no");

        if(changed) {
            last_change = i+1;
        }
    }

    // Not really needed as we're about to exit, but good habit to always free anyway.
    free(mem_before);
    free(mem_after);

    printf("\nrbp:        0x%016lx\n", rbp);
    printf("rsp:        0x%016lx\n", rsp);
    printf("stack base: 0x%016lx\n", get_stack_base());
    printf("difference: 0x%lx\n", diff);
    printf("estimated stack frame size: %d bytes\n", last_change * 8);

    return EXIT_SUCCESS;
}

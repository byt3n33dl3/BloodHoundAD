#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char** argv) {
    size_t upper = SIZE_MAX;
    size_t lower = 0;
    size_t size = upper;
    void* address;

    // Search for the largest successful allocation in a binary search like fashion.
    while(upper > lower && size != lower) {
        if((address = malloc(size))) {
            lower = size;
            free(address);
            printf("lower -> %zu\n", lower);
        } else {
            upper = size;
            printf("upper <- %zu\n", upper);
        }

        size = lower + (upper - lower) / 2;
    }

    printf("\nOne malloc can allocate at most %zu bytes.\n", lower);

    return EXIT_SUCCESS;
}

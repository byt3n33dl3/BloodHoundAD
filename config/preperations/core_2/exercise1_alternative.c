#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int cmp(const void* a, const void* b) {
    return *(uintptr_t*)a - *(uintptr_t*)b;
}

void print_var(void* var, size_t size, const char* name) {
    unsigned char* ptr = var;

    for(size_t i = 0; i < size; ++i, ++ptr) {
        printf("%p | 0x%02x          | %3d           | %s\n", ptr, *ptr, *ptr, i == 0 ? name : "");
    }
}

int main(int argc, char** argv) {
    short i = 0x1234;
    char x = -127;
    long sn1 = 1010048;
    long sn2 = 1009995;
    int y[2] = {0x11223344, 0x44332211};
    void* vars[] = {&i, &x, &y, &sn1, &sn2};

    printf("size of x:   %zu\n", sizeof(x));
    printf("size of i:   %zu\n", sizeof(i));
    printf("size of y:   %zu\n", sizeof(y));
    printf("size of sn1: %zu\n", sizeof(sn1));
    printf("size of sn2: %zu\n\n", sizeof(sn2));

    qsort(vars, 5, sizeof(void*), cmp);

    printf("address        | content (hex) | content (dec) | variable\n");
    printf("---------------|---------------|---------------|---------\n");

    for(int j = 0; j < 5; ++j) {
        if(vars[j] == &i) print_var(&i, sizeof(i), "i");
        if(vars[j] == &x) print_var(&x, sizeof(x), "x");
        if(vars[j] == &y) print_var(&y, sizeof(y), "y");
        if(vars[j] == &sn1) print_var(&sn1, sizeof(sn1), "sn1");
        if(vars[j] == &sn2) print_var(&sn2, sizeof(sn2), "sn2");
    }

    return 0;
}

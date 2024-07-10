#include <stddef.h>
#include <stdint.h>

void addvector(int *r, const int *a, const int *b, unsigned int len) {
    for(unsigned int i = 0; i < len; ++i) {
        *r++ = *a++ + *b++;
    }
}

int memcmp(const void *s1, const void *s2, size_t n) {
    char* p1 = (char*)s1;
    char* p2 = (char*)s2;

    for(size_t i = 0; i < n; ++i, ++p1, ++p2) {
        if(*p1 != *p2) {
            return *p1 - *p2;
        }
    }

    return 0;
}

int memcmp_backwards(const void *s1, const void *s2, size_t n) {
    char* p1 = ((char*)s1) + n - 1;
    char* p2 = ((char*)s2) + n - 1;

    for(size_t i = 0; i < n; ++i, --p1, --p2) {
        if(*p1 != *p2) {
            return *p1 - *p2;
        }
    }

    return 0;
}

int memcmp_fast(const void *s1, const void *s2, size_t n) {
    char* p1 = (char*)s1;
    char* p2 = (char*)s2;
    size_t step = 1;

    while(n) {
        if(n >= 8 && *(uint64_t*)p1 == *(uint64_t*)p2) {
           step = 8;
        } else if(*p1 != *p2) {
            return *p1 - *p2;
        } else {
            step = 1;
        }

        n -= step;
        p1 += step;
        p2 += step;
    }

    return 0;
}

int memcmp_consttime(const void *s1, const void *s2, size_t n) {
    char* p1 = (char*)s1;
    char* p2 = (char*)s2;
    int diff = 0;

    for(size_t i = 0; i < n; ++i, ++p1, ++p2) {
        if(*p1 != *p2 && diff == 0) {
            diff = *p1 - *p2;
        }
    }

    return diff;
}

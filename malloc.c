#include "malloc.h"

#include <assert.h>

#define MAGIC_NUMBER 0x12345678 /*XXX Magic number for header*/

typedef struct __header_t {
    int size;
    int magic;
} header_t;

void    *malloc(size_t __size) { (void)__size;return NULL; }

void    free (void *__ptr) {
    header_t *hptr = (void *)__ptr - sizeof(header_t);
    assert(hptr->magic == MAGIC_NUMBER);
}

/*Splitting and coalescing functions for memory blocks*/
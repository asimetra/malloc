#include "malloc.h"
#include <assert.h>

#include <stdlib.h>

static arena_t *arena = NULL;



void    *malloc(size_t __size) {
   (void)__size;return NULL;
}

void    free (void *__ptr) {
    header_t *hptr = (void *)__ptr - sizeof(header_t);
    assert(hptr->magic == MAGIC_NUMBER);
}

/*Splitting and coalescing functions for memory blocks*/

int    add_chunk(chunk_t **head, chunk_t *new_chunk) {
    (void)head;
    (void)new_chunk;
    return 0;
}

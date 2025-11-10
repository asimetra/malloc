#include "malloc.h"
#include <assert.h>

#include <stdlib.h>

static chunk_t  *top_chunk = NULL;
static chunk_t  *bin_chunks[128] = {0};

void    *__mmap(size_t __len, int __prot) {
    if (top_chunk != NULL)
        ;/*add leftover to free_list*/
    return mmap(NULL, __len, __prot, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
};


void    *malloc(size_t __size) {
    size_t  chunk_size;

    chunk_size = mem2chunk(__size + sizeof(header_t));
    if (chunk_size >= MMAP_MAX || chunk_size == 0)
        return NULL;
    if (top_chunk == NULL)
        top_chunk =__mmap(MMAP_MAX, PROT_READ | PROT_WRITE);
   return NULL;
}

void    free (void *__ptr) {
    // header_t *hptr = (void *)__ptr - sizeof(header_t);
}

/*Splitting and coalescing functions for memory blocks*/

int    add_chunk(chunk_t **head, chunk_t *new_chunk) {
    (void)head;
    (void)new_chunk;
    return 0;
}

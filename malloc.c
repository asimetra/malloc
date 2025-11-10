#include "malloc.h"
#include <assert.h>

#include <stdlib.h>

static arena_t  g_arena = {0};
static chunk_t  *bin_chunks[128] = {0};

static void    *__mmap(size_t __len, int __prot) {
    return mmap(NULL, __len, __prot, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
};

static arena_t  new_base_arena() {
    void	*top_chunk;

    top_chunk = __mmap(MMAP_MAX, PROT_READ | PROT_WRITE);
    if (top_chunk == NULL)
        errno = ENOMEM;
    return (arena_t){.top_chunk = top_chunk, .s = MMAP_MAX};
}

void    *__malloc(size_t __size, arena_t *arena) {
    size_t  chunk_size;

    chunk_size = mem2chunk(__size + sizeof(header_t));
    if (chunk_size >= MMAP_MAX || chunk_size == 0)
        return NULL;
    if (arena->top_chunk == NULL) {
		*arena = (arena_t) new_base_arena();
	}
   return NULL;
}

void    *malloc(size_t __size) {
    return __malloc(__size, &g_arena);
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

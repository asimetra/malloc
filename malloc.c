#include "malloc.h"
#include <assert.h>

#include <stdlib.h>

static arena_t  g_arena = {0};
static chunk_t  *bin_chunks[128] = {0};

static void    *__mmap(size_t __len, int __prot) {
    return mmap(NULL, __len, __prot, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
};

static bool  _init_arena(arena_t *arena) {
    void	*top_chunk;

    top_chunk = __mmap(MMAP_MAX, PROT_READ | PROT_WRITE);
    if (top_chunk == NULL) {
        return false;
    }
    *arena = (arena_t){
        .top_chunk = top_chunk,
        .size = MMAP_MAX
    };
    return true;
}

static chunk_t  *find_free_chunk(size_t idx) {
	chunk_t	*chunk;

	chunk = NULL;
	while (idx < 128) {
		chunk = get_free_chuk_from_bin(idx);
		if (chunk != NULL)
			break;
		idx++;
	}
	return chunk;
}

void	_unlink_chunk(chunk_t *chunk) {
	chunk_t	*next;
	chunk_t	*prev;

	prev = chunk->free_link.prev;
	next = chunk->free_link.next;
	if (prev != NULL) {
		prev->free_link.next = next;
	} else {
		bin_chunks[chunk2idx(CHUNK_SIZE(chunk->header.size))] = next;
	}
	if (next != NULL) {
		next->free_link.prev = prev;
	}
	chunk->free_link = (chunk_pair_t){0};
}

void	_prepend_chunk_in_bin(chunk_t *chunk) {

};



void	*__malloc(size_t size, arena_t *arena) {
    chunk_t	*chunk;
    size_t	chunk_size;


    if (size == 0) {
        return NULL;
    }
    if (arena->top_chunk == NULL && !_init_arena(arena)) {
        return NULL;
    }
    chunk_size = mem2chunk(size + sizeof(header_t));
    chunk = get_free_chunk((chunk_size));
    
	
	return NULL;
}

void    *malloc(size_t __size) {
    return __malloc(__size, &g_arena);
}

void    free (void *__ptr) {
    (void)__ptr;
    // header_t *hptr = (void *)__ptr - sizeof(header_t);
}

/*Splitting and coalescing functions for memory blocks*/

int    add_chunk(chunk_t **head, chunk_t *new_chunk) {
    (void)head;
    (void)new_chunk;
    return 0;
}

#include "malloc.h"
#include <assert.h>
#include <stdlib.h>

static arena_t  g_arena = {0};
static chunk_t  *bin_chunks[128] = {0};

static void    *__mmap(size_t __len, int __prot) {
    return mmap(NULL, __len, __prot, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

static bool  _init_arena(arena_t *arena) {
    void	*top_chunk;

    top_chunk = __mmap(MMAP_MAX, PROT_READ | PROT_WRITE);
    if (top_chunk == MAP_FAILED) {
        return false;
    }
    *arena = (arena_t){
        .top_chunk = top_chunk,
        .size = MMAP_MAX
    };
    return true;
}

// static chunk_t  *find_free_chunk(size_t idx) {
// 	chunk_t	*chunk;

// 	chunk = NULL;
// 	while (idx < 128) {
// 		chunk = get_free_chuk_from_bin(idx);
// 		if (chunk != NULL)
// 			break;
// 		idx++;
// 	}
// 	return chunk;
// }

static void _unlink_chunk(chunk_t *chunk) {
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

static void _prepend_chunk_in_bin(chunk_t *chunk) {
    (void)chunk;
}

static chunk_t  *_get_chunk(arena_t *arena, size_t size) {
    return NULL;
}

static void *_create_arena(size_t size) {
    chunk_t *chunk;

    chunk = __mmap(size, PROT_READ | PROT_WRITE);
    if (chunk == MAP_FAILED) {
        return NULL;
    }
    chunk->header.size = CHUNK_SIZE(size) | CHUNK_FINUSE | CHUNK_FSMMAP;  
    return chunk + sizeof(header_t);
}

static void	*__malloc(size_t size, arena_t *arena) {
    if (size == 0 || size > MMAP_THRESHOLD) {
        return NULL;
	} else if (size > MMAP_MAX) {
        return  _create_arena(mem2arena(size + sizeof(header_t))));
    } else if (arena->top_chunk == NULL && !_init_arena(arena)) {
        return NULL;
    }
	return _get_chunk(arena, mem2chunk(size + sizeof(header_t)));
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

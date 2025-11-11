#ifndef MALLOC_H
# define MALLOC_H

#include <stddef.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <errno.h>
#include <stdio.h>

#define IN_USE(x)      ((x) & (1 >> 1))
#define SELF_MMAPED(x) ((x) & (1 >> 0))
#define CHUNK_SIZE(x)  ((x) &  ~(size_t)0b11)

#define mem2chunk(size) ((size + 15) & ~15) // (x + mask) & ~mask
#define chunk2idx(size) ((size >> 4) - 2) /*(size / 16) - 2 cuz we start at 32 bytes */
#define idx2chunk(size) (((size) + 2) << 4)

/*i just yoinked from glibc*/
#define MMAP_MAX 65536
#define MMAP_THRESHOLD  (128 * 1024)
#define MAX_ALIGNMENT 16

typedef struct chunk chunk_t;

typedef struct chunk_pair {
    struct chunk_t *prev;
    struct chunk_t *next;
} chunk_pair_t;

typedef struct chunk_header {
    size_t      size;   // size h | in_use | self_mmaped
    chunk_t     *prev;
} header_t;

typedef struct chunk {
    header_t        header;
    chunk_pair_t    free_link;
} chunk_t;

typedef struct arena {
    chunk_t         *top_chunk;
    size_t          size;
} arena_t;


/* Chunk Utils */
// chunk_t *new_chunk(arena_t *arena, size_t size);
// chunk_t *find_free_chunk(chunk_t **head);

void    prep_chunk(chunk_t **head, chunk_t *chunk);
void    remove_chunk(chunk_t **head, chunk_t *chunk);

/* Arena Utils */
// arena_t *create_arena(size_t size);
// void    remove_arena(arena_t *arena);

/* Malloc API */
void    *malloc(size_t size);
void    *calloc(size_t nmemb, size_t size);
void    free (void *ptr);
int     malloc_info (int options, FILE *fp);

#endif
#ifndef MALLOC_H
# define MALLOC_H

#include <stddef.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>

/*i just yoinked from glibc*/
#define MMAP_MAX 65536
#define MMAP_THRESHOLD  (128 * 1024)
#define MAX_ALIGNMENT 16

typedef struct arena arena_t;
typedef struct chunk;

typedef struct chunk_pair {
    struct chunk *prev;
    struct chunk *next;
} chunk_pair_t;

typedef struct chunk {
    size_t          size; // size h | in_use | self_mmaped
    chunk_t         *prev;
    chunk_pair_t    free_link;
} chunk_t;

/* Chunk Utils */
chunk_t *new_chunk(arena_t *arena, size_t size);
chunk_t *find_free_chunk(chunk_t **head);

void    prep_chunk(chunk_t **head, chunk_t *chunk);
void    remove_chunk(chunk_t **head, chunk_t *chunk);

/* Arena Utils */
arena_t *create_arena(size_t size);
void    remove_arena(arena_t *arena);

/* Malloc API */
void    *malloc(size_t size);
void    *calloc(size_t nmemb, size_t size);
void    free (void *ptr);
int     malloc_info (int options, FILE *fp);

#endif
#ifndef MALLOC_H
# define MALLOC_H

#include <stddef.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <errno.h>
#include <stdio.h>

/*i just yoinked from glibc*/
#define MMAP_MAX 65536
#define MMAP_THRESHOLD  (128 * 1024)
#define MAX_ALIGNMENT 16
#define PAGE_SIZE 4096

#define IN_USE(x)      ((x) & (1 >> 1))
#define SELF_MMAPED(x) ((x) & (1 >> 0))
#define CHUNK_SIZE(x)  ((x) &  ~(size_t)0b11)

#define CHUNK_FINUSE (1 << 1)  
#define CHUNK_FSMMAP (1 << 0)

#define mem2chunk(size) ((size + 15) & ~15) // (x + mask) & ~mask
#define chunk2idx(size) ((size >> 4) - 2) /*(size / 16) - 2 cuz we start at 32 bytes */
#define idx2chunk(size) (((size) + 2) << 4)
#define mem2arena(size) ((size + (PAGE_SIZE -1)) & ~(PAGE_SIZE -1)

typedef struct chunk chunk_t;

typedef struct chunk_pair {
    chunk_t *prev;
    chunk_t *next;
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

/* Malloc API */
void    *malloc(size_t size);
void    *calloc(size_t nmemb, size_t size);
void    free (void *ptr);
int     malloc_info (int options, FILE *fp);

#endif
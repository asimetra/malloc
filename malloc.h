#ifndef MALLOC_H
# define MALLOC_H

#include <stddef.h>

void    *malloc(size_t __size);
void    free (void *__ptr);
#endif
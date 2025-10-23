#include "malloc.h"

void    *malloc(size_t __size) { (void)__size;return NULL; }
void    free (void *__ptr) {(void)__ptr;return; }
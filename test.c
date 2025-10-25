#include "malloc.h"


#include <stdio.h>
#include <limits.h>

int main(void)
{
    unsigned long *ptr = *(unsigned long *)ULONG_MAX;

    printf("Pointer address: %p\n", (void *)ptr);
    printf("Value: %ld\n", *ptr);

    return (0);
}

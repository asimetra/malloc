#include "stdio.h"  

#include <stdio.h>
#include <stddef.h>

int main(void) {
    printf("%zu\n", _Alignof(max_align_t));
    return 0;
}

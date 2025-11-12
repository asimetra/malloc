

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "malloc.h"


int main(int argc, char **argv) {

    puts("sa\n");
    // if (malloc(atoi(argv[1])) == NULL)
    //     printf("NULL\n");
    if (malloc(70000) == NULL)
        return 5;
    getpagesize();
    return (0);
}
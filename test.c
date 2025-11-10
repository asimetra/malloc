

#include <stdio.h>
// #include <limits.h>
#include <unistd.h>
       #include <stdlib.h>
// int main(void)
// {
//     void *ptr = mmap(NULL, 4096*5, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
//     // if (ptr == MAP_FAILED) {
//     //     perror("mmap");
//     //     return (1);
//     // }
//     // *(int *)ptr = 42;

//     int i = 0;
//     // printf("Page size: %ld\n", sysconf(_SC_PAGE_SIZE));
//     // while (i < 4096) {
//     //     ((int *)ptr)[i] = i;
//     //     // printf("Value: %d\n", ((int *)ptr)[i]);

//     //     i++;
//     // }

//     // sysconf(_SC_PAGE_SIZE);
//     // printf("Value: %d\n", *(int *)ptr);


//     void *test = sbrk(4);
//     *(int*)test = 42;
//     printf("Value: %d\n", *(int *)test);
//     return (0);
// }


int main(int argc, char **argv) {

    printf("%d\n", (atoi(argv[1]) + 15) & ~15);
    return (0);
}
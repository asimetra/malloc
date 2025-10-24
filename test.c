#include "malloc.h"

typedef struct {
    char chars[3];
    int number;
} MyStruct;


#include <stdio.h>
int main(void)
{
    MyStruct *ptr = (MyStruct *)malloc(sizeof(MyStruct) * 5);
    printf("Sizeof: %d\n", sizeof(MyStruct));
    free(ptr);
    return (0);
}

#include "malloc.h"

int main(void)
{
    char *str;

    str = malloc(100);
    if (str == NULL)
        return (1);
    free(str);
    return (0);
}

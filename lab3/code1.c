#include <stdio.h>


int main(void)
{
    unsigned short values[5] = { 0x22ff, 0xabcd, 0xeefb, 0xcef3, 0x8b8d };
    int i = 0;
    unsigned char *ptr = &values;

    for (i = 1; i < 10; i += 2)
        printf("%x\n", *(ptr + i));

    printf("\n---------------------\n\n");

    for (i = 0; i < 10; i += 2)
        printf("%x\n", *(ptr + i));


    return (0);
}
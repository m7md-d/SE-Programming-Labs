#include <stdio.h>
#include <stdlib.h>

int values = 0x3b9dff;

int sum(int a, int b)
{
    return (a + b + values);
}


int main(void)
{
    unsigned char *psum = (unsigned char*)sum;
    unsigned int code_size = 0;

    FILE *file = fopen("sum.code", "wb");


    while (1)
    {
        printf("%p -> %02x\n", psum, *(psum + code_size));
        if (*(psum + code_size) == 0xd6)
        {
            code_size++;
            break;
        }
        code_size++;
    }
    fwrite(psum, 1, code_size, file);
    printf("soce size: %u\n", code_size);
    fclose(file);

    return (0);
}
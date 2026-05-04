#include <stdio.h>

int main()
{
    unsigned int dword = 0x4d6a3fe2; /* -> 0x3fe24d6a */

    unsigned char tmp = 0;
    int i;

    for (i = 0; i < 16; i += 8)
    {
        tmp = dword;
        dword = dword >> 8;
        dword = dword | (tmp << 24);
    }
    printf("the new dword is: %x. \n", dword);
}
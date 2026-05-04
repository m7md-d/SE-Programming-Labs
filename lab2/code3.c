#include <stdio.h>

int main()
{
    unsigned short word = 0x54f2; /* 0101 0100 1111 0010*/

    unsigned short wmask = 1;
    int i, n_bit = 0;

    for (i = 0; i < 16; i++)
    {
        if (word & (wmask << i))
            n_bit++;
    }
    printf("the word has: %d bits. \n", n_bit);
}
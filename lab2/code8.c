#include <stdio.h>

unsigned int byte_pack(unsigned char a,
                       unsigned char b,
                       unsigned char c,
                       unsigned char d)
{
    return (a << 24 | b << 16 | c << 8 | d);
}

/**
 * l == h = 0
 * l > h = 1
 * l < h = -1
 */
int compare_nybble(unsigned char c)
{
    unsigned char tmp;

    tmp = c >> 4;
    c = c & 0x0f;

    if (tmp < c)
        return (1);
    if (tmp > c)
        return (-1);
    return (0);
}

int is_odd(unsigned char c)
{
    return (c & 1);
}

int main(void)
{
    unsigned char c1 = 0xfc, c2 = 0x55, c3 = 0x1a;
    unsigned int merge;

    merge = byte_pack(0xaa, 0xbb, 0xcc, 0xdd);

    printf("the c1 result is: %d, and c2 is: %d, and c3 is %d\n", compare_nybble(c1), compare_nybble(c2), compare_nybble(c3));
    printf("the result of merge (a + b + c + d) is : %x\n", merge);
}

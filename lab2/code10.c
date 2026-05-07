#include <stdio.h>

#define BYTE_SHL(value, o) value = ((value) << (o));

#define BYTE_SHR(value, o) value = ((value) >> (o));

#define BYTE_SH(value, l, r) \
BYTE_SHL(value, l) \
BYTE_SHR(value, r)


#define BYTE_SWAP_NYBBLE(value) \
unsigned char t = (value >> 4); \
value = (value << 4) | t;       \

int main(void)
{
    unsigned short word = 0xabcd;
    unsigned char v = 'C';
    printf("Before: %x\n", v);
    BYTE_SWAP_NYBBLE(v)
    printf("After: %x\n", v);

    printf("Before: %04x\n", word);
    BYTE_SH(word, 8, 4)
    printf("After: %04x\n", word);

    return (0);
}

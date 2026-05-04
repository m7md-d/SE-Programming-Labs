#include <stdio.h>

int main()
{
    unsigned char byte = 0x4e;
    unsigned short word = 0x3cfa;
    unsigned int dword = 0x00000000; /* 0x043c_afe0 */
    unsigned int mask = 0x00000000;

    mask = word >> 8;
    dword = dword | (mask << 16); /* 0x003c_0000 */

    printf("1- %x\n", dword);

    mask = byte >> 4; /* 0x04 */
    dword = dword | (mask << 24); /* 0x043c_0000 */

    printf("2- %x\n", dword);

    mask = (unsigned char)(byte << 4); /* 0xe0 */
    dword = dword | mask; /* 0x043c_00e0 */

    printf("3- %x\n", dword);

    mask = (unsigned short)(word << 12); /* 0xa000 */
    dword = dword | mask; /* 0x043c_a0e0 */

    printf("4- %x\n", dword);

    mask = (unsigned short)(word << 8) >> 12; /* 0xfa00 -> 0x000f */
    dword = dword | (mask << 8); /* 0x043c_afe0 */

    printf("5- %x\n", dword);


    
    return 0;
}
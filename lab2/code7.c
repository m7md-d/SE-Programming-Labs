#include <stdio.h>

int main()
{
    unsigned char c = 't'; /* 0111 0100 */

    unsigned char mask;

    mask = c >> 4; /* 0000 0111 */
    c = c ^ mask; /* 0111 0011 -> s */
    mask = c >> 6; /* 0000 0001 */
    c = c ^ mask; /* 0111 0011 -> r */
    mask = mask << 5;
    c = c ^ mask; /* 0101 0011 -> R */

    
    printf("%c\n", c);

    return 0;
}
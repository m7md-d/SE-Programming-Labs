#include <stdio.h>

int main()
{
    unsigned char c = 'A'; /* 0100 0001 */
    /* char 'Y' = 0101 1001 */
    unsigned char mask;
    mask = c >> 2;
    mask = mask | (c >> 3);
    c = c | mask;

    printf("%c\n", c);

    return 0;
}
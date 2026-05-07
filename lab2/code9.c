#include <stdio.h>

#define BEGIN_FOR(exp) for(exp) {
#define END_FOR }

#define BEGIN_DO_WHILE do {
#define END_DO_WHILE(exp) } while(exp);

int main(void)
{
    int i;

    BEGIN_FOR(i = 1; i <= 10; i++)
        printf("%02d-Hello World!\n", i);
    END_FOR

    BEGIN_DO_WHILE
        printf("%02d-Hello DWorld!\n", i);
        i++;
    END_DO_WHILE(i <= 20)

    return 0;
}

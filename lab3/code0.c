#include <stdio.h>

int main(void)
{
    int x[5] =  {1, 3, 5, 7, 9};
    printf("%i\n", *x+1);

    const int y;
    int *py = &y;

    printf("before y = %i\n", y);
    *py = 60;
    printf("after y = %i\n", y);
}

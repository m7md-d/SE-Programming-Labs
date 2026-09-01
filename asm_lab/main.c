#include <stdio.h>

int sub(int a, int b) {
    return (a - b);
}

int div(int a, int b) {
    return (a / b);
}

int sum(int a, int b);
int mul(int a, int b);


int main(void) {
    int a = 7;
    int b = 3;

    printf("%d + %d = %d\n", a, b, sum(a, b));
    printf("%d - %d = %d\n", a, b, sub(a, b));
    printf("%d * %d = %d\n", a, b, mul(a, b));
    printf("%d / %d = %d\n", a, b, div(a, b));

    return 0;
}

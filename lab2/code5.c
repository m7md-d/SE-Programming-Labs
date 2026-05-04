#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("usage: %s value1 value2\n", *argv);
        return 1;
    }
    printf("languages: %s and %s.\n", argv[1], argv[2]);
    return 0;
}
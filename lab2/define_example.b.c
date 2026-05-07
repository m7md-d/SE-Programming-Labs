for (int i = 1; i <= 10; i++)
{
    #ifdef loop1
    printf("i * y = %d\n", i * y); /* if loop1 and loop2 is on this code will run */
    #else
    printf("i * i = %d\n", i * i); /* if you end up here, it means that loop 1 is off and loop 2 is on */
    #endif
}

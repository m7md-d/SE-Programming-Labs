#include <stdio.h>


struct laptop
{
    unsigned short cpu, gpu, ram;
};

int main(void)
{
    struct laptop msi;
    FILE *p;

    msi.cpu = 9;
    msi.gpu = 5090;
    msi.ram = 256;

    p = fopen("msi.lap", "wb");
    if(p)
        fwrite(&msi, sizeof(struct laptop), 1, p);
    else
        return (-1);
    fclose(p);

    return (0);
}

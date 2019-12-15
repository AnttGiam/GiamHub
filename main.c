#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* args[])
{
    int f = open(args[1],O_RDONLY);
    int i=0;
    char c[256];
    setbuf(stdout,NULL);
    while(read(f,&c+0,1)>0) i++;
    while(i>=0) putchar(c[i]);

    return 0;
}

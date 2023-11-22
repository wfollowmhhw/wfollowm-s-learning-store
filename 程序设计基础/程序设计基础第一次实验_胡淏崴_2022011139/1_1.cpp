#include <stdio.h>
int main()
{
    long next = 1;
    int i = 0;
    while ( i++ < 33 )
    {
        next = next * 214013L + 2531011L;
        printf( "%d ", (unsigned)( next >> 16) & 0x7FFF );
    }
    printf("\n");
    printf("%d",214013L);
    return 0;
}
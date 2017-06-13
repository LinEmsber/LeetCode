#include <stdio.h>
#include <stdlib.h>

char * toHex(int num)
{
    if(num == 0)
            return "0";

    int i = 0;
    int tmp;
    unsigned int * unum = &num;

    char * res = (char *)malloc(9);
    res[8] = 0;

    while( *unum ){
        tmp = *unum & 0x0000000f;
        *(res+7-i) = tmp + ((tmp>9)?('a'-10):'0');
        *unum = *unum >> 4;
        i++;
    }

    return res+7-i+1;
}

int main()
{
        printf("toHex(100): %s\n", toHex(100));

        return 0;
}

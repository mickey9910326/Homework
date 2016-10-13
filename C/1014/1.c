#include <stdio.h>

int main(void) {
    int a=1;
    int sum=0;
    while ( a<99 ) {
        sum=sum+(a*a*a);
        a=a+2;
    }
    printf("sum=%d\n",sum);
    return 0;
}

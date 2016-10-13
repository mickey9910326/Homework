// 線上編譯： https://goo.gl/SwJHKH 2016.10.14 by LiYu

#include <stdio.h>

int main(void) {
    int num = 2;
    int target = 4;
    int i,j,k;
    for ( i = 0; i < target; i++) {
        for ( k = 0; k < target-i-1 ; k++) {
            printf(" ");
        }
        for ( j = 0; j < i*2+1; j++) {
            printf("%d", num);
        }
        printf("\n");
    }
	return 0;
}

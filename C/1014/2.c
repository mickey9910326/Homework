// 線上編譯： https://goo.gl/hMOgIU 2016.10.14 by LiYu

#include <stdio.h>

int main(void) {
    int num = 2;
    int target = 7;
    int i,j;
    for ( i = 0; i < target; i++) {
        for ( j = 0; j <= i; j++) {
            printf("%d", num);
        }
        printf("\n");
    }
	return 0;
}

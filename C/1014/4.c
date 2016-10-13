// 線上編譯： https://goo.gl/rXpcQn 2016.10.14 by LiYu

#include <stdio.h>
int main(void) {
	int target = 7;
	int times = 0;
	int num = 2;
	while( times < target ) {
		printf("%d\n",num);
		num = num*10+2;
		times++;
	}
	return 0;
}

#include "ASA_Lib.h"
#include "ASA_SPI.h"
#include <assert.h>

#define  _BV(bit)	   (1 << (bit))
#define  _bit_set(p,m)   ((p)|= _BV(m))
#define  _bit_clear(p,m) ((p)&= ~_BV(m))
#define  _bit_get(p,m)   (((p)& _BV(m)) >>m)
#define  _bit_is_set(p,m)
#define  _bit_is_clear(p,m)
void printf_bit(char s[10],char data);
int main(void)
{
	ASA_M128_set();
    char a=2;
    char temp,data;
	int int_tmp;
    printf("start!-----------------------------\n");
	assert(a==1);
	scanf("%d", &int_tmp);
	temp = int_tmp;
	scanf("%d", &int_tmp);
	printf("int_tmp=%d\n", int_tmp);
	data = int_tmp;
	_bit_clear(temp,data);
	printf("int_tmp=%d\n", temp);
	printf_bit("temp   ",temp);
	printf_bit("data   ",data);
	printf_bit("outcome",data);
	return 0;
}

void printf_bit(char s[10],char data) {
	printf("%s : ", s);
	for (int i = 0; i < 8; i++) {
		printf("%d", data&1);
		data=data>>1;
	}
	printf("\n");
}

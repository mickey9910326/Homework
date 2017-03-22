#include "ASA_Lib.h"
#include "ASA_SPI.h"
#include "bit_op.h"

void printf_bit(char s[10],char data);
int main(void)
{
	ASA_M128_set();
	char a[3];
	char b[4];
	void *data_p =a ;
	// *Data_p = a ;
	get_void_print(a);
	get_void_print(b);

	return 0;
}

void get_void_print( void *Data_p ) {
	printf("%d\n", Data_p);
	printf("%d\n", *Data_p);
	printf("size = %d\n", sizeof(*Data_p) );
	return;
}

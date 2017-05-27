#include <avr/io.h>
#include "LIB\ASA_lib.h"
#include "LIB\ASA_DIO.h"
#include "LIB\ASA_SPI.h"
#include "LIB\ASA_general.h"


char error_X = 0,error_Y = 0,error_Z = 0;
int X = 0,Y = 0,Z = 0;

int main(void)
{
    ASA_M128_set();
    spi_init_master();
    while(1)
	{
    error_X  = ASA_JS00_get(1,100,2,&X);  //旋鈕通道選擇' ”1”
	//_delay_ms(100);
	error_Y  = ASA_JS00_get(1,102,2,&Y);  //旋鈕通道選擇' ”1”
	//_delay_ms(100);
	error_Z  = ASA_JS00_get(1,104,2,&Z);   //旋鈕通道選擇' ”1”
	//_delay_ms(100);

    printf("error_X=%d  error_Y=%d   error_Z=%d ",error_X,error_Y,error_Z);  //顯示error值
    printf("X=%5d  Y=%5d  Z=%2d\n",X,Y,Z);  //顯示XYZ值
 	_delay_ms(100);
	}

	return 0;
}

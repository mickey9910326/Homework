Analog Comparater 模擬比較器 介紹

<!--more-->


- - -

####參考資源

 1. ATMEGA128規格書

- - -
## 步驟

1. 設定 SFIOR 特殊功能IO寄存器  
2. 設定 ACSR 模擬比較器控制、狀態寄存器
3. 設定中斷向量 ANALOG_COMP_vect

- - -
## Analog comparator registers:

### SFIOR (Special Function IO Register) :  
   特殊功能IO 寄存器

 - Bit 7 - ACME (Analog Comparator Multiplexer Enable)   
    模擬比較多路復用器致能  
    致能多路復用器用，在後面(多路復用器致能)中介紹。  

### ACSR (Analog Comparator Control and Status Register):

 - Bit 7 - ACD (Analog Comparator Disable) –   
 This bit disables the analog comparator when set to one.  

 - Bit 6 - ACBG (Analog Comparator Bandgap Select)  
 選擇能隙基準源，影響正極輸入。  
 1，正極輸入由能隙基準源(1.15 V < VBG < 1.4 V)取代。  
 0，AIN0為正極輸入。  
 可以參考規格書“Internal Voltage Reference” P.53  

 - Bit 5 - ACO (Analog Comparator Output)  
 模擬比較器結果輸出，唯獨，會有1~2個執行週期的延遲。  
 正極輸入電壓(AIN0)大於負極輸入電壓(AIN1)，輸出1。  

§ Bit 4~1 為設置中斷用，若不使用可先跳過此部分。  

 - Bit 4 - ACI (Analog Comparator Interrupt Flag)  
 中斷觸發時，此腳位被設置為1。

 - Bit 3 - ACIE (Analog Comparator Interrupt Enable)  
 中斷致能，配合SREG設置。1，致能。0，禁能。

 - Bit 2 - ACIC (Analog Comparator Input Capture Enable)  
 1，致能Timer/Counter1的輸入捕捉功能(input capture function)，配和TIMSK的TICIE1設置為1。
 0，關閉此功能。

 - Bit 1,0 - ASIC [1:0] (Analog Comparator Interrupt Mode Select)  

|ACIS1|ACIS0|中斷模式|
| --- | --- | ----- |
|0    |0    |輸出源直接觸發|
|0    |1    |保留|
|1    |0    |下緣觸發|
|1    |1    |上緣觸發|

- - -
## 範例程式碼

```c

#include "ASA_Lib.h"

void AC_init();
int Count = 0;
int Count2 = 0;

int main(void)
{
	ASA_M128_set();
	printf("AlalogCompartar test by LiYu 16.9.13\n");

	char status = 0, new_status=0;
	AC_init();
	printf("%d\n", ACSR);
	sei();

	while (1) {
		asm("nop");
		new_status = (ACSR>>5) && 1;
		if (new_status != status) {
			asm("nop");
			status = new_status;
			Count2++;
            printf("Status Changed! ");
			printf("status = %d , Count = %d , Count2 = %d \n", status, Count, Count2);
		}
	}
}
void AC_init() {
	SFIOR = 1 << ACME;
	ACSR  = (0<<ACD)  | (0<<ACBG) | (0<<ACO)   | (0<<ACI)
		  | (1<<ACIE) | (0<<ACIC) | (1<<ACIS1) | (1<<ACIS0);
}
ISR(ANALOG_COMP_vect){
	asm("nop");
	Count++;
}

```

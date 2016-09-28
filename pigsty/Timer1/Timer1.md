TIMER1,3介紹  

不同於Timer0,Timer2，Timer1,3是16位元精度的計時器，其擁有的輸出腳位，及中斷向量也較多。  

<!--more-->
- - -

####參考資源

 1. ATMEGA128規格書

- - -
## 步驟

1. 選擇頻率  
2. 設定 ACSR 模擬比較器控制、狀態寄存器
3. 設定中斷向量 ANALOG_COMP_vect

- - -
## Timer1 registers:

### TCCR1A (Timer/Counter1 Control Register A) :  
計時器1寄存器A  

![TCCR1A.png](F:\Homework\pigsty\Timer1\image\TIMER1_TCCR1A.png)

- Bit 7:6 – COM1A1:0 Compare Output Mode for Channel A  
- Bit 5:4 – COM1B1:0 Compare Output Mode for Channel B  
- Bit 3:2 – COM1C1:0 Compare Output Mode for Channel C  
上述bit是拿來控制輸出ABC的腳位模式

舉Bit 7:6 – COM1A1:0為例：  
在非PWM模式中

|COM1A1|COM1A0|中斷模式|  
| --- | --- | ----- |  
|0    |0    |視為一般IO PORT操作|  
|0    |1    |觸發時，輸出反向電壓|  
|1    |0    |觸發時，腳位清零(=0)，輸出低電位|  
|1    |1    |觸發時，腳位置位(=1)，輸出高電位|  

PWM模式中

|COM1A1|COM1A0|中斷模式|  
| --- | --- | ----- |  
|0    |0    |視為一般IO PORT操作|  
|0    |1    |觸發時，輸出反向電壓|  
|1    |0    |觸發時，腳位清零(=0)，輸出低電位|  
|1    |1    |觸發時，腳位置位(=1)，輸出高電位|  

 - Bit 1:0 WGMn1:0 Waveform Generation Mode  




### TCCR1B (Timer/Counter1 Control Register B) :  
計時器1寄存器B  

![TCCR1B.png](F:\Homework\pigsty\Timer1\image\TIMER1_TCCR1B.png)

- TCCR1A Bit 1:0 WGMn1:0 Waveform Generation Mode  
- TCCR1B Bit 4:3 WGMn3:2 Waveform Generation Mode  
上述腳位是拿來控制波形輸出

表格如下
![TCCR1B.png](F:\Homework\pigsty\Timer1\image\TIMER1_WGM_mode_tablepng.png)

- Bit 7 – ICNCn: Input Capture Noise Canceler
- Bit 6 – ICESn: Input Capture Edge Select
- Bit 5 – Reserved Bit
- Bit 4:3 – WGMn3:2: Waveform Generation Mode
- Bit 2:0 – CSn2:0: Clock Select

### TCCR1C (Timer/Counter1 Control Register C) :  
計時器1寄存器C  

![TCCR1C.png](F:\Homework\pigsty\Timer1\image\TIMER1_TCCR1C.png)

- Bit 7 – FOCnA: Force Output Compare for Channel A
- Bit 6 – FOCnB: Force Output Compare for Channel B
- Bit 5 – FOCnC: Force Output Compare for Channel C
- Bit 4:0 – Reserved Bits

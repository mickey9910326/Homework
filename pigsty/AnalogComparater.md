Analog Comparater 基本介紹

<!--more-->

上：
1. USART 簡介
2. USART 腳位介紹
3. USART 各種傳輸模式
4. USART 傳輸資料格式

下：
1. 寄存器介紹
2. 各模式下的寄存器
3. 中斷
4. coding



- - -

####參考資源

 1. 成大資工  
 http://wiki.csie.ncku.edu.tw/embedded/USART

 - wiki  
 https://en.wikipedia.org/wiki/Universal_asynchronous_receiver/transmitter

 - maxEmbedded.com  
 http://maxembedded.com/2013/09/the-usart-of-the-avr/

 - ATMEGA128規格書

- - -
## What is UART/USART

#### UART
Universal Asynchronous Receiver/Transmitter  
通用**非同步**收發傳輸器

#### USART
Universal **Synchronous** Asynchronous Receiver/Transmitter  
通用**同步**收發傳輸器

#### avr的USART有以下特色(取自規格書)  
- Full Duplex Operation (Independent Serial Receive and Transmit Registers)  
  全雙工模式 有獨立的接收/發送寄存器
- Asynchronous or Synchronous Operation  
  同步/非同步操作
- Master or Slave Clocked Synchronous Operation  
  主從計時同步操作
- High Resolution Baud Rate Generator  
  高精度鮑率  
- Supports Serial Frames with 5, 6, 7, 8, or 9 Data Bits and 1 or 2 Stop Bits  
  5,6,7,8,9 bits 數據傳輸，1,2 bits 停止位
- Odd or Even Parity Generation and Parity Check Supported by Hardware  
  支持奇偶校正  
- Data OverRun Detection  
  數據過速偵測
- Framing Error Detection  
  格式錯誤偵測
- Noise Filtering Includes False Start Bit Detection and Digital Low Pass Filter  
  雜訊濾波，錯誤起始位檢測、數位低通濾波  
- Three Separate Interrupts on TX Complete, TX Data Register Empty, and RX Complete  
  三個獨立中斷向量，發送結束、寄存器為空、接收完成
- Multi-processor Communication Mode  
  多工通訊模式
- Double Speed Asynchronous Communication Mode  
  倍速、非同步通訊模式


## UART關鍵字

- - -

## USART 設定步驟
簡介設定步驟，方便下文理解
1. 設定主從的鮑率，使主從有相同的通訊頻率
-  設定傳送資料位數(幾Bits)
-  將資料存入Buffer
-  致能，開始傳輸

## USART pins in AVR

1.AIN0
2.AIN1
3.


## Analog comparator registers:

T1. SFIOR (Special Function IO Register) :



ACME (Analog Comparator Multiplexer Enable) - When this bit is zero the negative analog input is applied only on AIN1 pin. When this bit is set and ADC system is disabled, the negative analog input can be given at ADC channel pins (ADC0-ADC7) which can be selected by ADMUX register.

2. ACSR (Analog Comparator Control and Status Register):



ACD (Analog Comparator Disable) – This bit disables the analog comparator when set to one.
ACBG (Analog Comparator Bandgap Select) – When this bit is set to one, a fixed internal bandgap voltage VBG(1.15 V < VBG < 1.4 V) is selected as positive input of comparator. When this bit is set to zero, voltage at pin AIN0 will be considered as positive input voltage.
ACO (Analog Comparator Output) – When voltage at pin AIN0 is higher than the negative input pin, this bit is set by hardware. The analog comparator needs one or two clock cycle to synchronize with ACO bit.
The following bits (ACI, ACIE, ACIC and ASIC) are used for further application (for eg. ADC triggering, etc.) which is beyond the scope of this article. (You can skip for the time being) The brief explanation for these bits is given below.
ACI (Analog Comparator Interrupt Flag) – This bit is set by hardware when a comparator output event triggers the interrupt mode which is defined ACIS1 and ACIS0 bits.
ACIE (Analog Comparator Interrupt Enable) – This bit is set in order to activate analog comparator interrupt.
ACIC (Analog Comparator Input Capture Enable) – This bit is used to enable the input capture function in Timer/Counter1. To enable the input capture along with ACIC bit the TICIE1 bit in TIMSK register is set to one. When this bit is set to zero, the analog comparator is disconnected with Timer system.
ASIC [1:0] (Analog Comparator Interrupt Mode Select) – This bit is used to select interrupt modes.

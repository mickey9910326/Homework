AVR UART/UART基本介紹 (上)

分為上下兩篇，上篇為介紹AVR的USART
上著重在USART的原理及傳輸方式，下則是設定AVR的USART

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

1. **RxD**  -  USART Receiver Pin  (**R**eceive **D**ata)  
  在USART中接收訊號的腳位
2. **TxD**  -  USART Transmit Pin  (**T**ransmit **D**ata)  
  在USART中發送訊號的腳位
3. **XCK**  -  USART External clock  
  在USART中計時的腳位

在 ATMEGA128中共有兩組的USART
USART0  
1. RxD  -  PE0
2. TxD  -  PE1
3. XCK  -  PE2

USART1
1. RxD  -  PD2
2. TxD  -  PD3
3. XCK  -  PD5

## USART Register in AVR

## Modes of Operation
Asynchronous Normal Mode  
Asynchronous Double Speed Mode  
Synchronous Mode  


## Baud Rate Generation

## Frame Formats

#### Order of Bits
Start bit (Always low)  
Data bits (LSB to MSB) (5-9 bits)  
Parity bit (optional) (Can be odd or even)  
Stop bit (1 or 2) (Always high)  
#### Setting the Number of DATA Bits
#### Setting Number of STOP Bits
#### Parity Bits
#### Even and Odd Parity
#### But why use the Parity Bit?

## Register Description

#### UDR: USART Data Register (16-bit)

#### UCSRA: USART Control and Status Register A (8-bit)

#### UCSRB: USART Control and Status Register B (8-bit)

#### UCSRC: USART Control and Status Register C (8-bit)

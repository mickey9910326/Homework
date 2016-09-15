這篇文章將會簡介AVR的SPI腳位，及SPI相關寄存器。
及SPI專有名詞介紹，使用將會在下一篇文章教學。

<!--more-->

- - -

#### 先附上大神的資源：

SPI簡介：
http://maxembedded.com/2013/11/serial-peripheral-interface-spi-basics/

SPI of AVR：
http://maxembedded.com/2013/11/the-spi-of-the-avr/


- - -

## SPI關鍵字
　● **SPCR**  – SPI Control Register
　● **SPSR**  – SPI Status Register
　● **SPDR**  – SPI Data Register
　● **SPSR**  – SPI Status Register
　● **Master Mode**
　● **Slave Mode**

- - -

## SPI pins in AVR
<img class="center" src="http://user-image.logdown.io/user/17101/blog/16516/post/699756/axeBttUtRceyh4BirQ6r_ATMEGA128_PIN_SPI.png" alt="ATMEGA128_PIN_SPI.png">

 1. **MISO**  -  **M**aster **I**n **S**lave **O**ut  
 	如名子所示，MISO是Master的輸入腳位、Slave的輸出腳位。訊息從Slave傳給Master。  

 2. **MOSI**  -  **M**aster **O**ut **S**lave **I**n  
 	如名子所示，MOSI是Slave的輸入腳位、Master的輸出腳位。訊息從Master傳給Slave。  

 3. **SCK**  - SPI Bus **S**erial **C**loc**k**  
 	在Master中做為SPI的clock輸出，由DDRB1控制輸出入，輸入模式由PORTB1控制pullup。
 	在Slave 中做為SPI的clock輸入，不論DDRB1如何設置，此腳位皆為輸入。

 4. **SS**  - SPI **S**lave **S**elect input  
 	在Slave中做為Select input，不論DDRB0設置，此腳位皆為輸入，當此腳位為低電位，Slave的SPI才被致能。

 如表所示：
 ![SPI PIN.png](http://user-image.logdown.io/user/17101/blog/16516/post/699756/2bF8jTF9RjSJPHG2qTNj_SPI%20PIN.png "Table 32 in ATmega128 datasheet")

- - -

## SPCR
### SPI Control Register
![SPCR.png](http://user-image.logdown.io/user/17101/blog/16516/post/699756/FBmiqDbVT5CfU9ADgCL4_SPCR.png)

 - Bit 7 – **SPIE**: SPI Interrupt Enable  
	此腳位可以致能SPI interrupt(SPI中斷)，SPSR中的SPIF觸發，在SREG中的全域中斷設置。  

 - Bit 6 – **SPE**: SPI Enable  
 	當此腳位SPE bit = 1，SPI致能。SPE bit = 0，SPI禁能。

 - Bit 5 – **DORD**: Data Order  
 	控制資料傳送順序。
 	當DORO bit = 1，從資料的LSB(最**低**有效位)開始傳送。
 	當DORO bit = 0，從資料的MSB(最**高**有效位)開始傳送。

 - Bit 4 – **MSTR**: Master/Slave Select  
 	當MSTR bit = 1，設置為Master模式；當MSTR bit = 0，設置為Slave模式。
 	當MSTR bit = 1，且SS腳位設置為輸入，在SS準位被拉低時，MSTR會被清空(default=0)，SPSR中的SPIF旗標被設置為1，如果有設置中斷會觸發SPI中斷。  

 - Bit 3 – **CPOL**: Clock Polarity (時鐘極性)  
 	當CPOL bit = 1，在閒置(idle)時，SCK是高準位的，即前緣拉高，後緣拉低。
 	當CPOL bit = 0，在閒置(idle)時，SCK是低準位的，即前緣拉低，後緣拉高。

| CPOL				 |  前緣 | 後緣 |
| ------------ | ---- | ---- |
| 0						 |  上升 | 下降 |
| 1						 |  下降 | 上升 |

 - Bit 2 – **CPHA**: Clock Phase (時鐘相位)  
 	當CPHA bit = 1，SCK的後緣被指定為採樣點(sample)。  
 	當CPHA bit = 0，SCK的前緣被指定為採樣點(sample)。  

|CPHA |  前緣 | 後緣 |
|---| ---|---|
|0  |採樣 | 設置|
|1  |設置 | 採樣|

 - Bits 1, 0 – **SPR1**, **SPR0**: SPI Clock Rate Select 1 and 0  
 	SPR1,SPR2 bit 是控制Master的SCK頻率(SPI存取速率)，在Slave中沒有作用。  
 	SCK速率與震盪器頻率fsoc關係；

|SPI2X |SPR1 |SPR0 |SCK Frequency|
|---|---|---|---|
|0| 0| 0| fosc /4|
|0| 0| 1| fosc /16|
|0| 1| 0| fosc /64|
|0| 1| 1| fosc /128|
|1| 0| 0| fosc /2|
|1| 0| 1| fosc /8|
|1| 1| 0| fosc /32|
|1| 1| 1| fosc /64|

- - -

## SPSR
### SPI Status Register

 - Bit 7 – **SPIF**: SPI Interrupt Flag  
 	當一串資料傳送完成時，SPIF旗標會被設置為1。如果SPCR的SPIE有致能、全域中斷有致能，將會觸發中斷。  
 	在Master模式中，SS為輸入、且準位被拉低，也同樣會致能SPIF。  
 	SPIF有兩種情況會自動清空，一是SPI中斷完成後；另一是讀取SPSR後，SPIF將被清空。  

 - Bit 6 – **WCOL**: Write COLlision flag  
 	在SPDR寫入資料時，WCOL旗標會被設置為1。讀取SPSR後，WCOL將被清空。  

 - Bit 5..1 – Res: Reserved Bits
 	保留，讀取永遠為0。  

 - Bit 0 – **SPI2X**: Double SPI Speed Bit  
	在Master模式時，當SPI2X = 1時，SCK頻率(SPI存取速率)，將被設置為兩倍，最高可達fosc/2。  
 	在Slave 模式時，SPI速率只在fosc/4以下(包含)穩定，大於fosc/4不穩定。  


- - -

## SPDR
### SPI Data Register

SPDR為讀／寫寄存器，在SPI Master和SPI Slave中傳輸數據。  
寫入寄存器將啟動數據傳輸，讀取寄存器將讀出寄存器的接收緩衝區。

- - -

## Data Modes
在AVR的SPI中，SCK共有四種不同的相位(**CPHA**)和極性(**CPOL**)的組合來傳輸資料。四種組合的傳輸格式如下：  
![SPI_TRANSFER_FORMAT_CHPA=0.png](http://user-image.logdown.io/user/17101/blog/16516/post/699756/gBgEW5PdQdGQEQBFFQo0_SPI_TRANSFER_FORMAT_CHPA=0.png)

![SPI_TRANSFER_FORMAT_CHPA=1.png](http://user-image.logdown.io/user/17101/blog/16516/post/699756/zm8VuqB2Q62oi5T66wd8_SPI_TRANSFER_FORMAT_CHPA=1.png)

- - -

## Master Mode
当SPI 配置为主机时（MSTR 的SPCR 置位），用户可以决定SS 引脚的方向。
若SS 配置为输出，则此引脚可以用作普通的I/O 口而不影响SPI 系统。典型应用是用来驱动从机的SS 引脚。
如果SS 配置为输入，必须保持为高以保证SPI 的正常工作。若系统配置为主机， SS 为输入，但被外设拉低，则SPI 系统会将此低电平解释为有一个外部主机将自己选择为从机。为了防止总线冲突， SPI 系统遵循以下规则：
1. 如果SPCR 的MSTR 位为’0’，则SPI 成为从机， MOSI 和SCK 变为输入。
2. 如果SPSR 的SPIF 置位，且SPI 中断和全局中断开放，则中断例程将得到执行。
因此，使用中断方式处理SPI 主机的数据传输，并且存在SS 被拉低的可能性时，中断例程应该检查MSTR 是否为'1’。若被清零，用户必须将其置位，以重新使能SPI 主机模式。

Master Mode When the SPI is configured as a master (MSTR in SPCR is set), the user can determine the
direction of the SS pin.
If SS is configured as an output, the pin is a general output pin which does not affect the SPI
system. Typically, the pin will be driving the SS pin of the SPI slave.
If SS is configured as an input, it must be held high to ensure Master SPI operation. If the SS pin
is driven low by peripheral circuitry when the SPI is configured as a master with the SS pin
defined as an input, the SPI system interprets this as another master selecting the SPI as a
slave and starting to send data to it. To avoid bus contention, the SPI system takes the following
actions:
1. The MSTR bit in SPCR is cleared and the SPI system becomes a slave. As a result of the
SPI becoming a slave, the MOSI and SCK pins become inputs.
2. The SPIF flag in SPSR is set, and if the SPI interrupt is enabled, and the I-bit in SREG is
set, the interrupt routine will be executed.
Thus, when interrupt-driven SPI transmission is used in master mode, and there exists a possibility
that SS is driven low, the interrupt should always check that the MSTR bit is still set. If the
MSTR bit has been cleared by a slave select, it must be set by the user to re-enable SPI master
mode.

## Slave Mode

当SPI 配置为主机时，从机选择引脚SS 总是输入。SS 为低将激活SPI 接口，MISO 成为输出( 用户必须进行相应的配置) 引脚，其他引脚成为输入引脚。当SS 为高时所有的引脚成为输入， SPI 接口复位，不再接收数据。
SS引脚对于数据包/字节的同步非常有用，可以使从机和主机同步。当SS 拉高时SPI从机立即复位接收和发送逻辑，移位寄存器里的数据有可能是不完整的数据。

Slave Mode When the SPI is configured as a slave, the Slave Select (SS) pin is always input. When SS is
held low, the SPI is activated, and MISO becomes an output if configured so by the user. All
other pins are inputs. When SS is driven high, all pins are inputs except MISO which can be user
configured as an output, and the SPI is passive, which means that it will not receive incoming
data. Note that the SPI logic will be reset once the SS pin is driven high.
The SS pin is useful for packet/byte synchronization to keep the slave bit counter synchronous
with the master clock generator. When the SS pin is driven high, the SPI slave will immediately
reset the send and receive logic, and drop any partially received data in the Shift Register.



- - -

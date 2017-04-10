## Why use RESET 電路
電容->防止電壓spark(電腦吃電，等)
ISP RESET : in system programming

## boot loader

## 關鍵字列表

電源供電電路及電腦開機RESET電路：外部供電5V，接地，均需旁路電容，RESET電路輸出接進MEGA88 RESET腳。

工作時脈震盪電路：利用內部震盪電路，外部提供石英震盪器。
Crystal Clock

燒錄及監控用UART埠：如同M128一樣，使用一個UART接到PC，一方面可以下載燒錄應用程式，另一方面可以由PC超級終端機監控M88。

SPI串列通訊埠：請參考SPI伺服端電路施作，將MEGA88定義為SLAVE端。

數位輸出入埠：使用一個平行埠其中4位元做為輸出拉到LED顯示，另4位元接到JUMPER，平常PULL LOW為0，JUMPER插上時接5V為1。

## Crystal Clock
工作時脈震盪電路  
![Crystal Oscillator Connections](.\CrystalOscillatorConnections.png)
#### Low Power Crystal Oscillator
p.25

#### Full Swing Crystal Oscillator

#### Low Frequency Crystal Oscillator

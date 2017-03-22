| LSByte    | bit     |
| :----- | :---- |
| Item One       | Item Two       |

LSByte include
LSByte = 201 雙倍速選擇
bit 0 - SPI2X 雙倍速
LSByte = 200 其他設定禁致能
時脈設定
bit 0 - SPR0
bit 1 - SPR1
送收同步時脈設定
bit 2 - CPHA
bit 3 - CPOL
主僕設定
bit 4 - MSTR
高低位元
bit 5 - DORD
禁致能中斷/SPI
bit 6 - SPE
bit 7 - SPIE
#### LSByte = 200  
| SPCR Bit    |      | function |
| :------------- | :------------- |
| 0 | SPR0 |時脈設定|
| 1 | SPR1 |時脈設定|
| 2 | CPHA |高低脈衝優先|
| 3 | CPOL |極性|
| 4 | MSTR |主僕|
| 5 | DORD |高低位元優先|
| 6 | SPE  |SPI禁制能|
| 7 | SPIE |SPI中斷盡致能|

SPI 缺點 沒有hand-shaking

ROM read only memory

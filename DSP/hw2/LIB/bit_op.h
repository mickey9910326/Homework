#ifndef __bit_op_h__
#define __bit_op_h__

#define bit(m) (1<<(m))
#define bit_set(p,m)   ((p)|=  bit(m))  //set   the bit m of p
#define bit_clear(p,m) ((p)&= ~bit(m))  //clear the bit m of p
// #define bit_is_set(p,m)   ( (p & bit(m))) //test the bit m of p is set(1)
// #define bit_is_clear(p,m) (!(p & bit(m))) //test the bit m of p is clear(0)
#define bit_get(p,m)  (((p)& bit(m)) >>m) //get the bit m of p is 0 or 1

// NOTE is bit_put useless?
// it's easier to be replaced by bit_set & bit_clear
#define bit_put(c,p,m) (c ? bit_set(p,m) : bit_clear(p,m))   //put c into the bit m of p
#define bit_flip(p,m) bit_write((~(bit_get(p,m))),p,m)  //flip the bit m of p, 1->0, 0->1

#define bits_get(source, mask, shift) (((source) & (mask)) >> shift)
// 讀取來源變數之連續遮罩區位元串並向右位移對齊取得遮罩區位元串對應整數值
#define bits_put(source, destination, mask, shift) (dest = bits_clear(dest,mask) | ((source <<shift) & mask))
// 將資料來源左移到其所佔用旗標群區域後蓋寫到目標變數，當 shift=0即是將來源值經遮罩處理後蓋寫到目標區，可做為控制暫存器選擇性蓋寫控制旗標之用。

#endif

## HW5_Q8

##### The Question

Compare the difference between using array and linked list to implement stack.

##### My Answer

**讀取：**  
Array:   
讀取資料速度快，因為節點位置是連續的，(首位位址+索引)就可以直接從記憶體位置讀取  
linked list :  
則是必須從頭開始一個一個往後找

**記憶體配置：**  
Array:  
使用固定空間，沒有彈性，且在記憶體中是連續的，不易規劃  
在插入與刪除上也不如linklist方便  
linked list :  
記憶體空間不連續，分配方便，規劃易  
在插入與刪除上較方便  

**適合之應用：**  
Array:  
資料個數固定的靜態資料的查詢  
linked list :  
較頻繁插入、刪除、等需要對操作記憶體的資料

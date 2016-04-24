## HW4_Q1

##### The Question

Give a doubly linked list with length n, which save odd number from 1 to 2n-1  
Ex: n = 3,  
list : 1 ⇔ 3 ⇔ 5  
Now, write a program to add an even number m into this list. Also, put m at the appropriate position of the list in order to keep the sequence of the list.  
Ex: m = 4,  
list after add 4 : 1 ⇔ 3 ⇔ 4 ⇔ 5

##### The Code

``` c++

#include <iostream>
using namespace std;

class node {
private:
    node *_prev;
    node *_next;
    int _data;
public:
    node(){                         //建構子
        _prev = NULL;
        _next = NULL;
        _data = 0;
    };
    node *prev(){return _prev;};    //取出 _prev
    node *next(){return _next;};    //取出 _next
    int   data(){return _data;};    //取出 _data
    void prev(node* n){_prev = n;}; //寫入 _prev
    void next(node* n){_next = n;}; //寫入 _next
    void data(int d)  {_data = d;}; //寫入 _data
    void show();
};

class list {
private:
    node* root_node;
public:
    list(int n){ //建構子 依題目要求建構出陣列
        /**
         * TODO
         * @var cur_node 存放當前節點
         * @var new_node 愈加入之新節點
         * 先令 cur_node = root_node
         * cur_node 不斷往後走(for @var i=0)
         *   每次產生新節點放入new_node，給值(2*i+1)
         *   new_node 與 cur_node 連接
         *   直到(i > n)
         *   或下個節點的直大於n(cur_node->data() >= n)
         */
    };
    node* root(){return root_node;};
    void show();    //印出當前陣列，code在下部
    void add(int n);//依題目要求加入節點，code在下部
};

int main() {
    /**
     * TODO
     * 輸入list長度n
     * 判斷n
     * 產生list list(n)
     * 先另 cur_node = root_node
     * 隨後不斷往後走(while)
     * 直到下個節點為空(cur_node->next()==NULL)
     * 或下個節點的直大於n(cur_node->data() >= n)
     */
    return 0;
}

void list::show(){
    /**
     * TODO
     * show all the node in the list
     */
}
void list::add(int n){
    /**
     * TODO
     * 插入數字n到list中
     * @var cur_node 存放當前節點
     * @var new_node 愈加入之新節點
     * 先令 cur_node = root_node
     * 隨後不斷往後走(while)
     * 直到下個節點為空(cur_node->next()==NULL)
     * 或下個節點的直大於n(cur_node->data() >= n)
     */
}

```

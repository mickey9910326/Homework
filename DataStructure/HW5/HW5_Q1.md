## HW5_Q1

##### The Question

Give two nature numbers, and write a program to check if the digits of a number is a permutation of the other. If yes, return 1, no, return 0, exception 1.  
Note each digit of a number has to be saved in a node of a linked list  
Ex : 123 is saved as 1->2->3  
Ex : the digits of 123 is a permutation of 231

##### My Answer

``` c++
#include <iostream>
using namespace std;

class node {
private:
    node *_next;
    int _data;
public:
    node(){
        _next = NULL;
        _data = 0;
    };
    node *next(){return _next;};
    int   data(){return _data;}
    void next(node* n){_next = n;};
    void data(int d)  {_data = d;};
    void show();
};

class num_list {
private:
    node* head_node;
public:
    num_list(int num);
    void prepend(int data);
    bool is_permutation(int num);
    int search(int value);
    void delete_node(int n);
};

num_list::num_list(int num){
    /**
    * a function to construct a linked-list as question-required
    * TODO
    * 當數字不等於0時(while)
    *   將數字最後一位插入頭之前( prepend(num%10) )
    * num = num/10;
    */
}

void num_list::prepend(int data) {
    /**
    * a funtion to prepend a node to a linked-list
    * TODO
    * use HW4_Q6 prepend
    */
}

void num_list::delete_node(int node_num) {
    /**
    * a funtion to delete a node in the linked-list
    * TODO
    * use HW4_Q6 delete_node
    */
}

int num_list::search(int value) {
    /**
    * a funtion to search a value in the linked-list
    * TODO
    * @var value 愈收尋之數
    * @var cur_node 存放當前節點
    * @postion 紀錄當前節點位置
    * cur_node = root_node
    * 當下個節點不為空 (while)
    *   如果當前節點的值等於value
    *     是，回傳postoin
    *   cur_node往後移一個位置
    * 回傳0
    *
    * EXCAPTION
    * list首位即為value
    */
}

bool num_list::is_permutation(int num){
    /**
    * a funtion to check if the digits of a number is a permutation of the linked-list
    * TODO
    * 當num不等於0時
    * 收尋數字最後一位是否在list中(n = search(num%10))
    *   有，刪除list中的數字(delete(n))，num = num/10
    *   否，return 0
    * reteurn 1
    */
}

int main(int argc, char const *argv[]) {
    /**
    * TODO
    * 輸入第一個數字num，判斷不過，重新輸入
    * 輸入第二個數字num，判斷不過，重新輸入
    * 判斷第二個數字是否為第一個數字的組合
    */
    return 0;
}

```

## HW5_Q3

##### The Question

Give two numbers, and write an algorithm to calculate the sum of the two number.  
Note : Each digit of the number is saved in a node of a linked list in reverse order.  
Hint: 123 is saved as 3->2->1  
Hint: Input : 123 456 are represented as 3->2->1, 6->5->4 : 321 + 642 = 963 (9->6->3)  
Output : 369  

##### The Code

``` c++
#include <iostream>
using namespace std;

class node {/* use HW5_Q2 class node */};

class num_list {
private:
    node* head_node;
public:
    num_list(int num);
    void prepend(int data);
    void print();
};

num_list::num_list(int num){
    /**
    * a function to construct a linked-list as question-required
    * TODO
    * use HW5_Q2 num_list
    */
}

void num_list::prepend(int data) {
    /**
    * a funtion to prepend a node to a linked-list
    * TODO
    * use HW4_Q6 prepend
    */
}

void num_list::print(){
    /**
    * a funtion to print a linked-list
    * TODO
    * use HW4_Q6 prepend
    */
}

int main(int argc, char const *argv[]) {
    /**
    * TODO
    * 輸入第一個數字num，判斷不過，重新輸入
    * 輸入第二個數字num，判斷不過，重新輸入
    * 兩數字相加
    */
    return 0;
}

```

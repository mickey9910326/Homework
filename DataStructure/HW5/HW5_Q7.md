## HW5_Q7

##### The Question

Implement a queue with a single array. The stack has the operation : push_back, pop_front, size, Isempty

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

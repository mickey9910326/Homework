## HW4_Q9

##### The Question  

Implement Q8 in C++ (This is handwriting homework.)

##### The Code

``` c++

// HW4_Q9
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
};

class circular_singly_linked_list { //單向環狀鍵結陣列
private:
    node* head_node;
public:
    void append(int data) {
        node* cur_node = head_node;
        node* new_node = new node();
        new_node ->data(data);

        while(cur_node->next()!=head_node){
            cur_node = cur_node->next();
        }
        cur_node->next(new_node);
    }
}

```

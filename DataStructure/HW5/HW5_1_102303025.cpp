#include <iostream>
using namespace std;

class node {
private:
    node *_prev;
    node *_next;
    int _data;
public:
    node(){
        _prev = NULL;
        _next = NULL;
        _data = 0;
    };
    node *prev(){return _prev;};
    node *next(){return _next;};
    int   data(){return _data;}
    void prev(node* n){_prev = n;};
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
    int search(int data);
    void delete_node(int n);
};
void delete_node(int node_num) { //node_num = m
    if (node_num <=0 ) {
        cout << "m <=0" << endl;
        return;
    }
    node* cur_node = head_node;

    int i = 0;
    while(cur_node->next()!=NULL || i !=node_num ){
        cur_node = cur_node->next();
        i++;
    }
    if (cur_node->next()==NULL && i !=node_num ) {
        cout << "Wrong input, m > list long L" << endl;
        return;
    }
    node* tmp_node = new node();
    cur_node->next(cur_node->next());
    delete tmp_node;
}

num_list::num_list(int num){
    /**
    * a function to construct a linked-list as question-required
    * TODO
    * 當數字不等於0時(while)
    * 將數字最後一位插入頭之前( prepend(num%10) )
    * num = num/10;
    */
}

num_list::prepend(int data) {
    /**
    * a funtion to prepend a node to a linked-list
    * TODO
    * use HW4_Q6 prepend
    */
}

num_list::is_permutation(int num){
    /**
    * a funtion to check if the digits of a number is a permutation of the linked-list
    * TODO
    * 當num不等於0時
    * 收尋數字最後一位是否在list中(n = search(num%10))
    * 有，刪除list中的數字(delete(n))，num = num/10
    * 否，reteurn 0
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

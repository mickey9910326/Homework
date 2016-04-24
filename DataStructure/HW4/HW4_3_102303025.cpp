// HW4_Q6
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
class singly_linked_list {
private:
    node* head_node;
public:
    void prepend(int data) {
        node* new_node = new node();
        new_node ->data(data);
        new_node ->next(head_node);
    };
    void append(int data) {
        node* cur_node = head_node;
        node* new_node = new node();
        new_node ->data(data);

        while(cur_node->next()!=NULL){
            cur_node = cur_node->next();
        }
        cur_node->next(new_node);
    };
    void insert(int node_num, int data) { //node_num = m
        if (node_num <=0 ) {
            cout << "m <=0" << endl;
            return;
        }
        node* cur_node = head_node;
        node* new_node = new node();
        new_node ->data(data);

        int i = 0;
        while(cur_node->next()!=NULL || i !=node_num ){
            cur_node = cur_node->next();
            i++;
        }
        if (cur_node->next()==NULL && i !=node_num ) {
            cout << "Wrong input, m > list long L" << endl;
            return;
        }
        new_node->next(cur_node->next());
        cur_node->next(new_node);
    };
    void delete_node(int node_num) { //node_num = m
        if (node_num <=0 ) {
            cout << "m <=0" << endl;
            return;
        }
        node* cur_node = head_node;

        int i = 1;
        while(cur_node->next()!=NULL && i !=node_num-1 ){
            cur_node = cur_node->next();
            i++;
        }
        if (cur_node->next()==NULL && i != node_num-1 ) {
            cout << "Wrong input, m > list long L" << endl;
            return;
        }
        node* tmp_node = new node();
        cur_node->next(cur_node->next());
        delete tmp_node;
    };
};
int main(int argc, char const *argv[]) {
    return 0;
}

// HW5_Q2
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
    node* root_node;
public:
    num_list (arguments);
    virtual ~num_list ();

};

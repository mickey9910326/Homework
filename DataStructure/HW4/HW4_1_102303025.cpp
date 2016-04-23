// HW4_Q2
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

class list {
private:
    node* root_node;
public:
    list(int n){
        int i;
        root_node = new node();
        node* cur_node = root_node;
        node* new_node = NULL;
        cur_node->data(1);
        for (i = 1; i < n; i++){
            new_node = new node();
            cur_node->next(new_node);
            new_node->prev(cur_node);
            cur_node= new_node;
            cur_node->data(2*i+1);
        }
    };
    node* root(){return root_node;};
    void show();
    void add(int n);
};

int main() {
    int list_long,m;
    cout << "plz input the n(list_long) : ";
    cin  >> list_long;
    while (list_long<=0) {
        std::cout << "wrong input, input a number again : ";
        cin  >> list_long;
    }
    list* mylist = new list(list_long);
    std::cout << "your list is :" ;
    mylist->show();

    cout << "plz input the m (the value you want to insert to the list) : ";
    cin  >> m;

    while (m<=0) {
        std::cout << "wrong input, input a number again : ";
        cin  >> m;
    }
    mylist->add(m);
    std::cout << "your list is :" ;
    mylist->show();

    return 0;
}

void list::show(){
    node* cur_node = root_node;
    cout<<"NULL <-- "<<cur_node->data();
    while (cur_node->next()!=NULL) {
        cur_node = cur_node->next();
        cout<<" <-> "<<cur_node->data();
    }
    cout<<" --> NULL"<<endl;
}
void list::add(int n){
    node* cur_node = root_node;
    node* new_node = new node();
    new_node ->data(n);
    do {
        if((cur_node->next()==NULL)){
            new_node->prev(cur_node);
            cur_node->next(new_node);
            break;
        }
        else if(cur_node->data() >= n){
            new_node ->next(cur_node);
            new_node ->prev(cur_node->prev());
            cur_node->prev()->next(new_node);
            cur_node->prev(new_node);
            break;
        }
        else{cur_node = cur_node->next();}
    } while(cur_node!=NULL);
}

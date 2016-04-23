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
};
void create(node* root_node,int n){
    int i;
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
void add_node(node* root_node,int n){
    if((root_node->next()==NULL)){
        node* new_node = new node();
        new_node ->data(n);
        new_node ->prev(root_node);
        root_node->next(new_node);
        root_node->next()->data(n);
    }
    else if(root_node->data() >= n){
        node* new_node = new node();
        new_node ->data(n);
        new_node ->next(root_node);
        new_node ->prev(root_node->prev());
        root_node->prev()->next(new_node);
        root_node->prev(new_node);
    }
    else{add_node(root_node->next(),n);}
}
void show_node(node* cur_node){
    if (cur_node->prev()!=NULL)
        cout<<cur_node->prev()->data();
    else
        cout<<"NULL";
    cout<<" <-- "<<cur_node->data()<<" --> ";

    if (cur_node->next()!=NULL)
        cout<<cur_node->next()->data()<<endl;
    else
        cout<<"NULL"<<endl;


}
void show(node* root_node){
    show_node(root_node);
    if (root_node->next()!=NULL) {
        show(root_node->next());
    }
}
int main(int argc, char const *argv[]) {
    node* root = new node();
    create(root,3);
    add_node(root,6);
    show(root);
    return 0;
}

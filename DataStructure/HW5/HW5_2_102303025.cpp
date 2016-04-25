#include <iostream>
using namespace std;

class node {
private:
    node *_prev;
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

class num_list {
private:
    node* head_node;
public:
    node *head(){return head_node;};
    void head(node* n){head_node = n;};

    num_list(){head_node = new node();};
    num_list(int num);

    void prepend(int data);
    void print();
    num_list* copy();
    int pop();
};

num_list::num_list(int num){
    head_node = new node();
    head_node->data(num%10);
    num/=10;
    while(num != 0) {
        prepend(num%10);
        num/=10;
    }
}

void num_list::prepend(int data) {
    node* new_node = new node();
    new_node ->data(data);
    new_node ->next(head_node);
    head_node = new_node;
}

void num_list::print() {
    node* cur_node = head_node;
    cout<<cur_node->data();
    while (cur_node->next()!=NULL) {
        cur_node = cur_node->next();
        cout<<"->"<<cur_node->data();
    }
    cout<<endl;
}

int num_list::pop() {
    node* cur_node = head_node;
    node* pre_node = head_node;
    while (cur_node->next()!=NULL) {
        pre_node = cur_node;
        cur_node = cur_node->next();
    }
    int data = cur_node->data();
    pre_node->next(NULL);
    if (cur_node == head_node)
        cur_node->data(0);
    else
        delete cur_node;
    return data;
}

num_list* add_two_num_list(num_list* a,num_list* b){
    num_list* new_list = new num_list(0);
    new_list->head()->data(a->pop()+b->pop());
    while ( a->head()->next()!=NULL || b->head()->next()!=NULL ) {
        new_list->prepend(a->pop()+b->pop());
    }
    new_list->prepend(a->pop()+b->pop());
    return new_list;
}

int main(int argc, char const *argv[]) {
    int num1,num2;
    cout << "Input the first number : ";
    cin >> num1;
    while (num1<0) {
        cout << "wrong input, input a number again : ";
        cin  >> num1;
    }
    cout << "Input the second number : ";
    cin >> num2;
    while (num2<0) {
        cout << "wrong input, input a number again : ";
        cin  >> num2;
    }
    num_list* num_list_1 = new num_list(num1);
    num_list* num_list_2 = new num_list(num2);
    cout<<"num1: "; num_list_1->print();
    cout<<"num1: "; num_list_2->print();
    num_list* num_list_add = add_two_num_list( num_list_1, num_list_2 );
    cout<<"add : "; num_list_add->print();

    return 0;
}

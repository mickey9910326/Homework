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

    num_list(int num);
    void prepend(int data);
    void delete_node(int n);
    int search(int data);
    bool is_permutation(int num);
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

void num_list::delete_node(int node_num) { //node_num = m
    if (node_num <=0 ) {
        cout << "m <=0" << endl;
        return;
    }
    if (node_num ==1 ) {
        node* tmp_node = head_node;
        head_node = head_node->next();
        delete tmp_node;
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
    node* tmp_node = cur_node->next();
    cur_node->next(cur_node->next()->next());
    delete tmp_node;
}

void num_list::prepend(int data) {
    node* new_node = new node();
    new_node ->data(data);
    new_node ->next(head_node);
    head_node = new_node;
}

int num_list::search(int value){
    int postion = 1;
    node* cur_node = head_node;
    if (cur_node->data() == value ) {
        return postion;
    }//handle the list has only one node
    while(cur_node->next() != NULL){
        cur_node = cur_node->next();
        postion++;
        if (cur_node->data() == value ) {
            return postion;
        }
    }
    return 0;
}

bool num_list::is_permutation(int num){
    int postion;
    do {
        postion = search(num%10);
        if (postion) {
            delete_node(postion);
            num/=10;
        }
        else
            return 0;
    } while(num != 0);
    return 1;
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
    if ( num_list_1->is_permutation(num2) )
        cout << num2 << " is the permutation of " << num1 << endl;
    else
        cout << num2 << " is not the permutation of " << num1 << endl;
    return 0;
}

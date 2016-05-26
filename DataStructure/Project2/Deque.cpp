#include"Deque.h"

Node *Head = &n, *cur_node = NULL;

void node::Print() {
    cur_node = Head;
    std::cout << cur_node->key <<" ";
    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
        std::cout << cur_node->key <<" ";
    }
    std::cout  << std::endl;
}

void node::pop_front() {
    cur_node = Head;
    Head = Head->next;
    // delete cur_node;
}

void node::pop_back() {
    cur_node = Head;
    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
    }
    // TODO delete cur->next
    cur_node= NULL;
    // delete cur_node->next;
}

void node::push_front(int k) {
    cur_node = new node();
    cur_node->key  = k;
    cur_node->next = Head;
    Head = cur_node;
    // TODO pop_back if top > 7
}

void node::push_back(int k) {
    cur_node = Head;
    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
    }
    cur_node->next = new node();
    cur_node->next_->key = k;
}

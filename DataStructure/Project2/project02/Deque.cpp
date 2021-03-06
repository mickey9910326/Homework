#include"Deque.h"

Node *Head = NULL, *current = NULL;
int top = 0;

void node::Print() {
    cur_node = Head;
    std::cout << cur_node->key <<" ";
    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
        std::cout << cur_node->key <<" ";
    }
}

void node::pop_front() {
	if (Head == NULL) return;
    cur_node = Head;
    Head = Head->next;
	top--;
	free(cur_node);
}

void node::pop_back() {
	if (Head == NULL) return;
    cur_node = Head;
    while (cur_node->next->next != NULL) {
        cur_node = cur_node->next;
    }
	free(cur_node->next);
	cur_node->next = NULL;
	top--;
}

void node::push_front(int k) {
	if (Head==NULL) {
		top++;
		Head = new node();
		Head->key=k;
		return;
	}
    cur_node = new node();
    cur_node->key  = k;
    cur_node->next = Head;
    Head = cur_node;
	if (top==Deque_size) pop_back();
	top++;
}

void node::push_back(int k) {
	if (Head==NULL) {
		top++;
		Head = new node();
		Head->key=k;
		return;
	}
    cur_node = Head;
    while (cur_node->next!= NULL) {
        cur_node = cur_node->next;
    }
    cur_node->next = new node();
    cur_node->next->key = k;
	if (top==Deque_size) pop_front();
	top++;
}

#include "project01_header.h"


node *Head = NULL, *cur_node = NULL, *tmp_node = NULL;

void Insert(int k){ //tmp_node act as a now node to be added
	cur_node = Head;
	if (Head == NULL) {
		Head = new Node();
		Head->key = k;
		return ;
	}
	else if (Head->key > k ) {
		cur_node = new Node();
		cur_node->key  = k;
		cur_node->next = Head;
		Head = cur_node;
		return ;
	}
	tmp_node = new node();
	tmp_node->key  = k;
	while (cur_node->next != NULL) {
		if (cur_node->next->key > k) {
			tmp_node->next = cur_node->next;
			cur_node->next = tmp_node;
			return ;
		}
		cur_node = cur_node->next;
	}
	cur_node->next = tmp_node;
}

Node *Delete(int k){  //tmp_node act as a node to be deleted
	if (Head->key == k) {
		tmp_node = Head;
		Head = Head->next;
		return tmp_node;
	}
	cur_node = Head;
	while (cur_node->next != NULL) {
		if (cur_node->next->key == k) {
			tmp_node = cur_node->next;
			cur_node->next = tmp_node->next;
			return tmp_node;
		}
		cur_node = cur_node->next;
	}
	return NULL;
}

void Print(){
	cur_node = Head;
	std::cout << cur_node->key <<" ";
	while (cur_node->next != NULL) {
		cur_node = cur_node->next;
		std::cout << cur_node->key <<" ";
	}
	std::cout  << std::endl;
}

void Swap(int a, int b){
	cur_node = Head;
    bool tag_a=1,tag_b=1;
    while (cur_node!= NULL) {
		if     (cur_node->key == a && tag_a){ cur_node->key = b; tag_a=0;}
    	else if(cur_node->key == b && tag_b){ cur_node->key = a; tag_b=0;}
        cur_node = cur_node->next;
	}
}

void Reverse(){ //tmp_node act as a pre_node to cur_node
	if (Head->next == NULL) { return ; }
	cur_node   = Head->next;
	tmp_node   = Head;
	Head->next = NULL;
	while (cur_node->next != NULL) {
		Head = cur_node;
		cur_node = cur_node->next;
		Head->next = tmp_node;
		tmp_node = Head;
	}
	Head = cur_node;
	Head->next = tmp_node;
}

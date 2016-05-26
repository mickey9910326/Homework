#include <stdlib.h>//malloc, free
#include<iostream>

using namespace std;

class node
{
public:
	void push_front(int);
	void push_back(int);
	void pop_back();
	void pop_front();
	void Print();
	int key;
	class node *next;
	int Deque_size;
};

typedef class node  Node; //define Node = struct node


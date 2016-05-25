#pragma once

#include <stdio.h> //printf, scanf, NULL
#include <stdlib.h>//malloc, free
#include<iostream>

using namespace std;

class node
{
public:
	int key;
	class node *Left, *Right, *Parent;
	void Delete(node *);
	void Insert(node *, node *);
	void Inorder(node *);
	void Preorder(node *);
	class node *root = NULL;
};

typedef class node Node;
node *Search(Node *, int);

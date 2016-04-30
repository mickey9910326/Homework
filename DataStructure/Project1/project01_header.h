#pragma once  //only be included once

#include <stdio.h> //printf, scanf, NULL
#include <stdlib.h>//malloc, free
#include<iostream>
using namespace std;

class node
{
	public:
		int key;
		class node *next;
		node(){
			next = NULL;
		};
};

typedef class node  Node; //define Node = struct node

void Insert(int);

Node *Delete(int);

void Print();

void Swap(int, int);//a<b

void Reverse();

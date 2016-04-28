#pragma once  //only be included once

#include <stdio.h> //printf, scanf, NULL
#include <stdlib.h>//malloc, free
#include<iostream>
using namespace std;


class node {
private:
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
    void show();
};

void swap(int a,int b) {
    node* pre_head = new node();
    pre_head->next(head_node);

    node* prea_node = NULL;
    node* preb_node = NULL;
    node* a_node    = NULL;
    node* b_node    = NULL;
    node* pre_node  = NULL;

    while (cur_node->next()!=NULL && a_node == NULL && b_node == NULL) {
        pre_node = cur_node;
        cur_node = cur_node->next();
        if ( cur_node->data() == a ) {
            prea_node = pre_node;
               a_node = cur_node;
        }
        if ( cur_node->data() == b ) {
            preb_node = pre_node;
               b_node = cur_node;
        }
    }
    if(a_node == NULL || b_node == NULL){/*ERROR*/return;}
    preb_node->next( b_node->next() );
       b_node->next( a_node->next() );
    prea_node->next( b_node );
       a_node->next( preb_node->next() );
    preb_node->next( a_node );
    delete pre_head;
}

int main()
{
    Node *x;
    int i=0,j=0;
    char w;

	while(w!='e')
	{
		cin>>w;

		while( w=='i')	//	insert
		{
			cin>>i;
			if (i==0)//0=end
			{
				break;
			}
			Insert(i);
		}
		while(w=='d')	//	delete
		{
			cin>>i;
			if (i==0)//0=end
			{
				break;
			}

			x=Delete(i);

			if(x!=NULL)
			{
				free(x);
			}
		}
		while(w=='r')	//	reverse
		{
			Reverse();
			break;
		}
		while(w=='s')	//	swap
		{
			cin>>i>>j;
			swap(i,j);
			break;
		}
	}
	Print();
    return 0;
}

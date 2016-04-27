#pragma once  //only be included once

#include <stdio.h> //printf, scanf, NULL
#include <stdlib.h>//malloc, free
#include<iostream>
using namespace std;


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

#include"btreeHeader.h"
Node *Search(Node, int);

node *Search(Node *root, int value){
	Node *tmp = root;
	int i=0;
	while(1){
		if(tmp==NULL){
			//printf("沒找到%d",value);
			return NULL;
		}
		if(tmp->key == value){
			//printf("找到%d，共搜尋：%2d次\n ",value,i);
			return tmp;
		}
		else if(tmp->key > value)
			tmp = tmp->Left;
		else
			tmp = tmp->Right;
		i++;
	}
}

void node::Delete(Node *x){
	Node *tmp  = root;
	Node *pre_x;
	while(1){
		if(tmp==NULL)
			return;
		if(tmp->key == x->key)
			break;
		else if(tmp->key > x->key){
			pre_x = tmp;
			tmp = tmp->Left;
		}
		else{
			pre_x = tmp;
			tmp = tmp->Right;
		}
	}

	Node* tmp = x;
	Node* pre_tmp;
	if(tmp==NULL){
		return ;
	}
	while(tmp->Left != NULL){
		pre_tmp = tmp;
		tmp = tmp->Left;
	}
	pre_tmp->Left = tmp->Right;

	if(pre_x->Right == x){
		pre_x->Right = tmp;
		tmp->Right = x->Right;
		tmp->Left  = x->Left;
	}
	if(pre_x->Left  == x){
		pre_x->Left = tmp;
		tmp->Right = x->Right;
		tmp->Left  = x->Left;
	}
}
void node::Insert(Node *root, Node *new_node){
	Node *tmp = root;
	while(1){
		if(tmp==NULL){
			tmp = new_node;
		}
		else if(tmp->key >= new_node->key)
			tmp = tmp->Left;
		else
			tmp = tmp->Right;
	}
}
void node::Inorder(Node *root){
	Node *tmp = root;
	if(tmp!=NULL){
        in(tmp->Left);
		cout<< tmp->key <<" ";
        in(tmp->Right);
    }
}
void node::Preorder(Node *root){
	Node *tmp = root;
    if(tmp!=NULL){
        cout<< tmp->key <<" ";
        pre(tmp->Left);
        pre(tmp->Right);
    }
}

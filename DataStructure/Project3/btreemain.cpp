#include"btreeHeader.h"

int main()
{
	char m = 'q';
	int a, b,c;
	Node n;
	Node *new_node, *to_be_deleted;
	while (m != 'e')
	{
		cin >> m;
		while (m == 'a')
		{

			new_node = (Node *)malloc(sizeof(Node));
			new_node->left = new_node->right = NULL;

			cin >> a;
			new_node->key = a;

			if (a == -1)
				break;
			else
				n.Insert(n.root, new_node);
		}
		while (m == 'b')
		{
			cin >> b;
			if (b == -1)
				break;
			else
			{
				to_be_deleted = Search(n.root, b);
				if (to_be_deleted)
				{
					n.Delete(to_be_deleted);
					free(to_be_deleted);
				}
			}
		}
		while (m == 'c')
		{

			cin >> c;

			if (c == -1)
				break;
			else
			{

				if(Search(n.root,c))
					cout << c << " is in the tree" << endl;
				else
					cout << c << " is not in the tree" << endl;
			}

		}

	}

	printf("Inorder: "); n.Inorder(n.root); printf("\n");
	printf("Preorder: "); n.Preorder(n.root); printf("\n");



	system("pause");
	return 0;

}

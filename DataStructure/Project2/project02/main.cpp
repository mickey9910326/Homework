#include"Deque.h"


int main()
{
	Node n;
	char y;
	char w = 'z';
	int i;
	//printf("Deque size:");
	cin >> n.Deque_size;
	while (w != 'e')
	{
		cin >> w;

		while (w == 'a')	//	push_front
		{
			cin >> i;
			n.push_front(i);
			//cout << "�O�_�~���J�Ʀr?" << endl;
			cin >> y;
			if (y == 'n')
			{

				break;
			}

		}
		while (w == 'b')	//	push_back
		{
			cin >> i;
			n.push_back(i);
			//cout << "�O�_�~���J�Ʀr?" << endl;
			cin >> y;
			if (y == 'n')
			{

				break;
			}


		}
		while (w == 'c')	//	pop_front
		{
			n.pop_front();
			//cout << "�O�_�~��?" << endl;
			cin >> y;
			if (y == 'n')
			{

				break;
			}
		}
		while (w == 'd')	//	pop_back
		{
			n.pop_back();
			//cout << "�O�_�~��?" << endl;
			cin >> y;
			if (y == 'n')
			{

				break;
			}
		}

	}

	n.Print();
	system("pause");
	return 0;

}

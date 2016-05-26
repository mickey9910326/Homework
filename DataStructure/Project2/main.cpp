#include"Deque.h"


int main()
{
	Node n
	Head = &n;
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
			//cout << "continue to input number?" << endl;
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
			//cout << "continue to input number?" << endl;
			cin >> y;
			if (y == 'n')
			{

				break;
			}


		}
		while (w == 'c')	//	pop_front
		{
			n.pop_front();
			//cout << "continue?" << endl;
			cin >> y;
			if (y == 'n')
			{

				break;
			}
		}
		while (w == 'd')	//	pop_back
		{
			n.pop_back();
			//cout << "continue?" << endl;
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

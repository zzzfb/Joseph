#include "CircleList.h"
#include <iostream>
using namespace std;

void startGame(int n,int m)
{
	CircleList<int> cl;
	for (int i = 1; i < n + 1; i++)
	{
		cl.push_back(i);
	}
	cout << "������������ǣ�" << endl;
	Node<int>* p = cl.getRear()->next;
	while (cl.getRear()->next != cl.getRear())
	{
		
		for (int i = 0; i < m; i++)
		{
			p = p->next;
		}
		Node<int>* q = p;//��q��¼��Ҫɾ���Ľڵ�
		p = p->next;//���˳��˵���һ����ʼ����
		cout << q->data<<" ";
		cl.pop(q);
	}
	cout << endl;
	cout << "��ʤ�����" << cl.getRear()->data << endl;
	
}
int main()
{
	startGame(10000,5);
	return 0;
}
#include "CircleList.h"
#include <iostream>
using namespace std;

void startGame(int n,int m)//共n个人，每隔传m次淘汰一人
{
	CircleList<int> cl;
	for (int i = 1; i < n + 1; i++)
	{
		cl.push_back(i);
	}
	cout << "出局玩家依次是：" << endl;
	Node<int>* p = cl.getRear()->next;
	while (cl.getRear()->next != cl.getRear())
	{
		
		for (int i = 0; i < m; i++)
		{
			p = p->next;
		}
		Node<int>* q = p;//用q记录下要删除的节点
		p = p->next;//从退出人的下一个开始传递
		cout << q->data<<" ";
		cl.pop(q);
	}
	cout << endl;
	cout << "获胜玩家是" << cl.getRear()->data << endl;
	
}
int main()
{
	startGame(10000,5);
	return 0;
}

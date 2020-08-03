#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	Node* next;
}Node;

/*
�����͸� �ִ� push �Լ�
�����͸� ������ pop �Լ� 
����ִ��� Ȯ���ϴ� isEmpty �Լ�

*/
class queue
{
private:
	Node* first=0;
	Node* rear = 0;
	int size;

public:
	void push(int& input);
	int pop(); // empty�� 1�̸� -1�� ����Ѵ�. 
	int empty(); //��������� 1 �ƴϸ� 0 
	int front();
	int back();
};
int queue::empty()
{
	if (size==0)
		return 1;
	else return 0;
}

void queue::push(int& input)
{
	if (empty())
	{
		first = new Node;
		rear = first; //front == rear�̸� 
		first->data = input;
		first->next = 0; // ���� ��尡 ����
	}
	rear->next = new Node;
	rear->next->data = input;
	rear->next->next = 0;
	rear = rear->next; //�߰��� ��尡 rear�� ��
	size++; //ť ���� ��� ���� +1
}
int queue::pop()
{
	if (empty())
	{
		cout << "ť�� ����ֽ��ϴ�.";
		return -1;
	}
	int returnData = rear->data;
	Node* searchNode=first;
	while (searchNode->next == rear)
	{
		searchNode = searchNode->next;
	}
	delete rear; // rear ��� ����
	rear = searchNode; //rear ������ ��带 rear�� ����
	rear->next = 0; // ������ ���� ����
	size--; // ť�� ��� ���� -1
	
	return returnData; // ������ �����͸� ����
}
int queue::front()
{
	if (empty()) return -1;
	return first->data;
}
int queue::back()
{
	if (empty()) return -1;
	return rear->data;
}
#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	Node* next;
}Node;

/*
데이터를 넣는 push 함수
데이터를 꺼내는 pop 함수 
비어있는지 확인하는 isEmpty 함수

*/
class queue
{
private:
	Node* first=0;
	Node* rear = 0;
	int size;

public:
	void push(int& input);
	int pop(); // empty가 1이면 -1을 출력한다. 
	int empty(); //비어있으면 1 아니면 0 
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
		rear = first; //front == rear이면 
		first->data = input;
		first->next = 0; // 다음 노드가 없음
	}
	rear->next = new Node;
	rear->next->data = input;
	rear->next->next = 0;
	rear = rear->next; //추가한 노드가 rear이 됨
	size++; //큐 안의 노드 개수 +1
}
int queue::pop()
{
	if (empty())
	{
		cout << "큐가 비어있습니다.";
		return -1;
	}
	int returnData = rear->data;
	Node* searchNode=first;
	while (searchNode->next == rear)
	{
		searchNode = searchNode->next;
	}
	delete rear; // rear 노드 해제
	rear = searchNode; //rear 이전의 노드를 rear로 설정
	rear->next = 0; // 마지막 노드로 설정
	size--; // 큐의 노드 개수 -1
	
	return returnData; // 해제한 데이터를 리턴
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
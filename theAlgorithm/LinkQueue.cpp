#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T> * next;
};

template <class T> class LinkQueue
{
public:
	LinkQueue();
	int 	Empty();
	T 		GetQueue();               //获取队头元素
	void 	EnQueue(T);                    //入队
	T 		DeQueue();                        //出队
	~LinkQueue();
private:
	Node<T>  *front, *rear;
};

template <class T>
LinkQueue<T>::LinkQueue()
{
	front = new Node<T>;
	front->next = NULL;
	rear = front;
}

template <class T>
void  LinkQueue<T>::EnQueue(T e)
{

}
template <class T>
T 	LinkQueue<T>::DeQueue()
{

}
template <class T>
int	LinkQueue<T>::Empty()
{
	if (front == rear)
		return true;
	return false;
}

template <class T>
T	LinkQueue<T> ::GetQueue()              //获取栈顶元素
{
	if (front == rear)
		throw "队列空";
	return top->data;
}

template <class T>
LinkQueue<T> :: ~LinkQueue()
{

}

void main()
{
	
}
#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T> * next;
};

template <class T>
class LinkStack
{
public:
	LinkStack() { top = NULL; }
	int 	Empty();
	T 		GetTop();                  //获取栈顶元素
	void 	Push(T);                    //入栈
	T 		Pop();                        //出栈
	~LinkStack();
private:
    Node<T>  *top;
};

template <class T>
void  LinkStack<T>::Push(T e)
{
	Node<T>*s = new Node<T>;
		s->data = e;
		s->next = top;
		top = s;
}
template <class T>
T 	LinkStack<T>::Pop()
{
	if (top != NULL)
		throw "stack empty"
	Node<T>*s = top;
	top = top->next;
	delete s;
}
template <class T>
int	LinkStack<T>::Empty()
{
	if (top == NULL)
		return true;
	return false;
}

template <class T>
T	LinkStack<T> :: GetTop()              //获取栈顶元素
{
	if (top == NULL)
		throw "栈空"；
	return top->data;
}

template <class T>
LinkStack<T> :: ~LinkStack()
{

}

void main()
{
	
}
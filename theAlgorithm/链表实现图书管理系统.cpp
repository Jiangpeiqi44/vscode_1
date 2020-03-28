#include <iosfwd>
#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>  *next;
};
template <class T> class LinkList
{
public:
	LinkList();
	LinkList(T a[], int n);
	//int Length();
	T 	Get(int);                       //查找
	int Locate(T);                      //定位
	void Insert(T, int);               //插入
	T	Remove(int);                   //删除
	~LinkList();
private:
	Node<T> *first;
};

template <class T>
LinkList<T>::LinkList()
{
	first = new  Node<T>;
	first->next = NULL;
}

template <class T>
LinkList<T>::LinkList(T a[], int n)
{   
	//尾插法
	//first = new  Node<T>;
	//Node<T> *r = first;  //指向最后一个结点
	//for (int i = 0; i<n; i++)
	//{
	//	Node<T> *s = new Node<T>; //（1）生成新结点
	//	s->data = a[i];
	//	s->next = NULL;

	//	r->next = s;  //(2) 链接在尾结点后面
	//	r = s; //(3) 尾指针后移
	//}

	//头插法
	first = new Node<T>;
	first->next = NULL;
	for (int i = 0; i < n; i++)
	{
		Node<T> *s = new Node<T>;
		s->data = a[i];
		s->next = first->next;
		first->next = s;
	}
}
template <class T>
LinkList<T>::~LinkList()
{
	while (first != NULL)
	{
		Node<T> *p = first;
		first = first->next;
		delete p;
	}
}
template <class T>
int LinkList<T>::Locate(T x) //找到返回结点位置 //O(n)
{      
	//初始化
	Node<T> *p = first->next;
	int j = 1;
	while (p!=NULL)
	{
		if (p->data == x)  return j;
		p = p->next;
		j++;
	}
	return 0;
}
template <class T>
T LinkList<T>::Get(int i)  //O(n)
{     //初始化
	Node<T> *p = first->next;
	int j = 1;
	while (p!=NULL && j<i)
	{
		 p = p->next; //指针下移
		j++;
	}
	if (p == NULL) throw "查找位置不合法\n";

	return p->data;
}

template <class T>
void LinkList<T>::Insert(T x ,int i) //O(n)
{     //初始化
	Node<T> *p = first;
	int j = 0;
	while (p != NULL && j<i-1)
	{
		p = p->next; //指针下移
		j++;
	}
	if (p == NULL) throw "插入位置不合法\n";

	Node<T> *s = new Node<T>;
	s->data = x;
	s->next = p->next;
	p->next = s;
}
template <class T>
T LinkList<T>::Remove(int i) //O(n)
{     //初始化
	Node<T> *p = first;
	int j = 0;
	while (p != NULL && j<i - 1)
	{
		p = p->next; //指针下移
		j++;
	}
	if (p == NULL) throw "删除位置不合法\n";

	Node<T> *s = p->next;
	T x = s->data;

	p->next = s->next;   //p->next = p->next->next; 
	delete s;

	return x;
}

//图书管理系统  
struct BOOK
{
	char name[128];
	float price;
	int ISBN;
	int group; //1 计算机 2 文学
};
void main()
{
	char str[8] = "abcdefg";
	LinkList<char> ls(str,7);

	cout<<ls.Locate('e')<<endl;

	try
	{
		cout<<ls.Get(3)<<endl;
		ls.Insert('y', 3);
		cout << ls.Get(3) << endl;
		ls.Remove(3);
		cout << ls.Get(3) << endl;
	}
	catch (const char* e)
	{
		cout << e << endl;
		return;
	}
}

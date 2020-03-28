#include<iostream>
using namespace std;
int search1(int a[], int n, int key,int start = 0);
int search(int a[], int n, int key);
void main()
{
	int a[9] = { 12,5,21,6,8,15,3,6,23 };
	int start = 0;
	start = search1(a, 9, 10, start);
	if (start == 0)
	{
		cout << "没找到" << endl;
		return;
	}
	while(start != 0){
		cout << start << endl;
		start = search1(a, 9, 6, start);
	}
}

//下标是i， 位置是i+1
//一个函数输出有三种方式：1 返回值   2 cout/printf屏幕打印  3 指针或引用
//1 返回值： 只能返回一个值
//2 cout/printf屏幕打印：语言问题，比如汉化问题
//3 指针或引用：指针C/C++支持，最灵活，切记做好指针保护；引用C++支持，做好内部数据的保护；需要返回多个值
int search1(int a[], int n, int key,int start)
{
	for (int i = start; i < n; i++)
	{
		if (key == a[i])
			return i + 1;
	}
	return 0;
}
int a[10] = { 0,12,5,21,16,8,15,3,6,23 };
int search(int a[], int n, int key)
{
	a[0] = key;//关键 哨兵
	int i;
	for (i = n; a[i] != key; i--);
	return i;
}
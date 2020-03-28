#include <iostream>
using namespace std;

//1 数据类型T（任意）
//2 数据长度L（任意）
//3 通用操作（算法）：插入 删除 查找 输出

//T 形式化参数
template <class T,int N> class Seqlist
{
	//数据成员
private:
	T data[N];
	int length; //有效数据长度
	//成员函数
public:
	Seqlist() { length = 0; }
	void Insert(T e, int pos);
	T Remove(int pos);
	int Find(T e);
	T Search(int pos);
	void print();
};

template <class T, int N>
void Seqlist<T,N>::Insert(T e, int pos)
{
	//异常处理 防止由于用户输入不当导致的程序崩溃
	if (pos < 1 || pos > length+1)
		throw "插入位置异常。";  //抛出异常

	//for (int j = length ; j >= pos; j--) //后移
	//	data[j] = data[j - 1];

	for (int j = length-1 ; j >= pos-1 ; j--) //后移
		data[j+1] = data[j];
	
	data[pos - 1] = e;
	length++;
	return;
}
template <class T, int N>
T Seqlist<T, N>::Remove(int pos) //计算时间复杂度
{
	//异常处理 防止由于用户输入不当导致的程序崩溃
		if (pos < 1 || pos > length)
			throw "删除位置异常。";  //抛出异常
			
		T t = data[pos - 1];
		//正常执行代码
		for (int i = pos-1 ; i < length-1 ; i++) //前移
			data[i] = data[i + 1];
		
		//for (int i = pos ; i < length ; i++)//前移
		//	data[i-1] = data[i];
		length--;
		return t;
}
template <class T, int N>
int Seqlist<T, N>::Find(T e)
{
	
}
template <class T, int N>
T Seqlist<T, N>::Search(int pos)
{

}
template <class T, int N>
void Seqlist<T, N>::print()
{
	for (int i = 0; i < length; i++)   //运算符重载
		cout << data[i] <<endl;
}

struct student
{
	char name[20];
	int age;
	int gender;
};
void main()
{
	Seqlist<student,1000> list;
	try
	{
		student s = { "abc",19,1 };
		list.Insert(s, 1);
		list.print();
				
		list.Remove(1);
		list.print();
	
	}
	catch (char *e)
	{
		cout << e <<endl;
		return;
	}
}
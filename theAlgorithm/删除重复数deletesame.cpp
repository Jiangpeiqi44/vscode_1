#include<iostream>
using namespace std;

void  DeleteSame(int a[], int n,int &k);
void main()
{
	int a[17] = { 1,2,2,2,4,5,5,8,8,8,8,9,10,12,15,19,19 };
	int k = 0;
	DeleteSame(a, 17, k);
	for (int i = 0; i < k; i++)
		cout << a[i] << endl;
}
void  DeleteSame(int a[], int n, int &k)
{
	k = 0; //指示b数据中的位置
	for (int i = 1; i < n; i++)
	{
		if (a[k] != a[i])
		{
			a[++k] = a[i];
		}
	}
	k++;
}

//void  DeleteSame(int a[], int n, int &k)
//{
//	int* b=new int[n];//堆空间申请空间可以是2G或更多；但是在栈空间里默认64K栈空间。
//	k = 0; //指示b数据中的位置
//	b[0] = a[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (b[k] != a[i])
//		{
//			k++;  b[k] = a[i];
//		}
//	}
//	k++;
//	memcpy(a, b, sizeof(int)*k);
//	delete[]b;
//}
#include<iostream>
using namespace std;
void  BSubstractA(int A[], int n, int B[], int m);//n,m是A和B的长度

void main()
{
	int A[13] = { 4,12,100,45,78,2,205,657,49,1234,36,29,10 };
	int B[12] = { 45,23,12,67,302,9,45,421,10,28,100,4 };
	BSubstractA(A, 13, B, 12);
}
void  BSubstractA(int A[], int n, int B[], int m)
{
	//一重循环hash
	unsigned char tmp[10000] = { 0 };//A[i] 数值tmp[A[i]]=1 //扩展：使用位运算符节约空间

	for (int i = 0; i < n; i++)
		tmp[A[i]] = 1;
	for (int i = 0; i < m; i++)//遍历B
	{
		if (tmp[B[i]] == 0)
			cout << B[i] << endl;
	}
}
//void  BSubstractA(int A[], int n, int B[], int m)
//{
//	//两重循环
//	for (int i = 0; i < m; i++)//遍历B
//	{
//		int j;
//		for (j = 0; j < n; j++)//遍历A
//		{
//			if (B[i] == A[j])
//				break;
//		}
//		if (j == n) cout << B[i] << endl;
//	}
//}
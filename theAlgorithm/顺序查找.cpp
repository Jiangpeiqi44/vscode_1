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
		cout << "û�ҵ�" << endl;
		return;
	}
	while(start != 0){
		cout << start << endl;
		start = search1(a, 9, 6, start);
	}
}

//�±���i�� λ����i+1
//һ��������������ַ�ʽ��1 ����ֵ   2 cout/printf��Ļ��ӡ  3 ָ�������
//1 ����ֵ�� ֻ�ܷ���һ��ֵ
//2 cout/printf��Ļ��ӡ���������⣬���纺������
//3 ָ������ã�ָ��C/C++֧�֣������м�����ָ�뱣��������C++֧�֣������ڲ����ݵı�������Ҫ���ض��ֵ
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
	a[0] = key;//�ؼ� �ڱ�
	int i;
	for (i = n; a[i] != key; i--);
	return i;
}
#include<iostream>
using namespace std;
void stat(const char* s, int num[]);
void main()
{
   const char *s = "This is a problem which can be solved by data structure method.";
	int num[128] ;
	stat(s, num);

	for (int i = 32; i < 128; i++)
		if (num[i] != 0)
			cout << (char)i << ": "<<num[i] << endl;
}
//���һ�����⣺����num[i]�д洢ASCII��=i���Ǹ��ַ�
void stat(const char* s, int num[])
{
	memset(num, 0, sizeof(int)*128); //�ڴ����������ķ���
	while (*s != '\0')
	{
		num[int(*s)]++; //�ؼ�
		s++;
	}
}
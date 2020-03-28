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
//解决一个问题：数组num[i]中存储ASCII码=i的那个字符
void stat(const char* s, int num[])
{
	memset(num, 0, sizeof(int)*128); //内存块置零的最快的方法
	while (*s != '\0')
	{
		num[int(*s)]++; //关键
		s++;
	}
}
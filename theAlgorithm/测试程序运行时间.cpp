#include<windows.h>
#include<stdio.h>
#include <iostream>
using namespace std;

void main()
{
	//初始化
	LARGE_INTEGER nFreq;
	LARGE_INTEGER t1;
	LARGE_INTEGER t2;
	double dt;
	//返回硬件支持的高精度计数器的频率
	QueryPerformanceFrequency(&nFreq);

	//获取当前时钟计数值
	QueryPerformanceCounter(&t1);

	//待测代码，可替换为自己的函数，用来测试运行时间
	int a = 0;
	for (int i = 0; i < 100000; i++)
		a += 2 * i;

	//获取当前时钟计数值
	QueryPerformanceCounter(&t2);

	//计算时间差，毫妙
	dt = (t2.QuadPart - t1.QuadPart) * 1000  / (double)nFreq.QuadPart;
	cout << dt << endl;
	//计算时间差，微妙
	dt = (t2.QuadPart - t1.QuadPart) * 1000 *1000 / (double)nFreq.QuadPart;
	cout << dt <<endl;

}
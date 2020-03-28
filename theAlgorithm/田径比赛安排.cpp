#include <iostream>
using namespace std;

int G[6][6] = { { 0,1,0,1,1,1},
				{1,0,0,0,1,1},
				{0,0,0,1,1,1},	
				{1,0,1,0,0,1},
				{1,1,1,0,0,1},
				{1,1,1,1,1,0} };
 
void Color(int c[],int n);
void main()
{
	int c[6] = { 0 };
	Color(c, 6);
	for (int i = 0; i < 6; i++)
		cout << c[i] << endl;
}
void Color(int c[], int n) //时间复杂度O(n*n) 空间复杂度O(1)
{
	c[0] = 1;//A结点染色号1
	int cnum = 1; //已使用的颜色种类

	for (int i = 1; i < n; i++)//遍历节点
	{
		int j;
		for (j = 0; j < cnum; j++) //遍历颜色
		{
			c[i] = j+1;
			int k;
			for (k = 0; k < n; k++) //遍历节点, 目的是找出来颜色j+1是否可用
				if (G[i][k] == 1 && c[k] == c[i])
					break;
			if (k == n) // 当前j+1的颜色是可以用，结点i染完了
				break;
		}
		if (j == cnum) //已有颜色都不可以用
		{
			cnum++;	 c[i] = cnum;
		}
	}

}
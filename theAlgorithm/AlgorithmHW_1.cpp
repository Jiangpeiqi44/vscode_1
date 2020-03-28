// AlgorithmHW_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath> //计算幂函数值
using namespace std;
//多项式结点
struct term
{
	float coef;
	int expn;
	term *next;
};
//参考p35
class LinkList

{
public:
	LinkList();
	LinkList(int n);
	~LinkList();
	void PrintList();
	float PrintValue(float x0);
	void Dfx();
	float *ToSeqList();
	int e = 0;

private:
	term *front; //头指针
};

LinkList::LinkList()
{
	front = new term;
	front->next = NULL;
}
//头插法
LinkList::LinkList(int n) //n为多项式的项数
{
	float coef_(0);
	int expn_(0);
	front = new term;
	front->next = NULL; //空单链表
	cout << "请按升幂次序,分别输入多项式系数与对应次数,用空格分隔,输入完成后回车" << endl;
	for (int i = n - 1; i >= 0; i--)
	{
		term *s = new term;
		cout << "输入第" << n - i << "项系数与指数" << endl;
		cin >> coef_ >> expn_;
		cin.get();
		s->coef = coef_;
		s->expn = expn_;
		s->next = front->next;
		front->next = s;
	}
	//输入指数或系数为0时如何处理有缺陷
}
void LinkList::PrintList()
{
	term *p = front->next;
	while (p->next != NULL) //处理可能存在的常数项与最后的 + 号
	{
		if (p->coef != 0)
		{
			cout << p->coef << "X^" << p->expn << " + ";
		}
		p = p->next;
	}
	if (p->expn != 0)
		cout << p->coef << "X^" << p->expn << endl;
	else
		cout << p->coef << endl;
};
float LinkList::PrintValue(float x0)
{
	float res(0);
	term *v = front->next;
	while (v != NULL)
	{
		res += v->coef * pow(x0, v->expn);
		v = v->next;
	}
	return res;
}
void LinkList::Dfx()
{
	term *d = front->next;
	while (d->next != NULL)
	{
		if (d->expn != 1 && d->expn != 0)
		{
			cout << (double)d->coef * d->expn << "X^" << d->expn - 1 << " + ";
		}
		else
			cout << d->coef << "+";
		d = d->next;
	}
	if (d->expn != 1 && d->expn != 0)
		cout << (double)d->coef * d->expn << "X^" << d->expn - 1 << endl;
	else if (d->expn == 1)
		cout << d->coef << endl;
	else
		cout << "0" << endl;
}
float *LinkList::ToSeqList()
{
	term *c = front->next;
	e = c->expn;
	float *Pol = new float[e + 1]();

	while (c != NULL)
	{
		Pol[c->expn] = c->coef;
		c = c->next;
	}
	return Pol;
}
LinkList::~LinkList()
{
}
void Plus(float *p1, float *p2, int e1, int e2)
{
	int E1 = e1 >= e2 ? e1 : e2;
	int E2 = e1 >= e2 ? e2 : e1;
	float *res = new float[E1 + 1]();
	if (E1 == e1)
	{
		for (size_t i = 0; i <= E1; i++)
		{
			res[i] = p1[i];
		}
		for (size_t i = 0; i <= E2; i++)
		{
			res[i] += p2[i];
		}
	}
	if (E1 = e2)
	{
		for (size_t i = 0; i <= E1; i++)
		{
			res[i] = p2[i];
		}
		for (size_t i = 0; i <= E2; i++)
		{
			res[i] += p1[i];
		}
	}
	for (size_t i = E1; i > 0; i--)
	{
		if (res[i] != 0)
		{
			cout << res[i] << "X^" << i << " + ";
		}
	}

	cout << res[0] << endl;
}
void Minus(float *p1, float *p2, int e1, int e2)
{
	int E1 = e1 >= e2 ? e1 : e2;
	int E2 = e1 >= e2 ? e2 : e1;
	float *res = new float[E1 + 1]();
	if (E1 == e1)
	{
		for (size_t i = 0; i <= E1; i++)
		{
			res[i] = p1[i];
		}
		for (size_t i = 0; i <= E2; i++)
		{
			res[i] -= p2[i];
		}
	}
	if (E1 = e2)
	{
		for (size_t i = 0; i <= E1; i++)
		{
			res[i] = -p2[i];
		}
		for (size_t i = 0; i <= E2; i++)
		{
			res[i] += p1[i];
		}
	}
	for (size_t i = E1; i > 0; i--)
	{
		if (res[i] != 0)
		{
			cout << res[i] << "X^" << i << " + ";
		}
	}
	cout << res[0] << endl;
}
void Multiply(float *p1, float *p2, int e1, int e2)
{
	float *res = new float[e1 + e2 + 1]();
	for (size_t i = 0; i <= e1 + e2; i++)
	{
		for (size_t j = 0; j <= e1; j++)
		{
			for (size_t k = 0; k <= e2; k++)
			{
				if (j + k == i && p1[j] != 0 && p2[k] != 0)
				{
					res[i] += p1[j] * p2[k];
					goto next;
				}
			}
		next:;
		}
	}
	for (size_t i = e1 + e2; i > 0; i--)
	{
		if (res[i] != 0)
		{
			cout << res[i] << "X^" << i << " + ";
		}
	}
	cout << res[0] << endl;
}
int main()
{
	int n(0), step(0);
	float x1(0), x2(0);
	float *p1 = NULL, *p2 = NULL;
	cout << "请输入第一个多项式F(x)项数" << endl;
	cin >> n;
	cin.get();
	LinkList Pol_1(n);
	cout << "请输入第二个多项式G(x)项数" << endl;
	cin >> n;
	cin.get();
	LinkList Pol_2(n);
	p1 = Pol_1.ToSeqList();
	p2 = Pol_2.ToSeqList();
	do
	{
	select:
		cout << "请选择下一步操作" << endl
			 << "1.输出多项式F(x)与G(x)" << endl
			 << "2.F(x) + G(x)" << endl
			 << "3.F(x) - G(x)" << endl
			 << "4.计算F(x1)值与G(x2)值 " << endl
			 << "5.计算F'(x)与G'(x) " << endl
			 << "6.计算 F(x)·G(x)" << endl
			 << "7.退出" << endl;
		cin >> step;
		cin.get();
		switch (step)
		{
		case 1:
			cout << "F(x)= ";
			Pol_1.PrintList();
			cout << "G(x)= ";
			Pol_2.PrintList();
			cin.get();
			goto select;
		case 2:
			Plus(p1, p2, Pol_1.e, Pol_2.e);
			cin.get();
			goto select;
		case 3:
			Minus(p1, p2, Pol_1.e, Pol_2.e);
			cin.get();
			goto select;

		case 4:
			cout << "请输入x1" << endl;
			cin >> x1;
			cin.get();
			cout << "F(x1)= " << Pol_1.PrintValue(x1) << endl;
			cout << "请输入x2" << endl;
			cin >> x2;
			cin.get();
			cout << "G(x2)= " << Pol_2.PrintValue(x2) << endl;
			cin.get();
			goto select;
		case 5:
			cout << "F'(x)= ";
			Pol_1.Dfx();
			cout << "G'(x)= ";
			Pol_2.Dfx();
			cin.get();
			goto select;
		case 6:
			Multiply(p1, p2, Pol_1.e, Pol_2.e);
			cin.get();
			goto select;
		default:
			break;
		}
	} while (step != 7);

	return 0;
}
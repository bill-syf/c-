// Solver.cpp
#include <cmath>

void Solver(double a, double b, double c, double &x1, double &x2, int &flag)
{                          // 函数定义（6个参数，无返回类型）
	double d = b*b - 4*a*c;

	flag = 0;
	if(d<0) return;

	d = sqrt(d);
	if(a>0)
	{
		x1 = (-b - d)/(2*a);
		x2 = (-b + d)/(2*a);
	}
	else
	{
		x1 = (-b + d)/(2*a);
		x2 = (-b - d)/(2*a);
	}
	if(d>0)
		flag = 2;
	else
		flag = 1;
}

int Solver(double a, double b, double c, double &x1, double &x2)
{                         // 函数定义（5个参数，返回类型为int）
	int flag = 0;
	double d = b*b - 4*a*c;

	if(d<0) return 0;

	d = sqrt(d);
	if(a>0)
	{
		x1 = (-b - d)/(2*a);
		x2 = (-b + d)/(2*a);
	}
	else
	{
		x1 = (-b + d)/(2*a);
		x2 = (-b - d)/(2*a);
	}
	if(d>0)
		flag = 2;
	else
		flag = 1;
	return flag;
}

#include <iostream>
using namespace std;

void Display(int flag, double x1, double x2)
{
	switch(flag)
	{
	case 1: cout << "该方程有重根: x1 = x2 = " << x1; break;
	case 2: cout << "该方程的根为: x1 = " << x1 << ", x2 = " << x2; break;
	default: cout << "该方程无实根。"; break;
	}
	cout << endl;
}

int main()
{
    double a, b, c, x1, x2;             // 定义 5 个 double 型变量
    int flag;

    flag = Solver(1, -2, 1, x1, x2);    // 调用5个参数的函数}@/
    Display(flag, x1, x2);
    Solver(1, 2, -3, x1, x2, flag);     // 调用6个参数的函数}@/
    Display(flag, x1, x2);

    a = 1; b = 2; c = 3;
    flag = Solver(a, b, c, x1, x2);
    Display(flag, x1, x2);
    Solver(a, b, c, x1, x2);
    Display(flag, x1, x2);

    return 0;
}

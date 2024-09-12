// Solver.cpp
#include <cmath>

void Solver(double a, double b, double c, double &x1, double &x2, int &flag)
{                          // �������壨6���������޷������ͣ�
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
{                         // �������壨5����������������Ϊint��
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
	case 1: cout << "�÷������ظ�: x1 = x2 = " << x1; break;
	case 2: cout << "�÷��̵ĸ�Ϊ: x1 = " << x1 << ", x2 = " << x2; break;
	default: cout << "�÷�����ʵ����"; break;
	}
	cout << endl;
}

int main()
{
    double a, b, c, x1, x2;             // ���� 5 �� double �ͱ���
    int flag;

    flag = Solver(1, -2, 1, x1, x2);    // ����5�������ĺ���}@/
    Display(flag, x1, x2);
    Solver(1, 2, -3, x1, x2, flag);     // ����6�������ĺ���}@/
    Display(flag, x1, x2);

    a = 1; b = 2; c = 3;
    flag = Solver(a, b, c, x1, x2);
    Display(flag, x1, x2);
    Solver(a, b, c, x1, x2);
    Display(flag, x1, x2);

    return 0;
}

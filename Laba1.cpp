// ConsoleApplication17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

double function(double a, double b, double c, double x)
{
	if (c < 0 && x != 0)
	{
		return -a * x - c;
	}
	else if (c > 0 && x == 0)
	{
		return ((x - a) / -c);
	}
	else 
    {
		return (b*x / (c - a));
    }
}

int main()
{
	double a, b, c;
	double initialX, finalX, dX;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
	cout << "Enter c:";
	cin >> c;
	cout << "Enter initial x:";
	cin >> initialX;
	cout << "Enter final x:";
	cin >> finalX;
	cout << "Enter dx:";
	cin >> dX;

	for (double x = initialX; x <= finalX; x += dX)
	{
		cout << "x=" << x << '\t' << "y=" << function(a, b, c, x) << '\n';
	}
	system("pause");
	return 0;
}



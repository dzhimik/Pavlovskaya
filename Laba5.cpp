// ConsoleApplication23.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Ошибка в 75 строке, библиотека нужная стоит, но идентификатор не объявляется
#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

struct point 
{
	double x;
	double y;
};

std::ostream& operator << (std::ostream &s, const point &p)
{
	s << '(' << p.x << "; " << p.y << ')';
}

// Функция, вычисляющая расстояние между точками A и B по теореме Пифагора
double getDist(const point &A, const point &B) 
{
	return hypot(A.x - B.x, A.y - B.y);
}

// Функция, вычисляющая площадь треугольника ABC по формуле Герона
double getTriangleArea(const point &A, const point &B, const point &C) {
	double a = getDist(A, B);
	double b = getDist(B, C);
	double c = getDist(A, C);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Функция, определяющая, являются ли точки A, B, C и D вершинами квадрата
bool isSquare(const point &A, const point &B, const point &C, const point &D) {
	bool result = true;

	double P[6] = { getDist(A, B), getDist(A, C), getDist(A, D), getDist(B, C), getDist(B, D), getDist(C, D) };

	for (int i = 0; i < 5; i++) 
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (P[i] > P[j]) 
			{
				double temp = P[i];
				P[i] = P[j];
				P[j] = temp;
			}
		}
	}

	for (int i = 5; i >= 0; i--) 
	{
		P[i] /= P[0];
	}

	for (int i = 0; i < 4; i++) 
	{
		result *= (fabs(P[i] - 1.0) < 1e-12);
	}

	for (int i = 4; i < 6; i++) 
	{
		result *= (fabs(P[i] - sqrt(2)) < 1e-12);
	}

	return result;
}

// Функция, вычисляющая угол между отрезком AB и осью OX. Результат лежит в диапазоне [0, 2*Pi).
float getAzimuth(const point &A, const point &B)
{
	return fmod(atan2(B.y - A.y, B.x - A.x) + 2*Pi, 2*Pi);
}

// Функция, определяющая, лежит ли точка P внутри квадрата ABCD
// "квадратность" ABCD гарантируется, т.к. проверяется перед вызовом функции
bool inSquare(const point &P, const point &A, const point &B, const point &C, const point &D) 
{

	point verteces[4] = { A, B, C, D };

	for (int i = 1; i < 3; i++) 
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (getAzimuth(verteces[0], verteces[i]) > getAzimuth(verteces[0], verteces[j]))
			{
				point temp = verteces[i];
				verteces[i] = verteces[j];
				verteces[j] = temp;
			}
		}
	}

	double S1 = getTriangleArea(verteces[0], verteces[1], P);
	double S2 = getTriangleArea(verteces[1], verteces[2], P);
	double S3 = getTriangleArea(verteces[2], verteces[3], P);
	double S4 = getTriangleArea(verteces[0], verteces[3], P);

	double S = 2 * getTriangleArea(A, B, C);

	return fabs(S - S1 - S2 - S3 - S4) < 1e-10;
}

int main()
{
	point verteces[] = { {0,0}, {10,0}, {0,10}, {10,10}, {0, 20}, {-10,10}, {-1, 4}, {6, 4}, {6, 11}, {-1, 11} };
	int vertecesCount = sizeof verteces / sizeof *verteces;  
	point points[] = { {2, 7}, {3, 9}, {9, 6}, {-1, -1} };     
	int pointsCount = sizeof points / sizeof *points;        

	point square[4]; 

	bool foundSquare = false;  
	double area = 0;          

	
	for (int i = 0; i < vertecesCount - 3; i++) 
	{
		for (int j = i + 1; j < vertecesCount - 2; j++) 
		{
			for (int k = j + 1; k < vertecesCount - 1; k++) 
			{
				for (int l = k + 1; l < vertecesCount; l++) 
				{
					
					if (isSquare(verteces[i], verteces[j], verteces[k], verteces[l])) 
					{

						double currentArea = 2 * getTriangleArea(verteces[i], verteces[j], verteces[k]);

						
						if (currentArea < area || !foundSquare) 
						{
							bool currentFind = true; 
							for (int z = 0; z < pointsCount && currentFind; z++) 
							{ 
								currentFind *= inSquare(points[z], verteces[i], verteces[j], verteces[k], verteces[l]);
							}
							if (currentFind)
							{ 
								
								square[0] = verteces[i];
								square[1] = verteces[j];
								square[2] = verteces[k];
								square[3] = verteces[l];

								
								foundSquare = true;

								
								area = currentArea;
							}
						}
					}
				}
			}
		}
	}

	
	if (foundSquare) {
		
		for (int i = 0; i < 4; i++)
		{
			std::cout << square[i] << " ";
		}
	}
	else 
	{
		
		std::cout << "Квадрат не найден.";
	}

	std::cout << std::endl;
}
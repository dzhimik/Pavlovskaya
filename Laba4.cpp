// ConsoleApplication20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	struct AEROFLOT
	{
		char *flight;
		int №aircraft;
		char *typeaircraft;
	};
	AEROFLOT k[7], n, h, k;

	printf("введите пункт назначения\t");
	printf("введите номер рейса\t");
	printf("введите тип самолета\t");
	int i;
	for (i = 0; i < 7; i++)
	{
		scanf_s("%s", &k[i].flight);
		scanf_s("%d", &k[i].№aircraft);
		scanf_s("%s", &k[i].typeaircraft);
	}
	char*h = new char[strlen(flight) + 1];
	char*k = new char[strlen(typeaircraft) + 1];

	for (i = 0; i < 7; i++)
		if (strcmp(k[i].flight, k[i + 1].flight) > 0)
		{
			strcpy(n.flight, k[i + 1].flight);
			strcpy(k[i + 1].flight, k[i].flight);
			strcpy(k[i].flight, n.flight);
		}
	printf("%s", "список фамилий отсортирован по алфавиту: ");
	printf("\n");
	for (i = 0; i < 7; i++)
		puts(k[i].flight);
}
	


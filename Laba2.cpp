// ConsoleApplication19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "iostream"
using namespace std;

void min(const int[], int);
void sum(const int[], int);
void filter(int[], int);

int main()
{
	setlocale(0, "Rus");

	int N;
	cout << "Введите кол-во элементов массива: ";
	cin >> N;
	int *MAS = new int[N];

	for (int i = 0; i < N; i++)
	{
		cout << "MAS[" << i << "]: ";
		cin >> MAS[i];
	}

	min(MAS, N);
	sum(MAS, N);
	filter(MAS, N);


	delete[]MAS;
	system("pause");
	return 0;
}

void min(const int mas[], int n)
{
	int min = mas[0];

	for (int i = 0; i < n; i++)
		if (min > mas[i]) min = mas[i];

	cout << "Наименьший элемент массива: " << min << endl;
}

void sum(const int mas[], int n)
{
	size_t first = 0, last = 0;
	int sum = 0;

	for (int i = 0; i < n; i++)
		if (mas[i] > 0)
		{
			first = i;
			break;
		}


	for (int j = n - 1; j >= 0; j--)
		if (mas[j] > 0)
		{
			last = j;
			break;
		}

	for (int m = first + 1; m < last; m++)
		sum += mas[m];

	cout << "Сумма=" << sum << endl;
}

void filter(int mas[], int n)
{
	int zero = 0;
	for (int i = 0; i < n; i++)
		if (mas[i] == 0)
		{
			mas[i] = mas[zero];
			mas[zero] = 0;
			++zero;
		}

	cout << "Массив:\n";
	for (int i = 0; i < n; i++)
		cout << mas[i] << "  ";

	cout << endl;
}
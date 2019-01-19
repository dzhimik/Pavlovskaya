// ConsoleApplication16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "iostream" 
using namespace std;

int main()
{
	srand(0);
	setlocale(LC_ALL, "rus");
	int i, j, n, m;
	int **mas = 0;

	cout << "Введите колличество строк n=";
	cin >> n;
	cout << "Введеите колличество столбцов m = ";
	cin >> m;
	mas = new int*[n];
	for (i = 0; i < n; ++i)
	{

		mas[i] = new int[m];
		for (j = 0; j < m; ++j)
		{
			mas[i][j] = rand() % 10 - 1;
			cout << mas[i][j] << "\t";
		}

		cout << "\n";
	}

	bool flag = false;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; j++)
		{
			if (mas[i][j] < 0)
				flag = true;

			if (j == m - 1 && flag == false)
			{
				int t = 1;
				for (int r = 0; r < m; r++)
				{
					t = mas[i][r] * t;
				}
				cout << "Произведение в " << i << " строке равно " << t << endl;
			}
		}
	}
	int *t1 = new int[n*m];
	int *t2 = new int[n*m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			t1[i] = 0;
			t2[i] = 0;
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m - i; j++)
		{
			t1[i] += mas[i + j][j];
			t2[i] += mas[j][i + j];
		}
	}
	for (int i = 1; i < n - 1; i++)
	{
		cout << "Res(" << i << "элемент вниз) = " << t1[i] << endl;
		cout << "Res(" << i << "элемент вправо) = " << t2[i] << endl;
	}

	system("pause");
	return 0;
}
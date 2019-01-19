// ConsoleApplication28.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "fstream"
#include "pch.h"
#include <iostream>
using namespace std;

struct scan_info {
	char model[25]; // наименование модели
	int price; // цена
	double x_size; // горизонтальный размер области сканирования
	double y_size; // вертикальный размер области сканирования
	int optr; // оптическое разрешение
	int grey; // число градаций серого
};

void write_file(const char *file_name, const int num_w);

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Введите имя файла для записи:";
	char file_name[15];
	cin >> file_name;
	cout << "Введите число записей:";
	int num_w;
	cin >> num_w;
	cin.ignore(1);
	write_file(file_name, num_w);
	system("pause");
	return 0;
}

void write_file(const char *file_name, const int num_w) {
	scan_info *Scaners = new scan_info[num_w];
	ofstream fout(file_name, ios::out | ios::binary);
	if (fout.fail()) {
		cerr << "Ошибка открытия выходного файла";
		exit(1);
	}
		fout.write((char*)&num_w;
		for (int i = 0; i < num_w; i++) {
		cout << "\nЗапись №" << i + 1;
		cout << "\nВведите модель:";
		cin.getline(Scaners[i].model;
		fout << Scaner[i].model, sizeof Scaners[i].model;
		cout << "Введите цену:";
		cin >> Scaners[i].price;
		fout << Scaner[i].price;
		cout << "Введите горизонтальный размер области сканирования:";
		cin >> Scaners[i].x_size;
		fout << Scaner[i].x_size;
		cout << "Введите вертикальный размер области сканирования:";
		cin >> Scaners[i].y_size;
		fout << Scaner[i].y_size;
		cout << "Введите оптическое разрешение:";
		cin >> Scaners[i].optr;
		fout << Scaner[i].optr;
		cout << "Введите число градаций серого:";
		cin >> Scaners[i].grey;
		fout << Scaner[i].grey;
		cin.ignore(1);
	}
	fout.close();
}
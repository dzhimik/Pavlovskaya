// ConsoleApplication26.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <clocale>
#include <windows.h>
using namespace std;

struct Bilet {
	int num;//Номер заявки
	char pn[30];// Пункт назначения
	int rei; // Номер рейса
	char name[40]; // ФИО пассажира
	int day;// День вылета
	int monat;//Месяц вылета
	int year;//Год вылета

	Bilet *next;
};
Bilet* first(int, char*, int, char*, int, int, int);
void add(Bilet**, int, char*, int, char*, int, int, int);
Bilet* search(Bilet* const, int);
void viewList(Bilet*);
void viewHead();

Bilet* first(int num, char *pn, int rei, char *name, int day, int monat, int year) {
	Bilet *enew = new Bilet;
	enew->num = num;
	strcpy(enew->pn, pn);
	strcpy(enew->name, name);
	enew->day = day;
	enew->monat = monat;
	enew->year = year;
	enew->rei = rei;
	enew->next = 0;
	return enew;
}
void add(Bilet **eend, int num, char *pn, int rei, char *name, int day, int monat, int year)
{
	Bilet *enew = new Bilet;
	enew->num = num;
	strcpy(enew->pn, pn);
	strcpy(enew->name, name);
	enew->rei = rei;
	enew->day = day;
	enew->monat = monat;
	enew->year = year;
	enew->next = 0;
	(*eend)->next = enew;
	*eend = enew;
	return;
}
Bilet* search(Bilet * const ebeg, int num) {
	Bilet *enew = ebeg;
	while (enew) {
		if (enew->num == num)
			break;
		enew = enew->next;
	}
	return enew;
}
void viewAvialableList(Bilet *ebeg) {
}

void viewList(Bilet *ebeg) {
	Bilet *enew = ebeg;
	while (enew) {
		printf(" Zayvka nomer %d\n", enew->num);
		printf(" Punkt naznocheniy: %s\n", enew->pn);
		printf(" FIO pasagira: %s\n", enew->name);
		printf(" Nomer reisa: %d\n", enew->rei);
		printf(" Data veleta: %d/%d/%d\n\n", enew->day, enew->monat, enew->year);
		if (enew->next) printf("\n");
		enew = enew->next;
	}
	return;
}
void viewHead() {
	system("cls");
	printf("1. Dobavit zayvku.\n");
	printf("2. vivod vsex zayvok.\n");
	printf("3. Zapros zayvki po nomeru reisa.\n");
	printf("4. Zapros zayvki po date.\n\n");

	printf("0. vivod.\n");
	return;
}

int main()
{
	{SetConsoleCP(1251);
	SetConsoleOutputCP(1251); }
	setlocale(0, "Russian");
	bool exit = false;
	char c = 0;
	Bilet *ebeg = 0, *eend = 0;
	int day = 0, monat = 0, year = 0, num = 0, rei = 0;
	char pn[30] = { 0 },
		name[40] = { 0 };
	while (!exit) {
		viewHead();
		c = _getch();
		system("cls");
		switch (c) {
		case '1': 
			if (!eend) num = 1;
			else num = eend->num + 1;
			printf("Nomer zayvki: %d\n", num);
			printf("Пункт назначения Pynkt nasnacheniy: ");
			scanf("%s", pn);
			printf("Nomer reisa: ");
			scanf("%d", &rei);
			printf("FIO pasagira(IvanovIA): ");
			scanf("%s", name);
			printf("Data vleta(day/mesytc/god): ");
			scanf("%d/%d/%d", &day, &monat, &year);
			if (!ebeg) {
				ebeg = first(num, pn, rei, name, day, monat, year);
				eend = ebeg;
			}
			else
				add(&eend, num, pn, rei, name, day, monat, year);
			printf("Zayvka dobavlena!");
			fflush(stdin);
			_getch();
			break;

		case '2': 
			if (ebeg)
				viewList(ebeg);
			else
				printf("Zayvok net!.\n");
			_getch();
			break;

		case '3':
			if (ebeg)
				viewAvialableList(ebeg);
			else
				printf("Takoy zayvki ne sushestvuet.\n");
			_getch();
			break;
		case '0':
			exit = true;
			break;
		default:
			break;
		}
	}
	return 0;
}

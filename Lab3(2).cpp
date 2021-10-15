#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <malloc.h>
#include <conio.h>
#include <string.h>

using namespace std;

int n, ** Matrix1 = NULL;
int pogr = 0, dopo = 0;

int choose = 0, ** Matrix3 = NULL, usrentr = 0, usrentr2 = 0;

void Otogdestvlenie() {

	if (n == 0) { return; } //Нельзя отождествить матрицу 1 на 1

	Matrix3 = (int**)calloc(n, 3);
	pogr = 0;

	for (int j = 0; j < n; j++) { Matrix3[j] = (int*)calloc(n, 3); }

	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) { Matrix3[i][m] = 2; Matrix3[m][m] = 0; }
	}

	cout << "Введите номера отождествляемых вершин: \n";
	cout << "Первая: ";
	cin >> usrentr;
	cout << "Вторая: ";
	cin >> usrentr2;
	usrentr--;
	usrentr2--;

	n++; //Возвращаем n до нормального(большего на 1) значения матрицы

	for (int j = 0; j < n; j++) { Matrix1[usrentr][j] = Matrix1[usrentr2][j]; Matrix1[j][usrentr] = Matrix1[usrentr2][j]; } //Цикл для переноски значений в нужную вершину

	for (int i = 0; i < n; i++) {
		for (int m = 0 + pogr; m < n; m++) {
			if (i == m || i == usrentr2 || m == usrentr2) {}
			else if (m > usrentr2 && i < usrentr2) { Matrix3[i][m - 1] = Matrix1[i][m]; Matrix3[m - 1][i] = Matrix1[m][i]; }
			else if (m > usrentr2 && i > usrentr2) { Matrix3[i - 1][m - 1] = Matrix1[i][m]; Matrix3[m - 1][i - 1] = Matrix1[i][m]; }
			else { Matrix3[i][m] = Matrix1[i][m]; Matrix3[m][i] = Matrix1[m][i]; }
		}
		pogr++;
	}
	cout << endl;

	n--; //Уменьшаем n для взаимодействия со старой матрицей(на n-1 и n-1)

	Matrix1 = (int**)calloc(n, 3);
	for (int j = 0; j < n; j++) { Matrix1[j] = (int*)calloc(n, 3); }

	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			Matrix1[i][m] = Matrix3[i][m];
			Matrix1[m][m] = 0;
			cout << Matrix1[i][m] << " ";
		}
		cout << endl;
	}
}

void Stuagivanie() {

	if (n == 0) { return; } //Нельзя отождествить матрицу 1 на 1

	Matrix3 = (int**)calloc(n, 3);
	pogr = 0;

	for (int j = 0; j < n; j++) { Matrix3[j] = (int*)calloc(n, 3); }

	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) { Matrix3[i][m] = 2; Matrix3[m][m] = 0; }
		cout << endl;
	}

	cout << "Введите номера стягиваемых вершин: \n";
	cout << "Первая: ";
	cin >> usrentr;
	cout << "Вторая: ";
	cin >> usrentr2;
	usrentr--;
	usrentr2--;

	n++; //Возвращаем n до нормального(большего на 1) значения матрицы

	for (int j = 0; j < n; j++) { Matrix1[usrentr][j] = Matrix1[usrentr2][j]; Matrix1[j][usrentr] = Matrix1[usrentr2][j]; } //Цикл для переноски значений в нужную вершину

	for (int i = 0; i < n; i++) {
		for (int m = 0 + pogr; m < n; m++) {
			if (i == m || i == usrentr2 || m == usrentr2) {}
			else if (m > usrentr2 && i < usrentr2) { Matrix3[i][m - 1] = Matrix1[i][m]; Matrix3[m - 1][i] = Matrix1[m][i]; }
			else if (m > usrentr2 && i > usrentr2) { Matrix3[i - 1][m - 1] = Matrix1[i][m]; Matrix3[m - 1][i - 1] = Matrix1[i][m]; }
			else { Matrix3[i][m] = Matrix1[i][m]; Matrix3[m][i] = Matrix1[m][i]; }
		}
		pogr++;
	}
	cout << endl;

	n--; //Уменьшаем n для взаимодействия со старой матрицей(на n-1 и n-1)

	Matrix1 = (int**)calloc(n, 3);
	for (int j = 0; j < n; j++) { Matrix1[j] = (int*)calloc(n, 3); }

	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			Matrix1[i][m] = Matrix3[i][m];
			Matrix1[m][m] = 0;
			cout << Matrix1[i][m] << " ";
		}
		cout << endl;
	}
}

void Raschep() {

	Matrix3 = (int**)calloc(n, 3);
	for (int j = 0; j < n; j++) { Matrix3[j] = (int*)calloc(n, 3); }
	//Расширяем матрицу на одну строку и столбец

	cout << "Введите номер вершины, которую хотите расщепить: ";
	cin >> usrentr;
	usrentr--;
	n--;//Уменьшаем n для взаимодействия со старой матрицей(на n-1 и n-1)

	if (usrentr > n || usrentr < 0) { cout << "\nНекорректный ввод. Повторите попытку." << endl; return; }
	//Ограничиваем ввод пользователя

	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			if (i == usrentr) { Matrix3[n][m] = Matrix1[i][m]; Matrix3[m][n] = Matrix3[n][m]; }
			else { Matrix3[i][m] = Matrix1[i][m]; Matrix3[m][i] = Matrix1[m][i]; }
		}
	}

	Matrix3[usrentr][n] = 1;
	Matrix3[n][usrentr] = 1;
	//У расщепляемых вершин должно быть соединяющее ребро

	n++; //Возвращаем n до нормального(большего на 1) значения матрицы
	Matrix1 = (int**)calloc(n, 3);
	for (int j = 0; j < n; j++) { Matrix1[j] = (int*)calloc(n, 3); }

	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			Matrix1[i][m] = Matrix3[i][m];
			Matrix1[m][m] = 0;
			cout << Matrix1[i][m] << " ";
		}
		cout << endl;
	}
	cout << "\nВершина " << usrentr + 1 << " была расщеплена в вершину " << n << endl;
}

int main() {

	setlocale(LC_ALL, "Rus");
	srand(time(0));

	//Задание 1//

	cout << "Введите размерность матрицы: ";
	cin >> n;

	if (n <= 0) { cout << "\nНекорректный ввод. Повторите попытку.\n"; return 0; } //Ограничитель на ввод

	Matrix1 = (int**)calloc(n, 3);
	for (int j = 0; j < n; j++) { Matrix1[j] = (int*)calloc(n, 3); }
	cout.precision(3 * n);

	for (int i = 0; i < n; i++) {
		for (int m = 0 + pogr; m < n; m++) {
			Matrix1[i][m] = 0 + rand() % 2;
			Matrix1[m][i] = Matrix1[i][m];
			Matrix1[i][i] = 0;
		}
		pogr++;
	}

	//Задание 2//

	while (choose != 4) {

		system("cls");

		cout << "\nМатрица №1:" << endl;
		for (int i = 0; i < n; i++) {
			for (int m = 0; m < n; m++) { cout << Matrix1[i][m] << " "; }
			cout << endl;
		}

		cout << "\n1.Отождествить вершины" << endl;
		cout << "2.Стянуть рёбра" << endl;
		cout << "3.Расщепление вершины" << endl;
		cout << "4.Выход\n" << endl;
		cout << "\nВыберите операцию для выполнения: ";

		cin >> choose;

		switch (choose) {

		case 1://Отождествление вершин
			n--;
			Otogdestvlenie();
			_getch();
			break;

		case 2://Стягивание ребра
			n--;
			Stuagivanie();
			_getch();
			break;

		case 3: //Расщепление вершины
			n++;
			Raschep();
			_getch();
			break;

		case 4:
			cout << "\nВыход из программы." << endl;
			break;

		default:
			cout << "\nНекорректный ввод. Повторите попытку." << endl;
			break;
		}
	}
	return 0;
 }

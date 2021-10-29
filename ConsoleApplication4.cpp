#include <iostream>
#include <ctime>
#include <stdio.h>
#include <malloc.h>
#include <conio.h>

using namespace std;

int n, ** Matrix1 = NULL;
int pogr = 0, usrentr, usrentr2;

int choose = 0, ** Matrix3 = NULL;

//Вершина / След.элемент; Номер
struct SmegnElem {
	SmegnElem* Nextelem;
	int num;
};

//Список смежности
struct SmegnList {
	SmegnElem* First;
	int Colo;
} **SpecMatrix = NULL, ** SpecMatrixRezerve = NULL;

//Создание списка смежности
SmegnList* CreateList() {
	SmegnList* groups = (SmegnList*)malloc(sizeof(SmegnList));
	groups->First = NULL;
	groups->Colo = 0;
	return groups;
}

//Добавление элемента в список смежности
void AddSmegElem(SmegnList* group, int Chis) {
	SmegnElem* newItem = (SmegnElem*)malloc(sizeof(SmegnElem));
	newItem->Nextelem = NULL;
	newItem->num = Chis;

	if (group->Colo == 0) {                          //При отсутствии элементов записываем как первый
		group->First = newItem;
		group->Colo++;
		return;
	}

	SmegnElem* last = group->First;                      //При наличии других элементов начинаем перебор

	while (last->Nextelem != NULL) {
		last = last->Nextelem;
	}
	last->Nextelem = newItem;
	group->Colo++;

}

//Отрисовка списка смежности
void PrintSmegElem(SmegnList* groups) {


	if (groups->Colo == 0) {                                        //При размере = 0, у нас нет данных
		cout << "Список пуст" << endl;
		return;
	}

	SmegnElem* current = groups->First;

	while (current != NULL) {                                       //Перебор структуры до последнего элемента(с выводом)
		int value = current->num;
		cout << value << " ";
		current = current->Nextelem;
	}
	cout << endl;
}

//Функции для матричного представления графа
void Otogdestvlenie() {

	if (n == 0) { return; } //Нельзя отождествить матрицу 1 на 1

	Matrix3 = (int**)calloc(n, 3); //Выделяем динамический массив
	pogr = 0;

	for (int j = 0; j < n; j++) { Matrix3[j] = (int*)calloc(n, 3); } //Заполняем динамический массив динамическими массивами

	for (int i = 0; i < n; i++) { for (int m = 0; m < n; m++) { Matrix3[i][m] = 2; Matrix3[m][m] = 0; } } // Заполняем матрицу 0 и 2

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

//Функции для представления графа списками смежности

void OtogdestvlenieSmegn() {

	SpecMatrixRezerve = (SmegnList**)calloc(n, sizeof(SmegnList**));

	SmegnElem* Actual = SpecMatrix[usrentr2]->First->Nextelem;
	SmegnElem* Fresh = SpecMatrix[usrentr]->First;

	bool Check = false;
	int Dopo = 0;

	usrentr2++;


	while (Actual != NULL) {

		Check = false;
		Fresh = SpecMatrix[usrentr]->First;

		while (Fresh != NULL) {
			if (Fresh->num == Actual->num) { Check = true; }
			Fresh = Fresh->Nextelem;
		}

		if (Check != true) {
			AddSmegElem(SpecMatrix[usrentr], Actual->num);
			AddSmegElem(SpecMatrix[Actual->num - 1], usrentr + 1);
		}

		Actual = Actual->Nextelem;
	}

	_getch();
	cout << "\nEtap 1" << endl;
	for (int i = 0; i < n + 1; i++) { PrintSmegElem(SpecMatrix[i]); }

	for (int i = 0; i < n + 1; i++) {
		Actual = SpecMatrix[i]->First->Nextelem;
		Fresh = SpecMatrix[i]->First;

		while (Actual != NULL) {

			if (Actual->Nextelem == NULL && Actual->num == usrentr2) { Fresh->Nextelem = NULL; }
			if (Actual->num == usrentr2 && Actual->Nextelem != NULL) { Fresh->Nextelem = Actual->Nextelem; }
			Fresh = Actual;
			Actual = Actual->Nextelem;
		}
	}

	_getch();
	cout << "\nEtap 2: " << usrentr2 << endl;
	for (int i = 0; i < n + 1; i++) { PrintSmegElem(SpecMatrix[i]); }

	for (int i = 0; i < n; i++) {
		if (SpecMatrix[Dopo]->First->num == usrentr2) { Dopo++; }
		SpecMatrixRezerve[i] = SpecMatrix[Dopo]; Dopo++;
	}

	_getch();
	cout << "\nEtap 3" << endl;
	for (int i = 0; i < n + 1; i++) { PrintSmegElem(SpecMatrix[i]); }
	cout << endl;
	for (int i = 0; i < n; i++) { PrintSmegElem(SpecMatrixRezerve[i]); }

	SpecMatrix = (SmegnList**)calloc(n, sizeof(SmegnList**));
	SpecMatrix = SpecMatrixRezerve;

	cout << endl;
	for (int i = 0; i < n; i++) { PrintSmegElem(SpecMatrix[i]); }
}

void StuagivanieSmegn() {

	SpecMatrixRezerve = (SmegnList**)calloc(n, sizeof(SmegnList**));

	SmegnElem* Actual = SpecMatrix[usrentr2]->First->Nextelem;
	SmegnElem* Fresh = SpecMatrix[usrentr]->First;

	bool Check = false;
	int Dopo = 0;

	usrentr2++;


	while (Actual != NULL) {

		Check = false;
		Fresh = SpecMatrix[usrentr]->First;

		while (Fresh != NULL) {
			if (Fresh->num == Actual->num) { Check = true; }
			Fresh = Fresh->Nextelem;
		}

		if (Check != true) {
			AddSmegElem(SpecMatrix[usrentr], Actual->num);
			AddSmegElem(SpecMatrix[Actual->num - 1], usrentr + 1);
		}

		Actual = Actual->Nextelem;
	}

	_getch();
	cout << "\nEtap 1" << endl;
	for (int i = 0; i < n + 1; i++) { PrintSmegElem(SpecMatrix[i]); }

	for (int i = 0; i < n + 1; i++) {
		Actual = SpecMatrix[i]->First->Nextelem;
		Fresh = SpecMatrix[i]->First;

		while (Actual != NULL) {

			if (Actual->Nextelem == NULL && Actual->num == usrentr2) { Fresh->Nextelem = NULL; }
			if (Actual->num == usrentr2 && Actual->Nextelem != NULL) { Fresh->Nextelem = Actual->Nextelem; }
			Fresh = Actual;
			Actual = Actual->Nextelem;
		}
	}

	_getch();
	cout << "\nEtap 2: " << usrentr2 << endl;
	for (int i = 0; i < n + 1; i++) { PrintSmegElem(SpecMatrix[i]); }

	for (int i = 0; i < n; i++) {
		if (SpecMatrix[Dopo]->First->num == usrentr2) { Dopo++; }
		SpecMatrixRezerve[i] = SpecMatrix[Dopo]; Dopo++;
	}

	_getch();
	cout << "\nEtap 3" << endl;
	for (int i = 0; i < n + 1; i++) { PrintSmegElem(SpecMatrix[i]); }
	cout << endl;
	for (int i = 0; i < n; i++) { PrintSmegElem(SpecMatrixRezerve[i]); }

	SpecMatrix = (SmegnList**)calloc(n, sizeof(SmegnList**));
	SpecMatrix = SpecMatrixRezerve;

	cout << endl;
	for (int i = 0; i < n; i++) { PrintSmegElem(SpecMatrix[i]); }
}

void RaschepSmegn() {

	SpecMatrixRezerve = (SmegnList**)calloc(n, sizeof(SmegnList**));

	int Save = 0;

	/*cout << "Введите номер вершины, которую хотите расщепить: ";      //Разблокировать при одиночном использовании(без матричной функции)
	cin >> usrentr;
	usrentr--;*/

	SmegnElem* Actual = SpecMatrix[usrentr]->First;

	SpecMatrixRezerve = SpecMatrix;

	SpecMatrixRezerve[n - 1] = CreateList();
	AddSmegElem(SpecMatrixRezerve[n - 1], n);

	while (Actual != NULL) {
		if (Actual->num != n) {
			AddSmegElem(SpecMatrixRezerve[n - 1], Actual->num);
			AddSmegElem(SpecMatrixRezerve[Actual->num - 1], n);
		}
		Actual = Actual->Nextelem;
	}

	SpecMatrix = (SmegnList**)calloc(n, sizeof(SmegnList**));
	SpecMatrix = SpecMatrixRezerve;

	cout << endl;
	for (int i = 0; i < n; i++) { PrintSmegElem(SpecMatrix[i]); }
}


int main() {

	setlocale(LC_ALL, "Rus");
	srand(time(0));

	//Задание 1//

	cout << "Введите размерность матриц: ";
	cin >> n;

	if (n <= 0) { cout << "\nНекорректный ввод. Повторите попытку" << endl; return 0; }

	Matrix1 = (int**)calloc(n, 3);
	SpecMatrix = (SmegnList**)calloc(n, sizeof(SmegnList**));

	for (int j = 0; j < n; j++) {
		Matrix1[j] = (int*)calloc(n, 3);
		SpecMatrix[j] = CreateList();  //Создаём список смежности
		AddSmegElem(SpecMatrix[j], j + 1); //Вставляем в начало каждого списка смежности номер отвечающей вершины
	}

	cout.precision(3 * n);

	for (int i = 0; i < n; i++) {
		for (int m = 0 + pogr; m < n; m++) {
			Matrix1[i][m] = 0 + rand() % 2;
			Matrix1[m][i] = Matrix1[i][m];
			Matrix1[i][i] = 0;
		}
		pogr++;
	}

	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) { if (Matrix1[i][m] == 1) { AddSmegElem(SpecMatrix[i], m + 1); } }
	}

	//Задание 3//

	while (choose != 4) {

		system("cls");

		cout << "\nМатрица №1:" << endl;
		for (int i = 0; i < n; i++) {
			for (int m = 0; m < n; m++) {
				cout << Matrix1[i][m] << " ";
			}
			cout << endl;
		}

		cout << "\nСписки смежности для Мартицы №1:" << endl;
		for (int i = 0; i < n; i++) { PrintSmegElem(SpecMatrix[i]); }

		cout << "\n1.Отождествить вершины" << endl;
		cout << "2.Стянуть рёбра" << endl;
		cout << "3.Расщепление вершины" << endl;
		cout << "4.Выход" << endl;
		cout << "\nВыберите операцию для выполнения: ";

		cin >> choose;

		switch (choose) {

		case 1://Отождествление вершин
			n--;
			Otogdestvlenie();
			OtogdestvlenieSmegn();
			_getch();
			break;

		case 2://Стягивание ребра
			n--;
			Stuagivanie();
			StuagivanieSmegn();
			_getch();
			break;

		case 3://Расщепление вершины
			n++;
			Raschep();
			RaschepSmegn();
			_getch();
			break;

		case 4://Выход из цикла
			cout << "\nВыход из программы." << endl;
			break;

		default:
			cout << "\nНекорректный ввод. Повторите попытку." << endl;
			break;
		}
	}

	return 0;
}

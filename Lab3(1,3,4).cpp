#include <iostream>
#include <ctime>
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <math.h>

using namespace std;

int n, ** Matrix1 = NULL, ** Matrix2 = NULL;
int pogr = 0;

int choose = 0, ** Matrix3 = NULL, ** Matrix4 = NULL;

//Вершина / След.элемент; Номер
struct SmegnElem {
	SmegnElem* Nextelem;
	int num;
};

//Список смежности
struct SmegnList {
	SmegnElem* First;
	int Colo;
} **SpecMatrix = NULL, ** SpecMatrix2 = NULL;

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

void Obiedinenie() {
	cout << "Объединение матриц 1 и 2:" << endl;
	//Объединение
	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			if (Matrix1[i][m] == 0 && Matrix2[i][m] == 0) {
				Matrix3[i][m] = 0;
			}
			else {
				Matrix3[i][m] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			cout << Matrix3[i][m] << " ";
		}
		cout << endl;
	}
}

void Peresechenie() {
	cout << "Пересечение матриц 1 и 2:" << endl;
	//Пересечение
	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			if (Matrix1[i][m] == 1 && Matrix2[i][m] == 1) {
				Matrix3[i][m] = 1;
			}
			else {
				Matrix3[i][m] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			cout << Matrix3[i][m] << " ";
		}
		cout << endl;
	}
}

void ShapeSumm() {
	cout << "Кольцевая сумма матриц 1 и 2:" << endl;
	//Кольцевая сумма
	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			if ((Matrix1[i][m] == 0 && Matrix2[i][m] == 0) || (Matrix1[i][m] == 1 && Matrix2[i][m] == 1)) {
				Matrix3[i][m] = 0;
			}
			else {
				Matrix3[i][m] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			cout << Matrix3[i][m] << " ";
		}
		cout << endl;
	}

}

void DekartProizv() {
	int pogro = 0;
	int x = 1, y = 1, x1 = 0, x2;
	int koef = 1, speca = 1, yepo = 0, depo = 1;
	int contain = 0;

	cout << "Декартово произведение матриц 1 и 2:" << endl;
	//Декартово произведение
	Matrix4 = (int**)calloc(n * n, 3);
	for (int i = 0; i < n * n; i++) { Matrix4[i] = (int*)calloc(n * n, 3); }

	for (int i = 0; i < n * n; i++) {
		for (int j = 0 + pogro; j < n * n; j++) {
			Matrix4[i][j] = x * 10 + y;
			x++;
		}
		y++;
		pogro++;
		x = pogro + 1;
	}

	pogro = 0;

	for (int i = 0; i < n * n; i++) {
		koef = i / n + 1;
		for (int j = 0 + pogro; j < n * n; j++) {
			x = Matrix4[i][j] / 10;
			y = Matrix4[i][j] % 10;
			x2 = i + 1;

			if (x + y <= (n * 2) * koef && x <= n * koef && y <= n * koef) { Matrix4[i][j] = Matrix2[x - (n * (koef - 1)) - 1][y - (n * (koef - 1)) - 1]; }
			else if (x2 + n * speca == x) {
				x1++;
				Matrix4[i][j] = Matrix1[yepo][depo];
				speca++;
				if (x1 == 3) { x1 = 0; depo++; }
			}
			else { Matrix4[i][j] = 0; }
			Matrix4[j][i] = Matrix4[i][j];

		}

		Matrix4[i][i] = 0;
		speca = 1;
		pogro++;
		if (depo <= 2) {}
		else { yepo = 1; depo = 2; }
	}

	for (int i = 0; i < n * n; i++) {
		Matrix4[i][i] = 0;
		for (int j = 0; j < n * n; j++) {
			cout.width(4);
			cout << Matrix4[i][j];
		}
		cout << endl;
	}

}

void DekartProizv2() {
	int x = -1, y = -1;

	Matrix4 = (int**)calloc(n * n, 3);
	for (int i = 0; i < n * n; i++) { Matrix4[i] = (int*)calloc(n * n, 3); }

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			y = -1;
			x++;
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < n; l++) {
					y++;
					if (i == j) { Matrix4[x][y] = Matrix2[k][l]; }
					else { Matrix4[x][y] = 0; }
					if (k == l) { Matrix4[x][y] = Matrix1[i][j]; }
				}
			}
		}
	}

	for (int i = 0; i < n * n; i++) {
		for (int j = 0; j < n * n; j++) {
			cout.width(4);
			cout << Matrix4[i][j];
		}
		cout << endl;
	}
}

int main() {

	setlocale(LC_ALL, "Rus");
	srand(time(0));

	//Задание 1//

	cout << "Введите размерность матриц: ";
	cin >> n;

	if (n <= 0) { cout << "\nНекорректный ввод. Повторите попытку" << endl; return 0; }

	Matrix1 = (int**)calloc(n, 3);
	Matrix2 = (int**)calloc(n, 3);
	SpecMatrix = (SmegnList**)calloc(n, sizeof(SmegnList**));
	SpecMatrix2 = (SmegnList**)calloc(n, sizeof(SmegnList**));

	for (int j = 0; j < n; j++) {
		Matrix1[j] = (int*)calloc(n, 3);
		Matrix2[j] = (int*)calloc(n, 3);
		SpecMatrix[j] = CreateList();  //Создаём списки смежности
		SpecMatrix2[j] = CreateList();
		AddSmegElem(SpecMatrix[j], j + 1); //Вставляем в начало каждого списка смежности номер отвечающей вершины
		AddSmegElem(SpecMatrix2[j], j + 1);
	}

	cout.precision(3 * n);

	for (int i = 0; i < n; i++) {
		for (int m = 0 + pogr; m < n; m++) {
			Matrix1[i][m] = 0 + rand() % 2;
			Matrix1[m][i] = Matrix1[i][m];
			Matrix1[i][i] = 0;

			Matrix2[i][m] = 0 + rand() % 2;
			Matrix2[m][i] = Matrix2[i][m];
			Matrix2[i][i] = 0;
		}
		pogr++;
	}

	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			if (Matrix1[i][m] == 1) { AddSmegElem(SpecMatrix[i], m + 1); }
			if (Matrix2[i][m] == 1) { AddSmegElem(SpecMatrix2[i], m + 1); }
		}
	}

	//Задание 3//

	while (choose != 5) {

		system("cls");

		cout << "\nМатрица №1:" << endl;
		for (int i = 0; i < n; i++) {
			for (int m = 0; m < n; m++) {
				cout << Matrix1[i][m] << " ";
			}
			cout << endl;
		}

		cout << "\nСписок смежности для Мартицы №1:" << endl;
		for (int i = 0; i < n; i++) { PrintSmegElem(SpecMatrix[i]); }

		cout << "\nМатрица №2:" << endl;
		for (int i = 0; i < n; i++) {
			for (int m = 0; m < n; m++) {
				cout << Matrix2[i][m] << " ";
			}
			cout << endl;
		}

		cout << "\nСписок смежности для Мартицы №2:" << endl;
		for (int i = 0; i < n; i++) { PrintSmegElem(SpecMatrix2[i]); }

		cout << "\n1.Объединение" << endl;
		cout << "2.Пересечение" << endl;
		cout << "3.Кольцевая сумма" << endl;
		cout << "4.Декартово произведение" << endl;
		cout << "5.Выход\n" << endl;
		cout << "Выберите операцию для выполнения: ";
		cin >> choose;
		cout << endl;

		Matrix3 = (int**)calloc(n, 3);
		for (int j = 0; j < n; j++) { Matrix3[j] = (int*)calloc(n, 3); }

		switch (choose) {

		case 1://Объединение
			Obiedinenie();
			_getch();
			break;

		case 2://Пересечение
			Peresechenie();
			_getch();
			break;

		case 3://Кольцевая сумма
			ShapeSumm();
			_getch();
			break;

		case 4://Декартово произведение
			DekartProizv2();
			cout << endl;
			DekartProizv();
			_getch();
			break;

		case 5:
			cout << "\nВыход из программы" << endl;
			break;

		default:
			cout << "\nНекорректный ввод. Повторите попытку." << endl;
			break;
		}
	}

	return 0;
}

#include <iostream>
#include <ctime>
#include <malloc.h>
#include <conio.h>

using namespace std;

int n, ** Matrix1 = NULL, ** Matrix2 = NULL;
int pogr = 0, dopo = 0;

int choose = 0, ** Matrix3 = NULL, usrentr = 0, usrentr2 = 0;

int main() {

	setlocale(LC_ALL, "Rus");
	srand(time(0));

	//Задание 1//

	cout << "Введите размерность матриц: ";
	cin >> n;

	Matrix1 = (int**)calloc(n, 3);
	Matrix2 = (int**)calloc(n, 3);

	for (int j = 0; j < n; j++) {
		Matrix1[j] = (int*)calloc(n, 3);
		Matrix2[j] = (int*)calloc(n, 3);
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

	cout << "\nМатрица №1:" << endl;
	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			cout << Matrix1[i][m] << " ";
		}
		cout << endl;
	}

	cout << "\nМатрица №2:" << endl;
	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			cout << Matrix2[i][m] << " ";
		}
		cout << endl;
	}

	//Задание 2//

	cout << "\n1.Отождествить вершины" << endl;
	cout << "2.Стянуть рёбра" << endl;
	cout << "3.Расщепление вершины\n" << endl;
	cout << "\nВыберите операцию для выполнения: ";

	cin >> choose;

	switch (choose) {

	case 1://Отождествление вершин
		Matrix3 = (int**)calloc(n - 1, 3);

		pogr = 0;

		for (int j = 0; j < n - 1; j++) { Matrix3[j] = (int*)calloc(n - 1, 3); }

		for (int i = 0; i < n - 1; i++) {
			for (int m = 0; m < n - 1; m++) {
				Matrix3[i][m] = 2;
				Matrix3[m][m] = 0;
			}
			cout << endl;
		}

		cout << "Введите номера отождествляемых вершин: \n";
		cout << "Первая: ";
		cin >> usrentr;
		cout << "Вторая: ";
		cin >> usrentr2;

		usrentr--;
		usrentr2--;

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

		for (int i = 0; i < n - 1; i++) {
			for (int m = 0; m < n - 1; m++) {
				cout << Matrix3[i][m] << " ";
			}
			cout << endl;
		}
		_getch();
		break;

	case 2://Стягивание ребра

		Matrix3 = (int**)calloc(n - 1, 3);

		pogr = 0;

		for (int j = 0; j < n - 1; j++) { Matrix3[j] = (int*)calloc(n - 1, 3); }

		for (int i = 0; i < n - 1; i++) {
			for (int m = 0; m < n - 1; m++) {
				Matrix3[i][m] = 2;
				Matrix3[m][m] = 0;
			}
			cout << endl;
		}

		cout << "Введите номера стягиваемых вершин: \n";
		cout << "Первая: ";
		cin >> usrentr;
		cout << "Вторая: ";
		cin >> usrentr2;
		usrentr--;
		usrentr2--;

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

		for (int i = 0; i < n - 1; i++) {
			for (int m = 0; m < n - 1; m++) {
				cout << Matrix3[i][m] << " ";
			}
			cout << endl;
		}
		break;

	case 3: //Расщепление вершины
		Matrix3 = (int**)calloc(n + 1, 3);

		for (int j = 0; j < n + 1; j++) {
			Matrix3[j] = (int*)calloc(n + 1, 3);
		}
		//Расширяем матрицу на одну строку и столбец

		cout << "Введите номер вершины, которую хотите расщепить: ";
		cin >> usrentr;
		usrentr--;

		if (usrentr > n || usrentr < 0) { cout << "\nНекорректный ввод. Повторите попытку." << endl; break; }
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

		for (int i = 0; i < n + 1; i++) {
			for (int m = 0; m < n + 1; m++) {
				Matrix3[m][m] = 0;
				cout << Matrix3[i][m] << " ";
			}
			cout << endl;
		}
		
		cout << "\nВершина " << usrentr + 1 << " была расщеплена в вершину " << n + 1 << endl;
		break;
	
	default:
		cout << "\nНекорректный ввод. Повторите попытку." << endl;
		break;
	}

	return 0;
}
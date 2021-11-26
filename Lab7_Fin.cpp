#include <iostream>
#include <time.h>
#include <malloc.h>
#include <locale.h>
#include <queue>
#include <ctime>
#include <conio.h>

#include <climits>  //Для предельного значения int
#include <string>

using namespace std;

int i, num = 0, pogr = 0;
int* vis = NULL, n = 7, ** p = NULL;
int Wei = 1, Way = 1;

//Поиск расстояний от вершины графа
void BFSD(int v, int** p) {

	queue <int> q;
	q.push(v);
	vis[v] = 0;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 0; i < n; i++) {

			if (vis[i] > vis[v] + p[i][v] && p[i][v] != 0) {
				q.push(i);
				vis[i] = vis[v] + p[i][v];
			}
		}
	}
	cout << endl;

}

//Функция для создания нужного графав виде матрицы смежности // Weight = макимально возможный вес// Way = 1 / 0(Направлен граф или нет)// Size - размер
void CreateGraphFunc(int Weight, int Way, int Size) {

	p = (int**)calloc(Size, sizeof(int));                             //Выделяем место под динамическую матрицу
	for (i = 0; i < n; i++) {p[i] = (int*)calloc(Size, sizeof(int));} //Выделение места для строк динамической матрицы

	for (int i = 0; i < n; i++) { //Генерация путей и их веса
		for (int m = 0; m < n; m++) {
			
			p[i][m] = 0 + rand() % Weight;
			
			switch (Way) {

			case 1:
				p[m][i] = 0 + rand() % Weight;
				break;

			case 0:
				p[m][i] = p[i][m];
				break;
			}

			p[i][i] = 0;
		}
	}
}

int main(int argc, char* argv[]) {

	setlocale(LC_ALL, "Rus");
	srand(time(0));

	cout.precision(3 * n);

	vis = (int*)calloc(n, sizeof(int));  //Выделяем место под массив прохождения
	for (i = 0; i < n; i++) {vis[i] = 0;} //Обнуляем массив прохождения

	if (argc <= 3) { cout << "Отсутствуют параметры для работы программы.\nАвтоматическое создание." << endl; CreateGraphFunc(2, 0, 7);}
	else {Wei = atoi(argv[1]); Way = atoi(argv[2]); n = atoi(argv[3]); CreateGraphFunc(Wei, Way, n);}

	cout << "\nМатрица:" << endl; //Вывод динамической матрицы
	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) { cout << p[i][m] << " "; }
		cout << endl;
	}

	for (int i = 0; i < n; i++) { vis[i] = INT_MAX; } //Для нахождения минимальной длинны пути, нужно максимальное значение int

	BFSD(0, p);

    for (int i = 1; i < n; i++) { cout << "Расстояние от вершины 1 до вершины " << i + 1 << " равно " << vis[i] << endl;} //Вывод расстояний
	cout << endl;

	_getch();

	return 0;

}



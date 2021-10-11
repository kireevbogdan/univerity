#include"stdafx.h"
#include<iostream>
#include<ctime>
#include<malloc.h>
#include<conio.h>


usingnamespace std;

int* vis = NULL, n, ** p = NULL, ** x = NULL;
intpogr = 1, pogrx = 0;


void DFS(intnum) {

	cout<<num + 1 <<" "; // вывод вершин
	vis[num] = 1;//вершина пройдена
	for (inti = 0; i<=n; i++) {
		if(p[num][i] == 1 &&vis[i] == 0) { // проверка на посещение ранее
			DFS(i);
		}
	}
}

int main() {

	setlocale(LC_ALL, "Rus");
	srand(time(0)); //по-настоящему случайная генерация массива
	cout<<"Пункты 1, 2:\n";
	cout<<"Введите размер матрицы: ";
	cin>>n;
	cout<<"Массив: \n";

	vis = (int*)calloc(n, 3);
	p = (int**)calloc(n, 3);
	x = (int**)calloc(n, 3);

	for (inti = 0; i< n; i++) {
		p[i] = (int*)calloc(n, 3);
		x[i] = (int*)calloc(n, 3);
		x[i][0] = i + 1;
	}
	cout.precision(3 * n);

	for (inti = 0; i< n; i++) {
		for (int m = 0+pogrx; m < n; m++) {
			p[i][m] = 0 + rand() % 2;
			p[m][i] = p[i][m];
			p[i][i] = 0;
		}
		pogrx++;
	}

	for (inti = 0; i< n; i++) {
		for (int m = 0; m < n; m++) {
			if (p[i][m] == 1 &&i!=m) { x[i][pogr] = m + 1; pogr++; }
			else { x[i][pogr] = 0; pogr++; }
			cout<< p[i][m] <<" ";
		}
		pogr = 1;
		cout<<endl;
	}

	cout<<"Вершины: "<<endl;

	DFS(0);
	DFS(n-1);


	cout<<"\n\nПункт 3:\n";


	for (inti = 0; i< n; i++) {
		for (int m = 0; m <= n; m++) {
			if (x[i][m]!=0){cout<< x[i][m] <<" ";}
			
		}
		cout<<endl;
	}

	return 0;
}

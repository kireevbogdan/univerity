#include <iostream>
#include <ctime>
#include <malloc.h>
#include <conio.h>

using namespace std;

int* vis = NULL, n, ** p = NULL, ** x = NULL;
int pogr = 1;


void DFS(int num) {

	cout << num + 1 << " "; // ����� ������
	vis[num] = 1;//������� ��������
	for (int i = 0; i < n; i++) {
		if (p[num][i] == 0 && vis[i] == 0) { // �������� �� ��������� �����
			DFS(i);
		}
	}
}

int main() {

	setlocale(LC_ALL, "Rus");
	srand(time(0)); //��-���������� ��������� ��������� �������
	cout << "������ 1, 2:\n";
	cout << "������� ������ �������: ";
	cin >> n;
	cout << "������: \n";

	vis = (int*)calloc(n, 3);
	p = (int**)calloc(n, 3);
	x = (int**)calloc(n, 3);

	for (int i = 0; i < n; i++) {
		p[i] = (int*)calloc(n, 3);
		x[i] = (int*)calloc(n, 3);
		x[i][0] = i + 1;
	}
	cout.precision(3 * n);

	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			p[i][m] = 0 + rand() % 2;

			if (p[i][m] == 1 && i!=m) { x[i][pogr] = m + 1; pogr++; }
			else { x[i][pogr] = 0; pogr++; }

			p[i][i] = 0;
			cout << p[i][m] << " ";
		}
		
		pogr = 1;
		cout << endl;

	}

	cout << "�������: " << endl;

	DFS(0);

	cout << "\n\n����� 3:\n";


	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			if (x[i][m]!=0){cout << x[i][m] << " ";}
			
		}
		cout << endl;
	}	

	return 0;
}

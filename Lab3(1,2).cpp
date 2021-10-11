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

	//������� 1//

	cout << "������� ����������� ������: ";
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

	cout << "\n������� �1:" << endl;
	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			cout << Matrix1[i][m] << " ";
		}
		cout << endl;
	}

	cout << "\n������� �2:" << endl;
	for (int i = 0; i < n; i++) {
		for (int m = 0; m < n; m++) {
			cout << Matrix2[i][m] << " ";
		}
		cout << endl;
	}

	//������� 2//

	cout << "\n1.������������ �������" << endl;
	cout << "2.������� ����" << endl;
	cout << "3.����������� �������\n" << endl;
	cout << "\n�������� �������� ��� ����������: ";

	cin >> choose;

	switch (choose) {

	case 1://�������������� ������
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

		cout << "������� ������ ��������������� ������: \n";
		cout << "������: ";
		cin >> usrentr;
		cout << "������: ";
		cin >> usrentr2;

		usrentr--;
		usrentr2--;

		for (int j = 0; j < n; j++) { Matrix1[usrentr][j] = Matrix1[usrentr2][j]; Matrix1[j][usrentr] = Matrix1[usrentr2][j]; } //���� ��� ��������� �������� � ������ �������

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

	case 2://���������� �����

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

		cout << "������� ������ ����������� ������: \n";
		cout << "������: ";
		cin >> usrentr;
		cout << "������: ";
		cin >> usrentr2;
		usrentr--;
		usrentr2--;

		for (int j = 0; j < n; j++) { Matrix1[usrentr][j] = Matrix1[usrentr2][j]; Matrix1[j][usrentr] = Matrix1[usrentr2][j]; } //���� ��� ��������� �������� � ������ �������

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

	case 3: //����������� �������
		Matrix3 = (int**)calloc(n + 1, 3);

		for (int j = 0; j < n + 1; j++) {
			Matrix3[j] = (int*)calloc(n + 1, 3);
		}
		//��������� ������� �� ���� ������ � �������

		cout << "������� ����� �������, ������� ������ ���������: ";
		cin >> usrentr;
		usrentr--;

		if (usrentr > n || usrentr < 0) { cout << "\n������������ ����. ��������� �������." << endl; break; }
		//������������ ���� ������������

		for (int i = 0; i < n; i++) {
			for (int m = 0; m < n; m++) {
				if (i == usrentr) { Matrix3[n][m] = Matrix1[i][m]; Matrix3[m][n] = Matrix3[n][m]; }
				else { Matrix3[i][m] = Matrix1[i][m]; Matrix3[m][i] = Matrix1[m][i]; }
			}
		}

		Matrix3[usrentr][n] = 1;
		Matrix3[n][usrentr] = 1;
		//� ������������ ������ ������ ���� ����������� �����

		for (int i = 0; i < n + 1; i++) {
			for (int m = 0; m < n + 1; m++) {
				Matrix3[m][m] = 0;
				cout << Matrix3[i][m] << " ";
			}
			cout << endl;
		}
		
		cout << "\n������� " << usrentr + 1 << " ���� ���������� � ������� " << n + 1 << endl;
		break;
	
	default:
		cout << "\n������������ ����. ��������� �������." << endl;
		break;
	}

	return 0;
}
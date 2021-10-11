#include <iostream>
#include <ctime>
#include <malloc.h>
#include <conio.h>

using namespace std;

int n, ** Matrix1 = NULL, ** Matrix2 = NULL;
int pogr = 0;

int choose = 0, ** Matrix3 = NULL;

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

	//������� 3//

	cout << "\n1.�����������" << endl;
	cout << "2.�����������" << endl;
	cout << "3.��������� �����\n" << endl;
	cout << "�������� �������� ��� ����������: ";
	cin >> choose;
	cout << endl;

	switch (choose) {

	case 1://�����������
		Matrix3 = (int**)calloc(n, 3);

		for (int j = 0; j < n; j++) { Matrix3[j] = (int*)calloc(n, 3); }
		cout << "����������� ������ 1 � 2:" << endl;
		//�����������
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

		break;
		
	case 2://�����������
		Matrix3 = (int**)calloc(n, 3);

		for (int j = 0; j < n; j++) { Matrix3[j] = (int*)calloc(n, 3); }
		cout << "����������� ������ 1 � 2:" << endl;
		//�����������
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

		break;

	case 3: //��������� �����
		Matrix3 = (int**)calloc(n, 3);

		for (int j = 0; j < n; j++) { Matrix3[j] = (int*)calloc(n, 3); }
		cout << "��������� ����� ������ 1 � 2:" << endl;
		//��������� �����
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

		break;

	default:
		cout << "\n������������ ����. ��������� �������." << endl;
		break;
	}

	return 0;
}

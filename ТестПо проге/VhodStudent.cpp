#include "VhodStudent.h"
#include "Lagutin.h"
#include <Windows.h>
const int COUNT = 19;

struct Students {
	string Login;
	string Password;
};

void FunctionVhod(Students *Students) {
	ifstream file("Students.txt");
	if (file) {
		for (int i = 0; i < COUNT; i++) {
			file >> Students[i].Login >> Students[i].Password;
		}
		for (int i = 0; i < COUNT; i++)
			cout << Students[i].Login<< " " << Students[i].Password << endl;
		file.close();
	}
	else {
		cout << "���� �� ��� ������ (���� ���������) " << endl;
		exit(1);
	}
}
void StartVhodStudent(int Count) {
	SetConsoleCP(1251);
	Students* Spisok = new Students[COUNT];
	FunctionVhod(Spisok);
	cout << endl;
	string Login1;
	string Password1;
	int Number = 0;
	bool check = false;
	bool flag = true;
	string Login;
	do {
		cout << "������� �����: "; cin >> Login1;
		cout << "������� ������: "; cin >> Password1;
		cout << "��������� ������: " << Login1 << " " << Password1 << endl;
		for (int i = 0; i < COUNT; i++) {
			if (Login1 == Spisok[i].Login) {
				Number = i;
				Login = Spisok[i].Login;
				check = true;
				break;
			}
		}if (check == true) {
			if (Password1 == Spisok[Number].Password) {
				Menu_Student(Login);
				cout << "\n����������� ������  �������!" << endl << endl;
				flag = false;
			}
			else {
				cout << "�������� ����� ��� ������, ��������� �������" << endl << endl;
			}
		}
		else {
			cout << "�������� �����!" << endl;
		}


	} while (flag == true);
}
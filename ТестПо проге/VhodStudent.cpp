#include "VhodStudent.h"
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
		cout << "Файл не был открыт (База студентов)" << endl;
		exit(1);
	}
}
void StartVhodStudent(int Count) {
	SetConsoleCP(1251);
	Students* Spisok = new Students[COUNT];
	FunctionVhod(Spisok);
	cout << endl;
	cout << Spisok[2].Login << " " << Spisok[2].Password << endl;
	string Login1;
	string Password1;
	int Number = 0;
	bool check = false;
	bool flag = true;
	do {
		cout << "Введите Логин: "; cin >> Login1;
		cout << "Введите Пароль: "; cin >> Password1;
		cout << "Введенные данные: " << Login1 << " " << Password1 << endl;
		for (int i = 0; i < COUNT; i++) {
			if (Login1 == Spisok[i].Login) {
				Number = i;
				check = true;
				break;
			}
		}if (check == true) {
			if (Password1 == Spisok[Number].Password) {
				cout << "Авторизация прошла  успешно!" << endl << endl;
				flag = false;
			}
			else {
				cout << "Неверный логин или пароль, повторите попытку" << endl << endl;
			}
		}
		else {
			cout << "Неверный логин!" << endl;
		}


	} while (flag == true);
}
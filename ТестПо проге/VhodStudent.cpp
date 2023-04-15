#include "VhodStudent.h"
#include "Lagutin.h"
#include "Shifr.h"
struct Students {
	string Login;
	string Password;
};

int FunctionVhod(Students *Students) {
	DeShifr();
	ifstream file("StudentsBAZADeShifr.txt");
	string s;
	string ss;
	int Count;
	file >> Count;
	if (file) {
		for (int i = 0; i < Count; i++) {
			if (getline(file, s)) {
				istringstream ss(s);
				ss>> Students[i].Login >> Students[i].Password;
			}
		}
		for (int i = 0; i < Count; i++)
			cout << Students[i].Login<< " " << Students[i].Password << endl;
		file.close();
	}
	else {
		cout << "Файл не был открыт (База студентов) " << endl;
		exit(1);
	}
	return Count;
}
void StartVhodStudent() {
	//Shifr();
	SetConsoleCP(1251);
	Students* Spisok = new Students[100];
	int COUNT = FunctionVhod(Spisok);
	cout << endl;
	string Login1;
	string Password1;
	int Number = 0;
	bool check = false;
	bool flag = true;
	string Login;
	cout << "Введите 0, чтобы вернуться назад" << endl;
	do {
		cout << "Введите Логин: "; cin >> Login1;
		if (Login1 == "0")
			return;
		cout << "Введите Пароль: "; cin >> Password1;
		if (Password1 == "0")
			return;
		cout << "Введенные данные: " << Login1 << " " << Password1 << endl;
		for (int i = 0; i < COUNT; i++) {
			if (Login1 == Spisok[i].Login) {
				Number = i;
				Login = Spisok[i].Login;
				check = true;
				break;
			}
		}if (check == true) {
			if (Password1 == Spisok[Number].Password) {
				cout << "\nАвторизация прошла  успешно!" << endl << endl;
				delete[] Spisok;
				Menu_Student(Login);
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
#include "VhodPrepod.h"
int COUNT = 3;

struct Prepods {
	string Login;
	string Password;
};

void FunctionVhod1(Prepods*  Prepods){
	ifstream file("login_teach.txt");
	if (file) {
		for (int i = 0; i < COUNT; i++) {
			file >> Prepods[i].Login >> Prepods[i].Password;
		}
	}
	else {
		cout << "Файл не был открыт (База студентов)" << endl;
		exit(1);
	}
}
void InputPassword() {
	Prepods* Spisok = new Prepods[COUNT];
	FunctionVhod1(Spisok);
	string Login1;
	string Password1;
	int Number = 0;
	bool flag = true;
	do {
		cout << "Введите Логин: "; cin >> Login1;
		cout << "Введите Пароль: "; cin >> Password1;
		cout << "Введенные данные: " << Login1 << " " << Password1 << endl;
		for (int i = 0; i < COUNT; i++) {
			if (Login1 == Spisok[i].Login) {
				Number = i;
				break;
			}
		}
		if (Password1 == Spisok[Number].Password) {
			cout << "Авторизация прошла  успешно!" << endl << endl;
			flag = false;
		}
		else {
			cout << "Неверный логин или пароль, повторите попытку" << endl << endl;
		}

	} while (flag == true);

}

//void FunctionVhod(Baza* Baza) {
//	ifstream file("baza.txt");
//	if (file) {
//		for (int i = 0; i < COUNT; i++) {
//			file >> Students[i].Login >> Students[i].Password >> Students[i].Name >> Students[i].SurName >> Students[i].GradeCicles >> Students[i].GradeStroki >> Students[i].GradeRecursia >> Students[i].GradeStruct >> Students[i].GradeFiles >> Students[i].GradeAdresa >> Students[i].GradeDynamic;
//		}
//	}
//	else {
//		cout << "Файл не был открыт (База студентов)" << endl;
//		exit(1);
//	}
//}

 void StartPrepod() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	InputPassword();
}
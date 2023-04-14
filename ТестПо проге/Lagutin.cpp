#include "Lagutin.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <locale>
#include <Windows.h>

using namespace std;

struct Task_answer {
	string answ, gansw;
	int Num;
};
struct Baza {
	string Login;
	string Name;
	string Password;
	string Surname;
	int GradeCicles;
	int GradeArrays;
	int GradeStroki;
	int GradeRecursia;
	int GradeStruct;
	int GradeFiles;
	int GradeAdresa;
	int GradeDynamic;
	int ITOGTEST;
	double Sredn;
};


string LOGIN;
Task_answer Arhiv[100];


void gradeRed(int Grade, int flag) {
	int CountStudent = 0;
	double sum, count_grade = 0;
	Baza* LIST = new Baza[100];
	ifstream infile("StudentsBAZA.txt");
	infile >> CountStudent;
	cout << CountStudent << endl;
	for (int i = 0; i < CountStudent;i++) {
			infile >> LIST[i].Login >> LIST[i].Password >> LIST[i].Name >> LIST[i].Surname >> LIST[i].GradeCicles
				>> LIST[i].GradeArrays >> LIST[i].GradeStroki >> LIST[i].GradeRecursia
				>> LIST[i].GradeStruct >> LIST[i].GradeFiles >> LIST[i].GradeAdresa >> LIST[i].GradeDynamic
				>> LIST[i].ITOGTEST >> LIST[i].Sredn;
		
	}
	cout << LIST[1].Name << endl;
	infile.close();
	ofstream file("StudentsBAZA.txt");
	file << CountStudent << endl;
	cout << CountStudent << endl;
	for (int i = 0; i < CountStudent; i++) {
		if (LIST[i].Login == LOGIN) {
			switch (flag)
			{
			case 1:LIST[i].GradeCicles = Grade; break;
			case 2:LIST[i].GradeArrays = Grade; break;
			case 3:LIST[i].GradeStroki = Grade; break;
			case 4:LIST[i].GradeRecursia = Grade; break;
			case 5:LIST[i].GradeStruct = Grade; break;
			case 6:LIST[i].GradeFiles = Grade; break;
			case 7:LIST[i].GradeAdresa = Grade; break;
			case 8:LIST[i].GradeDynamic = Grade; break;
			case 0:LIST[i].ITOGTEST = Grade; break;
			}
			if (LIST[i].GradeCicles != 0) { count_grade += 1; }
			if (LIST[i].GradeArrays != 0) { count_grade += 1; }
			if (LIST[i].GradeStroki != 0) { count_grade += 1; }
			if (LIST[i].GradeRecursia != 0) { count_grade += 1; }
			if (LIST[i].GradeStruct != 0) { count_grade += 1; }
			if (LIST[i].GradeFiles != 0) { count_grade += 1; }
			if (LIST[i].GradeAdresa != 0) { count_grade += 1; }
			if (LIST[i].GradeDynamic != 0) { count_grade += 1; }
			if (LIST[i].ITOGTEST != 0) { count_grade += 1; }
			sum = LIST[i].GradeCicles + LIST[i].GradeArrays + LIST[i].GradeStroki + LIST[i].GradeRecursia + LIST[i].GradeStruct + LIST[i].GradeFiles + LIST[i].GradeAdresa + LIST[i].GradeDynamic + LIST[i].ITOGTEST;
			LIST[i].Sredn = sum / count_grade;

			file << LIST[i].Login << " " << LIST[i].Password << " " << LIST[i].Name << " " << LIST[i].Surname << " " << Grade
				<< " " << LIST[i].GradeArrays << " " << LIST[i].GradeStroki << " " << LIST[i].GradeRecursia
				<< " " << LIST[i].GradeStruct << " " << LIST[i].GradeFiles << " " << LIST[i].GradeAdresa << " " << LIST[i].GradeDynamic
				<< " " << LIST[i].ITOGTEST << " " << LIST[i].Sredn << endl;
		}
		else {
			file << LIST[i].Login << " " << LIST[i].Password << " " << LIST[i].Name << " " << LIST[i].Surname << " " << LIST[i].GradeCicles
				<< " " << LIST[i].GradeArrays << " " << LIST[i].GradeStroki << " " << LIST[i].GradeRecursia
				<< " " << LIST[i].GradeStruct << " " << LIST[i].GradeFiles << " " << LIST[i].GradeAdresa << " " << LIST[i].GradeDynamic
				<< " " << LIST[i].ITOGTEST << " " << LIST[i].Sredn << endl;
		}
	}
	file.close();
	delete[]LIST;

}


//Главное меню студенческой части
void Menu_Student(string Login) {

	LOGIN = Login;

	gradeRed(5, 1);
	srand(time(NULL));
	SetConsoleCP(1251);
	int Number;
	do {
		cout << "Выберите модуль:" << endl;
		cout << "\t1)Тренинг;" << endl << "\t2)Тестирование;" << endl << "\t3)Итоговый тест;" << endl << "Введите '0' для повторного входа." << endl;
		cout << ">"; cin >> Number;
		switch (Number)
		{
		case 1:Trening(); break;
		case 2:Testirovanie(); break;
		case 3:Itog_test(); break;

		case 0: cout << "Выход в главное меню"; break;
		default: cout << "Введено неверное значение! Попробуйте снова." << endl; break;
		}
	} while (Number != 0);
}

//Меню тренинг
void Trening() {
	int Number;
	do {
		cout << "Выберите тему:" << endl;
		cout << "\t1)Циклы;" << endl << "\t2)Массивы;" << endl << "\t3)Строки;" << endl << "\t4)Рекурсия;"
			<< endl << "\t5)Структуры;" << endl << "\t6)Файлы;" << endl << "\t7)Адреса и указатели;" << endl << "\t8)Динамическая память;" << endl << "Введите '0' для выхода в главное меню." << endl;
		do {
			cout << ">"; cin >> Number;
			if (Number < 0 || Number>8) cout << "Введено неверное значение! Попробуйте снова." << endl;
		} while (Number != 0 && (Number < 0 || Number>8));
		if (Number != 0) Tren_logic(Number);
		if (Number < 0 || Number>8) cout << "Введено неверное значение! Попробуйте снова." << endl;
	} while (Number != 0);
}

//Меню тестирование
void Testirovanie() {
	int Number;
	do {
		cout << "Выберите тему:" << endl;
		cout << "\t1)Циклы;" << endl << "\t2)Массивы;" << endl << "\t3)Строки;" << endl << "\t4)Рекурсия;"
			<< endl << "\t5)Структуры;" << endl << "\t6)Файлы;" << endl << "\t7)Адреса и указатели;" << endl << "\t8)Динамическая память;" << endl << "Введите '0' для выхода в главное меню." << endl;
		do {
			cout << ">"; cin >> Number;
			if (Number < 0 || Number>8) cout << "Введено неверное значение! Попробуйте снова." << endl;
		} while (Number != 0 && (Number < 0 || Number>8));
		if (Number != 0) Test_logic(Number);
		if (Number < 0 || Number>8) cout << "Введено неверное значение! Попробуйте снова." << endl;
	} while (Number != 0);
}

//Тестирование по теме
void Test_logic(int flag) {
	int count = 0, grade, flag1 = 0, flag2 = 0, random, err = 0, povtor[100], c = 0, numbr = 0;
	string Ques, Answ_task, Answ_user, Task;
	ifstream file, answ;
	switch (flag)
	{
	case 1:file.open("Vopros\\Cikle_task.txt"); answ.open("Vopros\\Cikle_answ.txt"); break;
	case 2:file.open("Vopros\\Mas_task.txt"); answ.open("Vopros\\Mas_answ.txt"); break;
	case 3:file.open("Vopros\\Stroki_task.txt"); answ.open("Vopros\\Stroki_answ.txt"); break;
	case 4:file.open("Vopros\\Rec_task.txt"); answ.open("Vopros\\Rec_answ.txt"); break;
	case 5:file.open("Vopros\\Struct_task.txt"); answ.open("Vopros\\Struct_answ.txt"); break;
	case 6:file.open("Vopros\\File_task.txt"); answ.open("Vopros\\File_answ.txt"); break;
	case 7:file.open("Vopros\\Adress_task.txt"); answ.open("Vopros\\Adress_answ.txt"); break;
	case 8:file.open("Vopros\\Dynamic_task.txt"); answ.open("Vopros\\Dynamic_answ.txt"); break;
	}

	do {
		do {
			flag2 = 0;
			random = rand() % 30 + 1;
			if (random % 2 != 0) {
				for (int i = 0; i < c; i++) {
					if (povtor[i] == random) {
						flag2 = 1;
						break;
					}
				}
				if (flag2 == 0) { povtor[c] = random; c += 1; }
			}
		} while (random % 2 == 0 || flag2 == 1);
		numbr = 0;
		do {
			numbr += 1;
			getline(file, Task);
			getline(file, Ques);
		} while (numbr != random);

		for (int i = 0; i < random; i++) {
			getline(answ, Answ_task);
		}
		file.clear();
		file.seekg(0);
		answ.clear();
		answ.seekg(0);

		cout << endl << "Задание " << count + 1 << ": " << Task << endl << "Варианты ответа:" << endl << Ques << endl;

		do {
			flag1 = 0;
			Answ_user.clear();
			cout << "Ответ:"; cin >> Answ_user;
			if (Answ_user.size() > 1)cout << "Ответ не должен содержать пробелов и других символов!" << endl;
			else { if (Answ_user != "a" && Answ_user != "b" && Answ_user != "c" && Answ_user != "d") { cout << "Такого варианта ответа нет!" << endl; flag1 = 1; } }
		} while (Answ_user.size() > 1 || flag1 == 1);

		if (Answ_task != Answ_user) {
			Arhiv[err].Num = count + 1;
			Arhiv[err].answ = Answ_user;
			Arhiv[err].gansw = Answ_task;
			err += 1;
		}
		count += 1;
	} while (count < 10);
	cout << endl << "Ошибки:" << endl;
	if (err == 0) { cout << "Ошибок нет." << endl; }
	else {
		cout << " ___________________________________________________ \n";
		cout << "|Номера заданий |Правильные ответы|Введенные ответы |\n";
		for (int i = 0; i < err; i++) {
			cout << "|\t" << Arhiv[i].Num << "\t|        " << Arhiv[i].gansw << "        |        " << Arhiv[i].answ << "        |\n";
		}
		cout << " --------------------------------------------------- \n";
	}
	if (err <= 1)grade = 5;
	else {
		if (err <= 3)grade = 4;
		else {
			if (err <= 5)grade = 3;
			else {
				grade = 2;
			}

		}

	}
	gradeRed(grade, flag);
	cout << endl << "Результат:" << endl << "Количество правильных ответов:" << 10 - err << "\tОценка:" << grade << endl;
	file.close();
	answ.close();
}

//Тренинг по теме
void Tren_logic(int flag) {
	int count = 0, flag1 = 0, flag2 = 0, random, povtor[100], c = 0, numbr = 0, flag3 = 0;
	string Ques, Answ_task, Answ_user, Task;
	ifstream file, answ;
	switch (flag)
	{
	case 1:file.open("Vopros\\Cikle_task.txt"); answ.open("Vopros\\Cikle_answ.txt"); break;
	case 2:file.open("Vopros\\Mas_task.txt"); answ.open("Vopros\\Mas_answ.txt"); break;
	case 3:file.open("Vopros\\Stroki_task.txt"); answ.open("Vopros\\Stroki_answ.txt"); break;
	case 4:file.open("Vopros\\Rec_task.txt"); answ.open("Vopros\\Rec_answ.txt"); break;
	case 5:file.open("Vopros\\Struct_task.txt"); answ.open("Vopros\\Struct_answ.txt"); break;
	case 6:file.open("Vopros\\File_task.txt"); answ.open("Vopros\\File_answ.txt"); break;
	case 7:file.open("Vopros\\Adress_task.txt"); answ.open("Vopros\\Adress_answ.txt"); break;
	case 8:file.open("Vopros\\Dynamic_task.txt"); answ.open("Vopros\\Dynamic_answ.txt"); break;
	}

	do {
		do {
			flag2 = 0;
			random = rand() % 30 + 1;
			if (random % 2 != 0) {
				for (int i = 0; i < c; i++) {
					if (povtor[i] == random) {
						flag2 = 1;
						break;
					}
				}
				if (flag2 == 0) { povtor[c] = random; c += 1; }
			}
		} while (random % 2 == 0 || flag2 == 1);
		numbr = 0;
		do {
			numbr += 1;
			getline(file, Task);
			getline(file, Ques);
		} while (numbr != random);

		for (int i = 0; i < random; i++) {
			getline(answ, Answ_task);
		}
		file.clear();
		file.seekg(0);
		answ.clear();
		answ.seekg(0);

		cout << endl << "Задание " << count + 1 << ": " << Task << endl << "Варианты ответа:" << endl << Ques << endl;

		do {
			flag1 = 0;
			flag3 = 0;
			Answ_user.clear();
			cout << "Введите '0' чтобы выйти в меню." << endl;
			cout << "Ответ:"; cin >> Answ_user;
			if (Answ_user.size() > 1)cout << "Ответ не должен содержать пробелов и других символов!" << endl;
			else {
				if (Answ_user == "0")break;
				if (Answ_user != "a" && Answ_user != "b" && Answ_user != "c" && Answ_user != "d") { cout << "Такого варианта ответа нет!" << endl; flag1 = 1; }
				else {
					if (Answ_task != Answ_user) { cout << "Ответ неверный." << endl; flag3 = 1; }
				}
			}

		} while (Answ_user.size() > 1 || flag1 == 1 || flag3 == 1 || Answ_user != Answ_task);
		count += 1;
		if (Answ_user == "0") { break; }
	} while (count < 10);

	file.close();
	answ.close();
}

//Итоговый тест
void Itog_test() {
	int count = 0, grade, flag1 = 0, flag2 = 0, random, err = 0, povtor[8][5], c = 0, numbr = 0, i = 1;
	string Ques, Answ_task, Answ_user, Task;
	ifstream file, answ;
	do {
		switch (i)
		{
		case 1:file.open("Vopros\\Cikle_task.txt"); answ.open("Vopros\\Cikle_answ.txt"); break;
		case 2:file.open("Vopros\\Mas_task.txt"); answ.open("Vopros\\Mas_answ.txt"); break;
		case 3:file.open("Vopros\\Stroki_task.txt"); answ.open("Vopros\\Stroki_answ.txt"); break;
		case 4:file.open("Vopros\\Rec_task.txt"); answ.open("Vopros\\Rec_answ.txt"); break;
		case 5:file.open("Vopros\\Struct_task.txt"); answ.open("Vopros\\Struct_answ.txt"); break;
		case 6:file.open("Vopros\\File_task.txt"); answ.open("Vopros\\File_answ.txt"); break;
		case 7:file.open("Vopros\\Adress_task.txt"); answ.open("Vopros\\Adress_answ.txt"); break;
		case 8:file.open("Vopros\\Dynamic_task.txt"); answ.open("Vopros\\Dynamic_answ.txt"); break;
		}

		do {
			flag2 = 0;
			random = rand() % 30 + 1;
			if (random % 2 != 0) {
				for (int j = 0; j < c; j++) {
					if (povtor[i - 1][j] == random) {
						flag2 = 1;
						break;
					}
				}
				if (flag2 == 0) { povtor[i - 1][c] = random; }
			}
		} while (random % 2 == 0 || flag2 == 1);
		numbr = 0;
		do {
			numbr += 1;
			getline(file, Task);
			getline(file, Ques);
		} while (numbr != random);

		for (int i = 0; i < random; i++) {
			getline(answ, Answ_task);
		}
		file.clear();
		file.seekg(0);
		answ.clear();
		answ.seekg(0);

		cout << endl << "Задание " << count + 1 << ": " << Task << endl << "Варианты ответа:" << endl << Ques << endl;

		do {
			flag1 = 0;
			Answ_user.clear();
			cout << "Ответ:"; cin >> Answ_user;
			if (Answ_user.size() > 1)cout << "Ответ не должен содержать пробелов и других символов!" << endl;
			else { if (Answ_user != "a" && Answ_user != "b" && Answ_user != "c" && Answ_user != "d") { cout << "Такого варианта ответа нет!" << endl; flag1 = 1; } }
		} while (Answ_user.size() > 1 || flag1 == 1);

		if (Answ_task != Answ_user) {
			Arhiv[err].Num = count + 1;
			Arhiv[err].answ = Answ_user;
			Arhiv[err].gansw = Answ_task;
			err += 1;
		}
		count += 1;
		i += 1;
		if (i == 9) { i = 1; c += 1; }
		file.close();
		answ.close();
	} while (count < 40);
	cout << endl << "Ошибки:" << endl;
	if (err == 0) { cout << "Ошибок нет." << endl; }
	else {
		cout << " ___________________________________________________ \n";
		cout << "|Номера заданий |Правильные ответы|Введенные ответы |\n";
		for (int i = 0; i < err; i++) {
			cout << "|\t" << Arhiv[i].Num << "\t|        " << Arhiv[i].gansw << "        |        " << Arhiv[i].answ << "        |\n";
		}
		cout << " --------------------------------------------------- \n";
	}
	if (err <= 4)grade = 5;
	else {
		if (err <= 10)grade = 4;
		else {
			if (err <= 20)grade = 3;
			else {
				grade = 2;
			}
		}
	}
	gradeRed(grade, 0);
	cout << endl << "Результат:" << endl << "Количество правильных ответов:" << 40 - err << "\tОценка:" << grade << endl;
}
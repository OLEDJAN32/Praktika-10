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

Task_answer Arhiv[100];
void gradeRed() {
	int CountStudent = 19;
	Baza* LIST = new Baza[CountStudent];
	ifstream infile("StudentsBAZA.txt");
	for (int i = 0; i < CountStudent+1;i++) {
		if (i == 0) {
			infile >> CountStudent;
			cout << CountStudent << endl;
		}
		else {
			infile >> LIST[i-1].Login >> LIST[i-1].Password >> LIST[i-1].Name >> LIST[i-1].Surname >> LIST[i-1].GradeCicles
				>> LIST[i-1].GradeArrays >> LIST[i-1].GradeStroki >> LIST[i-1].GradeRecursia
				>> LIST[i-1].GradeStruct >> LIST[i-1].GradeFiles >> LIST[i-1].GradeAdresa >> LIST[i-1].GradeDynamic
				>> LIST[i-1].ITOGTEST >> LIST[i-1].Sredn;
		}

		}
	for (int i = 0; i < CountStudent;i++) {
		cout << LIST[i].Login <<" "<< LIST[i].Password <<" "<< LIST[i].Name <<" "<< LIST[i].Surname << " " << LIST[i].GradeCicles
			<<" "<<  LIST[i].GradeArrays <<" "<< LIST[i].GradeStroki <<" "<< LIST[i].GradeRecursia
			<<" "<< LIST[i].GradeStruct <<" "<< LIST[i].GradeFiles <<" "<< LIST[i].GradeAdresa <<" "<< LIST[i].GradeDynamic
			<<" "<< LIST[i].ITOGTEST <<" "<< LIST[i].Sredn << endl;

	}
}
//������� ���� ������������ �����
void Menu_Student(int CountStudent,string Login) {
	cout << CountStudent << endl;
	cout << Login << endl;
	gradeRed();
	srand(time(NULL));
	SetConsoleCP(1251);
	int Number;
	do {
		cout << "�������� ������:" << endl;
		cout << "\t1)�������;" << endl << "\t2)������������;" << endl << "\t3)�������� ����;"  << endl << "������� '0' ��� ���������� �����." << endl;
		cout << ">"; cin >> Number;
		switch (Number)
		{
		case 1:Trening(); break;
		case 2:Testirovanie(); break;
		case 3:Itog_test(); break;
		
		case 0: cout << "����� � ������� ����"; break;
		default: cout << "������� �������� ��������! ���������� �����." << endl; break;
		}
	} while (Number != 0);
}

//������ ������
void Grades(int grade, int flag) {
	ofstream file;
	
}

//���� �������
void Trening() {
	int Number;
	do {
		cout << "�������� ����:" << endl;
		cout << "\t1)�����;" << endl << "\t2)�������;" << endl << "\t3)������;" << endl << "\t4)��������;" 
			<< endl << "\t5)���������;" << endl << "\t6)�����;" << endl << "\t7)������ � ���������;" << endl << "\t8)������������ ������;" << endl << "������� '0' ��� ������ � ������� ����." << endl;
		do {
			cout << ">"; cin >> Number;
			if (Number < 0 || Number>8) cout << "������� �������� ��������! ���������� �����." << endl;
		} while (Number != 0 && (Number < 0 || Number>8));
		if (Number != 0) Tren_logic(Number);
		if (Number < 0 || Number>8) cout << "������� �������� ��������! ���������� �����." << endl;
	} while (Number != 0);
}

//���� ������������
void Testirovanie() {
	int Number;
	do {
		cout << "�������� ����:" << endl;
		cout << "\t1)�����;" << endl << "\t2)�������;" << endl << "\t3)������;" << endl << "\t4)��������;"
			<< endl << "\t5)���������;" << endl << "\t6)�����;" << endl << "\t7)������ � ���������;" << endl << "\t8)������������ ������;" << endl << "������� '0' ��� ������ � ������� ����." << endl;
		do {
			cout << ">"; cin >> Number;
			if (Number < 0 || Number>8) cout << "������� �������� ��������! ���������� �����." << endl;
		} while (Number != 0 && (Number < 0 || Number>8));
		if(Number!=0) Test_logic(Number);
		if (Number < 0 || Number>8) cout << "������� �������� ��������! ���������� �����." << endl;
	} while (Number != 0);
}

//������������ �� ����
void Test_logic(int flag) {
	int count=0, grade, flag1=0,flag2=0, random, err=0, povtor[100], c=0, numbr=0;
	string Ques, Answ_task, Answ_user, Task;
	ifstream file, answ;
	switch (flag)
	{
	case 1:file.open("Cikle_task.txt"); answ.open("Cikle_answ.txt"); break;
	case 2:file.open("Mas_task.txt"); answ.open("Mas_answ.txt"); break;
	case 3:file.open("Stroki_task.txt"); answ.open("Stroki_answ.txt"); break;
	case 4:file.open("Rec_task.txt"); answ.open("Rec_answ.txt"); break;
	case 5:file.open("Struct_task.txt"); answ.open("Struct_answ.txt"); break;
	case 6:file.open("File_task.txt"); answ.open("File_answ.txt"); break;
	case 7:file.open("Adress_task.txt"); answ.open("Adress_answ.txt"); break;
	case 8:file.open("Dynamic_task.txt"); answ.open("Dynamic_answ.txt"); break;
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
		} while (random % 2 == 0 || flag2==1);
		numbr = 0;
		do{
			numbr += 1;
			getline(file, Task);
			getline(file, Ques);
		} while (numbr != random);
		
		for (int i = 0; i < random ; i++) {
			getline(answ, Answ_task);
		}
		file.clear();
		file.seekg(0);
		answ.clear();
		answ.seekg(0);

		cout << endl<<"������� " << count + 1 << ": " << Task << endl<<"�������� ������:"<<endl<< Ques << endl;

		do {
			flag1 = 0;
			Answ_user.clear();
			cout << "�����:"; cin >> Answ_user;
			if (Answ_user.size() > 1)cout << "����� �� ������ ��������� �������� � ������ ��������!" << endl;
			else { if (Answ_user != "a" && Answ_user != "b" && Answ_user != "c" && Answ_user != "d") { cout << "������ �������� ������ ���!" << endl; flag1 = 1; } }
		} while (Answ_user.size() > 1 || flag1==1);

		if (Answ_task != Answ_user) {
			Arhiv[err].Num = count + 1;
			Arhiv[err].answ = Answ_user;
			Arhiv[err].gansw = Answ_task;
			err += 1;
		}
		count += 1;
	} while (count < 10);
	cout <<endl<< "������:"<<endl;
	if (err == 0) { cout << "������ ���." << endl; }
	else {
		cout << " ___________________________________________________ \n";
		cout << "|������ ������� |���������� ������|��������� ������ |\n";
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
	cout <<endl<< "���������:"<<endl << "���������� ���������� �������:" << 10 - err << "\t������:" << grade << endl;
	file.close();
	answ.close();
}

//������� �� ����
void Tren_logic(int flag) {
	int count = 0, flag1 = 0, flag2 = 0, random, povtor[100], c = 0, numbr = 0, flag3=0;
	string Ques, Answ_task, Answ_user, Task;
	ifstream file, answ;
	switch (flag)
	{
	case 1:file.open("Cikle_task.txt"); answ.open("Cikle_answ.txt"); break;
	case 2:file.open("Mas_task.txt"); answ.open("Mas_answ.txt"); break;
	case 3:file.open("Stroki_task.txt"); answ.open("Stroki_answ.txt"); break;
	case 4:file.open("Rec_task.txt"); answ.open("Rec_answ.txt"); break;
	case 5:file.open("Struct_task.txt"); answ.open("Struct_answ.txt"); break;
	case 6:file.open("File_task.txt"); answ.open("File_answ.txt"); break;
	case 7:file.open("Adress_task.txt"); answ.open("Adress_answ.txt"); break;
	case 8:file.open("Dynamic_task.txt"); answ.open("Dynamic_answ.txt"); break;
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

		cout << endl << "������� " << count + 1 << ": " << Task << endl << "�������� ������:" << endl << Ques << endl;

		do {
			flag1 = 0;
			flag3 = 0;
			Answ_user.clear();
			cout << "������� '0' ����� ����� � ����." << endl;
			cout << "�����:"; cin >> Answ_user;
			if (Answ_user.size() > 1)cout << "����� �� ������ ��������� �������� � ������ ��������!" << endl;
			else { 
				if (Answ_user == "0")break;
				if (Answ_user != "a" && Answ_user != "b" && Answ_user != "c" && Answ_user != "d") { cout << "������ �������� ������ ���!" << endl; flag1 = 1; }
				else {
					if (Answ_task != Answ_user) { cout << "����� ��������." << endl; flag3 = 1; }
				}
			}

		} while (Answ_user.size() > 1 || flag1 == 1 || flag3==1 || Answ_user!=Answ_task);
		count += 1;
		if (Answ_user == "0") { break; }
	} while (count < 10);
	
	file.close();
	answ.close();
}

//�������� ����
void Itog_test() {
	int count = 0, grade, flag1 = 0, flag2 = 0, random, err = 0, povtor[8][5], c = 0, numbr = 0, i = 1;
	string Ques, Answ_task, Answ_user, Task;
	ifstream file, answ;
	do{
		switch (i)
		{
		case 1:file.open("Cikle_task.txt"); answ.open("Cikle_answ.txt"); break;
		case 2:file.open("Mas_task.txt"); answ.open("Mas_answ.txt"); break;
		case 3:file.open("Stroki_task.txt"); answ.open("Stroki_answ.txt"); break;
		case 4:file.open("Rec_task.txt"); answ.open("Rec_answ.txt"); break;
		case 5:file.open("Struct_task.txt"); answ.open("Struct_answ.txt"); break;
		case 6:file.open("File_task.txt"); answ.open("File_answ.txt"); break;
		case 7:file.open("Adress_task.txt"); answ.open("Adress_answ.txt"); break;
		case 8:file.open("Dynamic_task.txt"); answ.open("Dynamic_answ.txt"); break;
		}

		do {
			flag2 = 0;
			random = rand() % 30 + 1;
			if (random % 2 != 0) {
				for (int j = 0; j < c; j++) {
					if (povtor[i-1][j] == random) {
						flag2 = 1;
						break;
					}
				}
				if (flag2 == 0) { povtor[i-1][c] = random; }
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

		cout << endl << "������� " << count + 1 << ": " << Task << endl << "�������� ������:" << endl << Ques << endl;

		do {
			flag1 = 0;
			Answ_user.clear();
			cout << "�����:"; cin >> Answ_user;
			if (Answ_user.size() > 1)cout << "����� �� ������ ��������� �������� � ������ ��������!" << endl;
			else { if (Answ_user != "a" && Answ_user != "b" && Answ_user != "c" && Answ_user != "d") { cout << "������ �������� ������ ���!" << endl; flag1 = 1; } }
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
	cout << endl << "������:" << endl;
	if (err == 0) { cout << "������ ���." << endl; }
	else {
		cout << " ___________________________________________________ \n";
		cout << "|������ ������� |���������� ������|��������� ������ |\n";
		for (int i = 0; i < err; i++) {
			cout << "|\t" << Arhiv[i].Num << "\t|        " << Arhiv[i].gansw << "        |        " << Arhiv[i].answ << "        |\n";
		}
		cout << " --------------------------------------------------- \n";
	}
	if (err <= 4)grade = 5;
	else {
		if (err <=10 )grade = 4;
		else {
			if (err <= 20)grade = 3;
			else {
				grade = 2;
			}
		}
	}
	cout << endl << "���������:" << endl << "���������� ���������� �������:" << 40 - err << "\t������:" << grade << endl;
}
#include "Teacher.h"

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
struct BazaSorted {
	string Name;
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



void DeletLineFile(string name, int number_line) {
	ifstream file;
	file.open(name);
	int i = 0;
	string line;
	string new_file;
	while (getline(file, line)) {
		i++;
		if (!(i == number_line)) {
			new_file.insert(new_file.size(), line);
			new_file.insert(new_file.size(), "\r\n");
		}
	}
	file.close();
	ofstream file_out;
	file_out.open(name, std::ios::trunc | std::ios::binary);
	file_out.write(new_file.c_str(), new_file.size());
	file_out.clear();
}

void �hangeLineFile(string line_add, string name, int number_line) {
	ifstream file;
	file.open(name);
	int i = 0;
	string line;
	string new_file;
	while (getline(file, line)) {
		i++;
		if (!(i == number_line)) {
			new_file.insert(new_file.size(), line);
			new_file.insert(new_file.size(), "\r\n");
		}
		else {
			new_file.insert(new_file.size(), line_add);
			new_file.insert(new_file.size(), "\r\n");
		}
	}
	file.close();
	ofstream file_out;
	file_out.open(name, std::ios::trunc | std::ios::binary);
	file_out.write(new_file.c_str(), new_file.size());
	file_out.clear();
}

void AddLineFile(string line_add1, string name) {
	ofstream file;
	file.open(name, ios::app);
	file << line_add1 << "\n";
	file.clear();
}

void ChooseSubject(string& name1, string& name2) {
	int subject;
	while (1) {
		cout << "�������� ����:" << endl;
		cout << "1) �����." << endl;
		cout << "2) �������." << endl;
		cout << "3) ��������." << endl;
		cout << "4) ���������." << endl;
		cout << "5) �����." << endl;
		cout << "6) ������ � ���������." << endl;
		cout << "7) ������������ ������." << endl;
		cout << "8) ������." << endl;
		cin >> subject;
		switch (subject) {
		case 1:
			name1 = "Vopros\\Cikle_task.txt";
			name2 = "Vopros\\Cikle_answ.txt";
			return;
		case 2:
			name1 = "Vopros\\Mas_task.txt";
			name2 = "Vopros\\Mas_answ.txt";
			return;
		case 3:
			name1 = "Vopros\\Rec_task.txt";
			name2 = "Vopros\\Rec_answ.txt";
			return;
		case 4:
			name1 = "Vopros\\Struct_task.txt";
			name2 = "Vopros\\Struct_answ.txt";
			return;
		case 5:
			name1 = "Vopros\\File_task.txt";
			name2 = "Vopros\\File_answ.txt";
			return;
		case 6:
			name1 = "Vopros\\Adress_task.txt";
			name2 = "Vopros\\Adress_answ.txt";
			return;
		case 7:
			name1 = "Vopros\\Dynamic_task.txt";
			name2 = "Vopros\\Dynamic_answ.txt";
			return;
		case 8:
			name1 = "Vopros\\Stroki_task.txt";
			name2 = "Vopros\\Stroki_answ.txt";
			return;
		default: cout << "����� ���� �� ����������."; break;
		}
	}
}

void gradeRed(Baza* LIST, int& CountStudent) {
	ifstream infile("StudentsBAZA.txt");
	infile >> CountStudent;
	for (int i = 0; i < CountStudent; i++) {
		infile >> LIST[i].Login >> LIST[i].Password >> LIST[i].Name >> LIST[i].Surname >> LIST[i].GradeCicles
			>> LIST[i].GradeArrays >> LIST[i].GradeStroki >> LIST[i].GradeRecursia
			>> LIST[i].GradeStruct >> LIST[i].GradeFiles >> LIST[i].GradeAdresa >> LIST[i].GradeDynamic
			>> LIST[i].ITOGTEST >> LIST[i].Sredn;
	}
	infile.close();
}

void EditQuest() {
	string name1, name2, task_name, ans_name, ans;
	int func, number_line;
	cout << "�������� �������:" << endl;
	cout << "1) �������� ��������." << endl;
	cout << "2) ���������� ��������." << endl;
	cout << "3) ��������� ��������." << endl;
	cin >> func;
	ChooseSubject(name1, name2);
	switch (func) {
	case 1:
		cout << "�������� ����� �������: ";
		cin >> number_line;
		DeletLineFile(name1, number_line * 2 - 1);
		DeletLineFile(name1, number_line * 2 - 1);
		DeletLineFile(name2, number_line);
		break;
	case 2:
		cout << "�������� ������: ";
		cin.ignore();
		getline(cin, task_name);
		cout << "�������� �������� �������: ";
		getline(cin, ans_name);
		cout << "�������� �����: ";
		getline(cin, ans);
		AddLineFile(task_name, name1);
		AddLineFile(ans_name, name1);
		AddLineFile(ans, name2);
		break;
	case 3:
		cout << "�������� ����� �������: ";
		cin >> number_line;
		cin.ignore();
		cout << "�������� ������: ";
		getline(cin, task_name);
		cout << "�������� �������� �������: ";
		getline(cin, ans_name);
		cout << "�������� �����: ";
		getline(cin, ans);
		�hangeLineFile(task_name, name1, number_line * 2 - 1);
		�hangeLineFile(ans_name, name1, number_line * 2);
		�hangeLineFile(ans, name2, number_line);
		break;
	default: cout << "����� ������� �� ����������."; break;
	}
}

void OutputStudentStruct(Baza* Student, int& CountStudent) {
	for (int i = 0; i < CountStudent; i++) {
		cout << Student[i].Login << " " << Student[i].Password << " " << Student[i].Name << " " << Student[i].Surname << " " << Student[i].GradeCicles
			<< " " << Student[i].GradeArrays << " " << Student[i].GradeStroki << " " << Student[i].GradeRecursia
			<< " " << Student[i].GradeStruct << " " << Student[i].GradeFiles << " " << Student[i].GradeAdresa << " " << Student[i].GradeDynamic
			<< " " << Student[i].ITOGTEST << " " << Student[i].Sredn << endl;
	}
}


void EditStudent(Baza* Student, int& CountStudent) {
	int func;
	string name, surname, login, password, string_student;
	OutputStudentStruct(Student, CountStudent);
	cout << "�������� �������:" << endl;
	cout << "1) �������� ��������." << endl;
	cout << "2) ����������� ��������." << endl;
	cin >> func;
	switch (func) {
	case 1:
		while (1) {
			cout << "������� ���: ";
			cin >> name;
			cout << "������� �������: ";
			cin >> surname;
			for (int i = 0; i < CountStudent; i++) if ((surname == Student[i].Name) && (name == Student[i].Surname)) {
				CountStudent--;
				�hangeLineFile(to_string(CountStudent), "StudentsBAZA.txt", 1);
				DeletLineFile("StudentsBAZA.txt", i + 2);
				gradeRed(Student, CountStudent);
				return;
			}
			cout << "������ �������� �� ����������. ������� ��� ���." << endl;
		}
		break;
	case 2:
		cout << "������� �����: ";
		cin >> login;
		cout << "������� ������: ";
		cin >> password;
		cout << "������� ���: ";
		cin >> name;
		cout << "������� �������: ";
		cin >> surname;
		string_student = login + " " + password + " " + surname + " " + name + " 0 0 0 0 0 0 0 0 0 0";
		AddLineFile(string_student, "StudentsBAZA.txt");
		CountStudent++;
		�hangeLineFile(to_string(CountStudent), "StudentsBAZA.txt", 1);
		break;
	default: cout << "����� ������� �� ����������." << endl; return;
	}
}

void EditGradeStudent(Baza* Student, int& CountStudent) {
	while (1) {
		string name, surname, string_student;
		cout << "������� ���: ";
		cin >> name;
		cout << "������� �������: ";
		cin >> surname;
		int subject, grade;

		for (int i = 0; i < CountStudent; i++) if ((surname == Student[i].Name) && (name == Student[i].Surname)) {
			cout << "�������� ����:" << endl;
			cout << "1) �����." << endl;
			cout << "2) ������ � ���������." << endl;
			cout << "3) �������." << endl;
			cout << "4) ������������ ������ " << endl;
			cout << "5) �����." << endl;
			cout << "6) ��������." << endl;
			cout << "7) ������." << endl;
			cout << "8) ���������." << endl;
			cout << "9) �������� ����." << endl;
			cout << "10) ������� ����." << endl;
			cin >> subject;
			cout << "������� ������: ";
			cin >> grade;
			switch (subject) {
			case 1:
				Student[i].GradeCicles = grade; break;
			case 2:
				Student[i].GradeAdresa = grade; break;
			case 3:
				Student[i].GradeArrays = grade; break;
			case 4:
				Student[i].GradeDynamic = grade; break;
			case 5:
				Student[i].GradeFiles = grade; break;
			case 6:
				Student[i].GradeRecursia = grade; break;
			case 7:
				Student[i].GradeStroki = grade; break;
			case 8:
				Student[i].GradeStruct = grade; break;
			case 9:
				Student[i].ITOGTEST = grade; break;
			case 10:
				Student[i].Sredn = grade; break;
			default: cout << "����� ���� �� ����������. ������� ��� ���." << endl;
				break;
			}
			string_student = Student[i].Login + " " + Student[i].Password + " " + Student[i].Name + " " + Student[i].Surname + " " + to_string(Student[i].GradeCicles)
				+ " " + to_string(Student[i].GradeArrays) + " " + to_string(Student[i].GradeStroki) + " " + to_string(Student[i].GradeRecursia)
				+ " " + to_string(Student[i].GradeStruct) + " " + to_string(Student[i].GradeFiles) + " " + to_string(Student[i].GradeAdresa) + " " + to_string(Student[i].GradeDynamic)
				+ " " + to_string(Student[i].ITOGTEST) + " " + to_string(Student[i].Sredn);
			�hangeLineFile(string_student, "StudentsBAZA.txt", i + 2);
			gradeRed(Student, CountStudent);
			return;
		}
		cout << "������ �������� �� ����������. ������� ��� ���." << endl;
	}
}


void SortedGrade(int Point, Baza* LIST, int Count) {
	BazaSorted* NewList = new BazaSorted[Count];
	for (int i = 0; i < Count;i++) {
		NewList[i].Name = LIST[i].Name;
		NewList[i].Surname = LIST[i].Surname;
		NewList[i].GradeCicles = LIST[i].GradeCicles;
		NewList[i].GradeAdresa = LIST[i].GradeAdresa;
		NewList[i].GradeArrays = LIST[i].GradeArrays;
		NewList[i].GradeDynamic = LIST[i].GradeDynamic;
		NewList[i].GradeFiles = LIST[i].GradeFiles;
		NewList[i].GradeRecursia = LIST[i].GradeRecursia;
		NewList[i].GradeStroki = LIST[i].GradeStroki;
		NewList[i].GradeStruct = LIST[i].GradeStruct;
		NewList[i].ITOGTEST = LIST[i].ITOGTEST;
		NewList[i].Sredn = LIST[i].Sredn;
	}

	int tempGrade;
	double tempGradeSredn;
	string tempName;
	string tempSurname;
	if (Point == 1) {
		for (int i = 0; i < Count;i++) {
			for (int j = 0; j < Count - 1;j++) {
				if (NewList[j].GradeCicles > NewList[j + 1].GradeCicles) {
					tempGrade = NewList[j].GradeCicles;
					NewList[j].GradeCicles = NewList[j + 1].GradeCicles;
					NewList[j + 1].GradeCicles = tempGrade;
					tempName = NewList[j].Name;
					NewList[j].Name = NewList[j + 1].Name;
					NewList[j + 1].Name = tempName;
					tempSurname = NewList[j].Surname;
					NewList[j].Surname = NewList[j + 1].Surname;
					NewList[j + 1].Surname = tempSurname;
				}
			}
		}

		for (int i = 0; i < Count;i++) {
			cout << NewList[i].Name << " " << NewList[i].Surname << " " << NewList[i].GradeCicles << endl;
		}
	}
	if (Point == 2) {
		for (int i = 0; i < Count;i++) {
			for (int j = 0; j < Count - 1;j++) {
				if (NewList[j].GradeArrays > NewList[j + 1].GradeArrays) {
					tempGrade = NewList[j].GradeArrays;
					NewList[j].GradeArrays = NewList[j + 1].GradeArrays;
					NewList[j + 1].GradeArrays = tempGrade;
					tempName = NewList[j].Name;
					NewList[j].Name = NewList[j + 1].Name;
					NewList[j + 1].Name = tempName;
					tempSurname = NewList[j].Surname;
					NewList[j].Surname = NewList[j + 1].Surname;
					NewList[j + 1].Surname = tempSurname;
				}
			}
		}

		for (int i = 0; i < Count;i++) {
			cout << NewList[i].Name << " " << NewList[i].Surname << " " << NewList[i].GradeArrays << endl;
		}
	}
	if (Point == 3) {
		for (int i = 0; i < Count;i++) {
			for (int j = 0; j < Count - 1;j++) {
				if (NewList[j].GradeStroki > NewList[j + 1].GradeStroki) {
					tempGrade = NewList[j].GradeStroki;
					NewList[j].GradeStroki = NewList[j + 1].GradeStroki;
					NewList[j + 1].GradeStroki = tempGrade;
					tempName = NewList[j].Name;
					NewList[j].Name = NewList[j + 1].Name;
					NewList[j + 1].Name = tempName;
					tempSurname = NewList[j].Surname;
					NewList[j].Surname = NewList[j + 1].Surname;
					NewList[j + 1].Surname = tempSurname;
				}
			}
		}

		for (int i = 0; i < Count;i++) {
			cout << NewList[i].Name << " " << NewList[i].Surname << " " << NewList[i].GradeStroki << endl;
		}
	}
	if (Point == 4) {
		for (int i = 0; i < Count;i++) {
			for (int j = 0; j < Count - 1;j++) {
				if (NewList[j].GradeRecursia > NewList[j + 1].GradeRecursia) {
					tempGrade = NewList[j].GradeRecursia;
					NewList[j].GradeRecursia = NewList[j + 1].GradeRecursia;
					NewList[j + 1].GradeRecursia = tempGrade;
					tempName = NewList[j].Name;
					NewList[j].Name = NewList[j + 1].Name;
					NewList[j + 1].Name = tempName;
					tempSurname = NewList[j].Surname;
					NewList[j].Surname = NewList[j + 1].Surname;
					NewList[j + 1].Surname = tempSurname;
				}
			}
		}

		for (int i = 0; i < Count;i++) {
			cout << NewList[i].Name << " " << NewList[i].Surname << " " << NewList[i].GradeRecursia << endl;
		}
	}
	if (Point == 5) {
		for (int i = 0; i < Count;i++) {
			for (int j = 0; j < Count - 1;j++) {
				if (NewList[j].GradeStruct > NewList[j + 1].GradeStruct) {
					tempGrade = NewList[j].GradeStruct;
					NewList[j].GradeStruct = NewList[j + 1].GradeStruct;
					NewList[j + 1].GradeStruct = tempGrade;
					tempName = NewList[j].Name;
					NewList[j].Name = NewList[j + 1].Name;
					NewList[j + 1].Name = tempName;
					tempSurname = NewList[j].Surname;
					NewList[j].Surname = NewList[j + 1].Surname;
					NewList[j + 1].Surname = tempSurname;
				}
			}
		}


		for (int i = 0; i < Count;i++) {
			cout << NewList[i].Name << " " << NewList[i].Surname << " " << NewList[i].GradeStruct << endl;
		}
	}
	if (Point == 6) {
		for (int i = 0; i < Count;i++) {
			for (int j = 0; j < Count - 1;j++) {
				if (NewList[j].GradeFiles > NewList[j + 1].GradeFiles) {
					tempGrade = NewList[j].GradeFiles;
					NewList[j].GradeFiles = NewList[j + 1].GradeFiles;
					NewList[j + 1].GradeFiles = tempGrade;
					tempName = NewList[j].Name;
					NewList[j].Name = NewList[j + 1].Name;
					NewList[j + 1].Name = tempName;
					tempSurname = NewList[j].Surname;
					NewList[j].Surname = NewList[j + 1].Surname;
					NewList[j + 1].Surname = tempSurname;
				}
			}
		}
		for (int i = 0; i < Count;i++) {
			cout << NewList[i].Name << " " << NewList[i].Surname << " " << NewList[i].GradeFiles << endl;
		}
	}
	if (Point == 7) {
		for (int i = 0; i < Count;i++) {
			for (int j = 0; j < Count - 1;j++) {
				if (NewList[j].GradeAdresa > NewList[j + 1].GradeAdresa) {
					tempGrade = NewList[j].GradeAdresa;
					NewList[j].GradeAdresa = NewList[j + 1].GradeAdresa;
					NewList[j + 1].GradeAdresa = tempGrade;
					tempName = NewList[j].Name;
					NewList[j].Name = NewList[j + 1].Name;
					NewList[j + 1].Name = tempName;
					tempSurname = NewList[j].Surname;
					NewList[j].Surname = NewList[j + 1].Surname;
					NewList[j + 1].Surname = tempSurname;
				}
			}
		}
		for (int i = 0; i < Count;i++) {
			cout << NewList[i].Name << " " << NewList[i].Surname << " " << NewList[i].GradeAdresa << endl;
		}
	}
	if (Point == 8) {
		for (int i = 0; i < Count;i++) {
			for (int j = 0; j < Count - 1;j++) {
				if (NewList[j].GradeDynamic > NewList[j + 1].GradeDynamic) {
					tempGrade = NewList[j].GradeDynamic;
					NewList[j].GradeDynamic = NewList[j + 1].GradeDynamic;
					NewList[j + 1].GradeDynamic = tempGrade;
					tempName = NewList[j].Name;
					NewList[j].Name = NewList[j + 1].Name;
					NewList[j + 1].Name = tempName;
					tempSurname = NewList[j].Surname;
					NewList[j].Surname = NewList[j + 1].Surname;
					NewList[j + 1].Surname = tempSurname;
				}
			}
		}
		for (int i = 0; i < Count;i++) {
			cout << NewList[i].Name << " " << NewList[i].Surname << " " << NewList[i].GradeDynamic << endl;
		}
	}
	if (Point == 9) {
		for (int i = 0; i < Count;i++) {
			for (int j = 0; j < Count - 1;j++) {
				if (NewList[j].ITOGTEST > NewList[j + 1].ITOGTEST) {
					tempGrade = NewList[j].ITOGTEST;
					NewList[j].ITOGTEST = NewList[j + 1].ITOGTEST;
					NewList[j + 1].ITOGTEST = tempGrade;
					tempName = NewList[j].Name;
					NewList[j].Name = NewList[j + 1].Name;
					NewList[j + 1].Name = tempName;
					tempSurname = NewList[j].Surname;
					NewList[j].Surname = NewList[j + 1].Surname;
					NewList[j + 1].Surname = tempSurname;
				}
			}
		}
		for (int i = 0; i < Count;i++) {
			cout << NewList[i].Name << " " << NewList[i].Surname << " " << NewList[i].ITOGTEST << endl;
		}
	}
	if (Point == 10) {
		for (int i = 0; i < Count;i++) {
			for (int j = 0; j < Count - 1;j++) {
				if (NewList[j].Sredn > NewList[j + 1].Sredn) {
					tempGradeSredn = NewList[j].Sredn;
					NewList[j].Sredn = NewList[j + 1].Sredn;
					NewList[j + 1].Sredn = tempGradeSredn;
					tempName = NewList[j].Name;
					NewList[j].Name = NewList[j + 1].Name;
					NewList[j + 1].Name = tempName;
					tempSurname = NewList[j].Surname;
					NewList[j].Surname = NewList[j + 1].Surname;
					NewList[j + 1].Surname = tempSurname;
				}
			}
		}
		for (int i = 0; i < Count;i++) {
			cout << NewList[i].Name << " " << NewList[i].Surname << " " << NewList[i].Sredn << endl;
		}
	}
	delete[] NewList;
}
void SortedMenu(Baza* LIST, int Count) {
	int check; bool flag = false; int Point;
	cout << "����������� ������ �� �����������" << endl;
	do {
		cout << "1 - ����: ����� " << endl;
		cout << "2 - ����: �������  " << endl;
		cout << "3 - ����: ������  " << endl;
		cout << "4 - ����: ��������  " << endl;
		cout << "5 - ����: ���������  " << endl;
		cout << "6 - ����: �����  " << endl;
		cout << "7 - ����: ������ � ��������� " << endl;
		cout << "8 - ����: ������������ ������  " << endl;
		cout << "9 -  �������� ����  " << endl;
		cout << "10 - ������� ����" << endl << endl;
		cout << "������� 0, ����� ��������� �����" << endl;
		cout << "����: "; cin >> check;
		switch (check) {
		case 1:
			Point = 1;SortedGrade(Point, LIST, Count);break;
		case 2:
			Point = 2;SortedGrade(Point, LIST, Count);break;
		case 3:
			Point = 3;SortedGrade(Point, LIST, Count);break;
		case 4:
			Point = 4;SortedGrade(Point, LIST, Count);break;
		case 5:
			Point = 5;SortedGrade(Point, LIST, Count);break;
		case 6:
			Point = 6;SortedGrade(Point, LIST, Count);break;
		case 7:
			Point = 7;SortedGrade(Point, LIST, Count);break;
		case 8:
			Point = 8;SortedGrade(Point, LIST, Count);break;
		case 9:
			Point = 9;SortedGrade(Point, LIST, Count);break;
		case 10:
			Point = 10; SortedGrade(Point, LIST, Count);break;
		case 0:
			flag = true; break;
		default:
			cout << "�� ����� �������� ��������, ���������� �����!" << endl;
		}
	} while (flag == false);
}



void OutputTheme(Baza* Student, int count, int Point) {
	string FIO;
	if (Point == 1) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			cout << FIO << setw(2) << Student[i].GradeCicles << endl;
		}
	}
	if (Point == 2) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			cout << FIO << setw(2) << Student[i].GradeArrays << endl;
		}
	}
	if (Point == 3) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			cout << FIO << setw(2) << Student[i].GradeStroki << endl;
		}
	}
	if (Point == 4) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			cout << FIO << setw(2) << Student[i].GradeRecursia << endl;
		}
	}
	if (Point == 5) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			cout << FIO << setw(2) << Student[i].GradeStruct << endl;
		}
	}
	if (Point == 6) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			cout << FIO << setw(2) << Student[i].GradeFiles << endl;
		}
	}
	if (Point == 7) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			cout << FIO << setw(2) << Student[i].GradeAdresa << endl;
		}
	}
	if (Point == 8) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			cout << FIO << setw(2) << Student[i].GradeDynamic << endl;
		}
	}
}
void OutputITOG(Baza* Student, int count) {
	string FIO;
	for (int i = 0; i < count; i++) {
		FIO = Student[i].Name + " " + Student[i].Surname;
		int size = FIO.size();
		int Msize = 30;
		for (int i = Msize;i > size;i--) {
			FIO += " ";
		}
		cout << FIO << setw(2) << Student[i].ITOGTEST << endl;
	}
}
void OutputSredn(Baza* Student, int count) {
	string FIO;
	for (int i = 0; i < count; i++) {
		FIO = Student[i].Name + " " + Student[i].Surname;
		int size = FIO.size();
		int Msize = 30;
		for (int i = Msize;i > size;i--) {
			FIO += " ";
		}
		cout << FIO << setw(2) << Student[i].Sredn << endl;
	}
}
void Themes(Baza* LIST, int Count) {
	int check; bool flag = false; int Point;
	cout << "����� ������, �������� ����" << endl;
	do {
		cout << "1 - ����: ����� " << endl;
		cout << "2 - ����: �������  " << endl;
		cout << "3 - ����: ������  " << endl;
		cout << "4 - ����: ��������  " << endl;
		cout << "5 - ����: ���������  " << endl;
		cout << "6 - ����: �����  " << endl;
		cout << "7 - ����: ������ � ��������� " << endl;
		cout << "8 - ����: ������������ ������  " << endl;
		cout << "������� 0, ����� ��������� �����" << endl;
		cout << "����: "; cin >> check;
		switch (check) {
		case 1:
			Point = 1; OutputTheme(LIST, Count, Point);break;
		case 2:
			Point = 2; OutputTheme(LIST, Count, Point);break;
		case 3:
			Point = 3; OutputTheme(LIST, Count, Point);break;
		case 4:
			Point = 4; OutputTheme(LIST, Count, Point);break;
		case 5:
			Point = 5; OutputTheme(LIST, Count, Point);break;
		case 6:
			Point = 6; OutputTheme(LIST, Count, Point);break;
		case 7:
			Point = 7; OutputTheme(LIST, Count, Point);break;
		case 8:
			Point = 8; OutputTheme(LIST, Count, Point);break;
		case 0:
			flag = true; return;
		default:
			cout << "�� ����� �������� ��������, ���������� �����!" << endl; break;
		}
	} while (flag == false);
}
void OutputFull(Baza* Student, int count) {
	cout << "1 ������� - ����: ����� " << endl;
	cout << "2 ������� - ����: �������  " << endl;
	cout << "3 ������� - ����: ������  " << endl;
	cout << "4 ������� - ����: ��������  " << endl;
	cout << "5 ������� - ����: ���������  " << endl;
	cout << "6 ������� - ����: �����  " << endl;
	cout << "7 ������� - ����: ������ � ��������� " << endl;
	cout << "8 ������� - ����: ������������ ������  " << endl;
	cout << "9 ������� - �������� ����  " << endl;
	cout << "10 ������� - ������� ����" << endl << endl;
	string FIO;
	for (int i = 0; i < count; i++) {
		FIO = Student[i].Name + " " + Student[i].Surname;
		int size = FIO.size();
		int Msize = 30;
		for (int i = Msize;i > size;i--) {
			FIO += " ";
		}
		cout << FIO << setw(2) << Student[i].GradeCicles
			<< "\t" << Student[i].GradeArrays << "\t" << Student[i].GradeStroki << "\t" << Student[i].GradeRecursia
			<< "\t" << Student[i].GradeStruct << "\t" << Student[i].GradeFiles << "\t" << Student[i].GradeAdresa << "\t" << Student[i].GradeDynamic
			<< "\t" << Student[i].ITOGTEST << "\t" << Student[i].Sredn << endl;
	}
	cout << endl;
}
void MenuOutput(Baza* LIST, int Count) {
	cout << "������ 0 ��������, ��� ������� ��� �� �������� ������������ �� ����" << endl;
	int check; bool flag = false;
	do {
		cout << "1 - ����� ������ ��������� �� ���� �����" << endl;
		cout << "2 - ����� ������ ��������� �� ���������� ����" << endl;
		cout << "3 - ����� ������ ��������� �� ��������� �����" << endl;
		cout << "4 - ����� �������� ����� ���������" << endl << endl;
		cout << "0 - ��������� �����" << endl;
		cout << "����: "; cin >> check;
		switch (check) {
		case 0:
			return;
		case 1:
			OutputFull(LIST, Count); break;
		case 2:
			Themes(LIST, Count); break;
		case 3:
			OutputITOG(LIST, Count); break;
		case 4:
			OutputSredn(LIST, Count); break;
		default:
			cout << "�� ����� �������� ��������, ���������� �����!" << endl;
		}
	} while (flag == false);
}



void FullFilt(Baza* LIST, int Count) {
	SetConsoleCP(1251);
	bool flag = false;
	string Name, Surname;
	string FIO;
	int Index = 0;
	do {
		cout << "������� ������� � ��� ��������, ����� ������� ��� ������" << endl;
		cout << "������� ���: "; cin >> Name;
		cout << "������� �������: "; cin >> Surname;
		for (int i = 0; i < Count;i++) {
			if ((Surname == LIST[i].Name) && (Name == LIST[i].Surname)) {
				Index = i;
				flag = true;
				break;
			}
		}
		if (flag == false)
			cout << "������� � ����� ������ � �������� �� ������, ��������� �������" << endl;
	} while (flag == false);

	for (int i = 0; i < Count;i++) {
		if (i == Index) {
			FIO = LIST[i].Name + " " + LIST[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			cout << FIO << setw(2) << LIST[i].GradeCicles
				<< "\t" << LIST[i].GradeArrays << "\t" << LIST[i].GradeStroki << "\t" << LIST[i].GradeRecursia
				<< "\t" << LIST[i].GradeStruct << "\t" << LIST[i].GradeFiles << "\t" << LIST[i].GradeAdresa << "\t" << LIST[i].GradeDynamic
				<< "\t" << LIST[i].ITOGTEST << "\t" << LIST[i].Sredn << endl;
		}
	}cout << endl;

}
void OutputFiltrITOG(Baza* Student, int count) {
	string FIO;
	bool flag = false; int Grade;
	do {
		cout << "������� ������, ����� ������� ������ ���������, ������� � �������� �� ������ ����" << endl;
		cout << "����: "; cin >> Grade;
		if (Grade < 1 && Grade > 5)
			cout << "�� ����� �������� ��������, ���������� �����" << endl;
		else {
			flag = true;
			break;
		}

	} while (flag == false);
	for (int i = 0; i < count; i++) {
		FIO = Student[i].Name + " " + Student[i].Surname;
		int size = FIO.size();
		int Msize = 30;
		for (int i = Msize;i > size;i--) {
			FIO += " ";
		}
		if (Student[i].ITOGTEST == Grade)
			cout << FIO << setw(2) << Student[i].ITOGTEST << endl;

	}
}
void OutputFiltrSREDN(Baza* Student, int count) {
	string FIO;
	bool flag = false; double Grade;
	do {
		cout << "������� ������, ����� ������� ������ ���������, � ������� ������� ���� ������ ����������" << endl;
		cout << "����: "; cin >> Grade;
		if (Grade < 1 && Grade > 5)
			cout << "�� ����� �������� ��������, ���������� �����" << endl;
		else {
			flag = true;
			break;
		}

	} while (flag == false);
	for (int i = 0; i < count; i++) {
		FIO = Student[i].Name + " " + Student[i].Surname;
		int size = FIO.size();
		int Msize = 30;
		for (int i = Msize;i > size;i--) {
			FIO += " ";
		}
		if (Student[i].Sredn > Grade)
			cout << FIO << setw(2) << Student[i].Sredn << endl;

	}
}
void OutputFiltrTheme(Baza* Student, int count, int Point) {
	string FIO;
	bool flag = false; int Grade;
	do {
		cout << "������� ������, ����� ������� ������ ���������, ������� � �������� �� ������ ����" << endl;
		cout << "����: "; cin >> Grade;
		if (Grade < 1 && Grade > 5)
			cout << "�� ����� �������� ��������, ���������� �����" << endl;
		else {
			flag = true;
			break;
		}

	} while (flag == false);

	if (Point == 1) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			if (Student[i].GradeCicles == Grade)
				cout << FIO << setw(2) << Student[i].GradeCicles << endl;
		}
	}
	if (Point == 2) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			if (Student[i].GradeArrays == Grade)
				cout << FIO << setw(2) << Student[i].GradeArrays << endl;
		}
	}
	if (Point == 3) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			if (Student[i].GradeStroki == Grade)
				cout << FIO << setw(2) << Student[i].GradeStroki << endl;
		}
	}
	if (Point == 4) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			if (Student[i].GradeRecursia == Grade)
				cout << FIO << setw(2) << Student[i].GradeRecursia << endl;
		}
	}
	if (Point == 5) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			if (Student[i].GradeStruct == Grade)
				cout << FIO << setw(2) << Student[i].GradeStruct << endl;
		}
	}
	if (Point == 6) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			if (Student[i].GradeFiles == Grade)
				cout << FIO << setw(2) << Student[i].GradeFiles << endl;
		}
	}
	if (Point == 7) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			if (Student[i].GradeAdresa == Grade)
				cout << FIO << setw(2) << Student[i].GradeAdresa << endl;
		}
	}
	if (Point == 8) {
		for (int i = 0; i < count; i++) {
			FIO = Student[i].Name + " " + Student[i].Surname;
			int size = FIO.size();
			int Msize = 30;
			for (int i = Msize;i > size;i--) {
				FIO += " ";
			}
			if (Student[i].GradeDynamic == Grade)
				cout << FIO << setw(2) << Student[i].GradeDynamic << endl;
		}
	}
}
void FiltrTheme(Baza* LIST, int Count) {
	int check; bool flag = false; int Point;
	cout << "�������� ����" << endl;
	do {
		cout << "�������� ����" << endl;
		cout << "1 - ����: ����� " << endl;
		cout << "2 - ����: �������  " << endl;
		cout << "3 - ����: ������  " << endl;
		cout << "4 - ����: ��������  " << endl;
		cout << "5 - ����: ���������  " << endl;
		cout << "6 - ����: �����  " << endl;
		cout << "7 - ����: ������ � ��������� " << endl;
		cout << "8 - ����: ������������ ������  " << endl;

		cout << "������� 0, ����� ��������� �����" << endl;
		cout << "����: "; cin >> check;
		switch (check) {
		case 1:
			Point = 1;OutputFiltrTheme(LIST, Count, Point); break;
		case 2:
			Point = 2;OutputFiltrTheme(LIST, Count, Point); break;
		case 3:
			Point = 3;OutputFiltrTheme(LIST, Count, Point); break;
		case 4:
			Point = 4;OutputFiltrTheme(LIST, Count, Point); break;
		case 5:
			Point = 5;OutputFiltrTheme(LIST, Count, Point); break;
		case 6:
			Point = 6;OutputFiltrTheme(LIST, Count, Point); break;
		case 7:
			Point = 7;OutputFiltrTheme(LIST, Count, Point); break;
		case 8:
			Point = 8;OutputFiltrTheme(LIST, Count, Point); break;
		case 0:
			flag = true; break;
		default:
			cout << "�� ����� �������� ��������, ���������� �����!" << endl;
		}
	} while (flag == false);
}
void MenuFilt(Baza* LIST, int Count) {
	cout << "������ 0 ��������, ��� ������� ��� �� �������� ������������ �� ����" << endl;
	int check; bool flag = false;
	do {
		cout << "1 - ����� ������ ��������� �� ���� �����" << endl;
		cout << "2 - ����� ������ ��������� �� ���������� ����" << endl;
		cout << "3 - ����� ������ ��������� �� ��������� �����" << endl;
		cout << "4 - ����� �������� ����� ���������" << endl << endl;
		cout << "0 - ��������� �����" << endl;
		cout << "����: "; cin >> check;
		switch (check) {
		case 0:
			return;
		case 1:
			FullFilt(LIST, Count); break;
		case 2:
			FiltrTheme(LIST, Count); break;
		case 3:
			OutputFiltrITOG(LIST, Count); break;
		case 4:
			OutputFiltrSREDN(LIST, Count); break;
		default:
			cout << "�� ����� �������� ��������, ���������� �����!" << endl;
		}
	} while (flag == false);
}

void MenuReqQuest(Baza* LIST, int Count) {
	int check; bool flag = false;
	do {
		cout << "1 - ������� ������" << endl;
		cout << "2 - �������� ������" << endl;
		cout << "3 - �������� ������" << endl;
		cout << "0 - ��������� �����" << endl;
		cout << "����: "; cin >> check;
		switch (check) {
		case 0:
			return;
		case 1:
			EditStudent(LIST, Count);
		case 2:
			EditGradeStudent(LIST, Count);
		case 3:
			MenuOutput(LIST, Count); break;
		default:
			cout << "�� ����� �������� ��������, ���������� �����!" << endl;
		}
	} while (flag == false);
}
void MenuRedStudents(Baza* LIST, int Count) {
	int check; bool flag = false;
	do {
		cout << "1 - ����������� � �������� ���������" << endl;
		cout << "2 - ��������� ��������� ���������" << endl;
		cout << "3 - ����� ������ ���������" << endl;
		cout << "4 - ����������" << endl;
		cout << "5 - ���������� �� �������" << endl;
		cout << "0 - ��������� �����" << endl;
		cout << "����: "; cin >> check;
		switch (check) {
		case 0:
			return;
		case 1:
			EditStudent(LIST, Count); break;
		case 2:
			EditGradeStudent(LIST, Count); break;
		case 3:
			MenuOutput(LIST, Count); break;
		case 4:
			MenuFilt(LIST, Count);
		case 5:
			SortedMenu(LIST, Count); break;
		default:
			cout << "�� ����� �������� ��������, ���������� �����!" << endl;
		}
	} while (flag == false);
}
void MenuPrepodMAIN() {
	Baza* LIST = new Baza[100];
	int Count;
	gradeRed(LIST, Count);
	int check; bool flag = false;
	do {
		cout << "1 - �������������� ��������" << endl;
		cout << "2 - ������ �� ������� ���������" << endl;
		cout << "0 - ��������� �����" << endl;
		cout << "����: "; cin >> check;
		switch (check) {
		case 0:
			delete[] LIST; return;
			return;
		case 1:
			EditQuest(); break;
		case 2:
			MenuRedStudents(LIST, Count); break;
		default:
			cout << "�� ����� �������� ��������, ���������� �����!" << endl;
		}
	} while (flag == false);
}
void InputPasswordTeacher() {
	SetConsoleCP(1251);
	Teacher Teacher[2];
	string login, password;
	ifstream file("TeachBAZA.txt");
	for (int i = 0; i < 2; i++) file >> Teacher[i].Login >> Teacher[i].Password;
	file.close();
	bool flag = false;
	while (flag==false) {
		cout << "������� �����: "; cin >> login;
		cout << "������� ������: "; cin >> password;
		for (int i = 0; i < 2; i++)
			if ((login == Teacher[i].Login) && (password == Teacher[i].Password)) { flag = true; MenuPrepodMAIN();}
		cout << "������ ��������. ������� ��� ���." << endl;
	}
}

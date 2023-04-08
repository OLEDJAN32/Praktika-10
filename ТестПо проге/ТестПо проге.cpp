#include "VhodStudent.h"
#include <iostream>
using namespace std;

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
};

int main()
{
    int CountStudents = 19;
    setlocale(LC_ALL, "rus");
    int check; 
    do {
        cout << "1, чтобы работать в режиме студента" << endl;
        cout << "2, чтобы работать в режиме преподавателя" << endl;
        cout << "Введите 0, чтобы выйти из программы" << endl;
        cout << "Ввод: "; cin >> check;
        switch (check) {
        case 1:
            StartVhodStudent(CountStudents); break;
        case 2:
            cout << endl; break;
        case 3:
            return 0;
        default:
            cout << "Вы ввели неверное значение, попробуйте снова" << endl << endl;
        }
    } while (true);

   // StartVhod();
    return 0;
}


#include "VhodStudent.h"
#include  "VhodPrepod.h"
#include "Teacher.h"
#include <iostream>
#include <fstream>

using namespace std;
#define MAXCOUNT 100

int main()
{
    int CountStudent = 0;

    ifstream StartFile("StudentsBAZA.txt");
    for (int i = 0; i < 1;i++)
        StartFile >> CountStudent;
    StartFile.close();
       
    setlocale(LC_ALL, "rus");
    int check; 
    do {
        cout << "1, чтобы работать в режиме студента" << endl;
        cout << "2, чтобы работать в режиме преподавателя" << endl;
        cout << "Введите 0, чтобы выйти из программы" << endl;
        cout << "Ввод: "; cin >> check;
        switch (check) {
        case 1:
            StartVhodStudent(CountStudent); break;
        case 2:
            InputPasswordTeacher(); break;
        case 0:
            cout << "Успешное завершение работы программы" << endl;
            return 0;

        default:
            cout << "Вы ввели неверное значение, попробуйте снова" << endl << endl;
        }
    } while (true);

   // StartVhod();
    return 0;
}


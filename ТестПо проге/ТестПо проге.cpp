#include "VhodStudent.h"
#include  "VhodPrepod.h"
#include "Teacher.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int check; 
    bool flag = false;
    do {
        cout << "\n1 - чтобы работать в режиме студента" << endl;
        cout << "2 - чтобы работать в режиме преподавателя" << endl;
        cout << "Введите 0, чтобы выйти из программы" << endl;
        cout << "Ввод: "; cin >> check;
        switch (check) {
        case 1:
            StartVhodStudent(); break;
        case 2:
            InputPasswordTeacher(); break;
        case 0:
            cout << "Успешное завершение работы программы" << endl;
            flag = true; break;

        default:
            cout << "Вы ввели неверное значение, попробуйте снова" << endl << endl;
        }
    } while (flag==false);

    return 0;
}


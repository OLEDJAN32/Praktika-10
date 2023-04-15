#include "VhodStudent.h"
#include "VhodPrepod.h"
#include "Shifr.h"
#include "Teacher.h"
#include <iostream>
#include <fstream>

using namespace std;


void ShifrQwest() {
    string Qwest1 = "Vopros\\Adress_task.txt";
    string Qwest2 = "Vopros\\Cikle_task.txt";
    string Qwest3 = "Vopros\\Dynamic_task.txt";
    string Qwest4 = "Vopros\\File_task.txt";
    string Qwest5 = "Vopros\\Mas_task.txt";
    string Qwest6 = "Vopros\\Rec_task.txt";
    string Qwest7 = "Vopros\\Stroki_task.txt";
    string Qwest8 = "Vopros\\Struct_task.txt";

    string Qwest1S = "Vopros\\Adress_taskSHIFR.txt";
    string Qwest2S = "Vopros\\Cikle_taskSHIFR.txt";
    string Qwest3S = "Vopros\\Dynamic_taskSHIFR.txt";
    string Qwest4S = "Vopros\\File_taskSHIFR.txt";
    string Qwest5S = "Vopros\\Mas_taskSHIFR.txt";
    string Qwest6S = "Vopros\\Rec_taskSHIFR.txt";
    string Qwest7S = "Vopros\\Stroki_taskSHIFR.txt";
    string Qwest8S = "Vopros\\Struct_taskSHIFR.txt";
    ShifrQW(Qwest1,Qwest1S);
    ShifrQW(Qwest2, Qwest2S);
    ShifrQW(Qwest3, Qwest3S);
    ShifrQW(Qwest4, Qwest4S);
    ShifrQW(Qwest5, Qwest5S);
    ShifrQW(Qwest6, Qwest6S);
    ShifrQW(Qwest7, Qwest7S);
    ShifrQW(Qwest8, Qwest8S);
}
void DeShifrQwest() {
    string Qwest1 = "Vopros\\Adress_task.txt";
    string Qwest2 = "Vopros\\Cikle_task.txt";
    string Qwest3 = "Vopros\\Dynamic_task.txt";
    string Qwest4 = "Vopros\\File_task.txt";
    string Qwest5 = "Vopros\\Mas_task.txt";
    string Qwest6 = "Vopros\\Rec_task.txt";
    string Qwest7 = "Vopros\\Stroki_task.txt";
    string Qwest8 = "Vopros\\Struct_task.txt";

    string Qwest1S = "Vopros\\Adress_taskSHIFR.txt";
    string Qwest2S = "Vopros\\Cikle_taskSHIFR.txt";
    string Qwest3S = "Vopros\\Dynamic_taskSHIFR.txt";
    string Qwest4S = "Vopros\\File_taskSHIFR.txt";
    string Qwest5S = "Vopros\\Mas_taskSHIFR.txt";
    string Qwest6S = "Vopros\\Rec_taskSHIFR.txt";
    string Qwest7S = "Vopros\\Stroki_taskSHIFR.txt";
    string Qwest8S = "Vopros\\Struct_taskSHIFR.txt";
    DeShifrQW(Qwest1S, Qwest1);
    DeShifrQW(Qwest2S, Qwest2);
    DeShifrQW(Qwest3S, Qwest3);
    DeShifrQW(Qwest4S, Qwest4);
    DeShifrQW(Qwest5S, Qwest5);
    DeShifrQW(Qwest6S, Qwest6);
    DeShifrQW(Qwest7S, Qwest7);
    DeShifrQW(Qwest8S, Qwest8);
}
void ClearDeShifr() {
    string Qwest1 = "Vopros\\Adress_task.txt";
    string Qwest2 = "Vopros\\Cikle_task.txt";
    string Qwest3 = "Vopros\\Dynamic_task.txt";
    string Qwest4 = "Vopros\\File_task.txt";
    string Qwest5 = "Vopros\\Mas_task.txt";
    string Qwest6 = "Vopros\\Rec_task.txt";
    string Qwest7 = "Vopros\\Stroki_task.txt";
    string Qwest8 = "Vopros\\Struct_task.txt";
    ofstream file1(Qwest1);
    file1 << "";
    file1.close();
    ofstream file2(Qwest2);
    file2 << "";
    file2.close();
    ofstream file3(Qwest3);
    file3 << "";
    file3.close();
    ofstream file4(Qwest4);
    file4 << "";
    file4.close();
    ofstream file5(Qwest5);
    file5 << "";
    file5.close();
    ofstream file6(Qwest6);
    file6 << "";
    file6.close();
    ofstream file7(Qwest7);
    file7 << "";
    file7.close();
    ofstream file8(Qwest8);
    file8 << "";
    file8.close();
}
int main()
{
    setlocale(LC_ALL, "rus");
    DeShifrQwest();
    DeShifr();
    //ShifrTeach();
    DeShifrTeach();
    int check; 
    bool flag = false;
    cout << "ВНИМАНИЕ!" << endl;
    cout << "Для корректной работы программы выход из неё ТОЛЬКО из главного меню (Закрывать консоль нельзя)" << endl;
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

    ClearDeShifr();

    ofstream file("StudentsBAZADeShifr.txt");
    file << "";
    file.close();
    ofstream file1("TeachBAZA.txt");
    file1 << "";
    file1.close();
    return 0;
}


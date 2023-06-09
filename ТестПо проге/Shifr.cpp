#include "Shifr.h"
#include <string>
#include <fstream>
#include <Windows.h>

#define English 26
#define Russian 32 

void Shifr()
{
    SetConsoleCP(1251);
    int n = 4;
    int flag;
    FILE* FILE1, * FILE2;
    fopen_s(&FILE1, "StudentsBAZADeShifr.txt", "r");
    if (!FILE1) {
        cout << "���� �� ��� ������!" << endl;
        return;
    }
    fopen_s(&FILE2, "StudentsBAZAShifr.txt", "w");
    if (!FILE2) {
        cout << "���� �� ��� ������!" << endl;
        return;
    }
    char c;
    c = getc(FILE1);
    while (!feof(FILE1))
    {
        flag = 0;
        if (c >= 'A' && c <= 'Z')
        {
            c = c + (n % English);
            if (c > 'Z')
                c = 'A' + (c - 'Z') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c + (n % English);
            if (c > 'z')
                c = 'a' + (c - 'z') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c + (n % Russian);
            if (c > '�')
                c = '�' + (c - '�') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c + (n % Russian);
            if (c > '�')
                c = '�' + (c - '�') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }if (c >= '0' && c <= '9')
        {
            c = c + (n % 10);
            if (c > '9')
                c = '0' + (c - '9') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf(FILE2, "%c", c);
        c = getc(FILE1);
    }
    fclose(FILE1);
    fclose(FILE2);
}

void DeShifr()
{
    int n = 4;
    int flag;
    FILE* FILE1, * FILE2;
    fopen_s(&FILE1, "StudentsBAZAShifr.txt", "r");
    if (!FILE1) {
        printf("���� �� ��� ������!");
        return;
    }
    fopen_s(&FILE2, "StudentsBAZADeShifr.txt", "w");
    if (!FILE2) {
        printf("���� �� ��� ������!");
        return;
    }
    char c;
    c = getc(FILE1);
    while (!feof(FILE1))
    {
        flag = 0;
        if (c >= 'A' && c <= 'Z')
        {
            c = c - (n % English);
            if (c < 'A')
                c = 'Z' - ('A' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c - (n % English);
            if (c < 'a')
                c = 'z' - ('a' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c - (n % Russian);
            if (c < '�')
                c = '�' - ('�' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c - (n % Russian);
            if (c < '�')
                c = '�' - ('�' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '0' && c <= '9') {
            c = c - (n % 10);
            if (c < '0')
                c = '9' - ('0' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf(FILE2, "%c", c);
        c = getc(FILE1);
    }
    fclose(FILE1);
    fclose(FILE2);
}

void ShifrQW(string name, string lastname)
{
    int n = 4;
    const char* name1 = name.c_str();
    const char* name2 = lastname.c_str();
    int flag;
    FILE* FILE1, * FILE2;
    fopen_s(&FILE1, name1, "r");

    if (!FILE1) {
        cout << "���� �� ��� ������!" << endl;
        return;
    }

    fopen_s(&FILE2, name2, "w");
    if (!FILE2) {
        cout << "���� �� ��� ������!" << endl;
        return;
    }
    char c;
    c = getc(FILE1);
    while (!feof(FILE1))
    {
        flag = 0;
        if (c >= 'A' && c <= 'Z')
        {
            c = c + (n % English);
            if (c > 'Z')
                c = 'A' + (c - 'Z') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c + (n % English);
            if (c > 'z')
                c = 'a' + (c - 'z') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c + (n % Russian);
            if (c > '�')
                c = '�' + (c - '�') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c + (n % Russian);
            if (c > '�')
                c = '�' + (c - '�') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }if (c >= '0' && c <= '9')
        {
            c = c + (n % 10);
            if (c > '9')
                c = '0' + (c - '9') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf(FILE2, "%c", c);
        c = getc(FILE1);
    }
    fclose(FILE1);
    fclose(FILE2);
}

void DeShifrQW(string name, string lastname)
{
    const char* name1 = name.c_str();
    const char* name2 = lastname.c_str();
    int n = 4;
    int flag;
    FILE* FILE1, * FILE2;
    fopen_s(&FILE1, name1, "r");
    if (!FILE1) {
        printf("���� �� ��� ������!");
        exit(-1);
    }
    fopen_s(&FILE2, name2, "w");
    if (!FILE2) {
        printf("���� �� ��� ������!");
        exit(-1);
    }
    char c;
    c = getc(FILE1);
    while (!feof(FILE1))
    {
        flag = 0;
        if (c >= 'A' && c <= 'Z')
        {
            c = c - (n % English);
            if (c < 'A')
                c = 'Z' - ('A' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c - (n % English);
            if (c < 'a')
                c = 'z' - ('a' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c - (n % Russian);
            if (c < '�')
                c = '�' - ('�' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c - (n % Russian);
            if (c < '�')
                c = '�' - ('�' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '0' && c <= '9') {
            c = c - (n % 10);
            if (c < '0')
                c = '9' - ('0' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf(FILE2, "%c", c);
        c = getc(FILE1);
    }
    fclose(FILE1);
    fclose(FILE2);
}

void ShifrTeach()
{
    int n = 4;
    int flag;
    FILE* FILE1, * FILE2;
    fopen_s(&FILE1, "TeachBAZA.txt", "r");
    if (!FILE1) {
        cout << "���� �� ��� ������!" << endl;
        return;
    }
    fopen_s(&FILE2, "TeachBAZAshifr.txt", "w");
    if (!FILE2) {
        cout << "���� �� ��� ������!" << endl;
        return;
    }
    char c;
    c = getc(FILE1);
    while (!feof(FILE1))
    {
        flag = 0;
        if (c >= 'A' && c <= 'Z')
        {
            c = c + (n % English);
            if (c > 'Z')
                c = 'A' + (c - 'Z') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c + (n % English);
            if (c > 'z')
                c = 'a' + (c - 'z') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c + (n % Russian);
            if (c > '�')
                c = '�' + (c - '�') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c + (n % Russian);
            if (c > '�')
                c = '�' + (c - '�') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }if (c >= '0' && c <= '9')
        {
            c = c + (n % 10);
            if (c > '9')
                c = '0' + (c - '9') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf(FILE2, "%c", c);
        c = getc(FILE1);
    }
    fclose(FILE1);
    fclose(FILE2);
}

void DeShifrTeach()
{
    int n = 4;
    int flag;
    FILE* FILE1, * FILE2;
    fopen_s(&FILE1, "TeachBAZAshifr.txt", "r");
    if (!FILE1) {
        printf("���� �� ��� ������!");
        return;
    }
    fopen_s(&FILE2, "TeachBAZA.txt", "w");
    if (!FILE2) {
        printf("���� �� ��� ������!");
        return;
    }
    char c;
    c = getc(FILE1);
    while (!feof(FILE1))
    {
        flag = 0;
        if (c >= 'A' && c <= 'Z')
        {
            c = c - (n % English);
            if (c < 'A')
                c = 'Z' - ('A' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            c = c - (n % English);
            if (c < 'a')
                c = 'z' - ('a' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c - (n % Russian);
            if (c < '�')
                c = '�' - ('�' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '�' && c <= '�')
        {
            c = c - (n % Russian);
            if (c < '�')
                c = '�' - ('�' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= '0' && c <= '9') {
            c = c - (n % 10);
            if (c < '0')
                c = '9' - ('0' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf(FILE2, "%c", c);
        c = getc(FILE1);
    }
    fclose(FILE1);
    fclose(FILE2);
}

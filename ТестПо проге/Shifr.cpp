#include "Shifr.h"

#define English 26
#define Russian 32 

void Shifr()
{
    int n = 4;
    int flag;
    FILE* FILE1, * FILE2;
    fopen_s(&FILE1, "StudentsBAZA.txt", "r");
    if (!FILE1) {
        cout << "ÔÀÉË ÍÅ ÁÛË ÎÒÊÐÛÒ!" << endl;
        exit(-1);
    }
    fopen_s(&FILE2, "StudentsBAZAShifr.txt", "w");
    if (!FILE2) {
        cout << "ÔÀÉË ÍÅ ÁÛË ÎÒÊÐÛÒ!" << endl;
        exit(-1);
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
        if (c >= 'À' && c <= 'ß')
        {
            c = c + (n % Russian);
            if (c > 'ß')
                c = 'À' + (c - 'ß') - 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= 'à' && c <= 'ÿ')
        {
            c = c + (n % Russian);
            if (c > 'ÿ')
                c = 'à' + (c - 'ÿ') - 1;
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
        printf("ÔÀÉË ÍÅ ÁÛË ÎÒÊÐÛÒ!");
        exit(-1);
    }
    fopen_s(&FILE2, "StudentsBAZADeShifr.txt", "w");
    if (!FILE2) {
        printf("ÔÀÉË ÍÅ ÁÛË ÎÒÊÐÛÒ!");
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
        if (c >= 'À' && c <= 'ß')
        {
            c = c - (n % Russian);
            if (c < 'À')
                c = 'ß' - ('À' - c) + 1;
            fprintf(FILE2, "%c", c);
            flag = 1;
        }
        if (c >= 'à' && c <= 'ÿ')
        {
            c = c - (n % Russian);
            if (c < 'à')
                c = 'ÿ' - ('à' - c) + 1;
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


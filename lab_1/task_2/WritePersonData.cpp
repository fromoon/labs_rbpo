#include "labs1.h"


void WritePersonData(const string& names, const unsigned short* ages, const string& heights, const string& weigths, string salaries)
{
    cout << "\n���: " << names << endl
        << "�������: " << *ages << endl
        << "����: " << heights << endl
        << "���: " << weigths << endl
        << "��������: " << salaries << "\n" << endl;
}
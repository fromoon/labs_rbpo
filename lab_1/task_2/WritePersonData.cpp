#include "labs1.h"


void WritePersonData(const string& names, const unsigned short* ages, const string& heights, const string& weigths, string salaries)
{
    cout << "\nИмя: " << names << endl
        << "Возраст: " << *ages << endl
        << "Рост: " << heights << endl
        << "Вес: " << weigths << endl
        << "Зарплата: " << salaries << "\n" << endl;
}
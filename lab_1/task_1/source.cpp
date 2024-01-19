#include <iostream>
#include <string>
using namespace std;

unsigned short ReadPersonAge()
{
    unsigned short age;
    cout << "Введите возраст: "; cin >> age;
    return age;
}

string ReadPersonName()
{
    string name;
    cout << "Введите имя: "; cin >> name;
    return name;
}

unsigned short g_height = 0;
void ReadPersonHeight()
{
    cout << "Введите рост: "; cin >> g_height;
}

void ReadPersonWeight(unsigned short& weight)
{
    cout << "Введите вес: "; cin >> weight;
}

void ReadPersonSalary(double* salary)
{
    cout << "Введите зарплату: "; cin >> *salary;
}

void ReadPersonData(string& names, unsigned short& ages, double& salaries)
{
    names = ReadPersonName();
    ages = ReadPersonAge();
    ReadPersonSalary(&salaries);
}

void ReadPersonData(string& names, unsigned short& ages, unsigned short& heights, unsigned short& weigths)
{
    names = ReadPersonName();
    ages = ReadPersonAge();
    ReadPersonHeight();
    heights = g_height;
    ReadPersonWeight(weigths);
}

void WritePersonData(const string& names, const unsigned short* ages, const string& heights, const string& weigths, string salaries)
{
    cout << "\nИмя: " << names << endl
        << "Возраст: " << *ages << endl
        << "Рост: " << heights << endl
        << "Вес: " << weigths << endl
        << "Зарплата: " << salaries << "\n" << endl;
}

#ifndef DO_NOT_DEFINE_MAIN
int main(void)
{
    setlocale(LC_ALL, "RUS");
    string name;
    unsigned short age, height, weight;
    double salary;
    string wait = "Значения ещё не были введены";

    ReadPersonData(name, age, salary);
    string st_salary = to_string(salary);
    WritePersonData(name, &age, wait, wait, st_salary);

    ReadPersonData(name, age, height, weight);
    string st_height = to_string(height);
    string st_weight = to_string(weight);
    WritePersonData(name, &age, st_height, st_weight, st_salary);
}
#endif

#include "labs1.h"
unsigned short g_height;


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

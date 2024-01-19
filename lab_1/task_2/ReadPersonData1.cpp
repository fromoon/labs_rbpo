#include "labs1.h"

//extern unsigned short g_height;
void ReadPersonData(string& names, unsigned short& ages, double& salaries)
{
    names = ReadPersonName();
    ages = ReadPersonAge();
    ReadPersonSalary(&salaries);
}

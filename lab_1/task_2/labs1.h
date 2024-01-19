#pragma once

#include <iostream>
#include <string>
using namespace std;

extern unsigned short g_height;

unsigned short ReadPersonAge();
string ReadPersonName();
void ReadPersonHeight();
void ReadPersonWeight(unsigned short& weight);
void ReadPersonSalary(double* salary);
void ReadPersonData(string& names, unsigned short& ages, double& salaries);
void ReadPersonData(string& names, unsigned short& ages, unsigned short& heights, unsigned short& weigths);
void WritePersonData(const string& names, const unsigned short* ages, const string& heights, const string& weigths, string salaries);

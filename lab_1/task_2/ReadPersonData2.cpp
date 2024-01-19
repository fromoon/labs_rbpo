#include "labs1.h"

void ReadPersonData(string& names, unsigned short& ages, unsigned short& heights, unsigned short& weigths)
{
    names = ReadPersonName();
    ages = ReadPersonAge();
    ReadPersonHeight();
    heights = g_height;
    ReadPersonWeight(weigths);
}
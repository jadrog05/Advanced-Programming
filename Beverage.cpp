#include "Beverage.h"  
	
Beverage::Beverage(string na, int cal, float pri, float AlcBV, int vol) : Item(na, cal, pri)
{
	abv = AlcBV;
    volume = vol;
}

float Beverage::getAbv()
{
    return abv;
}

int Beverage::getVolume()
{
    return volume;
}
	
Beverage::~Beverage()
{
	
}
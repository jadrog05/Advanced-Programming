#pragma once
#include "Item.h"
	
class Beverage : public Item 
{
	private:
	float abv;
	int volume;
	public:
		Beverage(string na, int cal, float pri, float AlcBV, int vol);
		float getAbv();
		int getVolume();
		~Beverage();

};

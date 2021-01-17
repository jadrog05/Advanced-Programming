#pragma once
#include <string>
#include <iostream>

using namespace std;

class Item 
{
protected:
	int calories;
	string name;
	float price;
	string type;
public:
	Item(string na, int cal, float pr);
	virtual void toString() = 0;
	string getName();
	int getCalories();
	float getPrice();
	string getItemType();
};



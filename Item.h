
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
public:
	Item(string na, int cal, float pr);
	int getCalories();
	void getName();
	float getPrice();
};



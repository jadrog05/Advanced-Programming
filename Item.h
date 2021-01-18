#pragma once
#include <string>
#include <iostream>
#include <fstream>

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
	~Item();
	virtual void toString(bool toReceipt) = 0;
	string getName();
	int getCalories();
	float getPrice();
	string getItemType();
};



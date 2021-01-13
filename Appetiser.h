#pragma once
#include "Item.h"
using namespace std;
	
class Appetiser: public Item
{
private:
	bool shareable;
	bool twoForOne;
public:
		Appetiser(string na, int cal, float pri, bool share);
		void toString();
		
};
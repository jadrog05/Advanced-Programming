#pragma once
#include "Item.h"
	
class Appetiser: public Item
{
private:
	bool shareable;
	bool twoForOne;
public:
	Appetiser(string na, int cal, float pri, bool share, bool twoFO);
	bool isShareable();
	bool isTwoForOne();
	void toString(bool toReceipt);		
};
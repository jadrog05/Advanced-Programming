#include "Appetiser.h" 

Appetiser::Appetiser(string na, int cal, float pri, bool share) : Item(na, cal, pri)
{
    shareable = share;
}

void Appetiser::toString()
{
    cout << "Hello";
}
	
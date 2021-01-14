#include "Appetiser.h" 

Appetiser::Appetiser(string na, int cal, float pri, bool share, bool twoFO) : Item(na, cal, pri)
{
    shareable = share;
    twoForOne = twoFO;
}

void Appetiser::toString()
{
    cout << "Hello";
}

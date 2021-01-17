#pragma once
#include "ItemList.h"
using namespace std;

class Order : public ItemList
{
    public:
    Order();
    void toString();
    void addItem(int itemNumber);
    void calculateTotal();
    void printReceipt();
};

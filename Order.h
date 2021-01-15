#pragma once
#include "ItemList.h"
using namespace std;

class Order : public ItemList
{
    public:
    Order();
    void addItem(int itemNumber);
    void calculateTotal();
    void printReceipt();
};

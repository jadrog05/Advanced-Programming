#pragma once
#include "ItemList.h"

using namespace std;

class Order : public ItemList
{
    private:
    vector<Item*> Items;
    public:
    Order();
    void toString();
    void add(Item* item);
    void remove(Item* item);
    void calculateTotal(bool toReceipt);
    void printReceipt();
};

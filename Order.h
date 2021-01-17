#pragma once
#include "ItemList.h"

using namespace std;

class Order : public ItemList
{
    private:
    vector<Item*> order_vec;
    public:
    Order(vector<Item*> menu_vec);
    void toString();
    void add(int itemNumber);
    void remove(int itemNumber);
    void calculateTotal();
    void printReceipt();
};

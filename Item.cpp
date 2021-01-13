#include "Item.h"  

//ITEM Methods
Item::Item(string na, int cal, float pr)
{
    cout << "hello";
    name =na;
    price = pr;
    calories = cal;
}

void Item::getName(){
    cout << name;
}
int Item::getCalories()
{
    return calories;
}

float Item::getPrice()
{
    return price;
}

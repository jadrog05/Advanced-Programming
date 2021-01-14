#include "Item.h"  

//ITEM Methods
Item::Item(string na, int cal, float pr)
{
    name =na;
    price = pr;
    calories = cal;
}

string Item::getName()
{
    return name;
}
int Item::getCalories()
{
    return calories;
}
float Item::getPrice()
{
    return price;
}

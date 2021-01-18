#include "Item.h"  

//ITEM Methods
Item::Item(string na, int cal, float pr)
{
    name =na;
    std::string num_text = std::to_string(pr);
    std::string pr_2dec = num_text.substr(0, num_text.find(".")+3);
    price = stof(pr_2dec);
    calories = cal;
    type = "Item";
}

Item::~Item(){
    
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
string Item::getItemType()
{
    return type;
}




#pragma once
#include "ItemList.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"

class Menu : public ItemList
{
private:
    void addAppetiser(string line);
    void addMainCourse(string line);
    void addBeverage(string line);
public:
    Menu(string filename);
    void toString();
};
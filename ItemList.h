#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include "Item.h"
using namespace std;

class ItemList
{
public:
    vector<Item*> Items;
    void toString();
    ItemList();
    void Load(Item*);;
};
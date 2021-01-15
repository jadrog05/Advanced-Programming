#include "ItemList.h"

ItemList::ItemList()
{

}

void ItemList::Load(Item*)
{
    Items.push_back (new Item("Pot", 300, 9.99));
}

#pragma once
#include "Item.h"
	
class MainCourse : public Item 
{
	public:
		MainCourse(string na, int cal, float pri);
		void toString();
		~MainCourse();
};
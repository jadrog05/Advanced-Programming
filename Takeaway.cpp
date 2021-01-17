/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Autumn 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"
#include "ItemList.h"


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order(menu.Items);

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			menu.toString();
		}
		else if (command.compare("add") == 0)
		{
			int choice;
			for (int i = 1; i < (parameters.size()); i++)
			{
				choice = stoi(parameters[i]);
				if (choice > 0 && choice <menu.Items.size())
				{
					order.add(choice);
					
				}
				else
				{
					cout << "This item number does not exist!" << endl;
				}	
			}
		}
		else if (command.compare("remove") == 0)
		{
			int choice;
			choice = stoi(parameters[1]);
			order.remove(choice);
		}
		else if (command.compare("checkout") == 0)
		{
			order.toString();
		}
		else if (command.compare("help") == 0)
		{
			cout << "get over it";
		}

		parameters.clear();

	}
};
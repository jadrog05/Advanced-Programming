#include "Menu.h"

Menu::Menu(string filename)
{
    ifstream data(filename);
    string line;
    if (data)
    {
        while(getline(data,line)) //checks if file exists before trying to extract
        {
            stringstream linestream(line); 
            switch (char ItemType = line.at(0)) //finds item type from file and calls the according method passing all the attributes as parameter
            {
                case 'a':
                    addAppetiser(line);
                    break;
                case 'm':
                    addMainCourse(line);
                    break;
                case 'b':
                    addBeverage(line);
                    break;
                default:
                    break;
            }   
        }
        data.close();
    
    }
    else
    {
        cout << "That file doesnt exist!" << endl;
        exit(0); //exits program if no menu.csv file is found
    }
    

}

void Menu::addAppetiser(string line) //extracts the data from the line input and constructs the item and adds it to menu item list
{                                    //same for all these methods
    vector<string> line_Vec;
    stringstream linestream(line);
    string cell;
    bool share;
    bool twoFO;
    while (getline(linestream,cell,','))
    {
        line_Vec.push_back(cell);
    }

    if(line_Vec[4] == "y")
    {
        share = true;
    }else
    {
        share = false;
    }

    if(line_Vec[5] == "y")
    {
        twoFO = true;
    }else
    {
        twoFO = false;
    }

    
    Items.push_back(new Appetiser(line_Vec[1],stoi(line_Vec[3]),stof(line_Vec[2]),share,twoFO));
}

void Menu::addMainCourse(string line)
{
    vector<string> line_Vec;
    stringstream linestream(line);
    string cell;
    while (getline(linestream,cell,','))
    {
        line_Vec.push_back(cell);
    }
    Items.push_back(new MainCourse(line_Vec[1],stoi(line_Vec[3]),stof(line_Vec[2])));
}

void Menu::addBeverage(string line)
{
    vector<string> line_Vec;
    stringstream linestream(line);
    string cell;
    while (getline(linestream,cell,','))
    {
        line_Vec.push_back(cell);
    }
    Items.push_back(new Beverage(line_Vec[1],stoi(line_Vec[3]),stof(line_Vec[2]),stof(line_Vec[7]),stoi(line_Vec[6])));

}

void Menu::toString()
{
    cout << "----------------Appetisers----------------" << endl; //displays the menu as a string allowing for changes to the menu.csv
    cout << "(1) ";                                               //as long as it follows the existing format
    Items[0]->toString(false);
    for(int i = 1; i < Items.size(); i++)
    {
        if ((Items[i]->getItemType() == "MainCourse") && (Items[i-1]->getItemType() == "Appetiser")) //when the type changes to main courses display the header
        {
            cout << "----------------Main dishes----------------" << endl;
        }

        if ((Items[i]->getItemType() == "Beverage") && (Items[i-1]->getItemType() == "MainCourse"))
        {
            cout << "----------------Beverages----------------" << endl;
        }
        
        cout << "(" << to_string(i + 1) << ") ";
        Items[i]->toString(false);
        
    }
    cout << endl;
}
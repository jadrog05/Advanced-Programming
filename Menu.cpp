#include "Menu.h"

Menu::Menu(string filename)
{
    ifstream data(filename);
    string line;
    while(getline(data,line))
    {
        stringstream linestream(line);
        switch (char ItemType = line.at(0))
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
                cout << ItemType;
                break;
        }
    }
}

void Menu::addAppetiser(string line)
{
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
    
}
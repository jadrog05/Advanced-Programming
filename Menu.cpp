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


    if(line_Vec[4] == "t")
    {
        share = true;
    }else
    {
        share = false;
    }

    if(line_Vec[5] == "t")
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
    cout << "----------------Appetisers----------------" << endl;
    cout << "(1) Nachos: £4.99, 600 cal (shareable)" << endl;
    cout << "(2) Buffalo wings: £3.99, 450 cal (2-4-1)" << endl;
    cout << "(3) Garlic bread: £3.99, 500 cal (2-4-1)" << endl;
    cout << endl;
    cout << "----------------Main dishes----------------" << endl;
    cout << "(4) Burger: £9.99, 950 cal" << endl;
    cout << "(5) Mac & cheese: £7.99, 850 cal" << endl;
    cout << "(6) Fish & chips: £8.99, 1000 cal" << endl;
    cout << "(7) Chicken tikka masala: £6.99, 700 cal" << endl;
    cout << endl;
    cout << "----------------Beverages----------------" << endl;
    cout << "(8) Lager: £3.50, 200 cal (568ml, 4.5% abv)" << endl;
    cout << "(9) White wine: £4.00, 150 cal (175ml, 11.5% abv)" << endl;
    cout << "(10) Red wine: £4.00, 170 cal (175ml, 12.5% abv)" << endl;
    cout << "(11) Coke: £2.50, 140 cal (330ml)" << endl;
    cout << "(12) Water: £1.50, 0 cal (330ml)" << endl;
    cout << endl;
}
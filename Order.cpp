#include "Order.h"

Order::Order()
{
    
}

void Order::toString()
{
    cout << "===== Checkout =====" << endl;
    for(int i = 0; i < Items.size(); i++)
    {
        cout << "(" << to_string(i + 1) << ")";
        Items[i]->toString(false);
    }
    cout << "-------------" << endl;

    calculateTotal(false);

    cout << endl;
    cout << endl;

    cout << "Do you want to place your order?" << endl;
    cout << "Type 'y' to confirm, or 'n' to go back and modify it." << endl;

    string userCommand;
    getline(cin, userCommand);

    while (userCommand != "n" && userCommand != "y")
    {
        cout << "Please enter a 'y' or an 'n'!" << endl;
        getline(cin, userCommand);
    }

    if (userCommand == "y")
    {
        printReceipt();
        cout << "Receipt printed to: 'receipt.txt'!" << endl;
        exit(0);
    }
    else
    {
        cout << endl;
        cout << "Welcome back to the menu!" << endl;
        cout << "Enter a command: " << endl;
    }

    cout << endl;
}



void Order::add(Item* item)
{
    Items.push_back(item);
    cout << item->getName() << " added to order!" << endl;
}



void Order::remove(Item* item)
{
    bool complete = false;

    if (Items.size() > 0)
    {
        if (item->getName() == Items[0]->getName()) //edit
        {
            cout << Items[0]->getName() << " removed from order!" << endl;
            Items.erase(Items.begin());
            complete = true;
        }
        else
        {    
            for (int i = 1; i < Items.size(); i++)
            {
                if(complete == false)
                {
                    if (item->getName() == Items[i]->getName())
                    {
                    cout << item->getName() << " removed from order!" << endl;
                    Items.erase(Items.begin() + (i));
                    complete = true;
                    }   
                }        
            }
        }
        if (complete == false)
        {
        cout << "Invalid item number: no item removed!" << endl;
        }
    }
    else
    {
        cout << "There are no items in your order!" << endl;
    }
}



void Order::printReceipt()
{
    ofstream myFile("receipt.txt");
    myFile << "===== Checkout =====" << endl;
    for(int i = 0; i < Items.size(); i++)
    {
        Items[i]->toString(true);
    }
    myFile.close();
    myFile.open("receipt.txt", ios_base::app);
    myFile << "-------------" << endl;
    myFile.close();

    calculateTotal(true);
}

void Order::calculateTotal(bool toReceipt)
{
    float total = 0;
    float savings = 0;
    float temp = 0;
    int twoFOs =0;

    for(int i = 0; i < Items.size(); i++)
    {
        if (Items[i]->getName() == "Buffalo wings" || Items[i]->getName() == "Garlic bread")
        {
            if (temp > 0)
            {
                if (Items[i]->getPrice() < temp)
                {
                    temp = Items[i]->getPrice();
                }

                savings =+ temp;
                temp = 0;
            }
            else
            {
                temp =+ Items[i]->getPrice();
            }
            
        }
        total = total + Items[i]->getPrice();
    }

    total = total - savings;

    string total_text = std::to_string(total);
    string total_str = total_text.substr(0, total_text.find(".")+3);

    string savings_text = std::to_string(savings);
    string savings_str = savings_text.substr(0, savings_text.find(".")+3);

    if (toReceipt == false)
    {
        if (savings_str != "0.00")
        {
            cout << "2-4-1 discount applied! Savings: £" << savings_str << endl;
        }
        else
        {   
            cout << "Savings: £" << savings_str << endl;
        }
    
        cout << "Total: £" << total_str << endl;
    }
    else if (toReceipt)
    {
        ofstream myFile;
        myFile.open("receipt.txt", ios_base::app);

        if (savings_str != "0.00")
        {
            myFile << "2-4-1 discount applied! Savings: £" << savings_str << endl;
        }
        else
        {   
            myFile << "Savings: £" << savings_str << endl;
        }
    
        myFile << "Total: £" << total_str << endl;
    }
}
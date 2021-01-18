#include "Order.h"

Order::Order(vector<Item*> menu_vec)
{
    Items = menu_vec;
}

void Order::toString()
{
    cout << "===== Checkout =====" << endl;
    for(int i = 0; i < order_vec.size(); i++)
    {
        cout << "(" << to_string(i + 1) << ")";
        order_vec[i]->toString(false);
    }
    cout << "-------------" << endl;

    calculateTotal(false);

    cout << endl;
    cout << endl;

    cout << "Do you want to place your order?" << endl;
    cout << "Type 'y' to confirm, or 'n' to go back and modify it." << endl;

    string userCommand;
    getline(cin, userCommand);

    while (userCommand != "n")
    {
        if (userCommand == "y")
        {
            printReceipt();
            userCommand = "n";
        }
        else
        {
            cout << "Please enter a 'y' or an 'n'!" << endl;
            getline(cin, userCommand);
        }
         
    }
    cout << endl;
}

void Order::add(int itemNumber)
{
    order_vec.push_back(Items[itemNumber - 1]);
    cout << Items[itemNumber - 1]->getName() << " added to order!" << endl;
}

void Order::remove(int itemNumber)
{
    bool complete = false;

    if (order_vec.size() > 0)
    {
        if (Items[itemNumber-1]->getName() == order_vec[0]->getName())
        {
            order_vec.erase(order_vec.begin());
        }
        else
        {    
            for (int i = 0; i < order_vec.size(); i++)
            {
                if(complete == false)
                {
                    if (Items[itemNumber-1]->getName() == order_vec[i]->getName())
                    {
                    cout << order_vec[i]->getName() << " removed from order!" << endl;
                    order_vec.erase(order_vec.begin() + (i));
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
    for(int i = 0; i < order_vec.size(); i++)
    {
        order_vec[i]->toString(true);
    }
    myFile.close();
    myFile.open("receipt.txt", ios_base::app);
    myFile << "-------------" << endl;
    myFile.close();

    calculateTotal(true);
    exit;
}

void Order::calculateTotal(bool toReceipt)
{
    float total = 0;
    float savings = 0;
    float temp = 0;
    int twoFOs =0;

    for(int i = 0; i < order_vec.size(); i++)
    {
        if (order_vec[i]->getName() == "Buffalo wings" || order_vec[i]->getName() == "Garlic bread")
        {
            if (temp > 0)
            {
                if (order_vec[i]->getPrice() < temp)
                {
                    temp = order_vec[i]->getPrice();
                }

                savings =+ temp;
                temp = 0;
            }
            else
            {
                temp =+ order_vec[i]->getPrice();
            }
            
        }
        total = total + order_vec[i]->getPrice();
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
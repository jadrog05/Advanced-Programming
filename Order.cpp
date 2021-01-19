#include "Order.h"

Order::Order()
{
    
}

void Order::toString() //called when user enters 'checkout' command. Dislpays checkout and gives user the option to
{                      //finish their order or modify it
    cout << "===== Checkout =====" << endl;
    for(int i = 0; i < Items.size(); i++) //displays each item in the order
    {
        cout << "(" << to_string(i + 1) << ")"; 
        Items[i]->toString(false); 
    }
    cout << "-------------" << endl;

    calculateTotal(false); //calls calculateTotal to work out and print total and savings

    cout << endl;
    cout << endl;

    cout << "Do you want to place your order?" << endl;
    cout << "Type 'y' to confirm, or 'n' to go back and modify it." << endl;

    string userCommand;
    getline(cin, userCommand);

    while (userCommand != "n" && userCommand != "y") //error handling. only continues when user enters either 'y' or 'n'
    {
        cout << "Please enter a 'y' or an 'n'!" << endl;
        getline(cin, userCommand);
    }

    if (userCommand == "y")
    {
        printReceipt();
        cout << "Receipt printed to: 'receipt.txt'!" << endl;
        exit(0); //ends program cleanly
    }
    else
    {
        cout << endl;
        cout << "Welcome back to the menu!" << endl;
        cout << "Enter a command: " << endl;
    }

    cout << endl;
}



void Order::add(Item* item) //takes item from input and adds it to the order Itemlist
{
    Items.push_back(item); 
    cout << item->getName() << " added to order!" << endl;
}



void Order::remove(Item* item)
{
    bool complete = false; //to track if an item has been removed to prevent duplicate removal

    if (Items.size() > 0) //only goes forward if there is actually items in the order
    {

        for (int i = 0; i < Items.size(); i++) //finds the item in the order and removes it
        {
            if(complete == false) //if an item has already been removed it wont remove any more
            {
                if (item->getName() == Items[i]->getName())
                {
                    cout << item->getName() << " removed from order!" << endl;
                    Items.erase(Items.begin() + (i));
                    complete = true;
                }   
            }        
        }
        
        if (complete == false) //if no items were removed
        {
        cout << "Invalid item number: no item removed!" << endl;
        }
    }
    else //if the order was empty
    {
        cout << "There are no items in your order!" << endl;
    }
}



void Order::printReceipt() //prints the checkout dialog to a .txt file
{
    ofstream myFile("receipt.txt"); //creates file if there isnt one already or overwrites the existing one if it does
    myFile << "===== Checkout =====" << endl;
    for(int i = 0; i < Items.size(); i++)
    {
        Items[i]->toString(true); //passes true to tell the item.toString method to output to the txt file instead of cout
    }
    myFile.close();
    myFile.open("receipt.txt", ios_base::app); //close and reopen the file into append mode so the rest isnt overwritten
    myFile << "-------------" << endl;
    myFile.close(); 

    calculateTotal(true); //appends the total and savings part to the file as true is the parameter.
}

void Order::calculateTotal(bool toReceipt) //calculates total and any savings from 2-4-1 deals
{
    float total = 0;
    float savings = 0;
    float temp = 0;
    int twoFOs =0;

    for(int i = 0; i < Items.size(); i++)//I couldnt find a way to call the Item.getTwoForOne() method without causing an error so
    {                                    //as Items[i] could be any type of item so I had to use the names.   
        if (Items[i]->getName() == "Buffalo wings" || Items[i]->getName() == "Garlic bread")
        {
            if (temp > 0)
            {
                if (Items[i]->getPrice() < temp) //detects the 2-4-1 deals in pairs in the same order as they appear in the order
                {                          
                    temp = Items[i]->getPrice();
                }

                savings = savings + temp;
                temp = 0; //if 2-4-1 is found, adds price to temp, if another 2-4-1 is found temp = lowest price of the two
            }             //then temp is added to savings and temp set to 0
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

    if (toReceipt == false) //either outputs the result to terminal or to receipt.txt depending on parameter
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
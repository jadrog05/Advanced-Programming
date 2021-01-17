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
        order_vec[i]->toString();
    }
    cout << "-------------" << endl;

    calculateTotal();

}

void Order::add(int itemNumber)
{
    order_vec.push_back(Items[itemNumber - 1]);
    cout << Items[itemNumber - 1]->getName() << " added to order!" << endl;
}

void Order::remove(int itemNumber)
{
    bool complete = false;

    for (int i = 0; i < order_vec.size(); i++)
    {
        if(complete == false)
        {
            if (Items[itemNumber-1]->getName() == order_vec[i]->getName())
            {
                order_vec.erase(order_vec.begin() + (i-1));
                complete = true;
            }
        }        
    }
}

void Order::printReceipt()
{

}

void Order::calculateTotal()
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
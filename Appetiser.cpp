#include "Appetiser.h" 

Appetiser::Appetiser(string na, int cal, float pri, bool share, bool twoFO) : Item(na, cal, pri)
{
    shareable = share;
    twoForOne = twoFO;
    type = "Appetiser";
}

void Appetiser::toString(bool toReceipt) //outputs the items data in a line to either terminal or to receipt.txt
{                                        //same for all item.tostring methods

    string menuOutput;
    menuOutput.append(name);
    menuOutput.append(": £");
    string num_text = std::to_string(price);
    string pr_2dec = num_text.substr(0, num_text.find(".")+3);
    menuOutput.append(pr_2dec);
    menuOutput.append(", ");
    menuOutput.append(to_string(calories));
    menuOutput.append(" cal");
    if (shareable)
    {
        menuOutput.append(" (shareable)");
    }
    if (twoForOne)
    {
        menuOutput.append(" (2-4-1)");
    }

    if (toReceipt == true)
    {
        ofstream myFile;
        myFile.open("receipt.txt", ios_base::app);
        myFile << menuOutput << endl;
        myFile.close();
    }
    else if (toReceipt == false)
    {
        cout << menuOutput << endl;
    }
}

bool Appetiser::isShareable()
{
    return shareable;
}

bool Appetiser::isTwoForOne()
{
    return twoForOne;
}

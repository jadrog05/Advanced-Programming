#include "Appetiser.h" 

Appetiser::Appetiser(string na, int cal, float pri, bool share, bool twoFO) : Item(na, cal, pri)
{
    shareable = share;
    twoForOne = twoFO;
    type = "Appetiser";
}

void Appetiser::toString()
{

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
    cout << menuOutput << endl;
}


#include "Beverage.h"  
	
Beverage::Beverage(string na, int cal, float pri, float AlcBV, int vol) : Item(na, cal, pri)
{
	abv = AlcBV;
    volume = vol;
    type = "Beverage";
}

float Beverage::getAbv()
{
    return abv;
}

int Beverage::getVolume()
{
    return volume;
}

void Beverage::toString()
{
    
    string menuOutput;
    menuOutput.append(name);
    menuOutput.append(": £");
    string num_text = std::to_string(price);
    string pr_2dec = num_text.substr(0, num_text.find(".")+3);
    menuOutput.append(pr_2dec);
    menuOutput.append(", ");
    menuOutput.append(to_string(calories));
    menuOutput.append(" cal (");
    menuOutput.append(to_string(volume));
    menuOutput.append("ml, ");
    num_text = std::to_string(abv);
    string ABV_2dec = num_text.substr(0, num_text.find(".")+3);
    menuOutput.append(ABV_2dec);
    menuOutput.append("% ABV)");
    cout << menuOutput << endl;
}	

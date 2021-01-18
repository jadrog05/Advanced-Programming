#include "MainCourse.h"  
	
MainCourse::MainCourse(string na, int cal, float pri) : Item(na, cal, pri)
{
	type = "MainCourse";
}

void MainCourse::toString(bool toReceipt)
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
	
MainCourse::~MainCourse()
{
	
}
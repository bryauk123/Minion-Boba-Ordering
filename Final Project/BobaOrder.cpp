#include <iostream>
#include <string>
#include "BobaOrder.h"
#include "DeliveryOrder.h"
using namespace std;

/*BobaOrder::BobaOrder(string name, string s1,string s2, int m, int d, int y, string pn, double mile, string shopName)
{   
    customerName = name;
    streetAddress1 = s1;
    streetAddress2 = s2;
    month = m;
    day = d;
    year = y;
    phoneNumber = pn;
    miles = mile;
    this->shopName = shopName;
    drinkCount = 0;
}*/
BobaOrder::BobaOrder(string customerName, string streetAddress1, string streetAddress2,int month, int day, int year,
string phoneNumber,double miles,string shopName):DeliveryOrder(customerName,streetAddress1,streetAddress2,month,day,year,phoneNumber,miles)
{
    this->shopName = shopName;
    drinkCount = 0;
}

BobaOrder::~BobaOrder()
{
    cout<<"BobaOrder Destroyed.\n";
}

void BobaOrder::printReceipt() const
{
    DeliveryOrder::printReceipt();
    cout << "\tOrdered Drinks: " << drinkCount << endl;
}

double BobaOrder::discount()
{
    if (drinkCount > 10)
    {
        return 0.8;
    }
    else if(drinkCount > 5)
    {
        return 0.9;
    }
    else if(drinkCount > 2)
    {
        return 0.95;
    }
    else if(drinkCount <= 2)
    {
        return 1;
    }
    return 0;
}

void BobaOrder::addDrink(string drinkName, bool boba, int count)
{  
    InvalidInput InvalidInput(drinkName);
    if(drinkName == "Matcha Lemonade" && boba == true)
    {
        totalBalance += (5.5 + 0.5) * count;
        drinkCount += count;
    }
    else if(drinkName == "Matcha Lemonade" && boba == false)
    {
        totalBalance += 5.5 * count;
        drinkCount += count;
    }
    if(drinkName == "Brown Sugar Oolong Tea" && boba == true)
    {
        totalBalance += (5 + 0.5) * count;
        drinkCount += count;
    }
    else if(drinkName == "Brown Sugar Oolong Tea" && boba == false)
    {
        totalBalance += 5 * count;
        drinkCount += count;
    }
    if(drinkName == "Lemon Green Tea" && boba == true)
    {
        totalBalance += (5.25 + 0.5) * count;
        drinkCount += count;
    }
    else if(drinkName == "Lemon Green Tea" && boba == false)
    {
        totalBalance += 5.25 * count;
        drinkCount += count;
    }
    if(drinkName != "Matcha Lemonade" && drinkName != "Brown Sugar Oolong Tea" && drinkName != "Lemon Green Tea")
    {
       InvalidInput.reason();
       cout<<"Not Serving requested drinks. Drink order ignored.\n\n";
    }
    
}

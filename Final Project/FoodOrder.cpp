#include "DeliveryOrder.h"
#include "FoodOrder.h"
#include <string>
#include <iostream>
using namespace std;

FoodOrder::FoodOrder(string customerName, string streetAddress1,string streetAddress2, int month, int day, int year, string phoneNumber, double miles, string restaurantName):
DeliveryOrder(customerName,streetAddress1,streetAddress2,month,day,year,phoneNumber,miles)
{
    this->restaurantName = restaurantName;
}

FoodOrder::~FoodOrder()
{
    cout<<"FoodOrder Destroyed.\n";
}
//Overrides printReceipt function and calls from DeliveryOrder
void FoodOrder::printReceipt() const
{
    DeliveryOrder::printReceipt();
    cout << "\tOrdered Foods: " << foodCount << endl;
}
//overrides discount
double FoodOrder::discount()
{
    if (totalBalance > 50)
    {
        return 0.8;
    }
    else if(totalBalance > 30)
    {
        return 0.9;
    }
    else if(totalBalance > 20)
    {
        return 0.95;
    }
    else if(totalBalance <= 20)
    {
        return 1;
    }
    return 0;
}

void FoodOrder::addFood(string meatName, int sides = 0, bool soup = false)
{
    InvalidInput InvalidInput(meatName);
    if(meatName == "Bone-in Ribeye" && soup == true)
    {
        totalBalance += ((32 + 0.5) + (1 * sides));
        foodCount++;
    }
    else if(meatName == "Bone-in Ribeye" && soup == false)
    {
        totalBalance += (32 + (1 * sides));
        foodCount++;
    }
    if(meatName == "Rack of Lamb" && soup == true)
    {
        totalBalance += ((28 + 0.5) + (1 * sides));
        foodCount++;
    }
    else if(meatName == "Rack of Lamb" && soup == false)
    {
        totalBalance += (28 + (1 * sides));
        foodCount++;
    }
    if(meatName == "Grilled Salmon" && soup == true)
    {
        totalBalance += ((24 + 0.5) + (1 * sides));
        foodCount++;
    }
    else if(meatName == "Grilled Salmon" && soup == false)
    {
        totalBalance += (24 + (1 *  sides));
        foodCount++;
    }
    if(meatName == "Beyond Meat Burger" && soup == true)
    {
        totalBalance += ((22 + 0.5) + (1 * sides));
        foodCount++;
    }
    else if(meatName == "Beyond Meat Burger" && soup == false)
    {
        totalBalance += (22 + (1 * sides));
        foodCount++;
    }
    if(meatName != "Bone-in Ribeye" && meatName != "Rack of Lamb" && meatName != "Grilled Salmon" && meatName != "Beyond Meat Burger")
    {
        InvalidInput.reason();
        cout<<"Not serving requested food. Food order ignored.\n\n";
    }
    
}
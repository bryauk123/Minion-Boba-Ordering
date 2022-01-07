#include "DeliveryOrder.h"
#include <iostream>
#include <string>
using namespace std;
//initializes order count to 0 by default
int DeliveryOrder::orderCount;
//default constructor
DeliveryOrder::DeliveryOrder()
{
    customerName = "Default";
    streetAddress1 = "Default";
    streetAddress2 = "Default";
    month = 1;
    day = 1;
    year = 1;
    phoneNumber = "000-000-000";
    orderCount++;
    totalBalance = 0;
}
//constructor for DeliveryOrder class
DeliveryOrder::DeliveryOrder(string customerName,string streetAddress1,string streetAddress2,int month, int day, int year, string phoneNumber, double miles)
{
    this->customerName = customerName;
    this->streetAddress1 = streetAddress1;
    this->streetAddress2 = streetAddress2;
    this->month = month;
    this->day = day;
    this->year = year;
    this->phoneNumber = phoneNumber;
    this->miles = miles;
    totalBalance = 0;
    orderCount++;//increases every time a new order is created
}
DeliveryOrder::~DeliveryOrder()
{
    cout<<"DeliveryOrder Destroyed.\n";
}
void DeliveryOrder::printReceipt() const
{
    cout << "Order Detail:" << "\n";
    cout << "\t" << customerName << "\n";
    cout << "\t" << streetAddress1 << "\n";
    cout << "\t" << streetAddress2 << "\n";
    cout << "\tDate: " << month << "/" << day << "/" << year << "\n";
    cout << "\tPhone: " << phoneNumber << "\n";
    cout << "\tTotal Balance: $" << totalBalance << endl;
}

double DeliveryOrder:: getBalance() const
{
    return totalBalance * (1 + taxRate) + miles * deliveryRate;
}

int DeliveryOrder:: getOrderCount()
{
    return orderCount;
}



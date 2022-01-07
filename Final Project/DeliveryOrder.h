//Header file for Delivery Order Class
//Abstract Class
#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

#include <string>
#include <iostream>
using namespace std;

class DeliveryOrder
{
    private:
            string customerName;
            string streetAddress1;
            string streetAddress2;
            int month;
            int day;
            int year;
            string phoneNumber;
            double miles;
            static int orderCount;
    public:
            //Default Construtor
            DeliveryOrder();
            //Constructor
            DeliveryOrder(string ,string , string ,int ,int , int ,string ,double);
            //Destructor
            ~DeliveryOrder();
            void printReceipt() const;
            //getters
            double getBalance() const;
            static int getOrderCount();
            //pure virtual function
            virtual double discount() = 0;
            double totalBalance;
            static constexpr double taxRate = 0.0887;
            static constexpr double deliveryRate = 0.5;

};

#endif
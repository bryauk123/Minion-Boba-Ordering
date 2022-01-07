//Header File for BobaOrder class
#include <iostream>
#ifndef BOBAORDER_H
#define BOBAORDER_H
#include <string>
#include "DeliveryOrder.h"
using namespace std;

class InvalidInput: public exception
{
    public:
            InvalidInput(string s) : message()
            {
                message = "Invalid input <" + s + ">.";
            }
            void reason() const
            {
                cout<<message<<endl;
            }
    private:
            string message;
               
};

class BobaOrder : public DeliveryOrder
{
        public:      
                //Constructor
                BobaOrder(string, string, string, int, int, int, string , double, string);
                
                //Destructor
                ~BobaOrder();
                void printReceipt() const;
                double discount();
                void addDrink(string drinkName, bool boba, int count);
        private:
                string shopName;
                int drinkCount = 0;
};

#endif
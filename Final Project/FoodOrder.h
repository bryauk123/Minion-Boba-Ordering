//Header File for FoodOrder Class
#include <iostream>
#include <string>
#include "DeliveryOrder.h"
#include "BobaOrder.h"
#ifndef FOODORDER_H
#define FOODORDER_H
using namespace std;

class FoodOrder : public DeliveryOrder
{
    public:   
            //Constructor
            FoodOrder(string,string ,string, int , int, int, string, double, string);
            //Destructor
            ~FoodOrder();
            void printReceipt() const;
            double discount();
            void addFood(string meatName, int sides, bool soup);
    private:
            string restaurantName;
            int foodCount = 0;

};


#endif
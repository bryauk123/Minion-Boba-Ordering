#include "Account.h"
#include "FoodOrder.h"
#include "BobaOrder.h"
#include "DeliveryOrder.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


double applyDiscount(DeliveryOrder* order,const Account& account)
{
    double discountedBalance = order->getBalance();
    if(account.getStatus() == "Owner")
    {
        return discountedBalance * .1;
    }
    else if(account.getStatus() == "VIP")
    {
        return discountedBalance * order->discount();
    }
    else if(account.getStatus() == "")
    {
        return discountedBalance = order->getBalance();
    }
    return discountedBalance;
}

int main()
{
    cout<<fixed<<setprecision(2)<<endl;
    const Account Stuart("Stuart","Owner");
    Account Kevin("Kevin","VIP");
    Account Bob("Bob","");
    DeliveryOrder *orderPtr;

    cout<<"Kevin Placing Order.\n";
    BobaOrder Kevin1("Kevin","123 Flower Way","New York, NY 10014",11,2,2020,"123-456-0000",10.4,"Bar Pa Tea");

    try
    {
    Kevin1.addDrink("Matcha Lemonade",true,1);
    Kevin1.addDrink("Lemon Green Tea",false,1);
    Kevin1.addDrink("Brown Sugar Oolong Tea",false,2);
    Kevin1.addDrink("Iron Goddess",false,1);
    }
    catch (InvalidInput& input)
    {
        input.reason();
    }
    Kevin1.printReceipt();
    cout<<"Balance: $"<<Kevin1.getBalance()<<endl;
    orderPtr = &Kevin1;
    cout<<"Discounted Balance: $"<<applyDiscount(&Kevin1,Kevin)<<endl;
    cout<<"\n\n";

    cout<<"Stuart Placing Order.\n";
    FoodOrder Stuart2("Stuart","123 Flower Way","New York, NY 10014",11,2,2020,"123-456-1111",25.5,"Trauts Steak House");
    try
    {
    Stuart2.addFood("Bone-in Ribeye",2,true);
    Stuart2.addFood("Grilled Salmon",1,false);
    Stuart2.addFood("Beyond Meat Burger",3,true);
    }
    catch(InvalidInput& input)
    {
        input.reason();
    }
    Stuart2.printReceipt();
    cout<<"Balance: $"<<Stuart2.getBalance()<<endl;
    orderPtr = &Stuart2;
    cout<<"Discounted Balance: $"<<applyDiscount(&Stuart2,Stuart)<<endl;
    cout<<"\n\n";
    cout<<"Bob decided to log into his account and see whether he can afford ordering the same order as Stuart.\n";
    Stuart2.printReceipt();
    cout<<"Balance: $"<<Stuart2.getBalance()<<endl;
    cout<<"Discounted Balance: $"<<applyDiscount(&Stuart2,Bob)<<endl;
    cout<<"Bob upset, cancelling order :(\n\n";
    cout<<"Total order placed: "<<DeliveryOrder::getOrderCount()<<"\n\n"<<endl;

    return 0;
}
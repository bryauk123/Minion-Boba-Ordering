#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class Account
{
    private:
            string userName;
            string status;
    public:
            //Constructor
            Account(string userName, string status = "");
            //Destructor
            ~Account();
            //Getter
            string getStatus() const;

};


#endif
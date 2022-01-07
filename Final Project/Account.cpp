#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

Account::Account(string userName, string status)
{
    this->userName = userName;
    this->status = status;
}

Account::~Account()
{
    cout<<"Account Removed.\n";
}

string Account::getStatus() const
{
    return status;
}
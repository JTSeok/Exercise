#include "Account.h"
#include "BankingCommonDecl.h"

Account::Account(int id, int money, char* name) : accID(id), balance(money)
{
    cusName = new char[strlen(name) + 1];
    strcpy(cusName, name);
}

Account::Account(const Account& ref) : accID(ref.accID), balance(ref.balance)
{
    cusName = new char[strlen(ref.cusName) + 1];
    strcpy(cusName, ref.cusName);
}

int Account::getAccID() const { return accID; }

void Account::deposit(int money)
{
    balance += money;
}

int Account::withdraw(int money)
{
    if (balance < money)
        return 0;

    balance -= money;
    return money;
}

void Account::showAccInfo() const
{
    using namespace std;
    cout << "°èÁÂID     : " << accID << endl;
    cout << "Name       : " << cusName << endl;
    cout << "Balance    : " << balance << endl;
}

Account::~Account()
{
    delete[] cusName;
}
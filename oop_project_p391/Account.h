/*
 * 파일이름 : Account
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
    int accID;
    int balance;
    char* cusName;

public:
    Account(int ID, int money, char* name);
    Account(const Account& ref);

    int getAccID() const;
    virtual void deposit(int money);
    int withdraw(int money);
    void showAccInfo() const;

    ~Account();
};
#endif
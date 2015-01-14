#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account
{
private:
    int interRate;      // 이자율

public:
    NormalAccount(int id, int money, char* name, int rate)
        : Account(id, money, name), interRate(rate)
    {}

    virtual void deposit(int money)
    {
        Account::deposit(money);                        // 원금 추가
        Account::deposit(money * (interRate / 100.0));  // 이자 추가
    }
};
#endif
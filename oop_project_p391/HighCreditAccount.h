#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
    int specialRate;

public:
    HighCreditAccount(int id, int money, char* name, int rate, int special)
        : NormalAccount(id, money, name, rate), specialRate(special)
    {}

    virtual void diposit(int money)
    {
        NormalAccount::deposit(money);       // 원금과 이자 추가
        Account::deposit(money * (specialRate / 100.0));  // 특별 이자 추가
    }
};
#endif
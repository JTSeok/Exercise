#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

class AccountHandler
{
private:
    Account* accArr[100];
    int accNum;

public:
    AccountHandler();
    
    void showMenu(void) const;
    void makeAccount(void);
    void depositMoney(void);
    void withrawMoney(void);
    void showAllAccInfo(void) const;

    ~AccountHandler();

protected:
    void makeNormalAccount(void);
    void makeSpecialAccount(void);
};
#endif
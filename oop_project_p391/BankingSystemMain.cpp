#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void)
{
    AccountHandler manager;
    int choice;

    while (1)
    {
        manager.showMenu();
        cout << "¼±ÅÃ : "; cin >> choice;
        cout << endl;

        switch (choice)
        {
        case MAKE:
            manager.makeAccount(); break;
        case DEPOSIT:
            manager.depositMoney(); break;
        case WITHDRAW:
            manager.withrawMoney(); break;
        case INQUIRE:
            manager.showAllAccInfo(); break;
        case EXIT:
            return 0;
        default:
            cout << "illegal selection.." << endl;
        }
    }
    return 0;
}
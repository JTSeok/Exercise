#pragma once

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::showMenu(void) const
{
    cout << "-----MENU-----" << endl;
    cout << "1. ���°���" << endl;
    cout << "2. �Ա�" << endl;
    cout << "3. ���" << endl;
    cout << "4. �������� ���" << endl;
    cout << "5. ����" << endl;
}

void AccountHandler::makeAccount(void)
{
    int sel;
    cout << "-- ���� ���� ���� --" << endl;
    cout << "1. ���뿹�ݰ���" << endl;
    cout << "2. �ſ�ŷڰ���" << endl;
    cout << "���� : ";
    cin >> sel;

    if (sel == NORMAL)
        makeNormalAccount();
    else
        makeSpecialAccount();
}

void AccountHandler::makeNormalAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;

    cout << "-- ���뿹�ݰ��� ���� --" << endl;
    cout << "����ID : "; cin >> id;
    cout << "�̸� : "; cin >> name;
    cout << "�Աݾ� : "; cin >> balance;
    cout << "������ : "; cin >> interRate;
    cout << endl;

    accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::makeSpecialAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;
    int creditLevel;

    cout << "-- �ſ�ŷڰ��� ���� --" << endl;
    cout << "����ID : "; cin >> id;
    cout << "�̸� : "; cin >> name;
    cout << "�Աݾ� : "; cin >> balance;
    cout << "������ : "; cin >> interRate;
    cout << "�ſ���(1toA, 2toB, 3toC) : "; cin >> creditLevel;
    cout << endl;

    switch (creditLevel)
    {
    case 1:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A); break;
    case 2:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B); break;
    case 3:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C); break;
    }
}

void AccountHandler::depositMoney(void)
{
    int money;
    int id;

    cout << "-- �Ա� --" << endl;
    cout << "����ID: "; cin >> id;
    cout << "�Աݾ�: "; cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->getAccID() == id) {
            accArr[i]->deposit(money);
            cout << "�ԱݿϷ�" << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void AccountHandler::withrawMoney(void)
{
    int money;
    int id;

    cout << "-- ��� --" << endl;
    cout << "����ID: "; cin >> id;
    cout << "��ݾ�: "; cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->getAccID() == id) {
            if (accArr[i]->withdraw(money) == 0) {
                cout << "�ܾ׺���" << endl << endl;
                return;
            }                
            cout << "��ݿϷ�" << endl;
            return;
        }
    }
    cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void AccountHandler::showAllAccInfo(void) const
{
    for (int i = 0; i < accNum; i++) {
        accArr[i]->showAccInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler()
{
    for (int i = 0; i < accNum; i++)
        delete accArr[i];
}
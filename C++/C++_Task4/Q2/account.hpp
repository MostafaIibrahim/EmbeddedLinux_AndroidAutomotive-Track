#ifndef _ACCOUNT_H__
#define _ACCOUNT_H__


class Account{
    static int m_noOFAccounts;
    static int m_totalAmount;
    static int m_totalNbDeposits;
    static int m_totalNbWithdrawals;
    int m_accountIndex;
    int m_amount;
    int m_noOfDeposits;
    int m_noOfWithdrawals;

    static void m_displayTimestamp(void);
    public:
        Account(void) = default;
        Account(int intital_deposite);
        ~Account() = default;
        static int getNoOfAccounts(void);
        static int getTotalAmount(void);
        static int getNbDeposits(void);
        static int getNoOfWithdrawals(void);
        static void displayAccountInfo(void);
        void makeDeposite(int deposite);
        bool makeWithdrawal(int withdrawal);
        int checkAmount(void) const;
        void displayStatus(void) const;
};



#endif 
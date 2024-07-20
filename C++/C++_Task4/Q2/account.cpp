#include<iostream>
#include "account.hpp"
#include<ctime>
#include<iomanip>
int Account::m_noOFAccounts = 0 ; 
int Account::m_totalAmount = 0 ;
int Account::m_totalNbDeposits = 0 ;
int Account::m_totalNbWithdrawals =  0 ;
void Account::m_displayTimestamp(void)
{
        // Get the current time
    std::time_t currentTime = std::time(nullptr);

    // Convert to local time
    std::tm* localTime = std::localtime(&currentTime);

    // Print time in desired format
    // Example: YYYY-MM-DD HH:MM:SS
    std::cout << "Current time: "
              << std::put_time(localTime, "%Y-%m-%d %H:%M:%S") << std::endl;
}
Account::Account(int intital_deposite)
{
    m_totalAmount += intital_deposite;
    m_amount = intital_deposite;
    m_noOFAccounts++;
    m_totalNbDeposits++;
    m_noOfDeposits++;
}

int Account::getNoOfAccounts(void)
{
    return m_noOFAccounts;
}

int Account::getTotalAmount(void)
{
    return m_totalAmount;
}

int Account::getNbDeposits(void)
{
    return m_totalNbDeposits;
}

int Account::getNoOfWithdrawals(void)
{
    return m_totalNbWithdrawals;
}

void Account::displayAccountInfo(void)
{
    m_displayTimestamp();
    std::cout << "The Number of Accounts= " << getNoOfAccounts() << '\n'
              << "The total Number of Deposits= " << getNbDeposits() << '\n'
              << "The total amount of Withdarawals= " << getNoOfWithdrawals()<<'\n'
              << "The total amount of all accounts= " << getTotalAmount() << std::endl;   
}

void Account::makeDeposite(int deposite)
{
    m_amount = deposite ; 
    m_noOfDeposits++;
    m_totalNbDeposits += m_noOfDeposits;
    m_totalAmount += m_amount;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if(withdrawal < m_totalAmount){
        return false;
    }
    m_totalAmount -= withdrawal ;
    m_totalNbWithdrawals++;
    return true;
}

int Account::checkAmount(void) const
{
    return  m_amount;
}

void Account::displayStatus(void) const
{
    displayAccountInfo();
}

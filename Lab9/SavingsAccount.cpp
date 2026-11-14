#include <iostream>
#include <numeric>
#include "SavingsAccount.h"

/**
* @file SavingsAccount.cpp
* @brief Implrments the SavingsAccount class.
* @author Richie
* @date 2026-11-12
*/

using namespace std;

/**
*@brief Creates a Savings Account and initializes its interest rate.
@param accNum The account number for the savings account.
@param initialBalance The starting account balance.
@param customer The customer who owns the account.
@param interestRate The daily interest rate for the savings account.
@return None
*/
SavingsAccount::SavingsAccount(const string& accNum, double initialBalance, const Customer& customer, double interestRate)
	: Account(accNum, initialBalance, customer), dailyInterestRate(interestRate)
{
}

/**
*@brief Processes daily transactions and applies interest to the balance.
*@return None
*/
void SavingsAccount::closeOfBusiness()
{
	double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
	double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);
	
	double previousBalance = balance;
	double newBalance = previousBalance + totalDeposits - totalWithdrawals;

	if (newBalance >= 0)
	{
		newBalance = newBalance + (newBalance * dailyInterestRate);
	}

	printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

	balance = newBalance;

	deposits.clear();
	withdrawals.clear();

	
}
/**
@brief Prints the account information and daily interest rate.
@return None
*/
void SavingsAccount::printAccountInfo() const
	{
		Account::printAccountInfo();
		cout << "Daily Interest Rate: " << dailyInterestRate * 100 << "%" << endl;
	}
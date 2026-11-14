
/**
* @file SavingsAccount.h
* @brief Declares the SavingsAccount class.
* @author Richie
* @date 2026-11-12
*/
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account 
{
private:
	double dailyInterestRate; 


public:


	/*
	* @brief Creates a savings account with an interest rate.
	* @param accNum The account number.
	* @param initialBalance The starting balance of the account.
	* @param customer The customer who owns the account.
	* @param InterestRate The daily interest rate for the account.
	* @return None
	*/
	SavingsAccount(const string& accNum, double initialBalance, const Customer& customer, double InterestRate);

	/*
	* @brief Processes daily transactions and applies interest to the balance.
	* @return None
	*/
	void closeOfBusiness() override;

	/*
	* @brief Displays account information, including the daily interest rate.
	* @return None
	*/
	void printAccountInfo() const override;
	
};

#endif

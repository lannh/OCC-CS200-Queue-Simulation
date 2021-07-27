/*
		L&N Lightbot
		Nguyen, Lan (11:10)

		Date April 30, 2020

		CS A250
		Project 1 - Part A
*/

#include "ServerType.h"

#include <iostream>

using namespace std;

	//setBusy
void ServerType::setBusy()
{
	status = "busy";
}

	//setFree
void ServerType::setFree()
{
	status = "free";
}

	//setTransactionTime
void ServerType::setTransactionTime(int t)
{
	transactionTime = t;
}

	//setTransactionTime
void ServerType::setTransactionTime()
{
	transactionTime = currentCustomer.getTransactionTime();
}

	//setCurrentCustomer
void ServerType::setCurrentCustomer(const CustomerType& theCurrentCustomer)
{
	/*********************************************************************************
		your code here...			
	*********************************************************************************/
	currentCustomer.setCustomerInfo(theCurrentCustomer.getCustomerNumber(),
		theCurrentCustomer.getArrivalTime(), 
		theCurrentCustomer.getWaitingTime(),
		theCurrentCustomer.getTransactionTime());
}

	//getCurrentCustomerNumber
int ServerType::getCurrentCustomerNumber() const
{
	/*********************************************************************************
		your code here...			
	*********************************************************************************/
	return currentCustomer.getCustomerNumber();
}

	//getCurrentCustomerArrivalTime
int ServerType::getCurrentCustomerArrivalTime() const
{
	/*********************************************************************************
		your code here...
			
			return -1;
	*********************************************************************************/
	return currentCustomer.getArrivalTime();
}

	//getCurrentCustomerWaitingTime
int ServerType::getCurrentCustomerWaitingTime() const
{
	/*********************************************************************************
		your code here...			
	*********************************************************************************/
	return currentCustomer.getWaitingTime();
}

	//getCurrentCustomerTransactionTime
int ServerType::getCurrentCustomerTransactionTime() const
{
	/*********************************************************************************
		your code here...			
	*********************************************************************************/
	return currentCustomer.getTransactionTime();
}

	//getRemainingTransactionTime
int ServerType::getRemainingTransactionTime() const
{
	/*********************************************************************************
		your code here...
	*********************************************************************************/
	return transactionTime;
}

	//decreaseTransactionTime
void ServerType::decreaseTransactionTime()
{
	transactionTime--;
}

	//isFree
bool ServerType::isFree() const
{
	return (status == "free");
}

	//destructor
ServerType::~ServerType()
{}
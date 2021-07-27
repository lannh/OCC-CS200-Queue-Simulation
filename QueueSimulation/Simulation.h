/*
		L&N Lightbot
		Nguyen, Lan (11:10)

		Date April 30, 2020

		CS A250
		Project 1 - Part A
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include "ServerList.h"
#include <queue>

void setSimulationParameters(int& simulationTime, int& numOfServers,
	int& transactionTime,
	double& timeBetweenCustomerArrival);

bool isCustomerArrived(double arrivalTimeDifference);

void generateStatistics(ServerList& serverList,
	std::queue<CustomerType>& customerQueue,
	int numOfCustomersArrived,
	int waitTimeServedCustomers);

void runSimulation();

void updateCustQueue(std::queue<CustomerType>& customerQueue);

#endif SIMULATION_H
/*
		L&N Lightbot
		Nguyen, Lan (11:10)

		Date April 30, 2020

		CS A250
		Project 1 - Part A
*/

#include "Simulation.h"

#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

void runSimulation()
{

	/*********************************************************************************
		your code here...
	*********************************************************************************/
	int simulationTime = 0;
	int numOfServers = 0;
	int transactionTime = 0;
	double timeBetweenCustomerArrival = 0;
	setSimulationParameters(simulationTime, numOfServers,
		transactionTime, timeBetweenCustomerArrival);

	int customerNumber = 0;
	int numOfCustomersArrived = 0;
	int numOfCustomersWaiting = 0;
	int waitTimeServedCustomers = 0;
	queue<CustomerType> customersQueue;
	
	ServerList serversList(numOfServers);

	for (int clock = 1; clock <= simulationTime; ++clock)
	{
		serversList.updateServers();

		if (!customersQueue.empty())
			updateCustQueue(customersQueue);

		if (isCustomerArrived(timeBetweenCustomerArrival))
		{
			++numOfCustomersArrived;
			++numOfCustomersWaiting;
			CustomerType newCustomer(numOfCustomersArrived, clock, 0, transactionTime);
			customersQueue.push(newCustomer);
			cout << "Customer number " << numOfCustomersArrived
				<< " arrived at time unit " << clock << endl;
		}

		if (!customersQueue.empty())
		{
			int freeServerID = serversList.getFreeServerID();
			if (freeServerID != -1)
			{
				serversList.setServerBusy(freeServerID, customersQueue.front());
				waitTimeServedCustomers += customersQueue.front().getWaitingTime();
				customersQueue.pop();
			}
		}
	}

	cout << "\nSimulation ran for " << simulationTime
		<< " time units\n";
	cout << "Number of servers: " << numOfServers << endl;
	cout << "Average transaction time: " << transactionTime << endl;
	cout << "Average arrival time difference between customers: "
		<< timeBetweenCustomerArrival << endl;

	generateStatistics(serversList, customersQueue, 
		numOfCustomersArrived, waitTimeServedCustomers);
}

void setSimulationParameters(int& simulationTime, int& numOfServers,
	int& transactionTime,
	double& timeBetweenCustomerArrival)
{
	cout << "Enter the simulation time: " << flush;
	cin >> simulationTime;
	cout << endl;

	cout << "Enter the number of servers: " << flush;
	cin >> numOfServers;
	cout << endl;

	cout << "Enter the transaction time: " << flush;
	cin >> transactionTime;
	cout << endl;

	cout << "Enter the time between customer arrivals: " << flush;
	cin >> timeBetweenCustomerArrival;
	cout << endl;
}

bool isCustomerArrived(double arrivalTimeDifference)
{
	double value = 0.0;

	value = static_cast<double> (rand()) / static_cast<double>(RAND_MAX);

	return (value > exp(-1.0 / arrivalTimeDifference));
}


void generateStatistics(ServerList& serverList,
	queue<CustomerType>& customerQueue,
	int numOfCustomersArrived,
	int waitTimeServedCustomers)
{
	int customersLeftInQueue = 0;

	int totalWaitTime = waitTimeServedCustomers;

	CustomerType customer;

	while (!customerQueue.empty())
	{
		customer = customerQueue.front();
		customerQueue.pop();
		totalWaitTime = totalWaitTime + customer.getWaitingTime();
		customersLeftInQueue++;
	}

	//Find number of customers left in servers
	int customersLeftInServers = serverList.getNumberOfBusyServers();
	//Find number of customers completely served
	int numberOfCustomersServed = numOfCustomersArrived -
		customersLeftInServers -
		customersLeftInQueue;

	double averageWaitTime = 0;

	cout << "Total wait time: " << totalWaitTime << endl;
	cout << "Number of customers who completed a transaction: "
		<< numberOfCustomersServed << endl;
	cout << "Number of customers left in the servers: "
		<< customersLeftInServers << endl;
	cout << "Number of customers left in the queue: " << customersLeftInQueue
		<< endl;

	if (numOfCustomersArrived > 0)  // If number of customers arrived is > 0
		averageWaitTime = (static_cast<double>(totalWaitTime)) / numOfCustomersArrived;

	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << "Average wait time: " << averageWaitTime << endl;

	cout << "\n************** END SIMULATION *************" << endl;

}

void updateCustQueue(queue<CustomerType>& customerQueue)
{
	CustomerType customer;

	customer.setWaitingTime(-1);
	int wTime = 0;

	customerQueue.push(customer);

	while (wTime != -1)
	{
		customer = customerQueue.front();
		customerQueue.pop();
		wTime = customer.getWaitingTime();
		if (wTime != -1)
		{
			customer.incrementWaitingTime();
			customerQueue.push(customer);
		}
	}
}


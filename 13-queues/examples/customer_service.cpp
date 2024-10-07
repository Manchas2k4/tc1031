// =================================================================
//
// File: customer_service.cpp
// Author: Pedro Perez
// Description: This file contains a simulation of a waiting line at 
//				a bank. The goal is to determine how many tellers 
//				are needed to keep customer wait time under 4 
//				minutes. Assume that customers arrive on average 
//				every 15  seconds. Processing a request takes two 
//				minutes once a customer reaches a cashier.
//
// Source: https://www.csd.uwo.ca/courses/CS1027b/code.html
//
// Copyright (c) 2024 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================


#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>

using namespace std;

#define PROCESS			120
#define MIN_TIME		240
#define MAX_CASHIERS	10
#define MAX_CUSTOMERS	100

class Customer {
private:
	int arrivalTime, departureTime;

public:
	Customer();
	Customer(int);

	int getArrivalTime() const;
	int getDepartureTime() const;
	int getTotalTime() const;

	void setDepartureTime(int);
};

Customer::Customer() 
	: arrivalTime(0), departureTime(0) {}

Customer::Customer(int arrives) 
	: arrivalTime(arrives), departureTime(0) {}

int Customer::getArrivalTime() const {
	return arrivalTime;
}

int Customer::getDepartureTime() const {
	return departureTime;
}

int Customer::getTotalTime() const {
	return departureTime - arrivalTime;
}

void Customer::setDepartureTime(int departs) {
	departureTime = departs;
}

int main(int argc, char* argv[]) {
	Customer customer;
	queue<Customer> customerQueue;
	vector<int> cashierTime (MAX_CASHIERS);
	int totalTime, averageTime, departs, limit;

	limit = 1;
	do {
		for (int i = 0; i < limit; i++) {
			cashierTime [i] = 0;
		}

		for (int i = 1; i <= MAX_CUSTOMERS; i++) {
			customerQueue.push(Customer(i * 15));
		}

		totalTime = 0;
		while (!customerQueue.empty()) {
			for (int i = 0; i < limit; i++) {
				if (!customerQueue.empty()) {
					customer = customerQueue.front(); customerQueue.pop();
					if (customer.getArrivalTime() > cashierTime[i]) {
						departs = customer.getArrivalTime() + PROCESS;
					} else {
						departs = cashierTime[i] + PROCESS;
					}
					customer.setDepartureTime(departs);
					cashierTime[i] = departs;
					totalTime += customer.getTotalTime();
				}
			}
		}

		averageTime = totalTime / MAX_CUSTOMERS;
		cout << "Number of cashiers = " << limit << "\n";
		cout << "Average time = " << averageTime << "\n";
		limit++;
	} while (averageTime > MIN_TIME);

	return 0;
}
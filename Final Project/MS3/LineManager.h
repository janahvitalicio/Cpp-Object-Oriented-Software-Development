// Name:                Janah Vitalicio
// Date of completion:  December 1, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <iostream>
#include <vector>
#include <deque>
#include "Task.h"
#include "CustomerOrder.h"

class LineManager {
	std::vector<Task*> AssemblyLine;      // A container containing all the references of the Task objects on the assembly line
	std::deque<CustomerOrder> ToBeFilled; // A queue of customer orders to be filled
	std::deque<CustomerOrder> Completed;  // A queue of customer orders completed
	unsigned int m_cntCustomerOrder;      // The number of CustomerOrder objects the assembly line started with
	size_t m_indexOfFirstTask;
	size_t m_indexOfLastTask;

public:
	LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);
	bool run(std::ostream&);
	void displayCompleted(std::ostream&) const;
	void validateTasks() const;
};


#endif
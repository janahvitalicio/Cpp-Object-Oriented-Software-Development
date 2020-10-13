// Name:                Janah Vitalicio
// Date of completion:  December 1, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <deque>
#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item {
	std::deque<CustomerOrder> m_orders; // A double ended queue with new CustomerOrders coming in one side and exiting out the other once filled.
	Task* m_pNextTask;                  // A pointer to the next task on the assembly line

public:
	Task(const std::string&);

	// A Task object cannot be copied or moved
	Task(Task&) = delete;
	Task& operator=(Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(Task&&) = delete;

	void runProcess(std::ostream&);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&);
	Task& operator+=(CustomerOrder&&);
};


#endif
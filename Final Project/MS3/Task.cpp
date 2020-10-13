// Name:                Janah Vitalicio
// Date of completion:  December 1, 2019

#include <iostream>
#include <iomanip>
#include <string>

#include "Task.h"

// Custom constructor
Task::Task(const std::string& record) : Item(record) {
	m_pNextTask = nullptr;
}

// Runs a single cycle of the assembly line for the current task
// If there are CustomerOrders in the queue, it will verify the fill status of the last CustomerOrder
// and fill it if the order contains the Item specified by the current Task
void Task::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		if (!m_orders.back().getOrderFillState()) {
			m_orders.back().fillItem(*this, os);
		}
	}
}

// Moves the last CustomerOrder in the queue to the next task on the assembly line if the orders fill
// state for the current Item is true. Otherwise, the CustomerOrder should remain in the queue 
// for the next processing cycle. If the queue is empty, return false.
bool Task::moveTask() {
	bool taskMoved = false;

	if (!m_orders.empty()) {
		if (m_orders.back().getItemFillState(this->getName()) && m_pNextTask) {
			*m_pNextTask += std::move(m_orders.back());
			m_orders.pop_back();
		}
		taskMoved = true;
	}

	return taskMoved;
}

// Stores the provided Task object's reference into the m_pNextTask pointer
void Task::setNextTask(Task& task) {
	m_pNextTask = &task;
}

// Removes the last CustomerOrder from the queue, places it in the parameter and returns true
// if the CustomerOrder queue is empty, return false
bool Task::getCompleted(CustomerOrder& order) {
	bool status = false;

	if (!m_orders.empty()) {
		if (m_orders.back().getItemFillState(this->getName()) && m_orders.front().getOrderFillState()) {
			order = std::move(m_orders.back());
			m_orders.pop_back();
			status = true;
		}
	}

	return status;
}

// Writes the name of the Item. This Task is responsible for into the parameter: ITEM_NAME --> NEXT_ITEM_NAME
void Task::validate(std::ostream& os) {
	if (m_pNextTask != nullptr) {
		os << this->getName() << " --> " << m_pNextTask->getName() << std::endl;
	}
	else {
		os << this->getName() << " --> END OF LINE" << std::endl;
	}
}

// Moves the parameter onto the front of the CustomerOrder queue
Task& Task::operator+=(CustomerOrder&& newOrder) {
	m_orders.push_front(std::move(newOrder));
	return *this;
}
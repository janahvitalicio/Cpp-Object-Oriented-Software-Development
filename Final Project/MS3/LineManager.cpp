// Name:                Janah Vitalicio
// Date of completion:  December 1, 2019

#include <iostream>
#include <fstream>
#include <string>

#include "LineManager.h"
#include "Utilities.h"

// Custom constructor
LineManager::LineManager(const std::string& filename, std::vector<Task*>& tasks, std::vector<CustomerOrder>& orders) {
	Utilities util;
	std::ifstream file(filename);
	std::string line;
	bool first = false;
	int count = 0;

	while (!file.eof()) {
		// Read the records from file
		std::getline(file, line);
		std::string next = "";
		std::string current;
		size_t pos = 0;
		bool more = false;
		std::string temp(line);
		temp.insert(0, 1, ' ');

		current = util.extractToken(temp, pos, more);
		count++;

		if (count < 5) {
			next = util.extractToken(temp, pos, more);
		}

		for (size_t i = 0; i < tasks.size(); i++) {
			if (tasks[i]->getName() == current) {
				if (!first) {
					m_indexOfFirstTask = i;
					first = true;
				}

				if (next.empty()){
					m_indexOfLastTask = i;
				}
				else {
					// Setup all the m_pNextTask references in the Task objects
					// Linking each Task object together to form the assembly line
					for (size_t j = 0; j < tasks.size(); j++) {
						if (tasks[j]->getName() == next) {
							tasks[i]->setNextTask(*tasks[j]);
							break;
						}
					}
				}

				break;
			}
		}
	}
	file.close();

	m_cntCustomerOrder = orders.size();

	// Move all the CustomerOrder objects onto the front of the ToBeFilled queue
	for (size_t num = 0; num < orders.size(); num++) {
		ToBeFilled.push_front(std::move(orders[num]));
	}

	orders.erase(orders.begin(), orders.end());

	// Copy all the Task objects into the AssemblyLine container
	AssemblyLine = tasks;
}

// Performs one cycle of operations on the assembly line
bool LineManager::run(std::ostream& os) {
	bool filled = true;

	// If there are any CustomerOrder objects in the ToBeFilled queue
	if (!ToBeFilled.empty()) {
		// Move the last CustomerOrder object onto the starting point of the AssemblyLine
		*AssemblyLine[m_indexOfFirstTask] += std::move(ToBeFilled.back());
		ToBeFilled.pop_back();
	}

	// Loop through all tasks on the assembly line and run one cycle of the taks's process
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->runProcess(os);
	}

	CustomerOrder temp;
	// Loop through all tasks on the assembly line and move the CustomerOrder objects down the line
	if (AssemblyLine[m_indexOfLastTask]->getCompleted(temp)) {
		// completed orders should be moved into the Completed queue
		Completed.push_back(std::move(temp));
	}
	
	// Return false if not all customer orders have been filled
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		if (AssemblyLine[i]->moveTask()) {
			m_cntCustomerOrder--;
			filled = false;
		}
	}

	return filled;
}

// Displays all the orders that were completed
void LineManager::displayCompleted(std::ostream& os) const {
	for (size_t i = 0; i < Completed.size(); i++) {
		Completed[i].display(os);
	}
}

// Validates each task on the assembly line
void LineManager::validateTasks() const {
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->validate(std::cout);
	}
}
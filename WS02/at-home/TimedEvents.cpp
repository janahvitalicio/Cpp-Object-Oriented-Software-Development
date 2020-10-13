// Name:                Janah Vitalicio
// Date of completion:  Sept. 23, 2019

#include <iostream>
#include <iomanip>
#include <chrono>
#include "TimedEvents.h"

using namespace std;

namespace sdds
{
	size_t TimedEvents::counter = 0;

	TimedEvents::TimedEvents() {
	}

	void TimedEvents::startClock() {
		mStart = chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		mEnd = chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* name) {
		auto start = mStart;
		auto end = mEnd;

		records[counter].mName = name;
		records[counter].mUnits = "nanoseconds";

		auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
		records[counter].mDuration = duration;

		counter++;
	}

	ostream& operator<<(ostream& os, TimedEvents tEvent) {
		os << "--------------------------" << endl
			<< "Execution Times:" << endl
			<< "--------------------------" << endl;

		for (size_t i = 0; i < TimedEvents::counter; i++) {
			os << left << setw(20) << fixed << tEvent.records[i].mName << " " << right << setw(12) << fixed
				<< chrono::duration_cast<chrono::nanoseconds>(tEvent.records[i].mDuration).count()
				<< " " << tEvent.records[i].mUnits << endl;
		}

		os << "--------------------------" << endl;
		return os;
	}

	TimedEvents::~TimedEvents() {

	}
}
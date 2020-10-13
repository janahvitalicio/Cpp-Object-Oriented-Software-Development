// Name:                Janah Gabrielle Vitalicio
// Date of completion:  Sept. 23, 2019

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>

namespace sdds
{
	const int MAX_REC = 7;

	class TimedEvents {
		static size_t counter;

		std::chrono::steady_clock::time_point mStart;
		std::chrono::steady_clock::time_point mEnd;

		struct {
			const char* mName;
			const char* mUnits = "seconds";
			std::chrono::steady_clock::duration mDuration;
		} records[MAX_REC];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend std::ostream& operator<<(std::ostream&, TimedEvents);
		~TimedEvents();
	};

}

#endif
// Name:                Janah Vitalicio
// Date of completion:  Sept. 23, 2019

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

#include <string>

namespace sdds
{
	class Text {
		static int counter;

		std::string* pStrings;
		int temp = 0;

	public:
		Text();
		Text(const char*);
		Text(const Text&);
		Text& operator=(const Text&);
		Text(Text&&); //move-constructor
		Text& operator=(Text&&); //move-assignment operator
		~Text();
		size_t size() const;
	};
}

#endif
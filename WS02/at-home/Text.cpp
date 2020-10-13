// Name:                Janah Vitalicio
// Date of completion:  Sept. 23, 2019

#include <fstream>
#include "Text.h"

using namespace std;

namespace sdds
{
	int Text::counter = 0;

	Text::Text() {
		pStrings = nullptr;
	}

	Text::Text(const char* fName) {
		string buffer = {};
		ifstream file;
		file.open(fName);

		if (file.is_open()) {
			while (getline(file, buffer, ' ')) {
				counter++;
			}
			counter--;
		}

		pStrings = new string[counter];

		int temp = 0;
		string fLine = {};

		while (getline(file, fLine)) {
			pStrings[temp] = fLine;
		}
	}

	Text::Text(const Text& other) {
		*this = other;
	}

	Text& Text::operator=(const Text& other) {
		if (this != &other) {
			counter = other.counter;

			delete[] pStrings;

			if (other.pStrings != nullptr) {
				pStrings = new string[counter];

				for (int i = 0; i < counter; i++) {
					pStrings[i] = other.pStrings[i];
				}
			}
			else {
				pStrings = nullptr;
			}
		}
		return *this;
	}

	Text::Text(Text&& other) {
		*this = move(other);
	}

	Text& Text::operator=(Text&& other) {
		if (this != &other) {
			delete[] pStrings;
			pStrings = other.pStrings;
			temp = other.temp;
			other.pStrings = nullptr;
			other.temp = 0;
		}
		return *this;
	}

	Text::~Text() {
		delete[] pStrings;
		pStrings = nullptr;
	}

	size_t Text::size() const {
		return counter;
	}
}
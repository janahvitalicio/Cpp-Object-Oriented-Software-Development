// Name:                Janah Vitalicio
// Date of completion:  Sept. 30, 2019

#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H

#include <iostream>

namespace sdds {

	// L: The type of the label
	// V: The type of the value
	template<class L, class V>
	class LVPair {
		L mLabel;
		V mValue;
	public:
		// Sets the object in an empty state
		LVPair() {
			mLabel = "";
		}

		// Copies the values received in the parameters into the instance variables.
		LVPair(const L& aa, const V& bb) {
			mLabel = aa;
			mValue = bb;
		}

		// Returns the key component of the pair
		const L& key() const {
			return mLabel;
		}

		// Return the value component of the pair
		const V& value() const {
			return mValue;
		}

		// Inserts into the parameter the stored values in the following format
		virtual void display(std::ostream& os) const {
			os << mLabel << " : " << mValue << std::endl;
		}
	};

	// Free helper
	// Calls the function LVPair<L, V>::display() to insert a pair into the stream
	template<class L, class V>
	std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	};

	// Manages the summation and pretty displaying of labeled values
	template<class L, class V>
	class SummableLVPair : public LVPair<L, V> {
		static V initialValue;
		static size_t minFieldWidth;
	public:
		// Returns the initial value stored
		static const V& getInitialValue() {
			return initialValue;
		}

		// Default constructor
		SummableLVPair() {
		}
		// Stores the pair in the current instance
		SummableLVPair(const L& lbl, const V& val) : LVPair<L, V>(lbl, val) {
			// Updates the field width if necessary
			if (lbl.size() > minFieldWidth) {
				int additionalWidth = lbl.size() - minFieldWidth;
				minFieldWidth = minFieldWidth + additionalWidth;
			}
		}

		V sum(const L& lbl, const V& val) const {
			// Checks if the current instance is lbl, then adds the value of the pair and val together
			if (this->key() == lbl) {
				return this->value() + val;
			}
			else {
				return val;
			}
		}

		void display(std::ostream& os) const {
			os << std::left << std::setw(minFieldWidth);
			LVPair<L, V>::display(os);
			os << std::right;
		}
	};

	template<typename L, typename V>
	size_t SummableLVPair<L, V>::minFieldWidth = 0;

	// Template Specializations
	template<>
	std::string SummableLVPair <std::string, std::string>::initialValue = std::string("");

	template<>
	int SummableLVPair<std::string, int>::initialValue = 0;

	template<>
	std::string SummableLVPair <std::string, std::string>::
		sum(const std::string& lbl, const std::string& val) const {
		if (this->key() == lbl) {
			if (val == "") {
				return this->value();
			}
			return val + ", " + this->value();
		}
		else {
			return val;
		}
	}
}

#endif
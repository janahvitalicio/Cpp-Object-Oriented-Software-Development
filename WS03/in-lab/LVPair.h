// Name:                Janah Vitalicio
// Date of completion:  Sept. 26, 2019

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
		LVPair() : mLabel{}, mValue{} {
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
		void display(std::ostream& os) const {
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
}

#endif
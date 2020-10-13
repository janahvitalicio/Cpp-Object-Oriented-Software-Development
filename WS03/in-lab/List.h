// Name:                Janah Vitalicio
// Date of completion:  Sept. 26, 2019

#ifndef SDDS_LIST_H
#define SDDS_LIST_H

namespace sdds {

	// T: The type of any element in the array
	// N: The maximum number of elements in the array (an integer without sign)
	template<class T, int N>
	class List {
		T mList[N]; // The capacity of the array (N)
		size_t mNumElements = 0; // The number of elements added to the list. Initially the list is empty.
	public:
		// Returns the number of elements in the list
		size_t size() const {
			return mNumElements;
		}

		// Returns the element at index i, assuming the parameter is valid
		const T& operator[](size_t i) const {
			return mList[i];
		}

		// If the list didn't reach the capacity, add a copy of the parameter
		// to the array. Otherwise, do nothing.
		void operator+=(const T& tt) {
			if (mNumElements < N) {
				mList[mNumElements] = tt;
				mNumElements++;
			}
		}
	};
}

#endif
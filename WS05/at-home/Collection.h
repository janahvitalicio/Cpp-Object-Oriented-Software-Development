// Name:                Janah Vitalicio
// Date of completion:  October 17, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <stdexcept>

namespace sdds {

	template<class T>
	class Collection {
		std::string mName;
		T* mItems;
		size_t mSize = 0;
		void (*mObserver)(const Collection<T>&, const T&);

	public:
		Collection() {
			mName = "";
			mItems = nullptr;
			mSize = 0;
			mObserver = nullptr;
		};

		Collection(std::string name) {
			mName = name;
			mItems = nullptr;
			mSize = 0;
			mObserver = nullptr;
		}

		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;

		~Collection() {
			delete[] mItems;
			mItems = nullptr;
			mName = "";
			mSize = 0;
		}

		const std::string& name() const {
			return mName;
		}

		size_t size() const {
			return mSize;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			mObserver = observer;
		}

		Collection<T>& operator+=(const T& item) {
			bool isInArray = false;
			// Check if the collection doesn't contain an item with the same title
			for (size_t i = 0; i < mSize; i++) {
				if (item.title() == mItems[i].title()) {
					isInArray = true;
					break;
				}
			}

			// If item is not already in the collection
			if (!isInArray) {
				// Resize the array to accomodate the new item
				mSize++;
				T* temp = new T[mSize];
				// Assign the old items to the new temp array
				for (size_t i = 0; i < mSize - 1; i++) {
					temp[i] = mItems[i];
				}
				// Assign the new item to the last element of temp array
				temp[mSize - 1] = item;

				delete[] mItems;
				mItems = nullptr;

				mItems = temp;
				temp = nullptr;

				// If there is an observer registered, call the observer function
				if (this->mObserver != nullptr) {
					// Passing *this and the new item as parameters
					mObserver(*this, mItems[mSize - 1]);
				}
			}

			return *this;
		}

		T& operator[](size_t idx) const {
			if (idx >= mSize) {
				std::string err = "Bad index [";
				err += std::to_string(idx);
				err += "]. Collection has [";
				err += std::to_string(mSize);
				err += "] items.";
				throw std::out_of_range(err);
			}
			return mItems[idx];
		}

		T* operator[](std::string title) const {
			size_t found = 0;
			size_t position = 0;
			for (size_t i = 0; i < mSize && found == 0; i++) {
				if (mItems[i].title() == title) {
					found = 1;
					position = i;
					break;
				}
			}
			if (found == 1) {
				return &(mItems[position]);
			}
			else {
				return nullptr;
			}
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& c) {
		for (size_t i = 0; i < c.size(); i++) {
			os << c[i];
		}

		return os;
	}
}

#endif
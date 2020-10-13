// Name:                Janah Vitalicio
// Date of completion:  October 7, 2019

#include <iostream>

#include "Restaurant.h"
#include "Reservation.h"

namespace sdds {

	// Default constructor
	Restaurant::Restaurant() {
		pReservation = nullptr;
		mNumReservation = 0;
	}

	// Copy constructor
	Restaurant::Restaurant(const Restaurant& src) {
		pReservation = nullptr;
		mNumReservation = 0;

		if (this != &src) {
			mNumReservation = src.mNumReservation;

			pReservation = new Reservation[mNumReservation];

			for (size_t i = 0; i < mNumReservation; i++) {
				pReservation[i] = src.pReservation[i];
			}
		}
	}

	// Copy assignment operator
	Restaurant& Restaurant::operator=(const Restaurant& src) {
		if (this != &src) {
			delete[] pReservation;
			pReservation = new Reservation[mNumReservation];

			mNumReservation = src.mNumReservation;

			for (size_t i = 0; i < mNumReservation; i++) {
				pReservation[i] = src.pReservation[i];
			}
		}
		return *this;
	}

	// Constructor that receives as a parameter an array of pointers to objects of type Reservation
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		pReservation = nullptr;
		mNumReservation = 0;

		if (cnt > 0 && reservations != nullptr) {
			mNumReservation = cnt;
			pReservation = new Reservation[mNumReservation];

			// Store copies of all reservations
			for (size_t i = 0; i < cnt; i++) {
				pReservation[i] = (*reservations[i]);
			}
		}
	}

	// Move-constructor
	Restaurant::Restaurant(Restaurant&& src) {
		*this = std::move(src);
	}

	// Move-assignment operator
	Restaurant& Restaurant::operator=(Restaurant&& src) {
		if (this != &src) {
			delete[] pReservation;
			pReservation = nullptr;
			mNumReservation = 0;

			if (src.pReservation != nullptr)
			{
				pReservation = src.pReservation;
				mNumReservation = src.mNumReservation;

				src.pReservation = nullptr;
				src.mNumReservation = 0;
			}
		}
		return *this;
	}

	// Returns how many reservations are in the system
	size_t Restaurant::size() const {
		return mNumReservation;
	}

	// Destructor
	Restaurant::~Restaurant() {
		delete[] pReservation;
		pReservation = nullptr;
	}

	std::ostream& operator<<(std::ostream& os, Restaurant rs) {
		os << "--------------------------" << std::endl
			<< "Fancy Restaurant" << std::endl
			<< "--------------------------" << std::endl;

		if (rs.mNumReservation == 0) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < rs.size(); i++) {
				os << rs.pReservation[i];
			}
		}

		os << "--------------------------" << std::endl;

		return os;
	}

}
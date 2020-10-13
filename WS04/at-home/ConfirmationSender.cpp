// Name:                Janah Vitalicio
// Date of completion:  October 7, 2019

#include <iostream>
#include "ConfirmationSender.h"

namespace sdds {

	// Default constructor
	ConfirmationSender::ConfirmationSender() {
		ppReservationCS = { nullptr };
		mNumReservations = 0;
	}

	// Copy constructor
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
		if (this != &src) {
			ppReservationCS = nullptr;
			mNumReservations = 0;

			if (src.ppReservationCS != nullptr) {
				mNumReservations = src.mNumReservations;
				ppReservationCS = new Reservation * [mNumReservations];

				for (size_t i = 0; i < mNumReservations; i++) {
					ppReservationCS[i] = src.ppReservationCS[i];
				}
			}
		}
	}

	// Move-constructor
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) {
		if (this != &src) {
			ppReservationCS = nullptr;
			mNumReservations = 0;

			if (src.ppReservationCS != nullptr)
			{
				mNumReservations = src.mNumReservations;
				ppReservationCS = src.ppReservationCS;

				src.mNumReservations = 0;
				src.ppReservationCS = nullptr;
			}
		}
	}

	// Destructor
	ConfirmationSender::~ConfirmationSender() {
		delete[] ppReservationCS;
		ppReservationCS = nullptr;
	}

	bool ConfirmationSender::isEmpty() {
		if (this->ppReservationCS != nullptr) {
			return false;
		}
		else {
			return true;
		}
	}

	void ConfirmationSender::emptyMemory() {
		if ((ppReservationCS != nullptr) && (mNumReservations != 0)) {
			// Deletes each element in the ppReservationCS array
			for (size_t i = 0; i < mNumReservations; i++)
			{
				if (ppReservationCS[i] != nullptr) {
					delete ppReservationCS[i];
				}
			}
			delete[] ppReservationCS;
			ppReservationCS = nullptr;
		}
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		int flag = 0;

		// Check if res is already in the array
		for (size_t i = 0; i < mNumReservations; i++) {
			if (this->ppReservationCS[i]->getResID().compare(res.getResID()) == 0) {
				flag = 1;
			}
		}

		// If not found resizes the array to make room for res
		if (flag == 0) {
			Reservation** temp = new Reservation * [mNumReservations + 1];
			for (size_t i = 0; i < mNumReservations; i++) {
				temp[i] = new Reservation(*ppReservationCS[i]);
			}
			temp[mNumReservations] = new Reservation(res);

			emptyMemory();

			ppReservationCS = temp;
			mNumReservations++;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		int flag = 0;
		size_t pos = 0; // Position of res
		size_t tempNum = 0;

		// Check if res is not in the array
		for (size_t i = 0; i < mNumReservations; i++) {
			if (this->ppReservationCS[i]->getResID().compare(res.getResID()) == 0) {
				ppReservationCS[i] = nullptr; // Set the pointer in the array to nullptr
				flag = 1;
				pos = i;
			}
		}

		// Resize array
		if (flag == 1) {
			Reservation** temp = new Reservation * [mNumReservations - 1];
			for (size_t i = 0; i < mNumReservations; i++) {
				if (i != pos) {
					temp[tempNum++] = new Reservation(*ppReservationCS[i]);
				}
			}

			emptyMemory();

			ppReservationCS = temp;
			mNumReservations--;
		}

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs) {
		os << "--------------------------" << std::endl
			<< "Confirmations to Send" << std::endl
			<< "--------------------------" << std::endl;

		if (cs.mNumReservations == 0) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < cs.mNumReservations; i++) {
				os << (*cs.ppReservationCS[i]);
			}
		}

		os << "--------------------------" << std::endl;

		return os;
	}

}
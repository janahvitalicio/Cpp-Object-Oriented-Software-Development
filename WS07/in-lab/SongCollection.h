// Name:                Janah Gabrielle Vitalicio
// Date of completion:  November 7, 2019

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <fstream>
#include <iostream>
#include <vector>

namespace sdds {

	struct Song {
		char mArtist[25] = { '\0' };
		char mTitle[25] = { '\0' };
		char mAlbum[25] = { '\0' };
		double mPrice = 0.0;
		int mYear = 0;
		int mLength = 0;
	};

	class SongCollection : public Song {
		std::vector<Song> mSongs;
	public:
		SongCollection(const char*);
		void display(std::ostream& out) const;
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif // !SDDS_SONGCOLLECTION_H


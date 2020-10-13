// Name:                Janah Vitalicio
// Date of completion:  November 11, 2019

#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
#include <algorithm>

#include "SongCollection.h"

namespace sdds {

	SongCollection::SongCollection(const char* filename) {
		std::ifstream file(filename);
		if (!file) {
			throw "ERROR: Cannot open file.\n";
		}
		else {
			while (file) {
				Song tempSong;

				file.get(mTitle, 26);
				std::string tempTitle(mTitle);
				tempTitle = std::regex_replace(tempTitle, std::regex("^ +| +$|( ) +"), "");
				strcpy(tempSong.mTitle, tempTitle.c_str());

				file.get(mArtist, 26);
				std::string tempArtist(mArtist);
				tempArtist = std::regex_replace(tempArtist, std::regex("^ +| +$|( ) +"), "");
				strcpy(tempSong.mArtist, tempArtist.c_str());

				file.get(mAlbum, 26);
				std::string tempAlbum(mAlbum);
				tempAlbum = std::regex_replace(tempAlbum, std::regex("^ +| +$|( ) +"), "");
				strcpy(tempSong.mAlbum, tempAlbum.c_str());

				char year[6] = { '\0' };
				file.get(year, 6);
				if (year[0] == ' ') {
					tempSong.mYear = 0;
					year[0] = { '\0' };
				}
				else {
					std::string tempYear(year);
					tempYear = std::regex_replace(tempYear, std::regex("^ +| +$|( ) +"), "");
					tempSong.mYear = std::stoi(tempYear);
				}

				char length[6] = { '\0' };
				file.get(length, 6);
				std::string tempLength(length);
				tempLength = std::regex_replace(tempLength, std::regex("^ +| +$|( ) +"), "");
				tempSong.mLength = std::stoi(tempLength);

				char price[6] = { '\0' };
				file.get(price, 6);
				std::string tempPrice(price);
				tempPrice = std::regex_replace(tempPrice, std::regex("^ +| +$|( ) +"), "");
				tempSong.mPrice = std::stod(tempPrice);

				mSongs.push_back(tempSong);

				file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				mSize++;
				totalSeconds += tempSong.mLength;

				if (file.eof()) {
					break;
				}
			}
		}
	}

	void SongCollection::display(std::ostream& out) const {
		std::for_each(mSongs.begin(), mSongs.end(),
			[&](const Song& s)
			{
				out << s << std::endl;
			});

		int minutes = totalSeconds / 60;
		int hours = minutes / 60;
		int seconds = totalSeconds % 60;

		out << "----------------------------------------------------------------------------------------" << std::endl
			<< "|                                                        Total Listening Time: "
			<< hours << ":" << (minutes % 60) << ":" << std::setfill('0') << std::setw(2) << seconds << " |" << std::endl;
	}

	void SongCollection::sort(std::string sortBy) {
		if (sortBy == "title") {
			std::sort(mSongs.begin(), mSongs.end(),
				[](Song& l, Song& r) { 
					std::string lTitle(l.mTitle);
					std::string rTitle(r.mTitle);
					return lTitle < rTitle;
				});
		}
		else if (sortBy == "album") {
			std::sort(mSongs.begin(), mSongs.end(),
				[](Song& l, Song& r) { 
					std::string lAlbum(l.mAlbum);
					std::string rAlbum(r.mAlbum);
					return l.mAlbum < r.mAlbum; 
				});
		}
		else if (sortBy == "length") {
			std::sort(mSongs.begin(), mSongs.end(),
				[](Song& l, Song& r) { return l.mLength < r.mLength; });
		}
	}

	void SongCollection::cleanAlbum() {
		std::for_each(mSongs.begin(), mSongs.end(),
			[](Song& s)
			{
				if (s.mAlbum[0] == '[') {
					memset(&s.mAlbum[0], 0, sizeof(s.mAlbum));
				}
			});
	}

	bool SongCollection::inCollection(std::string artistName) const {
		bool matchFound = false;

		std::for_each(mSongs.begin(), mSongs.end(),
			[&](const Song& s)
			{
				std::string artist(s.mArtist);
				if (artist == artistName) {
					matchFound = true;
				}
			});
		
		return matchFound;
	}

	std::list<Song> SongCollection::getSongsForArtist(std::string artistName) const {
		std::list<Song> songs;

		std::for_each(mSongs.begin(), mSongs.end(),
			[&](const Song& s)
			{
				std::string artist(s.mArtist);
				if (artist == artistName) {
					songs.push_back(s);
				}
			});

		return songs;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << std::setw(20) << std::left << theSong.mTitle
			<< " | " << std::setw(15) << std::left << theSong.mArtist
			<< " | " << std::setw(20) << std::left << theSong.mAlbum
			<< " | " << std::setw(6) << std::right;

		if (theSong.mYear == 0) {
			out << "";
		}
		else {
			out << theSong.mYear;
		}

		out << " | ";

		int minutes = theSong.mLength / 60;
		int seconds = theSong.mLength % 60;

		out << minutes << ":" << std::setfill('0') << std::setw(2) << seconds << std::setfill(' ');

		out << " | " << theSong.mPrice
			<< " |";

		return out;
	}
};

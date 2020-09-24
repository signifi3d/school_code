/*
ArtistCatalog.h
Blake Eakin
CS 260
Project 1
4/11/2019

Function prototypes and class definition of the ArtistCatalog
*/
#pragma once

//#include "LinkedList.h"
#include "ArtistRecord.h"
#include "SongRecord.h"
#include <fstream>

class ArtistCatalog {
	public:
		~ArtistCatalog();
		static ArtistCatalog* catalog();
		void addArtist(const char*, const char*, const char*);
		void addSongForArtist(const char*, const char*, const double, const int, const int);
		void setViewsForArtistSong(const char*, const char*, const int);
		void setLikesForArtistSong(const char*, const char*, const int);
		void displayArtists();
		void displaySongsForArtist(const char*);
		void removeAllSongsWithViewsUnder(const int);
		void writeToDatabase(std::ofstream&);

	private:
		ArtistCatalog();
		ArtistRecord* getArtist(const char*, ArtistRecord*);

		static ArtistCatalog* catalogInstance;
		ArtistRecord* artistHead;
};

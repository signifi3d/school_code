/*
ArtistCatalog.cpp
Blake Eakin
4/11/2019

Implementations of Artist Catalog class functions.
*/
#include "ArtistCatalog.h"
#include "ArtistRecord.h"
#include "SongRecord.h"
#include <iostream>
#include <iomanip>
#include <string.h>



//The static catalog singleton instance must be initialzed to nullptr
ArtistCatalog* ArtistCatalog::catalogInstance = nullptr;



//Default constructor initializes head node pointer of artist linked list to null
ArtistCatalog::ArtistCatalog():artistHead(nullptr) {}



//Frees the data in the artist list and the catalog instance
ArtistCatalog::~ArtistCatalog() {
	delete artistHead;
	delete catalogInstance;
}



//catalog function returns the singleton instance of the ArtistCatalog class or creates it if it doesn't exist
ArtistCatalog* ArtistCatalog::catalog() {
	if (catalogInstance == nullptr) {
		catalogInstance = new ArtistCatalog();
	}

	return catalogInstance;
}



//Takes in the information of an artist (name, top story, description) Iterates through the list and throws an error if the artist already exists, adds new artist to end of list
void ArtistCatalog::addArtist(const char* artistName, const char* topStory, const char* description) {
	ArtistRecord** curr = &artistHead;
	//curr holds a pointer to the memory address of, initially, the artist head, and is used to iterate through positions on the list


	if ( !strcasecmp("", artistName) || !strcmp(" ", artistName) || artistName == nullptr ) 
		throw "No artist name provided.";

	while ( *curr != nullptr ) {
		if ( !strcasecmp((*curr)->artistName, artistName ) )
			throw "Artist already exists.";
		curr = &((*curr)->next);
	}

	*curr = new ArtistRecord();
	(*curr)->artistName = new char[strlen(artistName)];
	strcpy((*curr)->artistName, artistName);
	(*curr)->topStory = new char[strlen(topStory)];
	strcpy((*curr)->topStory, topStory);
	(*curr)->artistDescription = new char[strlen(description)];
	strcpy((*curr)->artistDescription, description);
	(*curr)->next = nullptr;

}



//Function internal to the class for locating particular artists, 
//takes in a string for the artist's name, and a pointer to an ArtistRecord
//returns a nullptr if artist isn't found in list, or pointer to the ArtistRecord if found, or recurses otherwise
//This function is recursive to fulfill project requirements
ArtistRecord* ArtistCatalog::getArtist(const char* artistName, ArtistRecord* curr) {
	if ( curr == nullptr )
		return nullptr;
	else if ( !strcasecmp(curr->artistName, artistName ) )
		return curr;
	else
		return getArtist(artistName, curr->next);
}



//Takes in a string for the artist name to add a song for, a string for the songs title, a double for the length of the song, and ints of the song's views and likes.
//Locates the Artist and throws an error if the artist isn't found. If found it iterates through that artist's song list comparing the views of the song to be
//added with each song in the list and inserts the new song at the proper spot.
void ArtistCatalog::addSongForArtist(const char* artistName, const char* songTitle, const double songLength, const int songViews, const int songLikes) {
	ArtistRecord* selectedArtist;
	//A pointer to the artist record for which a song will be added
	SongRecord* newEntry;
	//Pointer for building a new song record to add to the database.
	SongRecord** newPosition;
	//Holds the position where the song will be inserted if it's not a duplicate
	SongRecord** curr;
	//iterator over list

	if ( !strcasecmp("", songTitle) || !strcmp(" ", songTitle) || songTitle == nullptr )
		throw "No song title provided";

	if ( songLength < 0 )
		throw "Invalid song length.";

	if ( songViews < 0 ) 
		throw "Invalid view size.";

	if ( songLikes < 0 ) 
		throw "Invalid amount of likes.";

	selectedArtist = getArtist(artistName, artistHead);

	if ( selectedArtist == nullptr )
		throw "Artist not found.";

	newPosition = curr = &(selectedArtist->songHead);


	while ( *curr != nullptr ) {
		if ( !strcasecmp((*curr)->title, songTitle) ) 
			throw "Song already exists.";
		if ( songViews <= (*curr)->views ) 
			newPosition = &((*curr)->next);	
		curr = &((*curr)->next);
	}

	newEntry = new SongRecord();
	newEntry->title = new char[strlen(songTitle)];
	strcpy(newEntry->title, songTitle);
	newEntry->length = songLength;
	newEntry->views = songViews;
	newEntry->likes = songLikes;
	newEntry->next = *newPosition;
	*newPosition = newEntry;

}



//takes in a string of the artist whose song is being changed, the name of the song to change, and the new number of views it has.
//Throws errors when the artist or song are not found. Removes the song from the list when found and readds it to put it in its proper place
void ArtistCatalog::setViewsForArtistSong(const char* artistName, const char* songName, const int newViews) {
	ArtistRecord* selectedArtist;
	//A pointer to the artist record that holds the song for which the views are being changed
	SongRecord* temp = nullptr;
	//A pointer to hold a SongRecord object temporarily so it can be reinserted at the proper position in the list
	SongRecord** curr;
	//Points to the memory address of SongRecords in the list in order to iterate through and operate on list items.

	if ( newViews < 0 ) 
		throw "Invalid number of views.";

	selectedArtist = getArtist(artistName, artistHead);

	if ( selectedArtist == nullptr )
		throw "Artist not found.";

	curr = &(selectedArtist->songHead);

	while ( *curr != nullptr ) {
		if ( !strcasecmp(songName,(*curr)->title) ) {
			temp = *curr;
			*curr = (*curr)->next;
			temp->views = newViews;
			temp->next = nullptr;
			break;
		}
		curr = &((*curr)->next);
	}

	if ( temp == nullptr )
		throw "Song not found.";
	else {
		addSongForArtist(artistName, temp->title, temp->length, temp->views, temp->likes);
		delete temp;
	}

}



//Gets passed an artist name, a song name, and a number of likes, alters the number of likes for the specified song. Throws an error if the song or artist don't exist in the catalog.
void ArtistCatalog::setLikesForArtistSong(const char* artistName, const char* songName, const int newLikes) {
	ArtistRecord* selectedArtist = getArtist(artistName, artistHead);
	//A pointer to the ArtistRecord that holds the song for which the likes are being changed
	SongRecord* curr;
	//Pointer to a SongRecord for iterating through the list

	if ( newLikes < 0 )
		throw "Invalid number of likes.";

	if ( selectedArtist == nullptr ) 
		throw "Artist not found;";

	curr = selectedArtist->songHead;

	while ( curr != nullptr ) {
		if ( !strcasecmp(songName, curr->title) ) {
			curr->likes = newLikes;
			break;
		}
		curr = curr->next;
	}

	if ( curr == nullptr )
		throw "Song not found.";

}



//Takes in an int to use to compare against the views of all the songs, removes from the list any that have views less than the passed threshold.
void ArtistCatalog::removeAllSongsWithViewsUnder(const int viewThreshold) {
	ArtistRecord* currArtist = artistHead;
	//Pointer for iterating through the list

	if ( viewThreshold < 0 ) 
		throw "Invalid view threshold.";

	while ( currArtist != nullptr ) {
		SongRecord** currSong = &(currArtist->songHead);
		while ( *currSong != nullptr ) {
			if ( (*currSong)->views < viewThreshold ) {
				delete *currSong;
				*currSong = nullptr;
				break;
			}
			currSong = &((*currSong)->next);
		}
		currArtist = currArtist->next;
	}
}



//Iterates through the list of artists and outputs the name, story, and description of each, throws an error if no artists exist.
void ArtistCatalog::displayArtists() {
	ArtistRecord* curr = artistHead;
	//Pointer for iterating through the list

	if ( curr == nullptr ) 
		throw "No artists to display.";
	do {
		std::cout << "Artist: " << curr->artistName << std::endl;
		std::cout << curr->artistName << "'s top story: " << curr->topStory << std::endl;
		std::cout << curr->artistName << "'s description: " << curr->artistDescription << std::endl << std::endl;
		curr = curr->next;
	} while ( curr != nullptr );
}



//Takes in a string for an artist name, throws an error if that artist isn't found. Also throws an error if that artist has no songs.
//Iterates through all of the songs in that artist's song list and outputs the title, length, views, and likes of each.
void ArtistCatalog::displaySongsForArtist(const char* artistName) {
	ArtistRecord* displayArtist = getArtist(artistName, artistHead);
	//Pointer to the ArtistRecord for the artist for whose songs will be displayed
	SongRecord* curr;
	//Pointer to iterate through the song list

	if ( displayArtist == nullptr ) 
		throw "Artist not found.";

	curr = displayArtist->songHead;

	if ( curr == nullptr ) {
		throw "No songs available for selected artist.";
	}
	
	do {
		int min = (int)(curr->length);
		double sec = (int)((curr->length - min)*100);
		std::cout << "Title: " << curr->title << std::endl;
		std::cout << "Length: " << min << ":" << std::setfill('0') << std::setw(2) << sec << std::endl;
		std::cout << "Views: " << curr->views << std::endl;
		std::cout << "Likes: " <<  curr->likes << std::endl;
		std::cout << std::endl;
		curr = curr->next;
	} while ( curr != nullptr );

}



//Gets passed a reference to an output stream representing the database, iterates through every artist and song and writes out all of the catalog data in the proper database format
void ArtistCatalog::writeToDatabase(std::ofstream& database) {
	ArtistRecord* currArtist = artistHead;
	//Pointer for iterating through artist list.

	while ( currArtist != nullptr ) {
		SongRecord* currSong = currArtist->songHead;

		database << currArtist->artistName << "," << currArtist->topStory << "," << currArtist->artistDescription << std::endl;

		while ( currSong != nullptr ) {
			database << currSong->title << "," << currSong->length << "," << currSong->views << "," << currSong->likes << std::endl;

			currSong = currSong->next;
		}

		database << "-" << std::endl;

		currArtist = currArtist->next;
	}
}


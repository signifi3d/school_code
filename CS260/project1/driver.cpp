/*
driver.cpp
Blake Eakin
CS 260
Project 1
4/11/2019

Main driver for testing and user interface of the ArtistCatalog ADT
*/
#include <iostream>
#include <fstream>
#include "ArtistCatalog.h"
#include "utilities.h"

//path for the test catalog data
const char * DB_PATH = "data.txt";

void catalogInit();
void programExit();
void menuLoop();
void displayMenu();
void displayArtists();
void displaySongs();
void addArtist();
void addSong();
void enterViews();
void enterLikes();
void removeByThreshold();



//main function
int main() {
	std::cout << "CS_Record_Label Artist Catalog" << std::endl;
	catalogInit();
	menuLoop();
	programExit();
	return 0;
}



//Handles initializing the catalog with data from the test data file
void catalogInit() {
	std::ifstream catalogDatabase;

	catalogDatabase.open(DB_PATH);

	while ( catalogDatabase.peek() != -1 ) {
		char artistName[100];
		char topStory[500];
		char description[500];

		catalogDatabase.get(artistName, 100, ',');
		catalogDatabase.ignore(100, ',');
		catalogDatabase.get(topStory, 500, ',');
		catalogDatabase.ignore(500, ',');
		catalogDatabase.get(description, 500, '\n');
		catalogDatabase.ignore(500, '\n');

		try {
			ArtistCatalog::catalog()->addArtist(artistName, topStory, description);
		} catch (const char* error) {
			std::cerr << error << std::endl;
			return;
		}

		while ( catalogDatabase.peek() != '-' ) {
			char songTitle[100];
			char songLength[5];
			char songViews[50];
			char songLikes[50];

			catalogDatabase.get(songTitle, 100, ',');
			catalogDatabase.ignore(100, ',');
			catalogDatabase.get(songLength, 5, ',');
			catalogDatabase.ignore(5, ',');
			catalogDatabase.get(songViews, 50, ',');
			catalogDatabase.ignore(50, ',');
			catalogDatabase.get(songLikes, 50, '\n');
			catalogDatabase.ignore(50, '\n');

			try {
				ArtistCatalog::catalog()->addSongForArtist(artistName, songTitle, cstod(songLength), cstoi(songViews), cstoi(songLikes));
			} catch (const char* error) {
				std::cerr << error << std::endl;
				return;
			}
		}
		catalogDatabase.ignore(100, '\n');


	}
		
	std::cout << "Catalog initialized." << std::endl;
}



//Handles all of the clean up of the catalog, writes changes to the test data file
void programExit() {
	std::ofstream databaseStream(DB_PATH);
	//Opens a stream for writing to the test data file

	ArtistCatalog::catalog()->writeToDatabase(databaseStream);

	std::cout << "Thanks for using the CS_Record_Label Artist Catalog." << std::endl;
}



//Loops the menu, directs the user based on choices, ends with proper input for exiting
void menuLoop() {
	char userChoice[20];
	//Holds the user input
	bool menuExit = false;
	//Loop test condition

	while (!menuExit) {

		displayMenu();

		std::cout << "What would you like to do? ";
		std::cin.getline(userChoice, 20);
		flushCin();
		std::cout << std::endl;

		if ( !strcmp(userChoice, "1" ) ) {
			displayArtists();
		} else if ( !strcmp(userChoice, "2" ) ) {
			displaySongs();
		} else if ( !strcmp(userChoice, "3" ) ) {
			addArtist();
		} else if ( !strcmp(userChoice, "4" ) ) {
			addSong();
		} else if ( !strcmp(userChoice, "5" ) ) {
			enterViews();
		} else if ( !strcmp(userChoice, "6" ) ) {
			enterLikes();
		} else if ( !strcmp(userChoice, "7" ) ) {
			removeByThreshold();
		} else if ( !strcmp(userChoice, "X") || !strcmp(userChoice, "q") || !strcmp(userChoice, "quit") || !strcmp(userChoice, "Q") || !strcmp(userChoice, "Quit")) {
			menuExit = true;
		} else {
			std::cout << "Invalid input. Please select a menu item by number." <<std::endl;
		}
	}

}



//simply displays menu options
void displayMenu() {
	std::cout << std::endl;
	std::cout << "1. Display all artists." << std::endl;
	std::cout << "2. Display artist songs." << std::endl;
	std::cout << "3. Add a new artist." << std::endl;
	std::cout << "4. Add a new song for an artist." << std::endl;
	std::cout << "5. Enter the number of view for a song." << std::endl;
	std::cout << "6. Enter the number of likes for a song." << std::endl;
	std::cout << "7. Remove songs below view threshold." << std::endl;
	std::cout << "X. Exit catalog." << std::endl;
}



//Calls the catalog artist display function
void displayArtists() {
	try {
		ArtistCatalog::catalog()->displayArtists();	
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
	}
}



//Queries user for artist, calls the catalog song display function for that artist
void displaySongs() {
	char userChoice[20];
	//Holds user input

	std::cout << "For what artist would you like to see the songs of? ";
	std::cin.getline(userChoice, 20);
	flushCin();
	std::cout << std::endl;
	
	try {
		ArtistCatalog::catalog()->displaySongsForArtist(userChoice);
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
	}
}



//Takes in artist data and sends it to catalog's function for adding artists
void addArtist() {
	char artistName[50];
	//Holds user input for artist's name
	char artistStory[500];
	//Holds user input for the artist's top story
	char artistDescription[500];
	//Holds user input for the artist's description


	std::cout << "Enter new artist's name: ";
	std::cin.getline(artistName, 50);
	flushCin();
	
	std::cout << "Enter new artist's top story: ";
	std::cin.getline(artistStory, 500);
	flushCin();

	std::cout << "Enter new artist's description: ";
	std::cin.getline(artistDescription, 500);
	flushCin();

	std::cout << std::endl;

	try {
		ArtistCatalog::catalog()->addArtist(artistName, artistStory, artistDescription);
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
		return;
	}

	std::cout << artistName << " added to catalog." << std::endl;

}



//Queries user for artist name song is being added for, then song details, passes data to catalog function for adding songs for artists.
void addSong() {
	char artist[50];
	//Holds artist name input by user
	char songName[50];
	//Holds the song name input by user
	char songLength[20];
	//Holds the length of the song input by user
	char songViews[20];
	//Holds the song views input by user
	char songLikes[20];
	//Holds the song's likes input by user

	std::cout << "What artist are you adding a song for? ";
	std::cin.getline(artist, 50);
	flushCin();
	std::cout << "What is name of " << artist <<"'s song? ";
	std::cin.getline(songName, 50);
	flushCin();
	std::cout << "What is " << songName << "'s length? ";
	std::cin.getline(songLength, 20);
	flushCin();
	std::cout << "How many views does " << songName << " have? ";
	std::cin.getline(songViews, 20);
	flushCin();
	std::cout << "How many likes does " << songName << " have? ";
	std::cin.getline(songLikes, 20);
	flushCin();

	try {
		ArtistCatalog::catalog()->addSongForArtist(artist, songName, cstod(songLength), cstoi(songViews), cstoi(songLikes));
	} catch ( const char* error) {
		std::cerr << error << std::endl;
		return;
	}

	std::cout << songName << " added successfully." << std::endl;
}



//Queries user for the artist and song the user wants to alter, and then for the new number of views. Passes data to catalog function for setting views
void enterViews() {
	char artist[50];
	//artist name input
	char songName[50];
	//song title input
	char views[20];
	//new number of views input

	std::cout << "For what artist would you like to change a song's view? ";
	std::cin.getline(artist, 50);
	flushCin();

	std::cout << "What song would you like to changes the views of? ";
	std::cin.getline(songName, 50);
	flushCin();
	

	std::cout << "How many views does " << songName << " have? ";
	std::cin.getline(views, 20);
	flushCin();

	try {
		ArtistCatalog::catalog()->setViewsForArtistSong(artist, songName, cstoi(views));
	} catch ( const char* error ) {
		std::cerr << error << std::endl;
		return;
	}

	std::cout << songName << " by " << artist << " has " << views << " views." << std::endl;
}



//Queries user for artist, song to alter, then number of likes, passes data to catalog function for setting likes
void enterLikes() {
	char artist[50];
	//artist name input
	char songName[50];
	//song title input
	char likes[20];
	//new likes input

	std::cout << "For what artist would you like to change a song's likes? ";
	std::cin.getline(artist, 50);
	flushCin();

	std::cout << "What song would you like to changes the likes of? ";
	std::cin.getline(songName, 50);
	flushCin();
	

	std::cout << "How many likes does " << songName << " have? ";
	std::cin.getline(likes, 20);
	flushCin();
	
	try {
		ArtistCatalog::catalog()->setLikesForArtistSong(artist, songName, cstoi(likes));
	} catch (const char* error) {
		std::cerr << error << std::endl;
		return;
	}

	std::cout << songName << " by " << artist << " has " << likes << " likes." << std::endl;
}



//Queries user for a threshold of views, then passes that to the catalog function that removes songs under a certain view number.
void removeByThreshold() {
	char threshold[20];
	//view threshold input

	std::cout << "What would you like to set the view threshold to? ";
	std::cin.getline(threshold, 20);

	try {
		ArtistCatalog::catalog()->removeAllSongsWithViewsUnder(cstoi(threshold));
	} catch (const char* error) {
		std::cerr << error << std::endl;
		return;
	}
	std::cout << "Songs below threshold of " << threshold << " successfully removed." << std::endl;
}

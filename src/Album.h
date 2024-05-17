#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Song.h"

using namespace std;

class Album {
	friend ostream& operator<<(ostream&, const Album& a);
	public:

		//constructors
		Album(const string& artist, const string& albumTitle);

		//destructor
		~Album();

		Song* operator[](int index) const;
		//getters
		const string& getTitle() const {return title;}
		const string& getArtist() const {return artist;}

		//comparison
		bool matches(const string& artist, const string& albumTitle) const;
		bool lessThan(const Album&) const;

		//add and remove
		bool addSong(Song*);
		bool getSong(const string& songTitle, Song**) const;
		bool getSong(int index, Song**) const;
		bool removeSong(const string& songTitle, Song**);
		bool removeSong(int, Song**);

		void printShort(ostream& out) const;
		void print(ostream& out) const;
	
		//getters
		int getSize();
	private:
		string artist;
		string title;
		Array<Song*> songs;
	
};
#endif
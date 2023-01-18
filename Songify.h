#ifndef SONGIFY_H
#define SONGIFY_H

#include <iostream>
#include <string>
#include "AlbumArray.h"

using namespace std;

class Songify {
		
	public:
		//constructors
		Songify();

		//destructor
		~Songify();

		//add and remove Songs and Albums
		bool addAlbum(const string& artist, const string& albumTitle);
		bool addSong(const string& albumTitle, const Song& song);
		// bool addSong(const Song& song);
		bool removeSong(const string& artist, const string& albumTitle, const string& songTitle);
		bool removeAlbum(const string& artist, const string& albumTitle);

		// download to a Client (who presumably will make a copy)
		// essentially a getter for Album with a fancy name
		bool downloadAlbum(const string& artist, const string& albumTitle, Album**) const;
		
		// download to a Client to play
		// essentially a getter for a Song
		bool streamSong(const string& artist, const string& albumTitle, const string& songTitle, Song**) const;

		
		void printAlbums() const;
		void printSongs() const;
	
	private:
		AlbumArray* albums;
	
};
#endif
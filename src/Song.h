#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

using namespace std;

class Song {
		
	friend ostream & operator << (ostream &out, const Song &s);
	
	public:
		//constructors
		Song(const string& artist = "sumfing", const string&  title = "title", const string& category = "cats",const string& content = "cont");

		//getters
		const string& getTitle() const;
		const string& getArtist() const;
		const string& getCategory() const;

		bool matches(const string& artist, const string& title) const;

		void print(ostream& p) const;
		void play(ostream& p) const;

	
	private:
		string title;
		string artist;
		string content;
		string category;
	
};
#endif
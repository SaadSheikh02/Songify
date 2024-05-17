#include "Song.h"

Song::Song(const string& art, const string& tit, const string& cat, const string& cont):artist(art), title(tit), category(cat), content(cont){
}

bool Song::matches(const string& artist, const string& title)const{
    if(artist == getArtist() && title == getTitle()){
        return true;
    }
    else{
        return false;
    }
}

void Song::print(ostream& p)const{
    p << "Artist: "<< artist << "\n";
    p << "Title: " << title << "\n";
    p << "Category "<< category<<endl;
}

void Song::play(ostream& p)const{
    p << "Artist: "<< artist << "\n";
    p << "Title: " << title << "\n";
    p << "Category "<< category<<endl;
    p << "Content: " << content << "\n";
}

//getters
const string& Song::getArtist()const{
    return artist;
}

const string& Song::getTitle()const{
    return title;
}

const string& Song::getCategory()const{
    return category;
}

ostream & operator << (ostream &out, const Song &s){
    s.play(out);
    return out;
}
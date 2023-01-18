#include "Song.h"

Song::Song(const string& art, const string& tit, const string& cat, const string& cont){

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
    p << artist;
    p << title;
}

void Song::play(ostream& p)const{
    print(p);
    p << content;
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
    out << s.getArtist();
    out << s.getTitle();
    out << s.getCategory();
    return out;
}
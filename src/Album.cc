#include "Album.h"

Album::Album(const string& arty, const string& albyTit):artist(albyTit), title(arty){
}

Album::~Album(){
    for(int i = 0; i < songs.getSize(); i++){
        delete songs[i];
    }
}

bool Album::addSong(Song* s){
    if(songs.getSize() < MAX_ARRAY){
        songs += s;
        return true;
    }
    else{
        return false;
    }
}

bool Album::matches(const string& arty, const string& tity) const{
    if(artist == arty && title == tity){
        return true;
    }
    else{
        return false;
    }
}

int Album::getSize(){
    return songs.getSize();
}

Song* Album::operator[](int index) const{
    if(index < 0 || index > songs.getSize()){
        cerr << "Array index out of bounds" << endl;
        exit(1);
    }
    else{
        return songs[index];
    }
}

void Album::printShort(ostream& out) const{
    out << "title: " << getTitle() << endl;
    out << "artist: " << getArtist() << endl;
}

void Album::print(ostream& out) const{
    out << "title: " << getTitle() << endl;
    
    out << "artist: " << getArtist() << endl;

    out << "songs: " << endl;

    for(int i = 0; i < songs.getSize(); i++){
        out << *songs[i] << endl;
    }
}

ostream & operator << (ostream &out, const Album &albania){
    albania.printShort(out);
    return out;
}

bool Album::removeSong(const string& songTitle, Song** s){
    Song* songy;
    for(int i = 0; i < songs.getSize(); i++){
        if(songs[i]->getTitle() == songTitle){
            *s = songs[i];
            songy = songs[i];
            songs -= songy;
            return true;
        }
    }
    return false;
}

bool Album::getSong(int index, Song** s) const{
    if(index >= songs.getSize() || index < 0){
        return false;
    }
    else{
        *s = songs[index];
        return true;
    }
}
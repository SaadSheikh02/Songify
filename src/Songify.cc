#include "Songify.h"

Songify::Songify(){}

Songify::~Songify(){
    for(int i = 0; i < albums.getSize(); i++){
        delete albums[i];
    }
}

const Array<Album*>& Songify::getAlbums(){
    return albums;
}

bool Songify::getAlbum(int index, Album** a){
    if(index >= albums.getSize() || index < 0){
        return false;
    }
    else if(index < albums.getSize()){
        *a = albums[index];
        return true;
    }
    return false;
}

bool Songify::addAlbum(const string& arty, const string& tity){
    Album* alby;
    if(albums.getSize() >= MAX_ARRAY){
        return false;
    }
    if(medium.createAlbum(arty, tity, &alby) == true){
        albums += alby;
        return true;
    }
    else{
        delete alby;
        return false;
    }

}

bool Songify::removeAlbum(const string& arty, const string& tity){
    for(int i = 0; i < albums.getSize(); i++){
        if(albums[i]->matches(arty, tity)){
            albums -= albums[i];
            delete albums[i];
            return true;
        }
    }
    return false;
}

bool Songify::addSong(const string& arty, const string& songTity, const string& albumTity){
    Song* songy;
    bool res = NULL;
    int daWae;
    for(int i = 0; i < albums.getSize(); i++){
        if(albums[i]->matches(arty, albumTity)){
            medium.createSong(arty, songTity, &songy);
            
            if(albums[i]->addSong(songy) == true){
                res = true;
            }
        }
    }
    if(res = NULL){
        res = false;
    }

    return res;

}

bool Songify::removeSong(const string& arty, const string& songTity, const string& albumTity){
    Song* songy;
    int daWae;
    for(int i = 0; i < albums.getSize(); i++){
        if(albums[i]->matches(arty, albumTity)){
            daWae = i;
        }
    }

    return albums[daWae]->removeSong(songTity, &songy);
    
}

void Songify::getPlaylist( const string& artist, const string& category, Array<Song*>& playlist){
    Criteria* griddy;

    if(medium.createCriteria(artist, category, &griddy) == true){
        for(int indyAlb = 0; indyAlb < albums.getSize(); indyAlb++){
            for(int indySong = 0; indySong < albums[indyAlb]->getSize(); indySong++){
                Song* songPtr;
                
                albums[indyAlb]->getSong(indySong, &songPtr);

                if(griddy->matches(*songPtr)){
                    playlist +=songPtr;
                }
            }
        }
    }
    delete griddy;
}
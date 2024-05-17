#include "Criteria.h"

A_Criteria::A_Criteria(const string& a){
    artist = a;
}

C_Criteria::C_Criteria(const string& c){
    category = c;
}

AorC_Criteria::AorC_Criteria(const string& artist, const string& category):A_Criteria(artist), C_Criteria(category){}

bool A_Criteria::matches(const Song& s){
    if(s.getArtist() == artist){
        return true;
    }
    else{
        return false;
    }
}

void A_Criteria::print(ostream& out) const{
    out << "The criteria will match if the artist is the same as " << artist << endl; 
}

bool C_Criteria::matches(const Song& s){
    if(s.getCategory() == category){
        return true;
    }
    else{
        return false;
    }
}

void C_Criteria::print(ostream& out) const{
    out << "The criteria will match if the category is the same as " << category << endl; 
}

bool AorC_Criteria::matches(const Song& s){
    if(C_Criteria::matches(s) && A_Criteria::matches(s)){
        return true;
    }
    else{
        return false;
    }
}

void AorC_Criteria::print(ostream& out) const{
    A_Criteria::print(out);
    C_Criteria::print(out);
}

ostream & operator << (ostream &out, const Criteria &critter){
    critter.print(out);
    return out;
}
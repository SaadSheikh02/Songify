#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <string>
#include "Song.h"

using namespace std;

class Criteria {
	friend ostream& operator<<(ostream&, const Criteria& c);
	public:
	virtual bool matches(const Song& song) = 0;
	virtual void print(ostream& print) const = 0;

};

class A_Criteria : virtual public Criteria{
	public:
		A_Criteria(const string& artist);
		bool matches(const Song& song);
		void print(ostream& print) const;
	
	private:
		string artist;
};

class C_Criteria : virtual public Criteria{
	public:
		C_Criteria(const string& category);
		bool matches(const Song& song);
		void print(ostream& print) const;
	
	private:
		string category;
};

class AorC_Criteria : virtual public A_Criteria, virtual public C_Criteria{
	public:
		AorC_Criteria(const string& artist, const string& category);
		bool matches(const Song& song);
		void print(ostream& print) const;
	
};
#endif
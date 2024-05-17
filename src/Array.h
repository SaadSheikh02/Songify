
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {
	template <class V>
	friend ostream& operator<<(ostream& out, Array<V>& arr);
	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		T& operator[](int index);
		T& operator[](int index) const;
		int getSize() const;
		bool isFull();
		Array<T>& operator+=(T&);
		Array<T>& operator-=(T&);
		void clear();
	
	private:
		int size;
		T* elements;
	
};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
int Array<T>::getSize() const{
	return size;
}

template <class T>
bool Array<T>::isFull(){
	return size >= MAX_ARRAY;
}

template <class T>
T& Array<T>::operator[](int index) const{
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
T& Array<T>::operator[](int index){
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
ostream& operator<<(ostream& out, Array<T>& arr){
	for(int i = 0; i < arr.size; i++){
		out << arr.elements[i] << endl;
	}
	return out;
}

template <class T>
Array<T>& Array<T>::operator+=(T& ting){
	if(size >= MAX_ARRAY){
		return *this;
	}
	else{
		elements[size++] = ting;
		return *this;
	}
}

template <class T>
Array<T>& Array<T>::operator-=(T& ting){ // change this to shift elements up, after finding element
	int indexOfDaTing;

	if(size >= MAX_ARRAY){
		return *this;
	}
	else{

		for(int i = 0; i < size; i++){
			if(elements[i] == ting){
				// cout << *elements[i] << endl;
				for(int j = i; j < size; j++){
					elements[j] = elements[j+1];
				}
				size = size - 1;
			}
		}
		return *this;
	}

}

template <class T>
void Array<T>::clear(){
	for(int i = size-1; i >= 0; i--){
		elements[i] = {};
		size = size - 1;
	}
}
#endif
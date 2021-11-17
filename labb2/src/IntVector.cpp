// Labb2, IntVector.cpp – definitioner av icke-triviala medlemsfunktioner

#include <cstring>
#include <iostream>
#include "IntVector.h"

IntVector::IntVector():length(0), int_arr(nullptr) { //null och inte null pointer?
}

IntVector::IntVector(const std::initializer_list<int>& initlist) : length(0), int_arr(new int[0]){
    for(int i : initlist){
        push_back(i);
    }
}

IntVector::IntVector(const IntVector& other) : length(other.length), int_arr(new int[length]){

    std::memcpy(int_arr, other.int_arr, length);
    
}

const IntVector& IntVector::operator=(const IntVector& other) {
	if (this != &other) {
		delete[] int_arr;
		length = other.length;
		int_arr = new int[other.length];
        std::memcpy(int_arr, other.int_arr, length);
	}
	return *this;
}

IntVector::IntVector(IntVector&& other) : length(other.length), int_arr(other.int_arr) { //move, värden i metodheadern istället
	other.int_arr = nullptr;
}

IntVector::~IntVector(){
	delete[] int_arr;
}

int& IntVector::operator[](int pos) {
	return int_arr[pos];
}

int IntVector::operator[](int pos) const {
	return int_arr[pos];
}

int IntVector::size() const {
    return length ;
}

void IntVector::push_back(const int& newInt) {

    int *temp_arr = new int[length+1];

    for (int i = 0; i < length; i++){
        temp_arr[i] = int_arr[i];
    }

    temp_arr[length] = newInt;

    delete[] int_arr;
    int_arr = temp_arr;
    length++;
}

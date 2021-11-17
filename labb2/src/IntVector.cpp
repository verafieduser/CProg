//Vera Sol Nygren

#include <cstring>
#include <iostream>
#include "IntVector.h"

//Default constructor
IntVector::IntVector():length(0), int_arr(nullptr) {}

//Init-list constructor
IntVector::IntVector(const std::initializer_list<int>& initlist) : length(0), int_arr(new int[0]){
    for(int i : initlist){
        push_back(i);
    }
}

//Copy constructor
IntVector::IntVector(const IntVector& other) : length(other.length), int_arr(new int[length]){
    for(int i = 0; i < length; i++){
        int_arr[i] = other.int_arr[i];
    }
}

//Assignment constructor
const IntVector& IntVector::operator=(const IntVector& other) {
	if (this != &other) {
		delete[] int_arr;
		length = other.length;
		int_arr = new int[other.length];

        for(int i = 0; i < length; i++){
            int_arr[i] = other.int_arr[i];
        }
	}
	return *this;
}

//Move constructor
IntVector::IntVector(IntVector&& other) : length(other.length), int_arr(other.int_arr) {
	other.int_arr = nullptr;
}

//Deconstructor
IntVector::~IntVector(){
	delete[] int_arr;
}

//@ operator
int& IntVector::operator[](int pos) {
	return int_arr[pos];
}

//@ operator const
int IntVector::operator[](int pos) const {
	return int_arr[pos];
}

int IntVector::size() const {
    return length ;
}

void IntVector::push_back(const int& newInt) {
    int *temp_arr = new int[length+1];

    //Copies previous values into temporary array.
    for (int i = 0; i < length; i++){
        temp_arr[i] = int_arr[i];
    }
    temp_arr[length] = newInt;
    delete[] int_arr;
    int_arr = temp_arr;
    length++;
}

// Labb2, IntVector.cpp – definitioner av icke-triviala medlemsfunktioner

#include <cstring>

#include "IntVector.h"

IntVector::IntVector():length(0), cptr(nullptr) {
}

IntVector::IntVector(const char* str) : length(std::strlen(str)+1),
cptr(new char[length])
{

    std::memcpy(cptr, str, length);

}

IntVector::IntVector(const IntVector& other) {
	length = other.length;
	cptr = new char[length];

    std::memcpy(cptr, other.cptr, length);
}

const IntVector& IntVector::operator=(const IntVector& other) {
	if (this != &other) {
		delete[] cptr;
		length = other.length;
		cptr = new char[other.length];
        std::memcpy(cptr, other.cptr, length);
	}
	return *this;
}

IntVector::IntVector(IntVector&& other) {
	length = other.length;
	cptr = other.cptr;
	other.cptr = nullptr;
	other.length = 0;
    //delete other?
}

IntVector::~IntVector(){
	delete[] cptr;
}

char& IntVector::operator[](int pos) {
	return cptr[pos];
}

int IntVector::size() {
    if(length == 0){
        return 0;
    }
    return length -1;
}
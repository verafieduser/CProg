class IntVector
{
public:
	IntVector();
	IntVector(const int* str);
	IntVector(const std::initializer_list<int>& initlist);
	IntVector(const IntVector& other);
	IntVector(IntVector&& other);
	const IntVector& operator=(const IntVector& other);
	int& operator[](int pos);
	int operator[](int pos) const;
	int size() const;
    void push_back(const int& newInt);
	~IntVector();
private:
	int length;
	int* int_arr;
	friend std::ostream &operator<<(std::ostream &os, const IntVector &intArray);
};

inline std::ostream& operator<< (std::ostream &out, const IntVector& intArray) { 
    int i;
    int amount_of_ints;
    for (i = 0, amount_of_ints = intArray.length; i < amount_of_ints; i++){
        out << intArray[i] << " ";
    }
    return out;
}


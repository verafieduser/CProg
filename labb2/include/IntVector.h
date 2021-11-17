class IntVector
{
public:
	IntVector();
	IntVector(const char* str);
	IntVector(const IntVector& other);
	IntVector(IntVector&& other);
	const IntVector& operator=(const IntVector& other);
	char& operator[](int pos);
	int size();
    void push_back(const int& newInt);
	~IntVector();
private:
	int length;
	char* cptr;
};


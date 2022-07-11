#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include "dijkstra.h"
#include "bellman_ford.h"
using std::array, std::vector, std::unique_ptr, std::shared_ptr;

class Simple
{
public:
	void go() { cout << "called go method, might fail !!!" << endl; }
	Simple() { cout << "Simple constructor called!" << endl; }
	~Simple() { cout << "Simple destructor called!" << endl; }
};

void leaky();
char **allocateCharacterBoard(size_t xDimension, size_t yDimension);
void releaseCharacterBoard(char **&myArray, size_t xDimension);
void notLeaky(Simple *s);

int main()
{
	/*
	int *ptr{nullptr};
	ptr = new int;
	*/
	// OR
	int *ptr{new int};
	delete ptr;
	ptr = nullptr;

	int **handle{nullptr};
	handle = new int *;
	*handle = new int;
	delete *handle, handle;	   // first deallocate
	*handle, handle = nullptr; // then set to nullptr

	int myArray[]{};			 // an address
	int *myArray2{new int[5]{}}; // (fixed size array) an address, Zero(dereferenced)
	delete[] myArray2;
	myArray2 = nullptr;

	Simple *mySimpleArray{new Simple[4]};
	delete[] mySimpleArray;
	mySimpleArray = nullptr;

	vector<vector<int>> twoDimensionalVector{{}};

	//! smart pointers !!
	unique_ptr<Simple> mySimpleSmartPtr{new Simple{}};
	notLeaky(mySimpleSmartPtr.get()); //!
	mySimpleSmartPtr.reset(new Simple{});
}

void leaky()
{
	new int; // BUG! Orphans/leaks memory!
	cout << "I just leaked an int!" << endl;
}

char **allocateCharacterBoard(size_t xDimension, size_t yDimension)
{
	char **myArray{new char *[xDimension]}; // Allocate first dimension
	for (size_t i{0}; i < xDimension; i++)
	{
		myArray[i] = new char[yDimension]; // Allocate ith subarray
	}
	return myArray;
}

void releaseCharacterBoard(char **&myArray, size_t xDimension)
{
	for (size_t i{0}; i < xDimension; i++)
	{
		delete[] myArray[i]; // Delete ith subarray
		myArray[i] = nullptr;
	}
	delete[] myArray; // Delete first dimension
	myArray = nullptr;
}

void notLeaky(Simple *s)
{
	// auto mySimpleSmartPtr { make_unique<Simple>() };
	auto mySimpleSmartPtr{std::make_unique<Simple>()}; //! better for performance
	mySimpleSmartPtr->go();
}
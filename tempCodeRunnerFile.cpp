int *myIntegerInFreeStore1{nullptr}; // declare uninitialized variable
	// myIntegerInFreeStore1 = new int;	 // allocate in free space
	// *myIntegerInFreeStore1 = 8;			 // initializing
	// int i{9};
	// int *myIntegerInFreeStore2{&i};	 // pointing to Address of i
	// delete myIntegerInFreeStore2;	 // deallocate in free space
	// myIntegerInFreeStore2 = nullptr; // prevent using after deallocation

	// Employee *anEmployee3{&anEmployee2}; // pointing to address of anEmployee2 by variable anEmployee3
	// (*anEmployee3).employeeNumber;		 // dereference then access
	// // OR
	// int en3 = anEmployee3->employeeNumber; // dereference and access
	// cout << en3 << endl;
	// bool isValidSalary{(anEmployee3 != nullptr && anEmployee3->salary > 0)};

	// int arraySize{5};							   // on the stack
	// int *myVariableSizedArray{new int[arraySize]}; // Dynamically Allocated Arrays in free store(heap)
	// myVariableSizedArray[0] = 10;
	// myVariableSizedArray[1] = 20;
	// myVariableSizedArray[2] = 30;
	// cout << myVariableSizedArray[0] << myVariableSizedArray[1] << myVariableSizedArray[2] << endl;
	// delete[] myVariableSizedArray;
	// myVariableSizedArray = nullptr;

	// //! read from right to left
	// const int *ipp;
	// // SIMILAR, both const the value
	// int const *ip;
	// ipp = new int[10];
	// // ipp[4] = 5; // DOES NOT COMPILE!
	// ip = new int[10];
	// // ip[4] = 5; // DOES NOT COMPILE!

	// int *const iip{nullptr}; // initialization required; const the iip itself
	// // iip = new int[10]; // DOES NOT COMPILE!
	// // iip[4] = 5;		   // Error: dereferencing a null pointer

	// int *const ippp{new int[10]};
	// ippp[4] = 5;

	// int const *const ip41{nullptr};
	// // SIMILAR: const both ip4 itself and value
	// const int *const ip42{nullptr};
	// int const *const ip43{nullptr};

	// string myString2{"The string"};
	// mysteryFunction(&myString2);

	// constexpr double const_inch{6.0};
	// constexpr double mm1{inchToMm(const_inch)}; // at compile time

	// double dynamic_inch{8.0};
	// double mm2{inchToMm(dynamic_inch)}; // at run time
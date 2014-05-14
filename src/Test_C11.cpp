//============================================================================
// Name        : Test_C11.cpp
// Author      : Olivia Neacsu
// Version     :
// Copyright   : Olivia - no copyright needed
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// Example - The C++ programming language 4th Edition, C++11 included, page 496
struct X{
	X(initializer_list<int>){ cout << "Initializer-list constructor"<<endl;}
	X(){ cout<< "default constructor"<<endl;}
	X(int){ cout << "one parameter constructor";}
};

int main() {
	cout << "Test C++11 features" << endl;
	X x0{}; // default constructor is preferred instead of initializer-list constructor
	X x1{1}; // initializer-list constructor is chosen, instead of one parameter constructor

	return 0;
}

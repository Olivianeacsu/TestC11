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

// Example - The C++ programming language 4th Edition, C++11 included, page 492
class S1{
	public: int a,b;
};

class S2{
	int m_a,m_b;
public:
	S2(int a=0, int b=0):m_a(a), m_b(b){}
};

int main() {
	cout << "Test C++11 features" << endl;
	X x0{}; // default constructor is preferred instead of initializer-list constructor
	X x1{1}; // initializer-list constructor is chosen, instead of one parameter constructor

	// Ex - Initialization by Constructors
	//S1 x11(1,2);   // error, no constructor
	S1 x12{1,2};   // Ok; member-wise initialization
	      // when private attributes: error: no matching constructor for initialization of 'S1'
	   // solution: make them public, as struct has by default

	S2 x21(1,2); // ok, use constructor
	S2 x22{1,2}; // ok, use constructor

	S2 x23(1);   // ok, use constructor and one default argument
	S2 x241{1};  // ok, use constructor and one default argument



	return 0;
}

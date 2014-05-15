//============================================================================
// Name        : Test_C11.cpp
// Author      : Olivia Neacsu
// Version     :
// Copyright   : Olivia - no copyright needed
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Example - The C++ programming language 4th Edition, C++11 included, page 496
struct X{
	X(initializer_list<int>){ cout << "Initializer-list constructor"<<endl;}
	X(){ cout<< "default constructor"<<endl;}
	X(int){ cout << "one parameter constructor";}
};
////////////////////

// Example - The C++ programming language 4th Edition, C++11 included, page 492
class S1{
	public: int a,b;
};

class S2{
	int m_a,m_b;
public:
	S2(int a=0, int b=0):m_a(a), m_b(b){}
};
////////////////////

// automatic type deduction
void funcTest(const vector<int> &vi){
	auto ci = vi.begin();
}
////////////////////

// C++11 supports in-class initialization of data members
class MyClass{
	int a = 7; // C++11 only
public:
	MyClass();
};
////////////////////

// example Defaulted functions
struct A
{
 A()=default; //C++11
 virtual ~A()=default; //C++11
};
////////////////////

// example Deleted Functions
struct NoCopy
{
	NoCopy() = default;
	NoCopy & operator =( const NoCopy & ) = delete;
	NoCopy ( const NoCopy & ) = delete;
};
////////////////////

// nullptr
void funcAmbigous(int a){ cout<<"funcAmbigous(int) called" <<endl;}
void funcAmbigous(char *c) { cout << "funcAmbigous(char*) called" <<endl;}
////////////////////

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

    // automatic type deduction and decltype; C++11 has changed the meaning of keyword 'auto'
	auto x=0; // x has type int because 0 is int
    auto c = 'a'; // char
    auto d = 0.76; //double

    cout << "variables declared with auto: "<< x <<" "<<c <<" "<<d;

    // C++11 container initializers - initialize containers intuitively
    vector<string> vs = {"first", "second", "third"};
    map<string, string> singers ={ {"Olivia Neacsu", "+46 727242724"},
    {"Anna Winquist", "+46 723299133"}};

    // example - deleted functions - usage: prevent object copying
    NoCopy a;
   // NoCopy b(a);  // error: call to deleted constructor of 'NoCopy'

    // example nullptr
    // C++ 2003
    funcAmbigous(0); // 0 is both int as NULL; which one will be called? with int or with char *
                    // my compiler chose to call the one with int
    //C++ 11
    funcAmbigous(nullptr); // the function with char* called. no ambiguities

	return 0;
}

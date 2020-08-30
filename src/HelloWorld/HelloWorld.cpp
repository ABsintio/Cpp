#include <iostream>

/*
All the elements in the standard C++ library are declared within what is called a namespace: the namespace std.
In order to refer to the elements in the std namespace a program shall either qualify each and every use of elements 
of the library. The most typical way to introduce visibility of these components is by means of using declarations.
The above declaration allows all elements in the std namespace to be accessed in an unqualified manner (without the std:: prefix).
*/
using namespace std;

int main() {
	cout << "Hello, World! ";
	cout << "I'm a C++ program ";
}
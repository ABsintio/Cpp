#include <iostream>

using namespace std;

// Definizione di costanti tramite const
const double pi = 3.14159;
const char newline = '\n';

// Definizione di costanti tramite #define
/*
#define PI 3.14159;
#define NEWLINE '\n';
*/

int main() {

	double r = 5.0;               // radius
  	double circle;

  	circle = 2 * pi * r;
  	cout << circle << endl;
  	cout << newline << endl;

	return 0;
}
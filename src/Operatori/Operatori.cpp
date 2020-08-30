/*
Bit-wise operator:
	- &  : Bitwise AND
	- |  : Inclusive bitwise OR
	- ^  : Exclusive bitwise OR (XOR)
	- ~  : NOT
	- << : Shift Left
	- >> : Shift rigth

Operatori di casting di tipo esplicito:
	Lo possiamo fare anteponendo ad una variabile
	il nuovo tipo tra parentesi (vedi codice).

	1) var_name = (<new_type>) other_var;
	2) var_name = <new_type> (other_var);

Operatore sizeof
	Restituisce la dimensione in byte dell'oggetto in input.

	1) size_t var_name = sizeof(<type>)
	2) size_t var_name = sizeof(<var_object>)
*/
#include <iostream>

using namespace std;

#define NEWLINE '\n';

int main() {

	// Casting da float ad int di tipo 1
	int i;
	float f{3.14};
	i = (int) f;

	cout << "Casting da float ad int di tipo 1: ";
	cout << "var_name = (<new_type>) other_var" << endl;
	cout << "Valore: ";
	cout << i << endl;
	cout << NEWLINE;

	// Casting da float ad int di tipo 2
	int j;
	j = int (f);

	cout << "Casting da float ad int di tipo 2: ";
	cout << "var_name = <new_type> (other_var)" << endl;
	cout << "Valore: ";
	cout << j << endl;
	cout << NEWLINE;

	// Operatore sizeof
	size_t size_char  = sizeof(char);
	size_t size_int   = sizeof(i);
	size_t size_float = sizeof(f);

	cout << "Operatore sizeof di tipo 1: size_t var_name = sizeof(<type>)" << endl;
	cout << "sizeof(char) = ";
	cout << size_char << endl;
	cout << NEWLINE;
	cout << "Operatore sizeof di tipo 2: size_t var_name = sizeof(<var_object>)" << endl;
	cout << "sizeof(i) = ";
	cout << size_int << endl;
	cout << NEWLINE;
	cout << "Operatore sizeof di tipo 2: size_t var_name = sizeof(<var_object>)" << endl;
	cout << "sizeof(f) = ";
	cout << size_float << endl;

	return 0;
}
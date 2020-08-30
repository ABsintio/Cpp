/*
Le parole chiave riservate standard che non possono essere utilizzate per gli identificatori creati dal programmatore sono:

alignas, alignof, and, and_eq, asm, auto, bitand, bitor, bool, break, case, catch, char, char16_t, char32_t, class, compl, 
const, constexpr, const_cast, continue, decltype, default, delete, do, double, dynamic_cast, else, enum, explicit, export, 
extern, false, float, for, friend, goto, if, inline, int, long, mutable, namespace, new, noexcept, not, not_eq, nullptr, 
operator, or, or_eq, private, protected, public, register, reinterpret_cast, return, short, signed, sizeof, static, 
static_assert, static_cast, struct, switch, template, this, thread_local, throw, true, try, typedef, typeid, typename, union, 
unsigned, using, virtual, void, volatile, wchar_t, while, xor, xor_eq

Tipi di dati:
	1. Tipi di carattere:
		- char     (almeno 8 bit)
		- char16_t (almeno 16 bit)
		- char32_t (almeno 32 bit)
		- wchar_t  (il più ampio set di caratteri supportato)

	2. Tipi numerici interi
		2.1. Segnati
			- signed char          (almeno 8 bit)
			- signed short int     (almeno 16 bit)
			- signed int 	   	   (almeno 16 bit)
			- signed long int      (almeno 32 bit)
			- signed long long int (almeno 64 bit)

		2.2. Non segnati
			- unsigned char          (almeno 8 bit)
			- unsigned short int     (almeno 16 bit)
			- unsigned int 	   	     (almeno 16 bit)
			- unsigned long int      (almeno 32 bit)
			- unsigned long long int (almeno 64 bit)

	3. Tipi a virgola mobile (più aumentano i bit più precisione hanno)
		- float 
		- double
		- long double

	4. Tipo booleano
		- bool

	5. Tipo vuoto
		- void

Metodi di inizializzazione delle variabili:
	1) <type> var_name = value;
	2) <type> var_name (value);
	3) <type> var_name {value};
*/
#include <iostream>

using namespace std;

int main() {

	int a = 5;	// Inizializzazione di tipo 1
	int b(2);	// Inizializzazione di tipo 2
	int c{3};	// Inizializzazione di tipo 3
	int result;

	result = a + (b * 3);

	cout << result;
	return 0;
}
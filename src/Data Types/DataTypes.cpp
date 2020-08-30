/*
Type aliases:
	Un "type alias" è un nome differente tramite il quale un tipo può essere indicato.
	In C++ qualsiasi tipo valido può avere un alias, e questo viene creato un due modi
	diversi:

	1. usando la keyword "typedef" (molto simile a C).

		typedef <type> <new_type_def>;

	2. usando la keyword "using" introdotta in C++.

		using <new_type_def> = <type>;

	Questa operazione può essere utilizzata per ridurre la lunghezza di tipi lunghi
	o con nomi difficili, ma è soprattutto utilizzata come tool per astrarre i programmi
	dai tipi che utilizzano.

Unions:
	Union permette di accedere ad una porzione della memoria con differenti tipi di dato.
	La sintassi per la dichiarazione è molto simile a quella dello "struct" ma la sua 
	funzionalità è totalmente diversa. Ogni membro occupa lo stesso spazio in memoria
	e la dimensione dell'union è pari a quella del membro con dimensione più ampia.

Enumerated Type:
	Sono tipi che sono definiti con un set di identificatori custom come possibili valori.
	Gli oggetti di questo tipo possono prendere ognuno di questi enumeratori come valore.
	La sintassi è la seguente:

	enum <type_name> {
		value1,
		value2,
		value3,
		...
		valueN
	} object_name;
	
	Possiamo dire che questo va a creare un insieme di nuovi tipi di dato senza basarsi
	su quelli già esistenti. Agli enumerators viene assegnato per default un valore intero
	i.e. value1 = 0, ..., valueN = N - 1. E' però possibile definire i valori da assegnare
	semplicemente inizializzando gli enumerators con un intero a nostra scelta.

Enum class:
	In C++ è possibile creare tipi enum "reali" ossia che non sono sia convertibili in int 
	e sia che non hanno enumeratori di tipo int, ma sono di tipo enum stesso. Questi sono
	dichiarati con "enum class" (o struct) invece di solo "enum". Questi tipi hanno molto
	più controllo sul tipo sottostante; può essere qualsiasi tipo di dato integrale, come
	char, short o unsigned int, che essenzialmente serve a determinare la dimensione del 
	tipo. Questo lo possiamo fare nel seguente modo

	enum class <type_name> : <type> { ... };

*/
#include <iostream>

using namespace std;

#define BUFF 50;

// Definizioni di alias con typedef
typedef char C;
typedef unsigned int WORD;
typedef char * pChar;
typedef char field[50];

// Definizioni di alias con using
using u_C     = char;
using u_WORD  = unsigned int;
using u_pChar = char *;
using u_field = unsigned long int [50];

// Dichiarazione union type
union mytypes_t {
	char  c;
	int   i;
	float f;
} mytypes;

// Dichiarazione di un tipo enum
enum colors_t {
	// Default black=0
	black=1, blue,   green,  cyan,
	red,   purple, yellow, white
};

// Dichiarazione di tipo enum class
enum class Colors {
	black, blue,   green,  cyan,
	red,   purple, yellow, white
};

enum class EyeColor : char { blue, green, brown };

int main() {

	// Inizializzazione usando i primi alias
	cout << "TYPEDEF INITIALIZATION" << endl;
	C mychar {'c'};
	pChar ptc;
	ptc = &mychar;
	cout << mychar << ", " << *ptc << endl;

	// Inizializzazione usando i secondi alias
	cout << "USING INITIALIZATION" << endl;
	u_C mychar2 {'c'};
	u_field campo;
	campo[0] = 1;
	for (int n = 1; n < 50; n++){
		campo[n] = (n + 1) * campo[n - 1];
	}
	cout << mychar2 << endl;
	for (auto i: campo){
		cout << i << " ";
	}
	cout << endl;

	// Inizializzazione tramite union type
	cout << "UNION TYPE INITIALIZATION" << endl;

	// Ricordiamo che tutti i tipi in mytypes 
	// condividono lo stesso spazio in memoria
	// quindi non possiamo memorizzare più valori
	// contemporaneamente, altrimenti andremo a
	// sovrascrivere quelli precedenti.
	mytypes.c = 'c';
	cout << mytypes.c << ", ";
	mytypes.i = 9;
	cout << mytypes.i << ", ";
	mytypes.f = 3.14956;
	cout << mytypes.f << endl;

	// Inizializzazione tramite enum
	cout << "ENUM TYPE INITIALIZATION" << endl;
	colors_t mycolor;
	mycolor = blue;
	cout << mycolor << endl; // con black=0 -> blue=1

	// Inizializzazione tramite enum class
	cout << "ENUM CLASS TYPE INITIALIZATION" << endl;
	Colors color;
	color = Colors::blue;
	
	return 0;
}
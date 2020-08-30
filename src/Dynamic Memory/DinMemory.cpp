/*
E' possibile allocare dinamicamente memoria utilizzando il costrutto "new" seguito dal tipo
di dato (int, float, char ...) e se è una sequenza di più di un elemento bisogna inserirne 
la dimensione tra le parentesi quadre. La sintassi è

	pointer = new <type>
	pointer = new <type> [<number_of_elements>]

La differenza principale tra la normale dichiarazione di un array ed una fatta con allocazione
della memoria è che nella prima la dimensione deve essere definita come costante prima di runnare
l'applicazione, mentre nella seconda la dimensione può cambiare a runtime.

Con la chiamata al costrutto new il programma alloca la memoria dinamicamente dall'heap, il quale
ha una memoria di per se limitata. Quindi non si assicura che tutte le chiamate fatto a new vadano
a buon fine. Fortunatamente C++ fornisce due meccanismi per controllare che l'allocazione sia andata
a buon fine. 

	1. Handling Exceptions. (PREFERIBILE)
		Quando l'allocazione fallisce il metodo new lancia un'eccezzione del tipo bad_alloc
		la quale viene catturata dal metodo new stesso. 

	2. Nothrow.
		Quando l'allocazione fallisce il metodo new non lancia un'eccezzione ma ritorna un
		puntatore nullo (nullptr).

In molti casi, la memoria allocata dinamicamente è necessaria solo per una particolare durata di tempo
all'interno del programma; nel momento in cui questa non è più di alcuna utilità può essere eliminata
(in gergo "deallocata") di modo che sia disponibili per una futura allocazione. Questo può essere fatto
dall'operatore "delete" la quale sintassi è

	delete   pointer;
	delete[] pointer;

Il primo statement dealloca memoria per puntatori dichiarati con "new <type>", mentre il secondo per le
sequenze di lunghezza maggiore di 1. Nel caso in cui il puntatore sia un nullpointer, delete non produce
alcun effetto.

E' possibile utilizzare le operazioni: malloc, realloc, calloc, free definite da C semplicemente includendo
<cstdlib> (noto come <stdlib.h> in C). Qualora si utilizziano tali operatori è molto importante non andarli
a mischiare con new e delete in quanto i blocchi di memoria allocati non sono sempre compatibili.
*/
#include <iostream>
#include <new>

using namespace std;

namespace allocthrow {
	int *allocarray(int n){
		int *c = new int[n];
		return c;
	}
}

namespace allocnothrow {
	int *allocarray(int n) {
		int *c = new (nothrow) int[n];
		return c;
	}

	void allocdealloc() {
		int i, n;
		int *p;
		cout << "How many numbers would you like to type? ";
		cin >> i;
		p = new (nothrow) int[i];
		if (p == nullptr) {
			cerr << "Error: memory could not be allocated";
		} else {
			for (n = 0; n < i; n++) {
				cout << "Enter number: ";
				cin >> p[n];
			}
			cout << "You've entered: ";
			for (n = 0; n < i; n++) {
				cout << p[n] << ", ";
			}
			cout << endl;
			delete[] p;
		}
	}
}

int main() {

	int *foo1 = allocthrow::allocarray(5);
	int *foo2 = allocnothrow::allocarray(5);

	if (foo2 == nullptr) {
		cout << "Problema allocazione di memoria dinamica" << endl;
		return 1;
	}

	allocnothrow::allocdealloc();

	cout << "Tutto OK!" << endl;

	return 0;
}
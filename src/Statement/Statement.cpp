/*
Goto statement:
	Lo statment goto permette di eseguire dei salti 
	verso un particolare punto del programma. Questo 
	salto incondizionato ignora i livelli di annidamento 
	e non causa alcun svolgimento automatico dello stack.
	Il punto di destinazione è identificato con un'etichetta
	che viene quindi utilizzata come argomento per goto.
*/
#include <iostream>

using namespace std;

int main() {

	int n {10};

	mylabel:
		cout << n << ", ";
		n--;
		if (n > 0) goto mylabel;

	cout << "Decollo" << endl;

	return 0;
}
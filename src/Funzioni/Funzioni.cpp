/*
Come sappiamo delle funzioni possono prendere degli argomenti in input 
e restituire un valore. Gli argomenti possono essere passati per valore
o per riferimento. Nel primo caso (vedi simple_factorial), semplicemente
andiamo a creare un nuova variabile x alla quale assegnamo il valore di i
preso dall'input, infatti nell'ultimo cout il valore di i rimane sempre lo
stesso nonstante nella funzione x venga decrementato. 

Le funzioni che prendomo parametri tramite il riferimento, seguono la
seguente sintassi

		<return_type> fun_name(<type_1>& arg1, ..., <type_N>& argN)

e la feature principale è che se gli argomenti in input vengono cambiati
allora verrà cambiato il valore anche delle variabile dalle quali hanno
preso quei valori (vedi secondo esempio).

Il costrutto inline:
	dice al compilatore di non invocare la funzione nel modo normale ma 
	di trasportare il contenuto (codice) di essa sulla riga in cui è 
	stata invocata. Questo produce ottimizzazione nel momento in cui 
	sarebbe più veloce scrivere direttamente il codice piuttosto che 
	invocare effettivamente una funzione. 

Prototipazione:
	Come ben sappiamo per poter utilizzare una funzione nel main dobbiamo
	prima andarla a dichiarare. Ma se volessimo dichiararla dopo il main?
	Beh semplicemente dobbiamo andare ad aggiungere la signature, ossia 
	il prototipo della funzione, contenente il nome, il tipo ritornato e 
	il tipo degli argomenti in input. Dopo aver aggiunto questo è possibile
	definire la funzione dopo il main.
*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

long recursive_factorial(long); // Prototipo della funzione

int simple_factorial(int x) {
	int result = x;
	do {
		result = result * (x - 1);
		x--;
	} while (x > 1);
	return result;
}

void duplicate(int& a, int& b, int& c){
	a *= 2;
	b *= 2;
	c *= 2;
}

inline string concatenate(const string& a, const string& b) {
	return a + b;
}

int main() {

	// Semplice funzione per il fattoriale
	cout << "Inserisci un numero intero tra 1 e 5: ";
	int i;
	cin >> i;
	int fact = simple_factorial(i);
	cout << "Il fattoriale di " << i << " è: " << fact << endl;

	// Funzione con argomenti passati per riferimento.
	int x{1}, y{2}, z{3};
	duplicate(x, y, z);
	cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

	// Funzione inline
	string str1{"Ciao, come stai? "}, str2{"Io mi chiamo Riccardo"};
	string conc = concatenate(str1, str2);
	cout << conc << endl;

	// Funzione ricorsiva con prototipazione
	long result = recursive_factorial(i);
	cout << "Il fattoriale di " << i << " è: " << result << endl;

	return 0;
}

long recursive_factorial(long x) {
	if (x > 1) {
		return x * recursive_factorial(x - 1);
	} else {
		return 1;
	}
}
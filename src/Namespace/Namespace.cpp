/*
Ogni variabile ha uno scope nel quale mantiene un proprio valore che
non può essere acceduto da altri elementi al di fuori di quello scope.

Può esistere una sola entità con un nome particolare in un determinato 
ambito. Questo è raramente un problema per i nomi locali, poiché i blocchi 
tendono ad essere relativamente brevi ei nomi hanno scopi particolari al 
loro interno, come denominare una variabile contatore, un argomento, ecc ...

Ma i nomi non locali offrono più possibilità di collisione di nomi , soprattutto 
considerando che le librerie possono dichiarare molte funzioni, tipi e variabili,
nessuna delle quali di natura locale, e alcune di esse molto generiche.

Gli spazi dei nomi ci consentono di raggruppare entità denominate che altrimenti 
avrebbero un ambito globale in ambiti più ristretti, dando loro l' ambito dello 
spazio dei nomi . Ciò consente di organizzare gli elementi dei programmi in diversi 
ambiti logici a cui si fa riferimento per nome.

La parola chiave using introduce un nome nella regione dichiarativa corrente 
(come un blocco), evitando così la necessità di qualificare il nome. Possiamo 
utilizzare using per introdurre l'intero spazio dei nomi.
*/
#include <iostream>

using namespace std;

// Dichiarazione di un namespace
namespace foo {
	int value() { return 5; }
}

namespace bar {
	const double pi = 3.14159;
	double value() { return 2 * pi; }
}

namespace nsp {
	int n {5}, m {2}, p {6};
}

namespace namesp {
	int n {5}, m {2}, p {6};
}

int main() {

	int x{50}, y{50};

	{
		int x;
		x = 10; // La x non viene cambiata in quanto ridichiarata
		y = 20; // La y viene cambiata
		cout << "inner block:\n";
    	cout << "x: " << x << '\n';
    	cout << "y: " << y << '\n';
	}

	cout << "outer block:\n";
  	cout << "x: " << x << '\n'; // La x non è cambiata
  	cout << "y: " << y << '\n'; // La y è stata cambiata nel blocco interno,

  	cout << foo::value() << '\n';
  	cout << bar::value() << '\n';
  	cout << bar::pi << '\n';

  	// Dichiarativa using
  	using nsp::n;
  	using nsp::m;
  	cout << n << '\n';
  	cout << m << '\n';
	cout << nsp::p << '\n';

	using namespace namesp;
	cout << n << '\n';
  	cout << m << '\n';
	cout << p << '\n';

	return 0;
}
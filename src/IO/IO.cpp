/*
Vari tipi di stream:
	1) cin  : flusso di input standard  		(stdin)
	2) cout : flusso di output standard 		(stdout)
	3) cerr : flusso di errore standard 		(stderr)
	4) clog : flusso di registrazione standard

Flusso di output standard:
	Per le azioni di output formattato viene utilizzato insieme
	all'operatore di inserimento "<<". Più operazioni di inserimento 
	(<<) possono essere concatenate in una singola istruzione. 

Flusso di input standard:
	Per le operazioni di input formattate, cinviene utilizzato insieme 
	all'operatore di estrazione, scritto come >>. Questo operatore è 
	quindi seguito dalla variabile in cui vengono memorizzati i dati 
	estratti. Ma questo metodo ha anche un grosso svantaggio. Cosa 
	succede se l'utente inserisce qualcos'altro che non può essere 
	interpretato come un numero intero? Ebbene, in questo caso, l'operazione 
	di estrazione fallisce. E questo, per impostazione predefinita, 
	consente al programma di continuare senza impostare un valore per la 
	variabile, producendo risultati indeterminati se il valore viene 
	utilizzato successivamente. Le estrazioni su cinpossono anche essere 
	concatenate per richiedere più di un dato in una singola istruzione

	Possiamo utilizzare cin per estrarre anche delle stringhe, tuttavia
	cin considera gli spazi bianchi come carattere di terminazione del 
	carattere estratto (vedi cin >> a >> b). Per ottenere il valore di 
	una riga intera utilizziamo la funzione getline(<stream>, <var_name>).

String Stream:
	L'intestazione sstream definisce un tipo detto stringstream che consente
	ad una stringa di essere trattata come un flusso, consentendo in questo
	modo le operazioni di estrazione/inserimento nello stesso modo con cui
	vengono trattate per cin e cout. Funzione utile per convertire stringhe
	in interi e viceversa.
*/
#include <iostream>
#include <string>
#include <sstream>

const double pi = 3.14159;

int main() {

	// Operazione di inserimento singola
	std::cout << "Hello, World!" << std::endl;

	// Operazione di inserimento composta
	std::cout << "Valore di pi-greco: " << pi << std::endl;

	int i, a, b;

	// Operazione di estrazione singola
	std::cout << "Inserisci un valore intero: ";
	std::cin >> i;
	std::cout << "Il quadrato del valore e': " << i*i << std::endl;

	// Operazione di estrazione composta
	std::cout << "Inserisci due valori interi: ";
	std::cin >> a >> b;
	std::cout << "Il quadrato del valore a e': " << a*a << std::endl;
	std::cout << "Il quadrato del valore b e': " << b*b << std::endl;

	// Operazione di estrazione di una stringa 
	std::string stringa;
	std::cout << "What's your name? ";
	getline(std::cin, stringa);
	std::cout << "Hello " << stringa << std::endl;

	// Estrazione di un intero da una stringa
	std::string mystr {"1024"};
	int from_str;
	std::stringstream(mystr) >> from_str;
	std::cout << "Valore: " << from_str * 2 << std::endl;

	return 0;
}
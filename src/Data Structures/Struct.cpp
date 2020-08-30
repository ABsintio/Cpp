/*
Simple Structure:
	Una struttura dati è un insieme di elementi raggruppati sotto un singolo nome. Questi
	elementi conosciuti come "membri", possono avere tipi e lunghezze differenti. Le strutture
	dati possono essere dichiarati in C++ tramite la seguente sintassi

		struct <type_name> {
			<member_type1> member_name1;
			...
			<member_typeN> member_nameN; 
		} object_names;

	Una volta che sono stati dichiarati gli object_names, essi possono essere acceduti direttamente
	senza istanziazione. I membri di ogni struttura, dato l'oggetto collegato, possono essere 
	acceduti tramite <object_name>.<member_name> ed assegnati con il classico operatore di assegnazione
	ossia il simbolo di uguale (vedi l'esempio sotto).

Array Struct:
	E' ovviamente possibile creare array di strutture (vedi arraystruct). 

Pointer to structures:
	Come ogni altro tipo le strutture possono essere puntate dai loro tipi di puntatori.
	(vedi esempio pointerstruct)

Nesting structure:
	Le strutture possono essere ramificate di modo che un elemento di una struttura sia di per sé
	un'altra struttura. 
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace product {

	struct product {
		int    weigth; // (gr)
		double price;  // €
	} apple, banana, melon;

	void setProductValues() {
		int w_a, w_b, w_m;
		double p_a, p_b, p_m;

		cout << "Inserisci i seguenti valori: " << endl;
		cout << "Peso della Mela: ";
		cin  >> w_a;
		cout << "Prezzo della Mela: ";
		cin  >> p_a;
		cout << "Peso della Banana: ";
		cin  >> w_b;
		cout << "Prezzo della Banana: ";
		cin  >> p_b;
		cout << "Peso del Melone: ";
		cin  >> w_m;
		cout << "Prezzo del Melone: ";
		cin  >> p_m;

		apple.weigth  = w_a;
		apple.price   = p_a,
		banana.weigth = w_b;
		banana.price  = p_b;
		melon.weigth  = w_m;
		melon.price   = p_m;
	}

	void getProductInfo() {
		cout << "Apple: "    << endl;
		cout << "\tweigth: " << apple.weigth  << "\n";
		cout << "\tprice : " << apple.price   << "\n\n";
		cout << "Banana: "   << endl;
		cout << "\tweigth: " << banana.weigth << "\n";
		cout << "\tprice : " << banana.price  << "\n\n";
		cout << "Melon: "    << endl;
		cout << "\tweigth: " << melon.weigth  << "\n";
		cout << "\tprice : " << melon.price   << endl;
	}

}

namespace arraystruct {

	struct movies_t {
		string title;
		int    year;
	} films[3];

	void getFilms() {
		string mystr;
		int n;

		for (n = 0; n < 3; n++) {
			cout << "Inserisci il titolo: ";
			getline(cin, films[n].title);
			cout << "Inserisci l'anno: ";
			getline(cin, mystr);
			stringstream(mystr) >> films[n].year;
		}
	}

	void getMoviesInfo(movies_t movie) {
		cout << movie.title << " (" << movie.year << ")" << endl;
	}

}

namespace pointerstruct {

	arraystruct::movies_t *createpointer() {
		string mystr;
		arraystruct::movies_t amovie;
		arraystruct::movies_t *pmovie;
		pmovie = &amovie;

		cout << "Inserisci il titolo: ";
		getline(cin, pmovie->title);
		cout << "Inserisci l'anno: ";
		getline(cin, mystr);
		stringstream(mystr) >> pmovie->year;

		return pmovie;		
	}

	void getMovieInfoFromPointer(arraystruct::movies_t *pnt) {
		cout << pnt->title << " (" << pnt->year << ")" << endl;
	}

}

namespace nestedstruct {

	struct friend_t {
		string 				  name;
		string 				  surname;
		arraystruct::movies_t favorite_movie;
	};

	friend_t createfriend() {
		string name, surname, mystr;
		
		cout << "Inserisci il nome: ";
		getline(cin, name);
		cout << "Inserisci il cognome: ";
		getline(cin, surname);

		friend_t newfriend;
		newfriend.name = name;
		newfriend.surname = surname;
		newfriend.favorite_movie = *pointerstruct::createpointer();

		return newfriend;
	}

	void getFriendInfo(friend_t fr) {
		cout << "Nome: " << fr.name << endl;
		cout << "Cognome: " << fr.surname << endl;
		pointerstruct::getMovieInfoFromPointer(&fr.favorite_movie);
	}

}

int main() {

	cout << "SIMPLE STRUCT EXAMPLE" << endl;
	product::setProductValues();
	product::getProductInfo();

	cout << "\n";

	cout << "ARRAY STRUCT EXAMPLE" << endl;
	arraystruct::getFilms();
	for (int n = 0; n < 3; n++) {
		arraystruct::getMoviesInfo(arraystruct::films[n]);
	}

	cout << "\n";

	cout << "POINTERED STRUCT EXAMPLE" << endl;
	arraystruct::movies_t *pointer;
	pointer = pointerstruct::createpointer();
	pointerstruct::getMovieInfoFromPointer(pointer);

	cout << endl;

	cout << "NESTED STRUCT EXAMPLE" << endl;
	nestedstruct::friend_t f {nestedstruct::createfriend()};
	nestedstruct::getFriendInfo(f);

	return 0;
}
/*
 * Le classi sono "espansioni" di strutture dati, difatti come quest'ultime l classi possono
 * contenere data members, ma possono anche contenere delle funzioni. Le classi possono essere
 * create utilizzando la parola chiave class (o anche struct) con la seguente sintassi
 *
 *      class <class_name> {
 *          access_specifier_1:
 *              member1;
 *          access_specifier_2:
 *              member2;
 *          ...
 *      } object_name;
 *
 * A differenza delle strutture dati viste fino ad adesso (come struct) le classi contengono di
 * nuovo non soltanto le funzioni (o metodi della classe) ma anche questi "access specifier", i
 * quali possono essere di tre tipi: public, private o protected. Ciascun membro dichiarato prima
 * di un qualsiasi access_specifier lo è private per default. Dopo aver dichiarato quali membri
 * della classe sono pubblici e quali no, possiamo accedere a quelli pubblici tramite il "."
 *
 *      <object_name>.<public_member>
 *
 * E' possibile definire le funzioni di una classe sia all'interno della sua dichiarazione, oppure
 * all'esterno referenziandola con i "::". La sola differenza tra questi due approcci è che
 * solitamente le funzioni dichiarate internamente sono considerate inline dal compilatore, mentre
 * quelle esterne solitamente sono più complesse e richiedono più righe. Essenzialmente il solo
 * motivo di fare questa differenziazione è per ottimizzare il compilatore.
 *
 * Una classe può includere una funzione speciale chiamata costrutture, il quale è automaticamente
 * invocato nel momento della creazione di un nuovo oggetto di quella classe. Il costruttore ha
 * il compito di inizializzare i membri della classe oppure allocare della memoria. Tale funzione
 * deve avere il nome della classe. Anche se sembrano delle funzioni normalissime i costruttori
 * non possono essere invocati normalmente.
 */
#include <iostream>

using namespace std;

class Rectangle {
        int width{}, height{};
    public:
        Rectangle();
        Rectangle(int, int);
        void set_values(int, int);
        int area() const {return width * height;};
};

void Rectangle::set_values(int w, int h) {
    width = w;
    height = h;
}

Rectangle::Rectangle() {
    width = 3;
    height = 4;
}

Rectangle::Rectangle(int w, int h) {
    set_values(w, h);
}

int main() {

    Rectangle rect{5, 6}, rectb{};
    cout << "Old area: " << rect.area() << endl;
    rect.set_values(10, 20);
    cout << "New area: " << rect.area() << endl;
    cout << "Default Area: " << rectb.area() << endl;

    return 0;
}
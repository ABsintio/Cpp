/*
 * E' possibile sovrascrivere gli operatori quali: +, -, *, /, =, <, >, ->, ->*
 * >>, <<, +=, -=, *=, /=, <<=, >>=, ==, !=, <=, >=, ++, --, %, &, ^, !, |, ~,
 * &=, ^=, |=, &&, ||, %=, [], (), ",", new, delete, new[], delete[].
 *
 * La sintassi con la quale sovrascrivere gli operatori è la seguente
 *
 *      type operator sign (parameters) { ... body ... }
 *
 * In genere l'overloads degli operatori può essere fatto in due modi: come membri
 * di una classe, oppure come esterni. Nel caso in cui siano esterni devono prendere
 * in input un oggetto dello stesso tipo ritornato come primo argomento.
 *
 * La parola chiave "this" rappresenta un puntatore all'oggetto della classe stesso ed
 * è usato all'interno dei metodi delle classi.
 *
 * Possiamo dichiarare anche degli static member, ossia le uniche varaibili che sono
 * condivise da tutti gli oggetti di una singola classe. Esse non possono essere
 * inizializzate all'interno della classe ma lo devono essere in qualche posto al di fuori.
 *
 * Se istanzio un oggetto di classe MyClass come const, allora questo avrò accesso solo in
 * lettura a tutti i membri (dati), ma non in scrittura. Le funzioni se non sono a loro
 * volta definite const non possono essere accedute neanche in lettura (in esecuzione).
 * Notiamo come "const" può essere utilizzato per qualificare il tipo di ritorno di una
 * funzione membro. Questi sono diversi tipologie di utilizzo di const
 * 1. Const member function
 *      <type> fun_name( ... param ... ) const { ... body ... };
 * 2. Member function returning a const&
 *      const <type>& fun_name( ... param ... ) { ... body ... };
 * 3. Const member function returning a const&
 *      const <type>& fun_name( ... param ... ) const { ... body ... };
 *
 * Le funzioni definite const non possono modificare membri non statici della classe e non
 * possono invocare altre funzioni che non sono const. Riassumendo, const members non possono
 * modificare lo stato di un oggetto.
 */
#include <iostream>

using namespace std;

class CartesianVector {
public:
    signed long int x{}, y{};
    CartesianVector() = default;
    CartesianVector(int a, int b) : x(a), y(b) {}
    CartesianVector operator + (const CartesianVector&) const;
};

// As a member function
CartesianVector CartesianVector::operator+(const CartesianVector& param) const {
    CartesianVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return temp;
}

// As a Non-member function
CartesianVector operator-(CartesianVector lhs, CartesianVector rhs) {
    CartesianVector temp;
    temp.x = lhs.x - rhs.x;
    temp.y = lhs.y - rhs.y;
    return temp;
}

class Dummy {
public:
    static int n;
    Dummy() { n++; };
    bool isitme(Dummy& param);
};

bool Dummy::isitme(Dummy& param) {
    if (&param == this) return true;
    return false;
}

int Dummy::n = 0;

class MyClass {
    int x;
public:
    MyClass() { x = 3; };
    MyClass(int val) : x(val) {};
    const int& get() const { return x; };
};

void print(const MyClass& arg) {
    cout << "myClass.x = " << arg.get() << endl;
}

template <class T> class MyPair {
    T values[2];
public:
    MyPair(T first, T second) {
        values[0] = first;
        values[1] = second;
    };
    T getFirst() { return values[0]; };
    T getSecond() { return values[1]; };
    T getMax();
};

template <class T> T MyPair<T>::getMax() {
    T retval;
    retval = values[0] > values[1] ? getFirst() : getSecond();
    return retval;
}

template <class T> class Container {
    T element;
public:
    Container(T arg) : element(arg) {};
    T increase() { return ++element; };
};

// Class template specialization
template <> class Container<char> {
    char element;
public:
    Container(char arg) : element(arg) {};
    char uppercase();
};

char Container<char>::uppercase() {
    if ((element >= 'a') && (element <= 'z')) {
        element += 'A' - 'a';
    }
    return element;
}

int main() {

    /*
     * DEFINIZIONE E ISTANZIAZIONE DI OGGETTI CARTESIANVECTOR
     */
    CartesianVector foo{3, 1};
    CartesianVector bar{1, 2};
    CartesianVector resultsomma{}, resultdifferenza{};

    /*
     * RISCRITTURA DEGLI OPERATORI + -
     */
    resultsomma = foo + bar;
    cout << "( " << foo.x    << ", " << foo.y    << " ) + ";
    cout << "( " << bar.x    << ", " << bar.y    << " ) = ";
    cout << "( " << resultsomma.x << ", " << resultsomma.y << " )" << endl;

    resultdifferenza = foo - bar;
    cout << "( " << foo.x    << ", " << foo.y    << " ) - ";
    cout << "( " << bar.x    << ", " << bar.y    << " ) = ";
    cout << "( " << resultdifferenza.x << ", " << resultdifferenza.y << " )" << endl;

    /*
     * PUNTATORI ALLA CLASSE DUMMY E VARIABILI STATICHE
     */
    Dummy a;
    cout << "a.n = " << a.n << endl;
    Dummy *b;
    b = &a;
    if (b->isitme(a)) {
        cout << "yes, &a is b" << endl;
    }

    Dummy c[5];
    cout << "a.n = " << a.n << endl;
    auto *f = new Dummy;
    cout << "Dummy::n = " << Dummy::n << endl;
    delete f;

    /*
     * INIZIALIZZAZIONE CONST DI CLASSE MYCLASS
     */
    const MyClass myClass(10);
    // myClass.x = 20; // Non lo posso fare
    print(myClass);

    /*
     * INIZIALIZZAZIONE CLASSE CON TEMPLATE
     */
    MyPair<int> mp{115, 36};
    cout << "MyPair<int> mp = ( " << mp.getFirst() << ", " << mp.getSecond() << " )" << endl;
    cout << "mp.getMax() = " << mp.getMax() << endl;
    MyPair<double> *mpdoble = new MyPair<double> (3.0, 2.18);
    cout << "MyPair<double> mpdouble = ( ";
    cout << mpdoble->getFirst() << ", " << mpdoble->getSecond() << " )" << endl;
    cout << "mpdouble.getMax() = " << mpdoble->getMax() << endl;
    delete mpdoble;

    /*
     * TEMPLATE SPECIALIZATION
     */
    Container<int> myint {7};
    Container<char> mychar = 'j';
    cout << "myint.increase() = "   << myint.increase()   << endl;
    cout << "mychar.uppercase() = " << mychar.uppercase() << endl;

    return 0;
}
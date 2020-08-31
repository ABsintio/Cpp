/*
 * Special members function sono metodi speciali definiti implicitamente come
 * membri di una classe sotto alcune circostanze. Sono sei:
 * - Default Costructor -> C::C();
 * - Destructor         -> C::~C();
 * - Copy Costructor    -> C::C (const C&);
 * - Copy Assignment    -> C& operator= (const C&);
 * - Move Costructor    -> C::C(C&&);
 * - Move Assignment    -> C& operator= (C&&);
 *
 * Default Costructor:
 *      Fino a quando nella classe non viene definito un costrutture
 *      allora viene utilizzato quello di default semplicemente creando un'istanza nel
 *      seguente modo, <Class_name> obj;. Quando invece viene utilizzato un costrutture
 *      "personalizzato" allora tale istanziazione non può essere effettuata senza richiamare
 *      il nuovo costrutture o senza definire in modo esplicito quello di default.
 *
 * Destructor:
 *      Appaiono come la funzione opposta dei costruttori. Sono responsabili della "pulizia"
 *      una volta che la vita dell'istanza di una classe termina. Ovviamente la classe Example
 *      non richiede alcun "clean-up" in quanto non alloca memoria. Vediamo invece l'esempio
 *      dopo.
 *
 * Copy Costructor:
 *      Viene invocato nel momento in cui si vuole creare una copia di un oggetto tramite la
 *      sintassi: <class_name> <new_obj> = <old_obj>. Il costruttore per le copie ha una
 *      sintassi molto vicina a tutti gli altri costruttori con la sola differenza che deve
 *      contenere come singolo argomento un oggetto del suo stesso tipo.
 *
 * Copy Assignment:
 *      Elementi non sono copiati solamente all'inizializzazione tramite il costrutture, ma anche
 *      con la semplice operazione di assegnamento. Queste sono le differenze principali:
 *      - MyClass foo;
 *      - MyClass bar (foo); -> Object initialization, Copy Costruction
 *      - MyClass baz = foo; -> Object initialization, Copy Costruction
 *      - foo = bar;         -> Object already initializated, Copy assignment
 *      L'operatore di copy assignment è un overload dell "operator=" il quale prende come parametro
 *      il valore oppure una referenza alla classe stessa (del suo stesso tipo). Questa funzione
 *      viene definita implictamente nel momento in cui la classe non ha tale metodo custom.
 *
 * Move Costructor and Assignment:
 *      Come copiare, anche muovere utilizza il valore di un oggetto per settare quello di un altro
 *      oggetto della stessa classe. Ma a differenza del copiare, la sorgente dalla quale prendiamo
 *      il contenuto per trasferirlo in una destinazione, ne viene privata di quest'ultimo. Questo
 *      movimento avviene quando la sorgente del valore è un "unnamed" object. Questi sono oggetti
 *      presenti in natura ma ai quali non è stato ancora dato un nome: ad es, valori di ritorno o
 *      type-cast. Utilizzando il valore di un tale oggetto temporaneo per inizializzare il valore
 *      di un altro oggetto non richiede una copia in quanto è implicito il fatto che la sorgente
 *      non venga più utilizzata, di conseguenza il valore viene fisicamente mosso nella destinazione.
 *      Questi casi triggerano i meccanismi di move costructor e move assignment.
 *      - MyClass fn();      -> function returning a MyClass object
 *      - MyClass foo;       -> Default Costructor
 *      - MyClass bar = foo  -> Copy Costructor
 *      - MyClass baz = fn() -> Move Costructor
 *      - foo = bar          -> Copy Assignment
 *      - baz = MyClass()    -> Move Assignment
 */
#include <iostream>
#include <string>
#include <new>

using namespace std;

class ExampleCostruct {
    int total{};
public:
    ExampleCostruct() = default;
    explicit ExampleCostruct(int initialvalue) : total(initialvalue) {};
    void accumulate (int x) { total += x; };
    auto getTotal() const { return total; };
};

class ExampleDestruct {
    string *ptr;
public:
    ExampleDestruct() : ptr(new string) {};
    explicit ExampleDestruct(const string& str) : ptr(new string(str)) {};
    ~ExampleDestruct() { delete ptr; };
    const string& content() const { return *ptr; };
    string& content() { return *ptr; }
};

template <class T> class ExampleCpyCostruct {
    T *ptr;
public:
    int n{2};
    ExampleCpyCostruct() : ptr(new (nothrow) T[2]) {};
    explicit ExampleCpyCostruct(const int& dim) : ptr(new (nothrow) T[dim]), n(dim) {};
    explicit ExampleCpyCostruct(int* a);
    ~ExampleCpyCostruct() { delete[] ptr; };
    ExampleCpyCostruct(const ExampleCpyCostruct<T>& x);
    void init();
    void getContent() const;
    void increaseAll();
};

template <class T> ExampleCpyCostruct<T>::ExampleCpyCostruct(const ExampleCpyCostruct<T> &x) {
    ptr = x.ptr;
    n = x.n;
}

template <class T> ExampleCpyCostruct<T>::ExampleCpyCostruct(int* a) {
    ptr = a;
    n = sizeof(a) / 4;
}

template <class T> void ExampleCpyCostruct<T>::init(){
    for (int i = 0; i < n; i++) {
        ptr[i] = 0;
    }
}

template <class T> void ExampleCpyCostruct<T>::getContent() const {
    cout << "Starting getting content ..." << endl;
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << ptr[i] << " ";
    }
    cout << "]" << endl;
    cout << "Finished getting content ..." << endl;
}

template <class T> void ExampleCpyCostruct<T>::increaseAll() {
    for (int i = 0; i < n; i++){
        ptr[i] += 1;
    }
}

class ExampleCpyAssignment {
    string *ptr;
public:
    ExampleCpyAssignment() : ptr(new string) {};
    explicit ExampleCpyAssignment(const string& str) : ptr(new string(str)) {};
    ~ExampleCpyAssignment() { delete ptr; };
    const string& content() const { return *ptr; };
    string& content() { return *ptr; }
    ExampleCpyAssignment& operator=(const ExampleCpyAssignment& cpy);
};

ExampleCpyAssignment& ExampleCpyAssignment::operator= (const ExampleCpyAssignment& cpy) {
    if (&cpy != this) {
        *ptr = cpy.content();
    }
    return *this;
}

class ExampleMv {
    string *ptr;
public:
    explicit ExampleMv(const string& str) : ptr(new string(str)) {};
    ~ExampleMv() { delete ptr; };
    ExampleMv (ExampleMv&& x)  noexcept : ptr(x.ptr) { x.ptr = nullptr; };
    ExampleMv& operator= (ExampleMv&& x)  noexcept {
      if (&x != this) {
          delete ptr;
          ptr = x.ptr;
          x.ptr = nullptr;
      }
      return *this;
    };
    const string& content() const { return *ptr; };
    ExampleMv operator+ (const ExampleMv& rhs) const {
        return ExampleMv(content() + rhs.content());
    };
};

int main() {

    ExampleCostruct ex, ex1 (100);
    cout << "ex.total = "  << ex.getTotal()  << endl;
    cout << "ex1.total = " << ex1.getTotal() << endl;

    ExampleDestruct foo;
    const ExampleDestruct bar("Example");
    foo.content() = "ciao";
    cout << "foo content: " << foo.content() << endl;
    cout << "bar content: " << bar.content() << endl;

    int *a = new (nothrow) int[2];
    a[0] = 1;
    a[1] = 2;
    ExampleCpyCostruct<int> ecc(a);
    ecc.getContent();
    ExampleCpyCostruct<int> ecc1 = ecc;
    ecc1.getContent();
    ecc1.increaseAll();
    ecc1.getContent();
    ExampleCpyCostruct<int> ecc2(5);
    ecc2.init();
    ecc2.getContent();
    ecc2.increaseAll();
    ecc2.getContent();

    delete[] a;

    ExampleCpyAssignment eca("ECA"), eca1("ECA1");
    cout << "eca.content() = "  << eca.content()  << endl;
    cout << "eca1.content() = " << eca1.content() << endl;
    eca = eca1;
    cout << "eca.content() = "  << eca.content()  << endl;
    cout << "eca1.content() = " << eca1.content() << endl;

    ExampleMv emv ("Exam");
    ExampleMv emv1 = ExampleMv("ple");
    emv = emv + emv1;
    cout << "emv's content: " << emv.content() << endl;

    return 0;
}
/*
 * Friend Function:
 *      In principio, membri private o protected non possono essere acceduti da fuori la classe
 *      stessa. Questa regola però non è applicata agli "amici". Gli "amici" sono funzioni o
 *      classi dichiarate con la keyword friends. Una funzione che non è membro di quella
 *      classe può accedere ai membri privati o protetti della classe nel momento in cui viene
 *      dichiarata friend. La sintassi per dichiarare tali funzioni è la seguente
 *
 *      friend <class_name> <fun_name>(...);
 *
 *      all'interno della classe stessa.
 *
 * Friend Class:
 *      Come per le funzioni una classe friend è una classe che può accedere ai membri privati
 *      della classe alla quale è amica. Una proprietà importante è che la friendship non è
 *      transitiva.
 *
 * Inheritance between classes:
 *      Le class in C++ posso essere estese, creando nuove classi che hanno come fondamenta
 *      la classe che estendono. Questo processo, conosciuto come inheritance, coinvolge la
 *      classe base e la classe derivata la quale prenderà i membri della classe basa e ne
 *      potrà aggiungere degli altri. Le classi derivate da altre ereditano tutti i membri
 *      accessibili della classe base. Ciò significa che se una classe base include un membro
 *      A e ne deriviamo una classe con un altro membro chiamato B, la classe derivata conterrà
 *      sia il membro A che il membro B. Ovviamente i membri della classe derivata posso accedere
 *      solamente ai membri protected e publici della classe base, ma non a quelli private, se
 *      l'inheritance è definita con la keyword public. Se invece la definiamo con quella private
 *      allora può accedere a tutto. In principio, la classe derivata pubblica permette l'accesso
 *      a ogni membro della classe a parte: costrutture e distrutture; operator=; friends; membri
 *      privati. I costruttori della classe di base vengono automaticamente chiamati dai
 *      costruttori e distruttori della classe derivata.
 *
 * Multiple Inheritance:
 *      Una classe può estendere più di una classe, separate dalla virgola. La classe derivata
 *      prenderà tutto da tutte le classe che estende (tranne i membri privati).
 */
#include <iostream>
#include <string>

using namespace std;

class Square;
class SomethingPolygonal;

class Polygon {
protected:
    int w{}, h{};
private:
    string *name{};
public:
    explicit Polygon(const int& x, const int& y, const string& str) : w(x), h(y), name(new string(str)) {};
    explicit Polygon(const int& x, const int& y) : w(x), h(y) {};
    Polygon() = default;
    ~Polygon() { delete name; };
    void print() const { cout << "w = " << w << ", " << "h = " << h << endl; };
    void set_values(const int& a, const int& b) {
        w = a;
        h = b;
    }
    void setName(SomethingPolygonal* sp) const;
    void setname(const string& nome) { name = new string(nome); };
    string getname() const {return *name;};
};


class Rectangle: public Polygon {
public:
    Rectangle() = default;
    explicit Rectangle(const int& x, const int& y) : Polygon(x, y) {};
    void convert (Square a);
    int area() const { return w * h; };
    friend Rectangle duplicate (const Rectangle&);
};

Rectangle duplicate (const Rectangle& param) {
    Rectangle res{};
    res.w = param.w * 2;
    res.h = param.h * 2;
    return res;
}

class Square {
    friend class Rectangle;
private:
    int side;
public:
    explicit Square(const int& a) : side(a) {};
};

void Rectangle::convert(Square a) {
    w = a.side;
    h = a.side;
}

class Triangle: public Polygon {
public:
    int area() const { return w * h / 2; };
};

class SomethingPolygonal {
    friend class Polygon;
private:
    string name;
public:
    SomethingPolygonal& operator=(const Polygon&);
    string getName() const { return name; };
};

void Polygon::setName(SomethingPolygonal* sp) const {
    sp->name = *name;
}

SomethingPolygonal& SomethingPolygonal::operator=(const Polygon &param) {
    param.setName(this);
    return *this;
}

class Mother {
public:
    Mother() { cout << "Mother: no parameters" << endl; };
   explicit Mother(const int& a) {
        cout << "Mother: int parameter" << endl;
    }
};

class Daughter: public Mother {
public:
    explicit Daughter(const int& a) { cout << "Doughter: int parameter" << endl; };
};

class Son: public Mother {
public:
    explicit Son(const int& a): Mother(a) { cout << "Son: int parameter" << endl; };
};

class Output {
public:
    static void printint(const int&);
};

void Output::printint(const int &i) {
    cout << i << endl;
}

class RandomPolygon: public Polygon, public Output {
public:
    explicit RandomPolygon(const int& x, const int& y, const string& s) : Polygon(x, y, s) {};
    RandomPolygon() = default;
    explicit RandomPolygon(const int& x, const int& y) : Polygon(x, y) {};
    ~RandomPolygon() = default;
};

int main() {

    cout << "FRIEND FUNCTION" << endl;
    Rectangle foo{};
    Rectangle bar{2, 3};
    foo = duplicate(bar);
    cout << "foo.area() = " << foo.area() << endl;

    cout << endl;

    cout << "FRIEND CLASS" << endl;
    bar.print();
    Square sq(4);
    bar.convert(sq);
    bar.print();

    cout << endl;

    cout << "INHERITANCE" << endl;
    Triangle trgl;
    trgl.set_values(4, 5);
    trgl.print();
    trgl.setname("triangle");
    cout << trgl.getname() << ".area() = " << trgl.area() << endl;

    Polygon p(3, 4, "polygon");
    SomethingPolygonal sp;
    // Beneamata merda. Ma che cazzo è sp = p era così complesso C++!!
    // Move costructor del cazzo fanculo.
    sp.operator=(p);
    cout << "sp.getName() = " << sp.getName() << endl; // Oddio si sono un cazzo di genio

    Daughter kelly(0);
    Son bud(0);

    cout << endl;

    cout << "MULTIPLE INHERITANCE" << endl;
    RandomPolygon rp {3, 4, "random"};
    rp.print();
    rp.printint(trgl.area());

    return 0;
}
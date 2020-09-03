/*
 * Pointer to base class:
 *      Una delle caratteristiche principali dell'inheritance è che un puntatore alla classe
 *      derivata è tipo-compatibile con un puntatore alla sua classe base. Il polimorfismo
 *      prende i vantaggi di questa versatile e semplice caratteristica. Possiamo notare
 *      come nel primo esempio vengano creati due puntatori a Polygon che puntano però agli
 *      oggetti di tipo Rectangle e Triangle che sono due classi derivate da Polygon. Notiamo
 *      però che questi puntatori possono accedere solo ai membri che sono stati presi dalla
 *      classe base, per questo quando andiamo a printare le aree notiamo che utilizziamo gli
 *      oggetti rect e trgl.
 *
 * Virtual members:
 *      Un membro virtuale è un membro della classe base che può essere ridefinito nelle
 *      classi derivate. Una classe che dichiara o eredita una funzione virtuale viene detta
 *      classe polimorfica.
 *
 * Abstract classes:
 *      Sono classi molto simili alla classe Polygon in quanto possno essere utilizzate solo
 *      come base per le altre classi. Esse possono avere virtual function senza una definizione
 *      rimpiazzando il classico {...} con = 0.
 */
#include <iostream>

using namespace std;

class Polygon {
protected:
    int w{}, h{};
public:
    void setValues(const int& a, const int& b) {
        w = a;
        h = b;
    };
    virtual int area() const { return 0; };
};

class Rectangle: public Polygon {
public:
    int area() const override { return w*h; };
};

class Triangle: public Polygon {
public:
    int area() const override { return w*h/2; };
};

class AbstractClass {
protected:
    int value{};
public:
    explicit AbstractClass (const int& v) : value(v) {};
    void setValue(const int& v) { value = v; };
    virtual void increment() = 0;
    int getValue() const { return value; };
    void printValue() const { cout << this->getValue() << endl; };
};

class PlusOne: public AbstractClass {
public:
    explicit PlusOne (const int& v) : AbstractClass(v) {};
    void increment() override { value++; };
};

class PlusTwo: public AbstractClass {
public:
    explicit PlusTwo (const int& v) : AbstractClass(v) {};
    void increment() override { value += 2; };
};

class PlusThree: public AbstractClass {
public:
    explicit PlusThree (const int& v) : AbstractClass(v) {};
    void increment() override { value += 3; };
};

int main() {

    cout << "POINTER TO BASE CLASS" << endl;
    Rectangle rect;
    Triangle trgl;
    Polygon *ppoly1 = &rect;
    Polygon *ppoly2 = &trgl;
    ppoly1->setValues(4, 5);
    ppoly2->setValues(4, 5);
    cout << "rect.area() = " << rect.area() << endl;
    cout << "trgl.area() = " << trgl.area() << endl;

    cout << endl;

    cout << "VIRTUAL MEMBERS" << endl;
    auto *ppoly3 = new Polygon;
    cout << "ppoly1->area() = " << ppoly1->area() << endl;
    cout << "ppoly2->area() = " << ppoly2->area() << endl;
    cout << "ppoly3->area() = " << ppoly3->area() << endl;
    delete ppoly3;

    cout << endl;

    cout << "ABSTRACT CLASS" << endl;
    PlusOne po(1);
    PlusTwo pt{1};
    AbstractClass *ab1 = &po;
    AbstractClass *ab2 = &pt;
    AbstractClass *ab3 = new PlusThree(1);
    ab1->setValue(1);
    ab2->setValue(1);
    ab3->setValue(1);
    ab1->increment();
    ab2->increment();
    ab3->increment();
    cout << "po.getValue() = " << po.getValue() << endl;
    cout << "pt.getValue() = " << ab2->getValue() << endl;
    cout << "pth.getValue() = ";
    ab3->printValue();

    return 0;
}
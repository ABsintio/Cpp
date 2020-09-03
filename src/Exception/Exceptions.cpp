#include <iostream>

using namespace std;

class MyException: public exception {
    const char* what() const noexcept override {
        return "My exception happened";
    };
};

int main () {

    try {
        throw 20;
    } catch (int a) {
        cout << "An exception occurred. Exception Nr. " << a << endl;
    }

    try {
        throw *(new MyException);
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
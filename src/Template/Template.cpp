/*
Potrebbe accadere che all'interno dello stesso programma
e non solo, esistano delle funzioni con lo stesso corpo e 
definizione ma che prendano argomenti di tipo diverso. 
Fortunatamente C++ ci mette a disposizione il costrutto template
che ci permette di definire una singola funzione di modo che 
possa essere richiamata con diversi tipi in input, se creare
una funzione per ogni tipo. 
*/
#include <iostream>

using namespace std;

// Creo una funzione modello
template <class T> T sum(T a, T b) {

	// Posso usare il tipo T come voglio
	T result;
	result = a + b;

	return result;
}

// Possiamo creare template che definiscono più classi
template <class T, class U> bool equal(T a, U b) {
	return a == b;
}

// Possiamo inserire valori predefiniti nella
// definizione del template al posto di creare dei tipi
template <class T, int N> T fixed_multiply(T val) {
	return val * N;
}

int main() {

	int i=5, j=6, k;
	double f=2.0, g=0.5, h;

	k = sum<int>(i, j);
	h = sum<double>(f, g);

	cout << k << endl;
	cout << h << endl;

	bool ans;
	ans = equal<int, double>(10, 10.0);
	cout << "La risposta è: " << ans << endl;

	cout << fixed_multiply<int,2>(10) << endl;
  cout << fixed_multiply<int,3>(10) << endl;

	return 0;
}
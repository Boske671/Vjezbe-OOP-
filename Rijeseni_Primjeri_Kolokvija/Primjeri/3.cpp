/*
3. Neka postoji klasa Kompleksni s podatkovnim članovima re i im. Napišite sve potrebne podatkovne članove, metode i funkcije kojima se omogućuje izvršavanje sljedećih izraza:

Kompleksni Z1(1, -1), Z2(2, 2);  // Z1.re = 1, Z1.im = -1;   Z2.re = 2, Z2.im = 2
Kompleksni Z3 = ++Z1 * Z2;       // Z3. re = 4, Z3.im = 4i;
cout << Z1 << " " << Z3 << endl; // 2 + 0i  4 + 4i

*/

#include <iostream>

using namespace std;

class Kompleksni {
public:
	double re, im;
	Kompleksni(double _re, double _im) : re(_re), im(_im) {}
	// množenje kompleksnih brojeva
	Kompleksni operator * (Kompleksni Z) {
		return Kompleksni(re * Z.re - im * Z.im, re * Z.im + im * Z.re);
	}
	// prefiks ++
	Kompleksni& operator ++() {
		re++;
		im++;
		return *this;
	}
};
// preopterećenje operator za ispis kompleksnog broja 
ostream& operator <<(ostream& izlaz, Kompleksni Z) {
	izlaz << Z.re << " + " << Z.im << "i";
	return izlaz;
}
int main() {
	Kompleksni Z1(1, -1), Z2(2, 2);  // Z1.re = 1, Z1.im = -1;   Z2.re = 2, Z2.im = 2
	Kompleksni Z3 = ++Z1 * Z2;       // Z3. re = 4, Z3.im = 4i;
	cout << Z1 << " " << Z3 << endl; // 2 + 0i  4 + 4i
	return 0;
}

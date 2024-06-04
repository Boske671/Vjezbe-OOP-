/*
4. Neka postoji sljedeći programski odsječak:
int main(){
	Matematika Racun;
	cout << Racun.suma(2, 4.3) << endl; // 6.3
	cout << Racun.suma(2.3, 4) << endl; // 6.3
	cout << Racun.suma(Kompleksni(2.5, 1), 4) << endl; // 6.5 1i
	return 0;
}
Napišite sve potrebne klase, metode i funkcije kako bi prikazani programski odsječak radio kao što je to u komentarima i predviđeno. Napomena: metoda suma vraća sumu bilo koja dva podatka koje je moguće zbrojiti operatorom +. Za tipove podatka koje nije moguće direktno zbrojiti operatorom + potrebno je preopteretiti taj operator za navedeni tip.
i  4 + 4i

*/

#include <iostream>

using namespace std;

class Kompleksni {
public:
	double re, im;
	Kompleksni(double _re, double _im) : re(_re), im(_im) {}
	// zbrajanje kompleksnih brojeva
	Kompleksni operator +(double re) {
		return Kompleksni(this->re + re, im);
	}
};
// preopterećenje operator za ispis kompleksnog broja 
ostream& operator <<(ostream& izlaz, Kompleksni Z) {
	izlaz << Z.re << " + " << Z.im << "i";
	return izlaz;
}
class Matematika {
public:
	template<class T1, class T2>
	auto suma(T1 a, T2 b)
	{
		return a + b;
	}
};
int main() {
	Matematika Racun;
	cout << Racun.suma(2, 4.3) << endl; // 6.3
	cout << Racun.suma(2.3, 4) << endl; // 6.3
	cout << Racun.suma(Kompleksni(2.5, 1), 4) << endl; // 6.5 1i
	return 0;
}

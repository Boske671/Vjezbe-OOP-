/*
 
 Neka je zadana sljedeća funkcija main. Napišite klasu Razlomak koja u sebi ima sve potrebne podatkovne članove i metode kako bi glavni program (funkcija main) mogla raditi kao što je to u kodu i predviđeno.

int main(){
	Razlomak r1(2,3), r2, r3;
	r2 = 2;  // 2/1
	r3 = r1 + r2;
	cout << r3++ << endl;	// 8/3
	cout << r3 * r1 << endl;	// 18/12
	return 0;
}

*/


#include <iostream>
using namespace std;

class Razlomak {
public:
	int brojnik, nazivnik;
	Razlomak() = default;
	Razlomak(int brojnik, int nazivnik) : brojnik(brojnik), nazivnik(nazivnik) { }

	Razlomak& operator = (int i) {
		this->brojnik = i;
		this->nazivnik = 1;
		return *this;
	}

	Razlomak operator + (const Razlomak& r) const {
		Razlomak rez;
		rez.nazivnik = nazivnik * r.nazivnik;
		rez.brojnik = (rez.nazivnik / nazivnik * brojnik) + (rez.nazivnik / r.nazivnik * r.brojnik);
		return rez;
	}

	Razlomak& operator ++() {
		brojnik += nazivnik;
		return *this;
	}

	Razlomak operator ++(int) {
		Razlomak temp = *this;
		++(*this);
		return temp;
	}

	Razlomak operator * (const Razlomak& r) const {
		Razlomak rez;
		rez.brojnik = brojnik * r.brojnik;
		rez.nazivnik = nazivnik * r.nazivnik;
		return rez;
	}

	friend ostream& operator << (ostream& izlaz, const Razlomak& r) {
		izlaz << r.brojnik << "/" << r.nazivnik;
		return izlaz;
	}
};

int main() {
	Razlomak r1(2, 3), r2, r3;
	r2 = 2;  // 2/1
	r3 = r1 + r2;
	cout << r3++ << endl;	// 8/3
	cout << r3 << endl;		// 11/3
	cout << r3 * r1<< endl;	// 22/9
	return 0;
}

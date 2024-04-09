/*Pijesak i zrno
kopirni i prijenosni konstruktor, operator =
Za klasu Pijesak napišite konstruktore i operatore pridruživanja s semantikom kopiranja i semantikom prijenosa. U funkciji main demonstrirajte njihove pozive.

#include <iostream>
#include <string>
using namespace std;

class Zrno{
public:
	string boja;
	float promjer;
};
class Pijesak{
public:
	int kolicina;
	Zrno* zrno;
	Pijesak(int _kolicina) : kolicina(_kolicina){
		// dinamički alocirajte polje 'zrno'
	}
	~Pijesak(){
		// ?
	}
};
int main(){
	Pijesak igraliste(1000000);
	cout << "Na igralistu ima " << igraliste.kolicina << " zrna pijeska!\n";

	// Demonstrirajte pozive oba konstruktora i oba operatora pridruživanja
	return 0;
}
*/


#include <iostream>
#include <string>


using namespace std;

class Zrno {
public:
	string boja;
	float promjer;
};

class Pijesak {
public:
	int kolicina;
	Zrno* zrno;

	Pijesak() = default;
	Pijesak(int _kolicina) : kolicina(_kolicina) {
		// dinamički alocirajte polje 'zrno'
		
	}
	
	Pijesak(const Pijesak& p)
	{
		kolicina = p.kolicina;
		zrno = new Zrno[kolicina];
		for (int i = 0; i < kolicina; i++)
		{
			zrno[i] = p.zrno[i];
		}
	}

	Pijesak(Pijesak&& p)
	{
		kolicina = p.kolicina;
		zrno = p.zrno;
		p.zrno = NULL;
		p.kolicina = NULL;
	}

	Pijesak& operator = (Pijesak& p)
	{
		if (this != &p)
		{
			delete[] zrno;
			kolicina = p.kolicina;
			zrno = new Zrno[kolicina];
			for (int i = 0; i < kolicina; i++)
			{
				zrno[i] = p.zrno[i];
			}
		}
		return *this;
	}


	Pijesak& operator = (Pijesak&& p)
	{
		delete[] zrno;
		zrno = p.zrno;
		kolicina = p.kolicina;
		p.zrno = NULL;
		p.kolicina = NULL;
		return *this;
	}

	~Pijesak() {
		delete[] zrno;
	}
};
int main() {
	Pijesak igraliste(1000000);
	cout << "Na igralistu ima " << igraliste.kolicina << " zrna pijeska!\n";

	// Demonstrirajte pozive oba konstruktora i oba operatora pridruživanja

	//KON KOPIRANJA
	Pijesak A(99999);
	Pijesak B = A;

	cout << "Na igralistu ima " << B.kolicina << " zrna pijeska!\n";


	//KON PRIJENOSA
	Pijesak C = Pijesak(100);
	cout << "Na igralistu ima " << C.kolicina << " zrna pijeska!\n";

	//OPERATOR PRIDRUZIVANJA S KOPIRANJEM

	Pijesak X(500), Y;
	Y = X;
	cout << "Na igralistu ima " << Y.kolicina << " zrna pijeska!\n";
	cout << "Na igralistu ima " << X.kolicina << " zrna pijeska!\n";

	//OPERATOR PRIDRUZIVANJA S PRIJENOSOM
	Pijesak Z(100);
	Z = Pijesak();

	cout << "Na igralistu ima " << Z.kolicina << " zrna pijeska!\n";

	return 0;
}

/*
5. Neka u funkciji main postoji sljedeći programski odsječak:

int main() {
	// klasa Osoba sadrži konstruktor koji prima naziv zanimanja (npr. Kuhar, Pekar...)
	Osoba* O = new Pekar("Pekar");
	cout << O->getZanimanje() << endl;
	delete O;
	return 0;

	// očekivani ispis:
	//Pekar
	//~Pekar
	//~Osoba
}

Napišite sve potrebne klase i metode kako bi se pokretanjem programa dobio očekivani rezultat.

*/

#include <iostream>
#include <vector>

using namespace std;

class Osoba
{
public:
	string zanimanje;
	Osoba(string zan) : zanimanje(zan) {}
	virtual string getZanimanje() = 0;

	virtual ~Osoba()
	{
		cout << "~Osoba" << endl;
	}
};

class Pekar : public Osoba
{
public:
	Pekar(string zan) : Osoba(zan){}
	string getZanimanje() override
	{
		return "Pekar";
	}
	~Pekar()
	{
		cout << "~Pekar" << endl;
	}
};

int main()
{
	// klasa Osoba sadrži konstruktor koji prima naziv zanimanja (npr. Kuhar, Pekar...)
	Osoba* O = new Pekar("Pekar");
	cout << O->getZanimanje() << endl;
	delete O;
	return 0;

	// očekivani ispis:
	//Pekar
	//~Pekar
	//~Osoba

	return 0;
}

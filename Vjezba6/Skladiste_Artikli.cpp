/*
Potrebno je napisati program za evidenciju artikala unutar nekog skladišta. Svaki od artikala ima svoj naziv, jediničnu cijenu i količinu. Slijedeći programski odsječak u nastavku napišite sve potrebne klase i metode kojima se dobije očekivano ponašanje programskog koda.

int main(){
	Skladiste Igracke;
	Igracke += Artikl("Bicikl", 1000, 10);	// Bicikl, 1000kn, 10 kom
	Igracke += Artikl("Lopta", 30, 50);	// Lopta, 30kn, 50 kom

	cout << Igracke;	// ispis svih artikala u skladištu
	cout << (int)Igracke << " kom" << endl; 	// ukupno artikala (60 kom)
	cout << (double)Igracke << " kn" <<endl;	// ukupna cijena (11500 kn)
	return 0;
}

*/


#include <iostream>
#include <vector>
using namespace std;

class Artikl
{
public:
	string naziv;
	int cijena, kol;

	Artikl(string naziv, int cijena, int kol) : naziv(naziv), cijena(cijena), kol(kol) { }
};

class Skladiste
{
public:
	vector <Artikl> artikli;

	Skladiste() = default;

	Skladiste operator += (const Artikl &a)
	{
		artikli.push_back(a);
		return *this;
	}

	friend ostream& operator << (ostream& izlaz, Skladiste& s)
	{
		for (int i = 0; i < s.artikli.size(); i++)
		{
			// Bicikl, 1000kn, 10 kom
			izlaz << s.artikli[i].naziv << ", " << s.artikli[i].cijena << "kn, " << s.artikli[i].kol << " kom" << endl;
		}
		return izlaz;
	}

	operator int()
	{
		int uk = 0;
		for (int i = 0; i < artikli.size(); i++)
		{
			uk += artikli[i].kol;
		}
		return uk;
	}

	operator double()
	{
		int uk = 0;
		for (int i = 0; i < artikli.size(); i++)
		{
			uk += artikli[i].cijena * artikli[i].kol;
		}
		return uk;
	}
};

int main() {
	Skladiste Igracke;
	Igracke += Artikl("Bicikl", 1000, 10);	// Bicikl, 1000kn, 10 kom
	Igracke += Artikl("Lopta", 30, 50);	// Lopta, 30kn, 50 kom

	cout << Igracke;	// ispis svih artikala u skladištu
	cout << (int)Igracke << " kom" << endl; 	// ukupno artikala (60 kom)
	cout << (double)Igracke << " kn" << endl;	// ukupna cijena (11500 kn)
	return 0;
}


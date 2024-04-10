/*
Podaci o nogometnom klubu sadrže naziv, adresu, podatke o treneru i popis igrača. Podaci o treneru sadrže ime, prezime i adresu, dok svaki igrač sadrži ime, prezime i tržišnu cijenu.

 a) Deklarirajte klase 'NogometniKlub', 'Trener' i 'Igrač' te njihove članove tako da se pomoću njih može opisati gore navedena specifikacija. Trener nogometnog kluba treba biti predstavljen objektom tipa 'Trener', dok popis igrača u nogometnom klubu realizirajte pomoću vektora pokazivača na igrače.

 b) Klasu 'Igrac' stavite u imenik 'ClanKluba' te implementirajte enkapsulaciju na način da je tržišna cijena igrača ne može biti negativna. Implementacija napisanih metoda mora se nalaziti van klase.

 c) U klasi 'NogometniKlub' implementirajte konstruktor sa semantikom prijenosa te demonstrirajte njegov poziv u funkciji main.

 d) U klasi 'NogometniKlub' implementirajte operator pridruživanja sa semantikom kopiranja te demonstrirajte njegov poziv u funkciji main.

 e) U klasi 'NogometniKlub' implementirajte metodu 'dodajIgraca' koja omogućuje ulančano dodavanje pokazivača tipa 'Igrac' u popis članova nogometnog kluba. U funkciji main demonstrirajte ulančano dodavanje barem dva pokazivača.

NAPOMENE:
*Klasa 'NogometniKlub' mora imati odgovarajući destruktor. U protivnom gubi se 0,5 bodova.
- Za rješavanje zadatka studenti mogu koristiti Visual Studio
- Studenti mogu pisati sav programski kod u istoj (jednoj) datoteci
- Konačno rješenje potrebno je predati kao tekst(copy / paste programskog koda)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


namespace ClanKluba
{
	class Igrac
	{
	public:
		string ime, prezime;

		void setCijena(int _cijena);
		int getCijena();

	private:
		int cijena;
	};
}

using namespace ClanKluba;

class Trener
{
public:
	string ime, prezime, adresa;
};


class NogometniKlub
{
public:
	string naziv, adresa;
	Trener trener;
	vector <Igrac*> igraci;

	NogometniKlub() = default;

	NogometniKlub(NogometniKlub&& k)
	{
		naziv = move(k.naziv);
		adresa = move(k.adresa);
		trener = move(k.trener);
		for (int i = 0; i < k.igraci.size(); i++)
		{
			igraci.push_back(k.igraci[i]);
			k.igraci[i] = NULL;
		}
		k.igraci.clear();
	}

	NogometniKlub& operator = (const NogometniKlub &k)
	{
		if (this != &k)
		{
			// Oslobađanje postojećih igrača
			for (int i = 0; i < igraci.size(); i++)
			{
				delete igraci[i];
			}
			igraci.clear();

			naziv = k.naziv;
			adresa = k.adresa;
			trener = k.trener;
			
			for (int i = 0; i < k.igraci.size(); i++)
			{
				igraci.push_back(new Igrac);
				*igraci[i] = *k.igraci[i];
			}
		}
		return *this;
	}
	

	NogometniKlub& dodajIgraca(ClanKluba::Igrac* igrac) {
		igraci.push_back(igrac);
		return *this;
	}
};




void Igrac::setCijena(int _cijena)
{
	cijena = _cijena;
}

int Igrac::getCijena()
{
	return cijena;
}

int main()
{
	NogometniKlub A = move(NogometniKlub());

	NogometniKlub B, C;
	C = B;
}

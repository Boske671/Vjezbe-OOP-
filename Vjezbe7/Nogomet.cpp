/*
Potrebno je napraviti ispravne klase kako bi donji programski odsječak funkcionirao ispravno. Potrebno je modelirati nasljeđivanje,te osigurati da postoji apstraktna klasa u modelu (ispravno odabrati metodu koja je čista virtualna).

Dodatno, plaća za se računa na način da se osnovici plaće pribroje bonusi:

	za igrača, svaki 10. gol donosi 10% osnovice kao bonus; dok svaka 5. asistencija donosi isto 10% osnovice kao bonus
	za trenera, svaka 5. pobjeda donosi bonus od 10% osnovice, svaki 10. remi (nerijeseno) donosi isto 10% osnovice, dok se za svaki 8. poraz skida 10% osnovice
	za detalje, pogledati primjere ispisa koda

int main()
{
Igrac i("Luka", "Modric", 100000); //Ime, prezime, osnovica plaće
i.dodajGolove(7);
i.dodajAsistencije(12);
i.ispis(); //Luka Modric - golova: 7, asistencija: 12
cout << "Placa: " << i.izracunPlace() << endl; //Placa: 120000

Igrac i2("C", "Ronaldo", 234505);
i2.dodajGolove(57);
i2.dodajAsistencije(32);
i2.ispis(); //C Ronaldo - Golova : 57, Asistencije : 32.
cout << "Placa: " << i2.izracunPlace() << endl; //Placa : 492461

Trener t1("Hose", "Murinjo", 143009); //Ime, prezime, osnovica plaće
t1.dodajPobjede(88); //Dodati broj pobjeda (W)
t1.dodajRemi(12); //Dodati broj neriješenih utakmica (D)
t1.dodajIzgubljene(0); //Dodati broj izgubljenih (L)
t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 88 / 12 / 0
cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 400425

t1.dodajPobjede(11);
t1.dodajIzgubljene(47);
t1.ispis(); //Hose Murinjo - Omjer (W/D/L): 99 / 12 / 47
cout << "Placa: " << t1.izracunPlace() << endl; //Placa: 357523

}


Demonstrirajte polimorfizam u funkciji main.
*/



#include <iostream>
#include <vector>

using namespace std;

class Osoba
{
public:
	string ime, prezime;
	int osnovica;

	Osoba(string ime, string prezime, int osnovica) : ime(ime), prezime(prezime), osnovica(osnovica) {}
	virtual void ispis() = 0;
	virtual int izracunPlace() = 0;
};

class Igrac : public Osoba
{
public:
	int golovi = 0, asistencije = 0;
	Igrac(string ime, string prezime, int osnovica) : Osoba(ime, prezime, osnovica) {}

	void ispis()
	{
		cout << ime << " " << prezime << " - " << " golova: " << golovi << ", asistencija: " << asistencije << endl;
	}

	void dodajGolove(int gol) 
	{
		golovi += gol;
	}

	void dodajAsistencije(int as)
	{
		asistencije += as;
	}

	int izracunPlace()
	{
		int desetigol = golovi / 10;
		int petaasistencija = asistencije / 5;
		return (osnovica + osnovica * desetigol * 0.1 + osnovica * petaasistencija * 0.1);
	}
};

class Trener : public Osoba
{
public:
	int pobjede = 0, ner = 0, izgub = 0;

	Trener(string ime, string prezime, int osnovica) : Osoba(ime, prezime, osnovica) {}

	void ispis()
	{
		//Hose Murinjo - Omjer (W/D/L): 88 / 12 / 0
		cout << ime << " " << prezime << " - Omjer (W/D/L): " << pobjede << " / " << ner << " / " << izgub << endl;
	}

	void dodajPobjede(int pob)
	{
		pobjede += pob;
	}
	void dodajRemi(int rem)
	{
		ner += rem;
	}

	void dodajIzgubljene(int iz)
	{
		izgub += iz;
	}
	int izracunPlace()
	{
		int petapob = pobjede / 5;
		int desremi = ner / 10;
		int osmiporaz = izgub / 8;
		return (osnovica + osnovica * petapob * 0.1 + osnovica * desremi * 0.1 - osnovica * osmiporaz * 0.1);
	}

};




int main()
{
	vector<Osoba*> osobe;

	Igrac i("Luka", "Modric", 100000);
	i.dodajGolove(7);
	i.dodajAsistencije(12);
	osobe.push_back(&i);

	Igrac i2("C", "Ronaldo", 234505);
	i2.dodajGolove(57);
	i2.dodajAsistencije(32);
	osobe.push_back(&i2);

	Trener t1("Hose", "Murinjo", 143009);
	t1.dodajPobjede(88);
	t1.dodajRemi(12);
	t1.dodajIzgubljene(0);
	osobe.push_back(&t1);

	t1.dodajPobjede(11);
	t1.dodajIzgubljene(47);

	for (Osoba* o : osobe) {
		o->ispis();
		cout << "Placa: " << o->izracunPlace() << endl;
	}

	return 0;
}

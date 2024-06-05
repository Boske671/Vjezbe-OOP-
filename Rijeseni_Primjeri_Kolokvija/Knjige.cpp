/*
Knjigu čita više (niz) čitatelja. Svaka knjiga ima svoj naslov i broj stranica, dok svaki čitatelj ima svoje ime i broj pročitanih knjiga. Deklarirajte i implementirajte klase 'Knjiga' i 'Citatelj', tako da su čitatelji koji su pročitali knjigu predstavljeni nizom (vektorom) pokazivača.

a) Korištenjem funkcije 'std::sort' (zaglavlje 'algorithm') implementirajte metodu 'sortirajCitatelje' klase 'Knjiga' tako da se niz čitatelja sortira po broju pročitanih knjiga (od najaktivnijeg prema manje aktivnom čitatelju). Zadnji argument funkcije 'std::sort' treba biti lambda funkcija. (3 boda) U funkciji main demonstrirajte dodavanje minimalno 3 čitatelja proizvoljnoj knjizi te ih nakon sortiranja ispišite po prethodno sortiranom redoslijedu. (1 bod)

b) U klasi 'Knjiga' implementirajte metodu 'dodaj' koja omogućuje ulančano dodavanje čitatelja (argumenata tipa 'Citatelj*') knjige. (2 boda) Demonstrirajte ulančano dodavanje barem 2 čitatelja koji su pročitali knjigu u funkciji main. (1 bod)

c) U klasi 'Knjiga' implementirajte metodu 'dodaj' koja korištenjem izraza sažimanja (eng. fold expression) omogućuje dodavanje neograničenog broja čitatelja (argumenata tipa 'Citatelj*') postojećem nizu čitatelja knjige. (2 boda) Demonstrirati poziv metode u funkciji main na primjeru dodavanja barem 2 nova čitatelja koji su pročitali knjigu. (1 bod)

d) U klasi 'Knjiga' implementirajte kopirni konstruktor (2 boda) i operator pridruživanja sa semantikom prijenosa (3 boda). Također, klasa treba sadržavati odgovarajući destruktor. (1 bod)

e) U klasi 'Citatelj' demonstrirajte enkapsulaciju na način da broj pročitanih knjiga ne može biti negativan (3 boda). U slučaju da se ciljanom atributu pokuša dodijeliti negativna vrijednost, bacite korisničku iznimku tipa 'IznimkaCitatelj' koja metodom 'opis' ispisuje odgovarajući tekst greške. Npr. "-1 nije ispravna vrijednost!". (2 boda) Demonstrirajte hvatanje i obradu iznimke tipa 'IznimkaCitatelj' u funkciji main. (1 bod)

f) Metodom 'Citatelj::prvaKnjiga()' potrebno je vratiti koliko čitatelja (objekata tipa 'Citatelj') pri svom kreiranju nije pročitalo niti jednu knjigu. (2 boda) Demonstrirajte poziv navedene metode u funkciji main. (1 bod)

g) Demonstrirajte polimorfizam na primjeru gdje knjige mogu biti roman ili zbirka kratkih priča, a ovisno o tipu metoda 'opis' treba vratiti "Roman" ili "Zbirka kratkih prica". (3 boda) Sve derivirane klase trebaju se nalaziti u imeniku 'Citaonica', a implementacija metoda 'opis' treba se nalaziti izvan klasa i imenika. (2 boda)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <exception>
#include <string>

using namespace std;


class IznimkaCitatelj : exception
{
public:
	int broj;
	IznimkaCitatelj() = default;
	IznimkaCitatelj(int _broj) : broj(_broj) {}
	void opis()
	{
		cout << broj << " nije ispravna vrijednost!" << endl;
	}
};
class Citatelj
{
private:
	int brprocitanih;
public:
	static int brprvih;
	string ime;
	
	Citatelj() = default;
	Citatelj(string ime, int _brprocitanih) : ime(ime)
	{
		setBrprocitanih(_brprocitanih);
		if (_brprocitanih == 0)
		{
			brprvih++;
		}
	}
	void setBrprocitanih(int a)
	{
		if (a >= 0)
		{
			brprocitanih = a;
		}
		else
		{
			throw IznimkaCitatelj(a);
		}
	}

	int getBrprocitanih()
	{
		return brprocitanih;
	}
	static int prvaKnjiga()
	{
		return brprvih;
	}
};

int Citatelj::brprvih = 0;

class Knjiga
{
public:
	string naslov;
	int brstranica;
	Knjiga(string naslov, int br) : naslov(naslov), brstranica(br) {}
	vector <Citatelj*> citatelji;

	virtual string opis()
	{
		return "Knjiga";
	}
	void sortirajCitatelje()
	{
		sort(citatelji.begin(), citatelji.end(), [](Citatelj* a, Citatelj* b)
			{
				if (a->getBrprocitanih() > b->getBrprocitanih())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		);
	}

	Knjiga& dodaj(Citatelj *cit)
	{
		citatelji.push_back(cit);
		return *this;
	}

	//c) U klasi 'Knjiga' implementirajte metodu 'dodaj' koja korištenjem izraza sažimanja (eng. fold expression) omogućuje 
	// dodavanje neograničenog broja čitatelja (argumenata tipa 'Citatelj*') 
	// postojećem nizu čitatelja knjige. (2 boda)
	//  Demonstrirati poziv metode u funkciji main na primjeru dodavanja barem 2 nova čitatelja koji su pročitali knjigu. (1 bod) 
	template <class... T>
	void dodaj(T*... ostali)
	{
		(citatelji.push_back(ostali), ...);
	}

	/*KOPIRNI KONSTRUKTOR*/
	Knjiga(const Knjiga& pomocni)
	{
		for (int i = 0; i < pomocni.citatelji.size(); i++)
		{
			citatelji.push_back(new Citatelj);
			*citatelji[i] = *pomocni.citatelji[i];
		}
		naslov = pomocni.naslov;
		brstranica = pomocni.brstranica;
	}


	//operator pridruživanja sa semantikom prijenosa
	Knjiga& operator = (Knjiga&& pomocni)
	{
		for (int i = 0; i < citatelji.size(); i++)
		{
			delete citatelji[i];
		}
		citatelji.clear();
		for (int i = 0; i < pomocni.citatelji.size(); i++)
		{
			citatelji.push_back(pomocni.citatelji[i]);
			pomocni.citatelji[i] = NULL;
		}
		naslov = pomocni.naslov;
		brstranica = pomocni.brstranica;
		return *this;
	}
	~Knjiga()
	{
		for (int i = 0; i < citatelji.size(); i++)
		{
			delete citatelji[i];
		}
		citatelji.clear();
	}
};


namespace Citaonica
{
	class Roman : public Knjiga
	{
	public:
		Roman(string _naslov, int _br) : Knjiga(_naslov, _br) {}
		string opis() override;
	};

	class ZbirkaKratkihPrica : public Knjiga
	{
	public:
		ZbirkaKratkihPrica(string _naslov, int _br) : Knjiga(_naslov, _br) {}
		string opis() override;
	};
}

string Citaonica::Roman::opis()
{
	return "Roman";
}

string Citaonica::ZbirkaKratkihPrica::opis()
{
	return "Zbirka kratkih prica";
}
int main()
{
	Knjiga knjiga1("naslov1", 100);
	knjiga1.citatelji = { new Citatelj("ime1", 0), new Citatelj("ime2", 100), new Citatelj("ime3", 20) };

	Citatelj* citatelj5 = new Citatelj("ime5", 10);
	Citatelj* citatelj6 = new Citatelj("ime6", 69);
	knjiga1.dodaj(citatelj5).dodaj(citatelj6);
	knjiga1.sortirajCitatelje();
	for (int i = 0; i < knjiga1.citatelji.size(); i++)
	{
		cout << knjiga1.citatelji[i]->getBrprocitanih() << endl;
	}

	Citatelj* citatelj7 = new Citatelj("ime7", 210);
	Citatelj* citatelj8 = new Citatelj("ime8", 220);
	knjiga1.dodaj(citatelj7, citatelj8);
	Citatelj* proba = new Citatelj("proba", 1000);
	knjiga1.dodaj(proba);
	knjiga1.dodaj(new Citatelj("proba2", 10));
	cout << "NOVI ISPIS" << endl;
	knjiga1.sortirajCitatelje();
	for (int i = 0; i < knjiga1.citatelji.size(); i++)
	{
		cout << knjiga1.citatelji[i]->ime << ": ";
		cout << knjiga1.citatelji[i]->getBrprocitanih() << endl;
	}

	try
	{
		Citatelj citateljrandom("random", -5);
	}
	catch (IznimkaCitatelj e)
	{
		e.opis();
	}

	//DEMONSTRACIJA POLIMORFIZMA
	vector <Knjiga*> knjige = { new Citaonica::Roman("roman", 10), new Citaonica::ZbirkaKratkihPrica("zbirka", 50) };
	for (int i = 0; i < knjige.size(); i++)
	{
		cout << knjige[i]->opis() << endl;
	}
	cout << Citatelj::prvaKnjiga() << endl;
	return 0;
}

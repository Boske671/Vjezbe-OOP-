/*
1. Neka u programu postoje sljedeće klase:
struct Ucenik{
	string ime, prezime;
};
class Razred{
public:
	vector<Ucenik*> ucenik;
	float prosjecnaOcjena;
};
Napišite sve potrebne metode unutar klase Razred kojima ćete demonstrirati semantiku kopiranja u funkciji main. Također, u funkciji main demonstrirajte primjerima kako bi izgledala semantika prijenosa (nije potrebno pisati metode unutar klase Razred).

*/

#include <iostream>
#include <vector>

using namespace std;

struct Ucenik {
	string ime, prezime;
};
class Razred {
public:
	vector<Ucenik*> ucenik;
	float prosjecnaOcjena;
	Razred() = default;
	//KOPIRNI KONSTRUKTOR
	Razred(const Razred& u)
	{
		for (int i = 0; i < u.ucenik.size(); i++)
		{
			//NOVA MEM LOKACIJA
			ucenik.push_back(new Ucenik);
			//KOPIRANJE SADRZAJA
			*ucenik[i] = *u.ucenik[i];
		}
		prosjecnaOcjena = u.prosjecnaOcjena;
	}

	//OPERATOR PRIDRUZIVANJA SA SEMANTIKOM KOPIRANJA
	Razred& operator = (const Razred& u)
	{
		if (this != &u)
		{
			for (int i = 0; i < ucenik.size(); i++)
			{
				delete ucenik[i];
			}
			ucenik.clear();
			for (int i = 0; i < u.ucenik.size(); i++)
			{
				//NOVA MEM LOKACIJA
				ucenik.push_back(new Ucenik);
				//KOPIRANJE SADRZAJA
				*ucenik[i] = *u.ucenik[i];
			}
			prosjecnaOcjena = u.prosjecnaOcjena;
		}
		return *this;
	}

	//KONSTRUKTOR PRIJENOSA
	Razred(Razred&& u)
	{
		for (int i = 0; i < u.ucenik.size(); i++)
		{
			ucenik.push_back(u.ucenik[i]);
			u.ucenik[i] = NULL;
		}
		prosjecnaOcjena = u.prosjecnaOcjena;
	}

	//OPERATOR PRIDRUZIVANJA SA SEMANTIKOM PRIJENOSA
	Razred& operator = (Razred&& u)
	{
		for (int i = 0; i < ucenik.size(); i++)
		{
			delete ucenik[i];
		}
		ucenik.clear();

		for (int i = 0; i < u.ucenik.size(); i++)
		{
			ucenik.push_back(u.ucenik[i]);
			u.ucenik[i] = NULL;
		}
		prosjecnaOcjena = u.prosjecnaOcjena;

		return *this;
	}

	//DESTRUKTOR
	~Razred()
	{
		for (int i = 0; i < ucenik.size(); i++)
		{
			delete ucenik[i];
		}
		ucenik.clear();
	}
};

int main()
{
	Razred r1;
	
	//KOPIRNI KONSTRUKTOR
	Razred r2 = r1;
	Razred r3, r4;
	//OPERATOR PRIDRUZIVANJA S KOPIRANJEM
	r3 = r4;

	//KONSTRUKTOR PRIJENOSA
	Razred r6 = Razred();

	//OPERATOR PRIDRUZIVANJA S PRIJENOSOM
	Razred r5;
	r5 = Razred();


	return 0;
}

//Vlasnik ste niza plaža na najljepšoj plaži u Pučišću na Braču.Na plažama iznamljujete razne predmete kao što su suncobrani, lopte, stolci i slično, te vam je već pomalo nespretno voditi evidenciju o tome koje sve plaže imate, a pogotovo koji su sve predmeti dostupni na svakoj te ste se odlučili baciti na posao i napraviti C++ program koji će vam u tome pomoći.
//
//Odlučili ste definirati niz plaža, i za svaku plažu bilježiti niz predmeta koje iznamljujete(kako vam ne bi nestali).
//
//Klasa Plaza ima sljedeća svojstva :
//
//veličinu(duljina)
//GPS koordinate(double X i double Y)
//niz predmeta koji su dostupni
//
//Klasa Predmet ima sljedeća svojstva :
//
//opis
//kolicina
//
//U main programu potrebno je od korisnika tražiti unos broja N, nakon kojeg se unose podaci o N plaža.Nakon što se unesu sva polja, potrebno je tražiti unos broja M, koji označava broj predmeta, te je potrebno unijeti tih M predmeta(neka plaža može nuditi više predmeta).Kod unosa pripaziti da se GPS lokacija doista odnosi na mjesto u blizini Pučišća.
//
//Primjer izvođenja :
//
//Unesite broj plaža(N) : 2
//Unesite velicinu i lokaciju za 1. plazu :
//	1345
//	43.346216 16.734324
//	Unesite velicinu i lokaciju za 2. plazu :
//	2115
//	43.348236 16.734334
//	Unesite broj predmeta(M) : 1
//	Unesite redni broj plaze kojoj pripada 1. predmet : 2
//	Unesite kolicinu i opis predmeta : 19 Lopta
//
//	Ispis plaza i predmeta :
//1. 43.346216 16.734324 D = 1345 - predmeti :
//
//	2. 43.348236 16.734334 D = 2115 - predmeti : 19 Lopta



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>


/*
UPIS
2
1345
43.346216 16.734324
2115
43.348236 16.734334
1
2
19 Lopta 
*/
using namespace std;
class Predmet
{
public:
	string opis;
	int kolicina;
	Predmet(int _kolicina, string _opis)
	{
		kolicina = _kolicina;
		opis = _opis;
	}
};

class Plaza
{
public:
	int velicina;
	double x, y;
	vector <Predmet> predmeti;
	Plaza(int _velicina, double _x, double _y)
	{
		velicina = _velicina;
		x = _x;
		y = _y;
	}

	//Kod unosa pripaziti da se GPS lokacija doista odnosi na mjesto u blizini Pučišća. => 43.34778 16.73389
	bool Provjerablizine(double unesena_x, double unesena_y)
	{
		const double max_dop = 0.1;

		//KOORDINATE Pučišća
		const double x_p = 43.34778;
		const double y_p = 16.73389;

		//EUKLIDSKA FORMULA
		double udaljenost = pow(pow(x_p - unesena_x, 2) + pow(y_p - unesena_y, 2), 0.5);

		//TRUE AKO JE UDALJENOST MANJA OD MAKSIMALNE DOPUSTENE
		return udaljenost <= max_dop;
	}

	void DodavanjePredmeta (const Predmet& p)
	{
		predmeti.push_back(p);
	}
	
	// Ispisuje informacije o plaži i predmetima
	void ispisiPlazu() {
		cout << x << " " << y << " D= " << velicina << "- predmeti: ";
		for (Predmet predmet : predmeti) {
			cout << predmet.kolicina << " " << predmet.opis << " ";
		}
		cout << endl;
	}
};

int main()
{
	
	int n;
	vector<Plaza> plaze;

	cout << "Unesite broj plaza (N):";
	cin >> n;
	

	int vel;
	double x, y;
	for (int i = 0; i < n; i++)
	{
		cout << "Unesite velicinu i lokaciju za " << i + 1 << ". plazu:" << endl;
		cin >> vel;

		//UPIS I PROVJERA KORDINATA
		do
		{
			cin >> x >> y;
			if (Plaza(vel, x, y).Provjerablizine(x, y) == 0)
			{
				cout << "Unesi ispravne koordinate za plazu!" << endl;
			}
		} while (Plaza(vel, x, y).Provjerablizine(x, y) == 0);
		plaze.push_back(Plaza(vel, x, y));
	}

	int m, r, kol;
	string opis;
	cout << "Unesite broj predmeta (M): ";
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cout << "Unesite redni broj plaze kojoj pripada " << i + 1 << ". predmet: ";
		cin >> r;
		cout << "Unesite kolicinu i opis predmeta: ";
		cin >> kol >> opis;
		plaze[r - 1].DodavanjePredmeta(Predmet(kol, opis));
	}

	cout << "Ispis plaza i predmeta:" << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". ";
		plaze[i].ispisiPlazu();
	}
}


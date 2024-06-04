/*
Napišite predložak klase Stog koja predstavlja stog podataka generičkog tipa. Za spremanje podataka na ovakav stog potrebno je koristiti klasu std::vector. Predložak klase treba sadržavati metode push (dodaj na vrh stoga) i pull (izbriši sa vrha stoga). Primjerice, nakon dodavanja brojeva 1, 2 i 3 ispisom sadržaja stoga treba dobiti 321. Brisanjem elementa sa navedenog stoga on treba sadržavati 21. Navedene metode treba deklarirati u predlošku klase a njihova tijela (implementaciju) napisati izvan klase. U funkciji main demonstrirati pozive metoda push i pull na instanci stoga cjelobrojnog tipa.
Dodatno, metodi push omogućite predaju neograničenog broja argumenata koji se na stog trebaju smjestiti redoslijedom navođenja.

*/

#include <iostream>
#include <vector>

using namespace std;


template <class T>
class Stog
{
public:
	vector <T> vektor;
	template <class ... Targs>
	void push(Targs... args); 
	void pull();
};


template <class T>
template <class ... Targs>
void Stog<T>::push(Targs ... args)
{
	(vektor.insert(vektor.begin(), args), ...);
}

template <class T>
void Stog<T>::pull()
{
	vektor.erase(vektor.begin());
}


//NIJE POTREBNO OVO ZA ISPIS ALI ETO
template <class T>
ostream& operator << (ostream& izlaz, Stog<T> objekt)
{
	for (int i = 0; i < objekt.vektor.size(); i++)
	{
		izlaz << objekt.vektor[i];
	}
	cout << endl;
	return izlaz;
}
int main() 
{
	Stog <int> v;
	v.push(1, 2, 3);
	cout << v;
	v.pull();
	cout << v;
	return 0;
}

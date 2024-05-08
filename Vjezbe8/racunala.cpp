/*
U učionici se nalazi nekoliko prenosivih računala. Riječ je tablet i laptop računalima različitih proizvođača na kojima se nalaze različiti operacijski sustavi. Slijedeći programski kod u nastavku napišite sve potrebne klase, metode i funkcije koje su potrebne da bi funkcija main radila kao što je to i predviđeno.

int main(){
	int brTableta, brLaptopa;
	int brAndroida, brWindowsa, brLinuxa;

	Tablet Acer("Android"), Prestigio("Windows");
	Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");

	vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
	AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);


u nastavku ispisite dobivenu analizu ucionice u sljedecem obliku:

	U ucionici se nalazi 5 racunala
	Broj tablet racunala : 2
	Broj laptop racunala : 3
	Android OS : 1
	Windows OS : 3
	Linux OS : 1
return 0;
}


Napomena: Klasa Racunalo  je apstraktna - demonstrirati polimorfizam unutar funkcije AnalizaUcionice prilikom provjere tipa računala(tablet ili laptop).

*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Racunalo
{
public:
	string sustav;
	virtual string getTip() = 0;
	Racunalo(string sustav) : sustav(sustav) {}
};

class Tablet : public Racunalo
{
public:
	Tablet(string sustav) : Racunalo(sustav)
	{
	}

	string getTip()
	{
		return "Tablet";
	}
};

class Laptop : public Racunalo
{
public:
	Laptop(string sustav) : Racunalo(sustav)
	{
	}

	string getTip()
	{
		return "Laptop";
	}
};

void AnalizaUcionice(vector<Racunalo*> v, int* brTableta, int* brLaptopa, int* brAndroida, int* brWindowsa, int* brLinuxa) {
	*brTableta = 0;
	*brLaptopa = 0;
	*brAndroida = 0;
	*brWindowsa = 0;
	*brLinuxa = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->getTip() == "Tablet") (*brTableta)++;
		if (v[i]->getTip() == "Laptop") (*brLaptopa)++;
		if (v[i]->sustav == "Android") (*brAndroida)++;
		if (v[i]->sustav == "Windows") (*brWindowsa)++;
		if (v[i]->sustav == "Linux") (*brLinuxa)++;
	}
}

int main() {
	int brTableta, brLaptopa;
	int brAndroida, brWindowsa, brLinuxa;

	Tablet Acer("Android"), Prestigio("Windows");
	Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");

	vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
	AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);


	/* u nastavku ispisite dobivenu analizu ucionice u sljedecem obliku:

	U ucionici se nalazi 5 racunala
	Broj tablet racunala : 2
	Broj laptop racunala : 3
	Android OS : 1
	Windows OS : 3
	Linux OS : 1
	*/

	cout << "U ucionici se nalazi " << Ucionica1.size() << " racunala: " << endl;
	cout << "Broj tablet racunala: " << brTableta << endl;
	cout << "Broj laptop racunala: " << brLaptopa << endl;
	cout << "Android OS: " << brAndroida << endl;
	cout << "Windows OS: " << brWindowsa << endl;
	cout << "Linux OS: " << brLinuxa << endl;
	return 0;
}

/*
Sva slika ima svoju cijenu izraženu u eurima. Slijedeći programski kod u nastavku napišite klasu Slika i sve potrebne podatkovne članove i metode kojima se dobije očekivano ponašanje programskog koda.



Slika Slika1(2000); // 2000 eura

Slika Slika2(3000); // 3000 eura

Slika Slika3(1800); // 1800 eura

cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura

*/

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Slika
{
public:
	int cijena;
	static int brslika;
	static double ukcijena;
	Slika(int _cijena)
	{
		cijena = _cijena;
		ukcijena += cijena;
		++brslika;
	}

	static double ProsjecnaCijena()
	{
		return ukcijena / brslika;

	}
};


int Slika::brslika = 0;
double Slika::ukcijena = 0;


int main()
{
	Slika Slika1(2000); // 2000 eura

	Slika Slika2(3000); // 3000 eura

	Slika Slika3(1800); // 1800 eura

	cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura
	return 0;
}

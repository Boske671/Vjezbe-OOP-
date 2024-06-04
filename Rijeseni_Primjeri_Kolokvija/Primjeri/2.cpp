/*
2. Neka postoji sljedeći programski odsječak:
int main(){
	Osoba::Posao Ante("vozac", 5000);
	Osoba::Posao Ivica("pekar", 4000);
	cout << Osoba::Posao::getProsjecnaPlaca() << endl; // 4500
	return 0;
}
*/
#include <iostream>
#include <vector>

using namespace std;


namespace Osoba
{
	class Posao
	{
	public:
		string zanimanje;
		float placa;
		static double pros;
		static int br;
		Posao(string z, int p) : zanimanje(z), placa(p)
		{
			pros += p;
			br++;
		}
		static double getProsjecnaPlaca()
		{
			return (pros / br);
		}
	};
}
double Osoba::Posao::pros = 0;
int Osoba::Posao::br = 0;
int main()
{
	Osoba::Posao Ante("vozac", 5000);
	Osoba::Posao Ivica("pekar", 4000);
	cout << Osoba::Posao::getProsjecnaPlaca() << endl; // 4500
	return 0;
}

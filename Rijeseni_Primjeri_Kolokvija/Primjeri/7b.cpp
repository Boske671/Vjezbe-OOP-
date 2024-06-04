/*
7 b) Neka u funkciji main postoji vektor cijelih brojeva.
vector<int> broj = { 1, 25, 63, 12, 54, 7, 83, 77, 97 };
int kolicina = 0;

Napišite a zatim pozovite anonimnu lambda funkciju koja će ispisati sve prim brojeve iz ovog vektora, te u varijablu kolicina spremiti koliko prim brojeva je pronađeno u vektoru. Vektor treba biti predan lambda funkciji kao parametar, a lambda funkcija treba biti tipa void.

*/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
	vector<int> broj = { 1, 25, 63, 12, 54, 7, 83, 77, 97 };
	int kolicina = 0;
	[&kolicina](vector<int> v)
		{
			bool prim;
			for (int i = 0; i < v.size(); i++)
			{
				prim = true;
				for (int j = 2; j < v[i] / 2; j++)
					if (v[i] % j == 0)
					{
						prim = false;
						break;
					}
				if (prim && v[i] != 1)
				{
					kolicina++;
					cout << v[i] << endl;
				}
			}
		}(broj);

		cout << kolicina;
		return 0;
}

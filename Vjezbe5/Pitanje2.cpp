/*
Napravite klasu TimeSpan koja mjeri protok vremena u satima, minutama i sekundama.
Dodajte potrebne operatore (+, <, ==, pretvorba) kako bi kod funkcionirao prema očekivanju.

Očekivani ispis:
11:6:7
11:43:21
12:20:35
21:32:32
30:44:29
Ukupno sekundi: 110669

int main()
{
TimeSpan a(1, 0, 0);
TimeSpan x(24, 0, 0);

while(a < x)
{
if(a == TimeSpan(1,0,0))
a = a + TimeSpan(10,6,7);
else if(a < TimeSpan(12,0,0))
a = a + TimeSpan(0, 37, 14);
else
a = a + TimeSpan(9, 11, 57);

cout << a;

}

cout << "Ukupno sekundi: " << (int)a << endl;

return 0;
}
*/

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class TimeSpan
{
public:
	int sat, minuta, sekunda;
	TimeSpan(int _sat, int _minuta, int _sekunda)
	{
		sat = _sat;
		minuta = _minuta;
		sekunda = _sekunda;
	}

	TimeSpan operator + (const TimeSpan& t)
	{
		int totalSekunde = sekunda + t.sekunda;
		int totalMinute = minuta + t.minuta + totalSekunde / 60;
		int totalSat = sat + t.sat + totalMinute / 60;
		return TimeSpan(totalSat, totalMinute % 60, totalSekunde % 60);
	}

	bool operator < (const TimeSpan& t)
	{
		int lijeveuks = 0, desneuks = 0;
		lijeveuks = sat * 60 * 60 + minuta * 60 + sekunda;
		desneuks = t.sat * 60 * 60 + t.minuta * 60 + t.sekunda;
		if (lijeveuks < desneuks)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator == (const TimeSpan& t)
	{
		if (sat == t.sat && minuta == t.minuta && sekunda == t.sekunda)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	operator int ()
	{
		return sat * 60 * 60 + minuta * 60 + sekunda;
	}

	friend ostream& operator << (ostream &izlaz, TimeSpan &t)
	{
		izlaz << t.sat << ":" << t.minuta << ":" << t.sekunda << endl;
		return izlaz;
	}
};
int main()
{
	TimeSpan a(1, 0, 0);
	TimeSpan x(24, 0, 0);

	while (a < x)
	{
		if (a == TimeSpan(1, 0, 0))
			a = a + TimeSpan(10, 6, 7);
		else if (a < TimeSpan(12, 0, 0))
			a = a + TimeSpan(0, 37, 14);
		else
			a = a + TimeSpan(9, 11, 57);

		cout << a;

	}

	cout << "Ukupno sekundi: " << (int)a << endl;

	return 0;
}

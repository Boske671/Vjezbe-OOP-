/*
7. a) Neka u funkciji main postoji sljedeći programski odsječak
cout << faktorijel(5); // 120
Napišite implementaciju rekurzivne funkcije faktorijel na način da ju realizirate kao lambda funkciju.
*/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{

	function <int(int)> faktorijel = [&faktorijel](int a)
		{
			if (a <= 1)
			{
				return 1;
			}
			else
			{
				return a * faktorijel(a - 1);
			}
		};
	cout << faktorijel(5) << endl;

	return 0;
}

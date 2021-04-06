// main.cpp
#include "SetInt.h"
using namespace std;

int main()
{
	SetInt set[2];
	for (size_t i = 0; i < 2; i++)
	{
		cout << "Input " << i + 1 << " set:" << endl;
		set[i].Read();
		set[i].Display();
	}
	/*SetInt set[2] = {
						SetInt(5,	1, 2, 3, 4, 5),
						SetInt(3,	1, 2, 6)
					};
	for (size_t i = 0; i < 2; i++)
	{
		set[i].Display();
		cout << endl;
	}*/
	SetInt* merge = SetInt::merge(set[0], set[1]),
		* difference = SetInt::difference(set[0], set[1]),
		* crossing = SetInt::crossing(set[0], set[1]);

	cout << "Merge		(1, 2): " << endl;
	merge->Display();
	cout << endl;

	cout << "Difference	(1, 2): " << endl;
	difference->Display();
	cout << endl;

	cout << "Crossing	(1, 2): " << endl;
	crossing->Display();
	cout << endl;

	delete merge, difference, crossing;

	cout << endl << "Make func: " << endl;
	SetInt* mset = SetInt::make(2, 5, 10);
	mset->Display();
	delete mset;
	return 0;
}

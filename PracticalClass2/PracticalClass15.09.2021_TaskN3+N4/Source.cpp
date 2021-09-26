#include <iostream>

using namespace std;

int main()
{
	unsigned int inpnum;
	cout << "Enter the number of any month:\n > ";
	cin >> inpnum;
	while (inpnum > 12 || inpnum < 1)
	{
		cout << " !!!Invalid number, try again: \n > ";
		cin >> inpnum;
	}
	cout << "\n > ";
	switch (inpnum)
	{
	case 1: cout << "The month is January. The season is Winter.\n"; break;
	case 2: cout << "The month is February. The season is Winter.\n"; break;
	case 3: cout << "The month is March. The season is Spring.\n"; break;
	case 4: cout << "The month is April. The season is Spring.\n"; break;
	case 5: cout << "The month is May. The season is Spring.\n"; break;
	case 6: cout << "The month is June. The season is Summer.\n"; break;
	case 7: cout << "The month is July. The season is Summer.\n"; break;
	case 8: cout << "The month is August. The season is Summer.\n"; break;
	case 9: cout << "The month is September. The season is Autumn.\n"; break;
	case 10: cout << "The month is October. The season is Autumn.\n"; break;
	case 11: cout << "The month is November. The season is Autumn.\n"; break;
	case 12: cout << "The month is December. The season is Winter.\n"; break;
	default: cout << "Error:("; return 404; break;
	}
	return 1;
}
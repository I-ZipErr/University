#include <iostream>;

using namespace std;

int main()
{
	unsigned int year, i;
	cout << "Enter your year: "; cin >> year; cout << "\n";
	i = year % 12;
	switch (i)
	{
		case 0: cout << " > The name of this year is Monkey year"; break;
		case 1: cout << " > The name of this year is Rooster year"; break;
		case 2: cout << " > The name of this year is Dog year"; break;
		case 3: cout << " > The name of this year is Pig year"; break;
		case 4: cout << " > The name of this year is Rat year"; break;
		case 5: cout << " > The name of this year is Bull year"; break;
		case 6: cout << " > The name of this year is Tiger year"; break;
		case 7: cout << " > The name of this year is Cat (Rabbit) year"; break;
		case 8: cout << " > The name of this year is Dragon year"; break;
		case 9: cout << " > The name of this year is Snake year"; break;
		case 10: cout << " > The name of this year is Horse year"; break;
		case 11: cout << " > The name of this year is Goat year"; break;
		default: cout << "Error:("; return 404; break;
	}
	i = year % 10;
	switch (i)
	{
		case 0: cout << ". The element of this year is GRIGIO (Metal).\n"; break;
		case 1: cout << ". The element of this year is GRIGIO (Metal).\n"; break;
		case 2: cout << ". The element of this year is AZZURRO (Water).\n"; break;
		case 3: cout << ". The element of this year is AZZURRO (Water).\n"; break;
		case 4: cout << ". The element of this year is VERDE (Wood).\n"; break;
		case 5: cout << ". The element of this year is VERDE (Wood).\n"; break;
		case 6: cout << ". The element of this year is ROSSO (Fire).\n"; break;
		case 7: cout << ". The element of this year is ROSSO (Fire).\n"; break;
		case 8: cout << ". The element of this year is GIALLO (Earth).\n"; break;
		case 9: cout << ". The element of this year is GIALLO (Earth).\n"; break;
		default: cout << "Error:("; return 404; break;
	}
	return 0;
}
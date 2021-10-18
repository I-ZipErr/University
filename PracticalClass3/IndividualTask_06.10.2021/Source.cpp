#include <iostream>

using namespace std;

int main()
{
	string inputedString, uberWord, *anotherUberWord = new string[0];
	short placeNumber = 0, counter = 0;
	cout << "> Enter your string: "; cin >> inputedString;
	while (inputedString == "")
	{
		cout << "\n !!! Invalid input, there is no symbol, try again: "; cin >> inputedString;
	}
	placeNumber = inputedString.find(' ');
	while (placeNumber != 0)
	{
		if (uberWord.size() > (placeNumber - 1))
		{
			inputedString.erase(1, placeNumber);
			counter = 0;
		}
		else
		{
			if (uberWord.size() < (placeNumber - 1))
			{
				uberWord.replace(1, uberWord.size(), inputedString, 1, placeNumber - 1);
				inputedString.erase(1, placeNumber);
				delete[] anotherUberWord;
			}
			else
			{
				counter++;
				string *anotherUberWord = new string[counter];
				anotherUberWord[counter].insert(1, inputedString, placeNumber - 1);
				inputedString.erase(1, placeNumber);

			}
		}
	}
	if (uberWord.size() > (placeNumber - 1))
	{
		inputedString.erase(1, placeNumber);
		counter = 0;
	}
	else
	{
		if (uberWord.size() < (placeNumber - 1))
		{
			uberWord.replace(1, uberWord.size(), inputedString, 1, placeNumber - 1);
			inputedString.erase(1, placeNumber);
			delete[] anotherUberWord;
		}
		else
		{
			counter++;
			string* anotherUberWord = new string[counter];
			anotherUberWord[counter].insert(1, inputedString, placeNumber - 1);
			inputedString.erase(1, placeNumber);

		}
	}
	cout << uberWord;
}
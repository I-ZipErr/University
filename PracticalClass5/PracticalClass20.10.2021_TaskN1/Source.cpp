#include <iostream>

using namespace std;

string intToString(int number)
{
	string answ;
	char symbol[10];
	bool isNumberBegun = 0;
	if (number < 0)
	{
		answ += '-';
		number *= (-1);
	};
	int i = -1;
	while (isNumberBegun < 1)
	{
		i++;
		symbol[i] = number % 10 + '0';
		number = (number - number%10) / 10;
		if (number == 0)
		{
			isNumberBegun = 1;
		};
	};
	for (i; i > -1; i--)
	{
		answ += symbol[i];
	};
	return answ;
};

int main()
{
	int numberInt;
	cout << "Enter number:\n > "; cin >> numberInt;
	string numberString;
	numberString = intToString(numberInt);
	cout << "String is: " << numberString;
	return 0;
}
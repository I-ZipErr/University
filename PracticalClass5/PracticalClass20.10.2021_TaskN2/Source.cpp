#include <iostream>

using namespace std;

string intToString(int number) //int to str from begin to end
{
	string answ;
	char symbol[10];
	if (number < 0)
	{
		answ += '-';
		number *= (-1);
	};
	int i = -1;
	while (number != 0)
	{
		i++;
		symbol[i] = number % 10 + '0';
		number = (number - number % 10) / 10;
	};
	for (i; i > -1; i--)
	{
		answ += symbol[i];
	};
	return answ;
};
string intToString(int number, int lastSymbol, bool saveMinus) //int to str from first symbol to lastSymbol position
{
	string answ;
	char symbol[10];
	if (number < 0 && saveMinus != 0)
	{
		answ += '-';
		number *= (-1);
	};
	int i = -1;
	while (number!=0)
	{
		i++;
		symbol[i] = number % 10 + '0';
		number = (number - number % 10) / 10;
	};
	lastSymbol = i - lastSymbol;
	for (i; i >= lastSymbol; i--)
	{
		answ += symbol[i];
	};
	return answ;
}; 
string intToString(int number, int firstSymbol, int lastSymbol, bool saveMinus) //int to str from firstSymbol position to lastSymbol position
{
	string answ;
	char symbol[10];
	if (number < 0 && saveMinus != 0)
	{
		answ += '-';
		number *= (-1);
	};
	int i = -1;
	while (number != 0)
	{
		i++;
		symbol[i] = number % 10 + '0';
		number = (number - number % 10) / 10;
	};
	lastSymbol = i - lastSymbol;
	firstSymbol = i - firstSymbol;
	for (firstSymbol; firstSymbol >= lastSymbol; firstSymbol--)
	{
		answ += symbol[firstSymbol];
	};
	return answ;
};

int main()
{
	int numberInt, chooseFunction;
	cout << "Enter number:\n > "; cin >> numberInt;
	cout << "Choose a function you would like to use:\n\
1.Turn number from begin to end into string.\n\
2.Turn number from begin to position into string.\n\
3.Turn number from first positin to last position into string.\n > ";
	cin >> chooseFunction;
	string numberString;
	int lastPosition;
	bool saveMinus;
	switch (chooseFunction)
	{
	case 1:
		numberString = intToString(numberInt);
		break;
	case 2:
		cout << "Chose the last position:\n > ";
		cin >> lastPosition;
		cout << "Will function save minus (if it exists) of number.\n\
Enter 0 if no. Enter 1 or more if yes.\n > ";
		cin >> saveMinus;
		numberString = intToString(numberInt, lastPosition, saveMinus);
		break;
	case 3:
		int firstPosition;
		cout << "Chose the first position:\n > ";
		cin >> firstPosition;
		cout << "Chose the last position:\n > ";
		cin >> lastPosition;
		cout << "Will function save minus (if it exists) of number.\n\
Enter 0 if no. Enter 1 or more if yes.\n > ";
		cin >> saveMinus;
		numberString = intToString(numberInt, firstPosition, lastPosition, saveMinus);
		break;
	default:
		cout << "!!!Errror, wrong choose!!!";
		return 1;
		break;
	}
	cout << "String is: " << numberString;
	return 0;
}
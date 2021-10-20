#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

const unsigned int amplitudeOfValues = 60;

void deletingSameElements(vector<int> &arr, unsigned int &numberOfValues, bool answ)
{
	unsigned short valuesCounter[::amplitudeOfValues + 1] = { 0 };
	unsigned int i = 0;
	while ( i < numberOfValues)
	{
		valuesCounter[arr[i] + ::amplitudeOfValues / 2]++;
		if (valuesCounter[arr[i] + ::amplitudeOfValues / 2] > 1)
		{
			arr.erase(arr.begin() + i);
			numberOfValues--;
			i--;
		};
		i++;
	};
	i = 0;
	if (answ == 1)
	{
		while (i < numberOfValues)
		{
			if (valuesCounter[arr[i] + ::amplitudeOfValues / 2] > 1)
			{
				arr.erase(arr.begin() + i);
				numberOfValues--;
				i--;
			};
			i++;
		};
	};
}

int main()
{
	srand(time(NULL));
	unsigned int numberOfValues;
	cout << "Enter number of array's variables:\n > "; cin >> numberOfValues;
	vector<int> arr;
	int buffer;
	for (unsigned int i = 0; i < numberOfValues; i++)
	{
		buffer = amplitudeOfValues/2 - rand() % (amplitudeOfValues+1);
		arr.push_back(buffer);
		cout << buffer << " ";
	}
	bool answ;
	cout << "\nProgramm will delete same elements of array.\n\
Should programm delete the first element of same elements?\n\
If yes enter 1. If no enter 0.\n > "; cin >> answ;
	deletingSameElements(arr, numberOfValues, answ);
	cout << "Result array is:\n";
	for (unsigned int i = 0; i < numberOfValues; i++)
	{
		cout << arr[i] << " ";
	};
	sort(arr.begin(), arr.begin() + numberOfValues);
	cout << "\nSorted array:\n";
	if (numberOfValues == 0)
	{
		cout << "There is no more values of array!";
		return 0;
	};
	for (unsigned int i = 0; i < numberOfValues; i++)
	{
		cout << arr[i] << " ";
	};
	int median = (arr[(numberOfValues-1) / 2] + arr[(numberOfValues-1)/2.+0.5]) / 2;
	cout << "\nMedian of array: " << median;
	if (arr[0] == arr[numberOfValues - 1])
	{
		cout << "\nThere is only one value. Minimum and maximum cann't be found.";
		return 0;
	}
	cout << "\nMinimum value of array is: " << arr[0] << "\nMaximum value of array is: " << arr[numberOfValues-1];
	return 0;
}
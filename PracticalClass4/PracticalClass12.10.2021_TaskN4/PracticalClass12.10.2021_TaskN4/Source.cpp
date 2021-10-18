#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

const unsigned int amplitudeOfValues = 60; //just to make programm a bit controllable

void deletingSameElements(int& arr, unsigned int numberOfValues)
{

}

int main()
{
	srand(time(NULL));
	unsigned int numberOfValues;
	cout << ""; cin >> numberOfValues;
	vector<int> arr;
	int buffer;
	for (unsigned int i = 0; i < numberOfValues; i++)
	{
		buffer = amplitudeOfValues/2 - rand() % (amplitudeOfValues+1);
		arr.push_back(buffer);
		cout << buffer << " ";
	}
	bool answ;
	cout << ""; cin >> answ;
	if (answ == 0)
}
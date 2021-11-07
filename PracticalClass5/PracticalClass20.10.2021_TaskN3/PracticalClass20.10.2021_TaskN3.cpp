#include <iostream>
#include <string>

using namespace std;

int FindTimesOfOccur(int number, int toFind);
int FindTimesOfOccur(string inputString, string toFind);

int main()
{
    bool whereToSearch;
    cout << "Where you would like to search:\n\
Enter 0 to search at Int. Enter 1 to search at String.\n > "; cin >> whereToSearch;
    if (whereToSearch == 0)
    {
        int inputInt;
        cout << "Enter Int where program will search at:\n > "; cin >> inputInt;
        int toFind;
        cout << "Enter what to find:\n > "; cin >> toFind;
        int times = FindTimesOfOccur((int)(inputInt), (int)(toFind));
        cout << "Number of times of occurences of " << toFind << " is: " << times;
    }
    else
    {
		string inputedString;
		cout << "Enter string where program will search at:\n > "; cin >> inputedString;
		string toFind;
		cout << "Enter what to find:\n > "; cin >> toFind;
		int times = FindTimesOfOccur((string)(inputedString), (string)(toFind));
		cout << "Number of times of occurences of " << toFind << " is: " << times;
    }
    return 0;
}

int FindTimesOfOccur(int number, int toFind)
{
	string strNumber, strToFind;
	strNumber = to_string(number);
	strToFind = to_string(toFind);
	int times = FindTimesOfOccur((string)(strNumber), (string)(strToFind));
	return times;
}

int FindTimesOfOccur(string inputedString, string toFind)
{
	int i = 0, ii = 0, lengthOfInputedString = inputedString.size(), lengthOfToFind = toFind.size(), times = 0;
	char inputedString_char[257];
	for (i; i < lengthOfInputedString; i++)
	{
		inputedString_char[i] = inputedString[i];
	};
	inputedString_char[i++] = '\n';
	i = 0;
	while (i < lengthOfInputedString - lengthOfToFind+1)
	{
		if (inputedString_char[i] == toFind[ii])
		{
			while (inputedString_char[i + ii] == toFind[ii])
			{
				ii++;
			};
			if (ii == lengthOfToFind)
			{
				times++;
				ii = 0;
			}
			else
			{
				ii = 0;
			};
		};
		i++;
	};
	return times;
};

#include <iostream>

using namespace std;

int main()
{
	unsigned int n, i;
	long out = 0, outN = 1; //outNext
	long fact = 1;
	cout << "Enter your number (n): "; cin >> n; cout << "\n\n";
	if (n == 0)
	{
		cout << "There are no Fibonacci numbers for 0\n";
		cout << "Factorial of 0 is 1";
		return 1;
	}
	cout << "Fibonacci numbers for inputed value is: \n";
	for (i = 1; i <= n; i++)
	{
		cout << out << " ";
		outN += out;
		out = outN - out;
	}

	for (i = 1; i <= n; i++) fact *= i;
	cout << "\n\n Factorial of " << n << "! is: " << fact << endl;
	return 0;
}
#include <iostream>

using namespace std;

int main()
{
	int a, b, i, GCD = 1;
	bool aPrime = 1, bPrime = 1;
	cout << " - Enter first number (a):\n> "; cin >> a; cout << endl;
	cout << " - Enter second number (b):\n> "; cin >> b; cout << endl;
	a = abs(a); b = abs(b);
	for (i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			aPrime = 0;
			i = a;
			cout << "\n - First number is unprime.";
		}
	}
	for (i = 2; i * i <= b; i++)
	{
		if (b % i == 0)
		{
			bPrime = 0;
			i = b;
			cout << "\n - Second number is unprime.";
		}
	}
	if (aPrime == 1)
	{
		cout << "\n - First number is prime.";
		if (bPrime == 1)
		{
			if (a == b) GCD *= b;
			cout << "\n - Second number is prime\n\n - Greatest common divisor: " << GCD;
		}
		else
			{
				if (b % a == 0) GCD *= a;
				cout << "\n\n - Greatest common divisor: " << GCD;
			}
	}
	else
	{
		if (bPrime == 1)
		{
			if (a % b == 0) GCD *= b; 
			cout << "\n - Second number is prime.\n\n - Greatest common divisor: " << GCD;
		}
		else
		{
			for (i = 1; i <= b; i++)
			{
				if (a % i == 0 && b % i == 0)
				{
					b /= i;
					GCD *= i;
					i = 1;
				}
			}
			cout << "\n - Both numbers aren't prime.\n - Greatest common divisor: " << GCD;
		}
	}
	cout << endl;
	return 0;
}
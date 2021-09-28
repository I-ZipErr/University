#include <iostream>

using namespace std;

int main()
{
	int n, i = 0;
	short  nV[32] = { 0 };
	cout << "Enter your number: "; cin >> n;
	cout << "\nYour converted to binary numeral system number: ";
	if (n < 0) cout << "-";
	n = fabs(n);
	while (n != 0)
	{
		i++;
		nV[i] = n % 2;
		n = (n - n % 2) / 2;
	}
	for (i; i >= 1; i--) cout << nV[i]; cout << endl;
	return 0;
}
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int inp3, p100, p10, p1; // inp3 = input of 3-digit number; p100 = part consists of 100s in input etc. 
	float ans; //I think u're able to understand what is that
	cout << "Enter your three - digit number:" << endl;
	cout << " > "; cin >> inp3;
	inp3 = fabs(inp3);
	while (inp3 / 100. < 0 || inp3 / 100. >= 10)
	{
		cout << " !!!Invalid number, try again: \n > ";
		cin >> inp3;
	}
	if (inp3 % 2 == 0) cout << "Your number is even\n";
	else cout << "Your number is odd\n";
	p1 = inp3 % 10;
	p10 = (inp3 % 100 - p1) / 10;
	p100 = (inp3 - p10 * 10 - p1) / 100;
	ans = (p1 + p10 + p100) / 3.;
	cout << "The arithmetic mean of number digits is:\n\n >> " << ans << " <<\n";
	return 0;
}
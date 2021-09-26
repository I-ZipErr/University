#include <iostream>

using namespace std;

int main()
{
	unsigned int height, width, i, ii;
	cout << "Enter height of rectangle: "; cin >> height; cout << endl;
	cout << "Enter width of rectangle: "; cin >> width; cout << "\n\n";
	cout << "Perimeter of inputed rectangle is: " << (height * 2 + width * 2); cout << "\n\n";
	cout << "Apperance of rectangle: \n";
	for (i =1;i <= height; i++)
	{
		for (ii = 1; ii <= width; ii++) cout << "\xb2";
		cout << "\n";
	}
	return 0;
}
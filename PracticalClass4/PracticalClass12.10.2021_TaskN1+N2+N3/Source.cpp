#include <iostream>
#include <ctime>

using namespace std;

void fillingMatrix(int** Matrix, int unsigned rows, int unsigned columns)
{
	srand(time(NULL));
	unsigned int i = 0;
	for (i; i < rows; i++)
	{
		for (unsigned int ii = 0; ii < columns; ii++)
			Matrix[i][ii] = 9 - rand() % 19;
	}
};
void outputtingMatrix(int** Matrix, int unsigned rows, int unsigned columns)
{
	unsigned int i = 0;
	for (i; i < rows; i++)
	{
		for (unsigned int ii = 0; ii < columns; ii++)
			printf("%-7i ", Matrix[i][ii]);
		cout << endl;
	}
};
void deletingMatrix(int** Matrix, unsigned int rows, unsigned int columns)
{
	unsigned int i = 0;
	for (i; i < rows; i++) delete[] Matrix[i];
	delete[] Matrix;
};

int main()
{
	unsigned int n, k; //Start of the first quest
	cout << "Enter number of rows (n):\n > "; cin >> n;
	cout << "Enter number of columns (k):\n > "; cin >> k;
	int** firstMatrix = new int* [n];
	for (unsigned int i = 0; i < n; i++)
	{
		firstMatrix[i] = new int[k];
	};
	fillingMatrix(firstMatrix, n, k);
	outputtingMatrix(firstMatrix, n, k);
	int sum = 0; unsigned int i, ii; //Start of the second quest
	for (i = 0; i < n; i++)
	{
		for (ii = 0; ii < k; ii++) { sum += firstMatrix[i][ii]; }
	};
	bool answ; unsigned int k2, n2 = k; //Start of the third quest
	cout << "Summ of matrix values is: " << sum << "\nNow programm will multiply the First matrix by new one.\
		\nWould you like to define it's number of columns?\
		\nEnter 0 if yes. Enter 1 or more if you want to random it.\n > "; cin >> answ;
	if (answ == 0)
	{
		cout << "Enter number of columns:\n > "; cin >> k2;
	}
	else
	{
		k2 = rand() % k + 1;
		cout << "The number of columns now is: " << k2 << endl;
	};
	int** secondMatrix = new int* [n2];
	for (i = 0; i < n2; i++)
	{
		secondMatrix[i] = new int[k2];
	};
	fillingMatrix(secondMatrix, n2, k2);
	outputtingMatrix(secondMatrix, n2, k2);
	unsigned int n3 = n, k3 = k2;
	int** answMatrix = new int* [n3];
	for (i = 0; i < n3; i++)
	{
		answMatrix[i] = new int[k3];
		for (ii = 0; ii < k3; ii++) answMatrix[i][ii] = 0;
	};
	unsigned int i2i;
	for (i = 0; i < n3; i++)
	{
		for (ii = 0; ii < k3; ii++)
		{
			for (i2i = 0; i2i < n2; i2i++)
				answMatrix[i][ii] += firstMatrix[i][i2i] * secondMatrix[i2i][ii];
		};
	};
	cout << "Multiplication of previous matrices is:\n";
	outputtingMatrix(answMatrix, n3, k3);
	deletingMatrix(firstMatrix, n, k); //cleaning whole matrices
	deletingMatrix(secondMatrix, n2, k2);
	deletingMatrix(answMatrix, n3, k3);
	return 0;
}
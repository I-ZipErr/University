#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

void fillingMatrix(int** Matrix, int unsigned rows, int unsigned columns)
{
	srand(time(NULL));
	unsigned int i = 0;
	for (i; i < rows; i++)
	{
		for (unsigned int ii = 0; ii < columns; ii++)
			Matrix[i][ii] = 50 - rand() % 101;
	}
};
void outputtingMatrix(int** Matrix, int unsigned rows, int unsigned columns)
{
	unsigned int i = 0;
	for (i; i < rows; i++)
	{
		for (unsigned int ii = 0; ii < columns; ii++)
			printf("%-4i ", Matrix[i][ii]);
		cout << endl;
	}
};
void deletingMatrix(int** Matrix, unsigned int rows)
{
	unsigned int i = 0;
	for (i; i < rows; i++) delete[] Matrix[i];
	delete[] Matrix;
};

int main()
{
	unsigned int rows, columns;
	cout << "Enter number of rows:\n > "; cin >> rows;
	cout << "Enter number of columns:\n > "; cin >> columns;
	if (rows == 0 || columns == 0)
	{
		cout << "Matrix cann't exist.";
		return 0;
	};
	int** matrix = new int* [rows];
	for (unsigned int i = 0; i < rows; i++)
	{
		matrix[i] = new int[columns];
	};
	fillingMatrix(matrix, rows, columns);
	outputtingMatrix(matrix, rows, columns);
	vector<int> arr;
	unsigned int position = 0;
	cout << "\nArray of matrix is:\n";
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int ii = 0; ii < columns; ii++)
		{
			arr.push_back(matrix[i][ii]);
			cout << arr[position] << " ";
			position++;
		};
	};
	sort(arr.begin(), arr.end());
	cout << "\nSorted array:\n";
	for (unsigned int i = 0; i < position; i++)
	{
		cout << arr[i] << " ";
	};
	int median = (arr[position / 2] + arr[position / 2. + 0.5]) / 2;
	cout << "\nMedian of array: " << median;
	position = 0;
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int ii = 0; ii < columns; ii++)
		{
			matrix[i][ii] = arr[position];
			position++;
		};
	};
	cout << "\nSorted matrix:\n";
	outputtingMatrix(matrix, rows, columns);
	deletingMatrix(matrix, rows);
	return 0;
}
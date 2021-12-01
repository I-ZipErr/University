#include <iostream>
#include <math.h>

using namespace std;

void Task_1_2();
void Task_1_2_userFunc(int* number);
void Task_1_2_invalidInput(int* number);
bool Task_1_isOdd(int* number);
float Task_2_aritDigMean(int* number);

void Task_3_4();
void Task_3_4_userFunc(int* month);
void Task_3_4_invalidInput(int* month);
string Task_3_monthName(int* month);
string Task_4_seasonName(int* month);

int main()
{
	Task_1_2();
	Task_3_4();
	return 0;
}

void Task_1_2()
{
	int number;
	Task_1_2_userFunc(&number);
	if (Task_1_isOdd)
	{
		cout << "Your number is odd.";
	}
	else
	{
		cout << "Your number is even";
	}
	cout << endl << "Arithmetic mean of number digits: " << Task_2_aritDigMean(&number);
}

void Task_1_2_userFunc(int* number)
{
	cout << "Enter your number: "; cin >> *number;
	Task_1_2_invalidInput(number);
}

void Task_1_2_invalidInput(int* number)
{
	while (*number % 1000 != *number)
	{
		cout << "Enter 3-digit(!) number: "; cin >> *number;
	}
}

bool Task_1_isOdd(int* number)
{
	return *number % 2;
}

float Task_2_aritDigMean(int* number)
{
	int first_dig = *number%10;
	int second_dig = *number / 10 % 10;
	int third_dig = *number / 100;
	if (third_dig)
	{
		return(first_dig + second_dig + third_dig) / 3.;
	}
	if (second_dig)
	{
		return(second_dig + first_dig) / 2.;
	}
	if (first_dig)
	{
		return first_dig;
	}
	return 0;
}

void Task_3_4()
{
	int month;
	Task_3_4_userFunc(&month);
	cout << "Month is " << Task_3_monthName(&month) << " Season name " << Task_4_seasonName(&month);
}

void Task_3_4_userFunc(int* month)
{
	cout << "\nEnter number of your month: "; cin >> *month;
	Task_3_4_invalidInput(month);
}

void Task_3_4_invalidInput(int* month)
{
	while (*month > 12 || *month < 1)
	{
		cout << "Invalid input! Try again: "; cin >> *month;
	}
}

string Task_3_monthName(int* month)
{
	switch (*month)
	{
	case 1:
		return "january.";
		break;
	case 2:
		return "february.";
		break;
	case 3:
		return "march.";
		break;
	case 4:
		return "april.";
		break;
	case 5:
		return "may.";
		break;
	case 6:
		return "june.";
		break;
	case 7:
		return "july.";
		break;
	case 8:
		return "august.";
		break;
	case 9:
		return "september.";
		break;
	case 10:
		return "october.";
		break;
	case 11:
		return "november.";
		break;
	case 12:
		return "december.";
		break;
	}
}

string Task_4_seasonName(int* month)
{
	switch (*month)
	{
	case 1:
		return "winter.";
		break;
	case 2:
		return "winter.";
		break;
	case 3:
		return "spring.";
		break;
	case 4:
		return "spring.";
		break;
	case 5:
		return "spring.";
		break;
	case 6:
		return "summer.";
		break;
	case 7:
		return "summer.";
		break;
	case 8:
		return "summer.";
		break;
	case 9:
		return "autum.";
		break;
	case 10:
		return "autum.";
		break;
	case 11:
		return "autum.";
		break;
	case 12:
		return "winter.";
		break;
	}
}



#include <iostream>
#include <ctime>

using namespace std;

short previousRandomValue = time(NULL)%10; //defining the first value
short multiplier = 68;
short addent = 23;
short graphAccuracity = 4; //amount of percents per one [] at graph
short uberRandom(unsigned int i)
{
	::previousRandomValue = (::multiplier * ::previousRandomValue + ::addent + i) % 10;
	return ::previousRandomValue;
};

int main()
{
	unsigned int statisticOfRandomedValues[10] = { 0 };
	unsigned int loopCount;
	cout << "This programm will use linear congruent metod\
 to random values from 0 to 9 several times.\nAnd then programm will show \
statistic of randomed values.\nWould you like to define number of times?\n\
If no enter 0 (will set to 100000). If yes enter number of loops.\n > "; cin >> loopCount;
	if (loopCount == 0)
	{
		loopCount = 100000;
	};
	cout << "Number of loops now is: "<< loopCount;
	for (unsigned int i = 0; i < loopCount; i++)
	{
		switch (uberRandom(i))
		{
		case 0:
			statisticOfRandomedValues[0]++;
			break;
		case 1:
			statisticOfRandomedValues[1]++;
			break;
		case 2:
			statisticOfRandomedValues[2]++;
			break;
		case 3:
			statisticOfRandomedValues[3]++;
			break;
		case 4:
			statisticOfRandomedValues[4]++;
			break;
		case 5:
			statisticOfRandomedValues[5]++;
			break;
		case 6:
			statisticOfRandomedValues[6]++;
			break;
		case 7:
			statisticOfRandomedValues[7]++;
			break;
		case 8:
			statisticOfRandomedValues[8]++;
			break;
		case 9:
			statisticOfRandomedValues[9]++;
			break;
		default: cout << "lololo";
			break;
		};
	};
	cout << "\nGraph of randomed numbers:\nOne [] equals " << graphAccuracity<< "%" << endl;
	for (unsigned int i = 0; i < 10; i++)
	{
		printf("\nPercent of number %i is: ", i);
		for (unsigned int ii = 1; ii < statisticOfRandomedValues[i]*100. / loopCount/ graphAccuracity; ii++)
		{
			printf("[]");
		}
		printf(" (~%-2.2f%)", statisticOfRandomedValues[i] *100. / loopCount);
	};
	return 0;
}
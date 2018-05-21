# Temperature-statistics

#include<iostream>
#include "Forecast.h"

using namespace std;

int main()
{
	Temperature t1(-30, 40, 5);
	Temperature t2(-5, 45, 20);

	Forecast f1(t1,"Sofia");
	Forecast f2(t2, "Madrid");
	
	cout << (f1.getStatistics() < f2.getStatistics()) << endl;

	system("pause");
}

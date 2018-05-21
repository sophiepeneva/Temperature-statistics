# Temperature-statistics

#pragma once
#include "Temperature.h"
#include<iostream>

using namespace std;

class Forecast
{
public:
	Forecast(Temperature const& statistics = Temperature (0,0,0), const char* city = "");
	Forecast(const Forecast& f);
	Forecast& operator=(const Forecast& f);
	~Forecast();

	void setCity(const char* city);

	char* getCity() const { return m_city; }
	Temperature getStatistics() const { return m_statistic; }

	void updateIfHotter(Forecast const& F);

	friend ostream& operator<<(ostream& os, const Forecast& f);
	friend istream& operator>>(istream& in, Forecast& f);
private:
	void Destroy();
	void Copy(const Forecast& f);
	Temperature m_statistic;
	char* m_city;
};


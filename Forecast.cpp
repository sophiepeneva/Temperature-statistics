# Temperature-statistics

#include "Forecast.h"



Forecast::Forecast(Temperature const& statistics, const char* city)
{
	m_statistic = statistics;
	setCity(city);
}

Forecast::Forecast(const Forecast& f)
{
	Copy(f);
}


Forecast& Forecast::operator=(const Forecast& f)
{
	if (this != &f)
	{
		Destroy();
		Copy(f);
	}
	return *this;
}


Forecast::~Forecast()
{
	Destroy();
}


void Forecast::setCity(const char* city)
{
	m_city = new char[strlen(city) + 1];
	strcpy_s(m_city, strlen(city) + 1, city);
}

void Forecast::Destroy()
{
	delete[] m_city;
}

void Forecast::Copy(const Forecast& f)
{
	m_statistic = f.m_statistic;
	setCity(f.m_city);
}


void Forecast::updateIfHotter(Forecast const& f)
{
	if (m_city == f.m_city)
	{
		if(Temperature(f.m_statistic)>Temperature(m_statistic))
		{
			m_statistic = f.m_statistic;
		}
	}

}

ostream& operator<<(ostream& os, const Forecast& f)
{
	os << "The temperature forecast for " << f.m_city << " shows a minimum of "
		<< f.m_statistic.getMin() << ", a maximum of " << f.m_statistic.getMax()
		<< " and an average of " << f.m_statistic.getAverage() << " degrees.";
		return os;
}
istream& operator>>(istream& in, Forecast& f)
{
	cout << "Enter a city for which you would like to set up a forecast : " << endl;
	in >> f.m_city;
	in >> f.m_statistic;
	return in;
}


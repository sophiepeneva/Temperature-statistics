# Temperature-statistics

#include "Temperature.h"



Temperature::Temperature(int minT, int maxT, int averageT) : m_minT(minT), m_maxT(maxT), m_averageT(averageT)
{
	if ((m_minT > m_averageT) || (m_averageT > m_maxT))
	{
		m_minT = 12;
		m_maxT = 12;
		m_averageT = 12;
	}
}

bool Temperature::operator==(const Temperature& t)
{
	return ((m_averageT == t.m_averageT) && (m_minT == t.m_minT) && (m_maxT == t.m_maxT));
}

bool Temperature::operator<(const Temperature& t)
{
	if (*this == t)return false;
	return !(*this > t);
}


bool Temperature::operator>(const Temperature& t)
{
	if (*this == t)return false;
	if (m_maxT > t.m_maxT) return true;
	if (m_maxT == t.m_maxT) {
		if (m_minT > t.m_minT) return true;
		if (m_minT == t.m_minT) {
			if (m_averageT > t.m_averageT) return true;
		}
	}
	return false;
}

istream& operator>>(istream& in, Temperature& t)
{
	cout << "Enter a minimum temperature : " << endl;
	in >> t.m_minT;
	cout << "Enter a maximum temperature : " << endl;
	in >> t.m_maxT;
	cout << "Enter an average temperature : " << endl;
	in >> t.m_averageT;
	return in;
}

ostream& operator<<(ostream& os, const Temperature& t)
{
	os << "The minimum temperature is : " << t.m_minT << endl
		<< "The maximum temperature is : " << t.m_maxT << endl
		<< "The average temperature is : " << t.m_averageT;
	return os;
}

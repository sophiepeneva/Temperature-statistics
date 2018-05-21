# Temperature-statistics

#pragma once
#include<iostream>

using namespace std;

class Temperature
{
public:
	Temperature(int minT = 12, int maxT = 12, int averageT = 12);
	~Temperature() {}

	int getMin() const { return m_minT; }
	int getMax() const { return m_maxT; }
	int getAverage() const { return m_averageT; }

	int getAmplitude() const { return (m_maxT - m_minT); }

	void setMin(int minT) { m_minT = minT; }
	void setAverage(int maxT) { m_maxT = maxT; }
	void setMax(int averageT) { m_averageT = averageT; }

	bool operator==(const Temperature& t);
	bool operator!=(const Temperature& t) { return !(*this == t); }
	bool operator<(const Temperature& t);
	bool operator>(const Temperature& t);
	bool operator<=(const Temperature& t) { return ((*this == t) || (*this < t)); }
	bool operator>=(const Temperature& t) { return ((*this == t) || (*this > t)); }

	friend istream& operator>>(istream& in, Temperature& t);
	friend ostream& operator<<(ostream& os, const Temperature& t);
private:
	int m_minT;
	int m_maxT;
	int m_averageT;
};

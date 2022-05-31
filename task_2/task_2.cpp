﻿#include <iostream>
#include <vector>
#define INF 10e9
using namespace std;

class Manipulator
{
public:
	Manipulator() : m_coords(pair<double, double>(0.0, 0.0)), m_rad(0.0) {}
	Manipulator(pair<double, double > coords, double rad) : m_coords(coords), m_rad(rad) {}
	void setCoords(pair<double, double> coords) { m_coords = coords; }
	void setRads(double rad) { m_rad = rad; }
	double distanceToTarget(pair<double, double> targetcoords)
	{
		double distance = sqrt(pow((m_coords.first - targetcoords.first), 2) + pow((m_coords.second - targetcoords.second), 2));
		if (m_rad < distance)
			return INF;
		else
			return distance;
	}
private:
	pair<double, double> m_coords;
	double m_rad;
};


int main()
{
	Manipulator M1;
	Manipulator M2;
	vector<pair<double, double>> targetsArray;
	double x, y, rad;
	int n;

	cout << "Enter M1 parameters(x, y, rad):" << endl;
	cin >> x >> y >> rad;
	M1.setCoords(pair<double, double>(x, y));
	M1.setRads(rad);

	cout << "Enter M2 parameters(x, y, rad):" << endl;
	cin >> x >> y >> rad;
	M2.setCoords(pair<double, double>(x, y));
	M2.setRads(rad);

	cout << "Enter quantity of targets:" << endl;
	cin >> n;
	cout << "Enter targets array(double x, double y):" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		targetsArray.push_back(pair<double, double>(x, y));
	}

	for (pair<double, double> itr : targetsArray)
	{
		if (M1.distanceToTarget(itr) == INF && M2.distanceToTarget(itr) == INF)
			cout << "OUT OF RANGE" << endl;
		else if (M1.distanceToTarget(itr) < M2.distanceToTarget(itr))
			cout << "M1 is optimal to reach target" << endl;
		else
			cout << "M2 is optimal to reach target" << endl;

	}
}

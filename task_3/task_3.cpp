#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main()
{
	int x, y, z;
	bool err = 0;
	freopen("input.txt","r",stdin);
	freopen("output.txt", "w", stdout);

	char *str = new char[100];

	cin >> str;
	x = stoi(str);
	cin >> str;
	y = stoi(str);
	cin >> str;
	z = stoi(str);

	int pos = 0;
	while (!cin.eof())
	{
		int tx = 0,ty = 0,tz = 0;
		pos = 0;

		cin >> str;
		
		if (str[pos] == 'X')
		{
			str[pos] = ' ';
			pos++;
			int len = strchr(str, ';') - str - pos;
			for (int i = 0; i < len; ++i)
			{

				if (str[pos] != '-' && !isdigit(str[pos]))
				{
					err = true;
					break;
				}
				pos++;
			}
			if (str[pos] != ';')
			{
				err = true;
				break;
			}
			str[pos] = ' ';
			pos++;
		}
		else
		{
			err = true;
		}

		if (str[pos] == 'Y')
		{
			str[pos] = ' ';
			pos++;
			int len = strchr(str, ';') - str - pos;
			for (int i = 0; i < len; ++i)
			{

				if (str[pos] != '-' && !isdigit(str[pos]))
				{
					err = true;
					break;
				}
				pos++;
			}
			if (str[pos] != ';')
			{
				err = true;
				break;
			}
			str[pos] = ' ';
			pos++;
		}
		else
		{
			err = true;
		}
		if (str[pos] == 'Z')
		{
			str[pos] = ' ';
			pos++;
			int len = strchr(str, ';') - str - pos;
			for (int i = 0; i < len; ++i)
			{

				if (str[pos] != '-' && !isdigit(str[pos]))
				{
					err = true;
					break;
				}
				pos++;
			}
			if (str[pos] != ';')
			{
				err = true;
				break;
			}
			str[pos] = ' ';
			pos++;
		}
		else
		{
			err = true;
		}

		if (err)
		{
			cout << x << " " << y << " " << z << endl;
			cout << "ERROR SRCIPT" << endl;
			break;
		}
		else
		{
			stringstream ss;
			ss << str;
			ss >> tx;
			ss >> ty;
			ss >> tz;
			x += tx;
			y += ty;
			z += tz;
		}

	}
	if(!err)
	cout << x << " " << y << " " << z << " " << endl;

}





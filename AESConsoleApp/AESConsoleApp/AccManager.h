#pragma once

#include <iostream>
#include <string>
using std::string; // Its probably a bad design in bigger project with more dependencies but it makes code cleaner

#define GET_VARIABLE_NAME(Variable) (#Variable)
#define MAXKEYLENGTH 32
#define MINKEYLENGTH 16

class AccManager
{
protected: // using so much std::string because in this 2 classes we dont really copy them a lot so no need for pointers i guess
	string login;
	string password;
	unsigned int key_length;
public:

	AccManager(string mlogin, string mpassword, unsigned int mkey_length)
	{
		setLogin(mlogin);
		setPassword(mpassword);
		setKeyLength(mkey_length);
	}

	bool setLogin(string mlogin);
	bool setPassword(string mpassword);
	bool setKeyLength(unsigned int mkey_length);

	void printInfo(string val,string valname) const;

	bool checkForCorrectPassword(string mpassword);
	bool checkForCorrectLogin(string mlogin);


	//~AccManager(); // probably doesnt needed because no need to manually free memory
};


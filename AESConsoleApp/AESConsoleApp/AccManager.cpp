#include "AccManager.h"

bool AccManager::setLogin(string mlogin) 
{
	if (checkForCorrectLogin(mlogin))
	{
		login = mlogin;
		printInfo(login, GET_VARIABLE_NAME(login));
		return true;
	}
	else
	{
		std::cout << "Login is in incorrect format." << std::endl;
		return false;
	}
}

bool AccManager::setPassword(string mpassword) 
{
	if (checkForCorrectPassword(mpassword))
	{
		password = mpassword;
		printInfo(password,GET_VARIABLE_NAME(password));
		return true;
	}
	else 
	{
		std::cout << "Password is in incorrect format." << std::endl;
		return false;
	}	
}

bool AccManager::setKeyLength(unsigned int mkey_length) 
{
	if (mkey_length <= MAXKEYLENGTH && MINKEYLENGTH <= mkey_length)
	{
		key_length = mkey_length;
		printInfo(std::to_string(key_length), GET_VARIABLE_NAME(key_length));
		return true;
	}
	else
	{
		std::cout << "Key length is not in range of 16 to 32 bytes." << std::endl;
		return false;
	}	
}

bool AccManager::checkForCorrectPassword(string mpassword) 
{
	
	if (mpassword.empty())// I coulndt come up with what else to check
	{
		return false;
	}
	return true;
}

bool AccManager::checkForCorrectLogin(string mlogin) 
{
	if (mlogin.empty())// I coulndt come up with what else to check
	{
		return false;
	}
	return true;
}

void AccManager::printInfo(string val,string valname) const
{
	std::cout << "Your " << valname << " is " << val<< std::endl;
}
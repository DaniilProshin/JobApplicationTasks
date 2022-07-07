#pragma once
#include "AccManager.h"

#include "cryptlib.h"
#include "rijndael.h"
#include "modes.h"
#include "files.h"
#include "osrng.h"
#include "hex.h"

using namespace CryptoPP;

class AccEncrypter :  AccManager
{
private:
	SecByteBlock key;
	SecByteBlock iv;
	
	string encryptedLogin;	// I decided to store ecnrypted and decrypted versions of login and password because it would be more simple for such small project
	string encryptedPassword;
	
	string decryptedLogin;
	string decryptedPassword;

public:
	AccEncrypter(string mlogin, string mpassword, unsigned int mkey_length) : AccManager(mlogin, mpassword, mkey_length) {}


	void initializeKeyAndIv(); // I did this method as part of interface because user could want to modify key_length before starting an encryption

	bool encryptLoginAndPassword();
	bool decryptLoginAndPassword();

	bool accordanceCheck() const;//  encryption/decryption validity test

	//~AccEncrypter(); // same as parent class
};


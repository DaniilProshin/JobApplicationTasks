#include "AccEncrypter.h"

void AccEncrypter::initializeKeyAndIv()
{
    key =  SecByteBlock(key_length);
    iv = SecByteBlock(AES::BLOCKSIZE);
}


bool AccEncrypter::encryptLoginAndPassword() // I didnt really wanted to invoke method two times for login and password independently cause i have really narrow task
{                                            // but if you wish i can do it properly
    AutoSeededRandomPool prng;
    HexEncoder encoder(new FileSink(std::cout));
    
    prng.GenerateBlock(key, key.size());
    prng.GenerateBlock(iv, iv.size());

    try
    {
        CBC_Mode< AES >::Encryption e;
        e.SetKeyWithIV(key, key.size(), iv);

        StringSource s(login, true, new StreamTransformationFilter(e, new StringSink(encryptedLogin))); 
    }
    catch (const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
    
    std::cout << "Encrypted login: ";
    encoder.Put((const byte*)&encryptedLogin[0], encryptedLogin.size());
    encoder.MessageEnd();
    std::cout << std::endl;

    try
    {
        CBC_Mode< AES >::Encryption e;
        e.SetKeyWithIV(key, key.size(), iv);

        StringSource s(password, true, new StreamTransformationFilter(e, new StringSink(encryptedPassword))); 
    }
    catch (const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
    std::cout << "Encrypted password: ";
    encoder.Put((const byte*)&encryptedPassword[0], encryptedPassword.size());
    encoder.MessageEnd();
    std::cout << std::endl;

    return 1;
}

bool AccEncrypter::decryptLoginAndPassword()
{
    try
    {
        CBC_Mode< AES >::Decryption d;
        d.SetKeyWithIV(key, key.size(), iv);

        StringSource s(encryptedLogin, true, new StreamTransformationFilter(d, new StringSink(decryptedLogin))); 

        std::cout << "Decrypted Login: " << decryptedLogin << std::endl;
    }
    catch (const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    try
    {
        CBC_Mode< AES >::Decryption d;
        d.SetKeyWithIV(key, key.size(), iv);

        StringSource s(encryptedPassword, true, new StreamTransformationFilter(d, new StringSink(decryptedPassword))); 

        std::cout << "Decrypted Password: " << decryptedPassword << std::endl;
    }
    catch (const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    return 1;
}

bool AccEncrypter::accordanceCheck() const
{
    if (login == decryptedLogin && password == decryptedPassword)
        std::cout << "Decrypted login and password are equivalent to original one" << std::endl;
    else
    {
        std::cout << "Decrypted login and password are different to original one" << std::endl;
        return false;
    }
    return true;
}
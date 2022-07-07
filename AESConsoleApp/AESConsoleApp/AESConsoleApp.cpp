////Написать программу, дающую возможность шифровать и расшифровать введенный пользователем логин и пароль алгоритмом AES.
//Длина ключа задается пользователем.Сам ключ генерируется автоматически.
////Программа должна состоять из 3 модулей:
//1) Основной модуль
//2) Модуль хранящий класс с паролями, уведомляющий пользователя о внесённых данных
//3) Модуль с классом, обеспечивающий работу шифрования.Он наследуется от класса, указанного выше.
//Реализовать проверку на корректность ввода, а также на то, что после проведенного шифрования и последующей расшифровке логин и пароль пользователя
//остался верным

#include <iostream>
#include <string>


#include"AccEncrypter.h"


// using Crypto++ library for AES algo

//user input: login, password, key length
//program output: correctness of input, input, encrypted input and ecnrypted result match

int main(int argc, char* argv[])
{
	string login;
	string password;
	unsigned int keylength;

	std::cout << "Enter your login: " << std::endl;
	std::cin >> login;;
	std::cout << "Enter your password:" << std::endl;
	std::cin >> password;
	std::cout << "Enter desirable key length:" << std::endl;
	std::cin >> keylength;

	AccEncrypter Enc(login,password,keylength);

	Enc.initializeKeyAndIv(); 

	
	Enc.encryptLoginAndPassword();
	
	Enc.decryptLoginAndPassword();
	
	Enc.accordanceCheck();

}
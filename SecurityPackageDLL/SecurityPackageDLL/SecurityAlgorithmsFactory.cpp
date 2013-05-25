#include "SecurityAlgorithmsFactory.h"
#include "AES.h"
#include "DES.h"
#include "AutoKey.h"
#include "Ceaser_Cipher.h"
#include "Columnar.h"
#include "Hill_Cipher.h"
#include "Ceaser_Cipher.h"
#include "Monoalphabetic_Cipher.h"
#include "Playfair_Cipher.h"
#include "Polyalphabetic.h"
#include "RailFence.h"
#include "RC4.h"
#include "Repeatingkey.h"

SecurityAlgorithmsFactory* SecurityAlgorithmsFactory::instance;

SecurityAlgorithmsFactory::SecurityAlgorithmsFactory(void)
{
}

SecurityAlgorithmsFactory::~SecurityAlgorithmsFactory(void)
{
}
Security_Package* SecurityAlgorithmsFactory::CreateAlgorithm(string p_AlgoName)
{
	if(p_AlgoName == "AES")
		return new AES();
	else if(p_AlgoName == "DES")
		return new DES();
	else if(p_AlgoName == "AutoKey")
		return new AutoKey();
	else if(p_AlgoName == "HiLL_Cipher")
		return new Hill_Cipher();
	else if(p_AlgoName == "RailFence")
		return new RailFence();
	else if(p_AlgoName == "Playfair_Cipher")
		return new Playfair_Cipher;
	else if(p_AlgoName == "Monoalphabetic_Cipher")
		return new Monoalphabetic_Cipher();
	else if(p_AlgoName == "Repeatingkey")
		return new RepeatingKey();
	else if(p_AlgoName == "Columnar")
		return new Columnar();
	else if(p_AlgoName == "Ceaser_Cipher")
		return new Ceaser_Cipher();
	else if(p_AlgoName == "RC4")
		return new RC4();


}

SecurityAlgorithmsFactory* SecurityAlgorithmsFactory::getInstance()
{
	if(instance == NULL)
		instance = new SecurityAlgorithmsFactory();
	return instance;
}

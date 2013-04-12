#ifndef PLAYFAIR_CIPHER_H
#define PLAYFAIR_CIPHER_H

#include"Security_Package.h"
#include <string>
#include <hash_map>
#include "IUtilities.h"

class Playfair_Cipher: public Security_Package, public IUtilities
{
private:
	char m_keyTable[5][5];
	const string Get_Corresponding(string &);// 2 chars per turn;
	const void UtilizeText(string &); //utilize the input text 

public:	
	Playfair_Cipher();
	Playfair_Cipher(string &);
	void Print_KeyTable();
	void Set_KeyTable(string &);
	const string Cipher(string&, string&);
	const string Cipher(string&, int&);

};
#endif //PLAYFAIR_CIPHER_H
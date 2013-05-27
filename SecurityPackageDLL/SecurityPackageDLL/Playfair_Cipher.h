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
	const string Get_Corresponding_For_Decipher(string &);// 2 chars per turn;
	virtual const void UtilizeText(string &); //utilize the input text 
	virtual int** UtilizeText(string&,int&);

public:	
	Playfair_Cipher();
	Playfair_Cipher(string &);
	void Print_KeyTable();
	void Set_KeyTable(string &);
	virtual const string Cipher(string&, string&);
	virtual const string Cipher(string&, int&);
	virtual const string Cipher(string&, int&, int **);
	virtual const string Decipher(string&, string&);
	virtual const string Decipher(string&, int&);
	virtual const string Decipher(string&, int&, int **);

};
#endif //PLAYFAIR_CIPHER_H
#ifndef MONOALPHABETIC_CIPHER_H
#define MONOALPHABETIC_CIPHER_H

#include <string>
#include <hash_map>

#include "Security_Package.h"
#include "IUtilities.h"

using namespace std;
class Monoalphabetic_Cipher: public Security_Package, public IUtilities
{
public:
	Monoalphabetic_Cipher()
	{
		Init_Alpha();
	}

	/*override the virtual functions*/
	virtual const string Cipher(string&, int&){return "";}
	virtual const string Cipher(string&, string&);
	

private:
	//members
	hash_map <char, char > m_alpha;

	//methods 
	void Init_Alpha();
	virtual const void UtilizeText(string&);
};


#endif //MONOALPHABETIC_CIPHER_H
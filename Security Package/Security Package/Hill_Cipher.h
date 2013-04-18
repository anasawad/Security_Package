#ifndef HILL_CIPHER_H_
#define HILL_CIPHER_H_

#include <string>
#include <hash_map>
#include "IUtilities.h"
#include "Security.h"
class Hill_Cipher:public Security_Package, public IUtilities
{
public:
	Hill_Cipher();
	/*override the virtual functions*/
	virtual const string Cipher(string&,int&);
	virtual const string Cipher(string&,string&);
	virtual const string Cipher(string&,int&, int**);

private:
	//members
	hash_map <char, int> m_alpha;

	//methods
	void Init_Alpha();
	const void UtilizeText(string &);
};

#endif//HILL_CIPHER_H_
#ifndef CEASER_CIHPER_H_
#define CEASER_CIHPER_H_

#include <string>
#include <hash_map>
#include "IUtilities.h"
using namespace std;

class Ceaser_Cipher:public Security_Package, public IUtilities
{
public:
	Ceaser_Cipher();

	/*override the virtual functions*/
	virtual const string Cipher(string&, int&);
	virtual const string Cipher(string&, string&);
	virtual const string Cipher(string&, int&, int **);
	virtual const string Decipher(string&, string&);
	virtual const string Decipher(string&, int&);
	virtual const string Decipher(string&, int&, int **);

private:

	//members
	hash_map <char, int > m_alpha;

	//methods
	void Init_Alpha();
	virtual const void UtilizeText(string&);
	virtual int** UtilizeText(string&,int&);
};


#endif //CEASER_CIHPER_H_
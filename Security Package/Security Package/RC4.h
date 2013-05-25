#ifndef RC4_H_
#define RC4_H_


#include "Security_Package.h"
#include "IUtilities.h"

class RC4 : public Security_Package, public IUtilities
{

private:
	int m_state[256];

public:
	RC4(void);
	void Initialize();
	void KSA(string& key);/*key-scheduling algorithm*/
	virtual const string Cipher(std::string&, int&);
	virtual const string Cipher(std::string&, std::string&);
	virtual const string Cipher(std::string&, int&, int **);
	virtual const string Decipher(string &in, string& key);
	virtual const void UtilizeText(string&);
	virtual int** UtilizeText(string&,int&);

};

#endif
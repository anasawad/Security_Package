#ifndef TDES_H_
#define TDES_H_

#include "DES.h"
#include "Security_Package.h"
class TDES : public Security_Package
{
private:
	DES* des;
public:
	TDES(void);
	~TDES(void);
	
//Override Virtual Functions
	virtual const string Cipher(string&, int&);
	virtual const string Cipher(string&, string&);
	virtual const string Cipher(string&, int&, int **);
	virtual const string Decipher(string&, string&);
	virtual const string Decipher(string&, int&);
	virtual const string Decipher(string&, int&, int **);
};

#endif
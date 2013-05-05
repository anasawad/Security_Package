#ifndef RAILFENCE_H_
#define RAILFENCE_H_

#include "Security_Package.h"
#include "IUtilities.h"
class Railfence:public Security_Package, public IUtilities
{
public:
	Railfence();
	~Railfence();

	//Override virtual functions
	virtual const string Cipher(string&, string&);
	virtual const string Cipher(string&, int&);
	virtual const string Cipher(string&, int&, int **);

private:
	//members

	//methods
};
#endif //RAILFENCE_H_
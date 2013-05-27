#ifndef RAILFENCE_H_
#define RAILFENCE_H_

#include "Security_Package.h"
#include "IUtilities.h"
#include <vector>
class RailFence:public Security_Package, public IUtilities
{
public:
	RailFence();
	~RailFence();

	//Override virtual functions
	virtual const string Cipher(string&, string&);
	virtual const string Cipher(string&, int&);
	virtual const string Cipher(string&, int&, int **);
	virtual const string Decipher(string&, string&);
	virtual const string Decipher(string&, int&);
	virtual const string Decipher(string&, int&, int **);
private:
	//members
	vector <vector <char> > m_textMat;

	//methods
	virtual const void UtilizeText(string&);
	virtual int** UtilizeText(string&,int&);
};
#endif //RAILFENCE_H_
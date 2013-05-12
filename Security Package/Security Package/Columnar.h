#ifndef COLUMNER_H_
#define COLUMNER_H_

#include "Security_Package.h"
#include "IUtilities.h"

class Columner: public Security_Package, public IUtilities
{
public:
	Columner();
	~Columner();
	//Override virtual functions
	virtual const string Cipher(string&, string&);
	virtual const string Cipher(string&, int&);
	virtual const string Cipher(string&, int&, int **);
	virtual const string Decipher(string&, string&);

private:
	//members
	vector <vector <char> > m_textMat;

	//methods
	virtual const void UtilizeText(string&);
	virtual int** UtilizeText(string&,int&);
};
#endif //COLUMNER_H_
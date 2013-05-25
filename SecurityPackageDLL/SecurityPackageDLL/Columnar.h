#ifndef Columnar_H_
#define Columnar_H_

#include "Security_Package.h"
#include "IUtilities.h"

class Columnar: public Security_Package, public IUtilities
{
public:
	Columnar();
	~Columnar();
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
#endif //Columnar_H_
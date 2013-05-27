#ifndef REPEATINGKEY_H_
#define REPEATINGKEY_H_

#include "Polyalphabetic.h"
#include "IUtilities.h"

class RepeatingKey:public Polyalphabetic, public IUtilities
{
public:
	RepeatingKey();
	~RepeatingKey();

	//Override virtual functions
	virtual const string Cipher(string&, string&);
	virtual const string Cipher(string&, int&);
	virtual const string Cipher(string&, int&, int **);
	virtual const string Decipher(string&, string&);
	virtual const string Decipher(string&, int&);
	virtual const string Decipher(string&, int&, int **);

private:
	//members

	//methods
	int MapChar(char);
	string UtilizeKey(string&,string&);
	virtual const void UtilizeText(string&);
	virtual int** UtilizeText(string&,int&);
};
#endif //REPEATINGKEY_H_
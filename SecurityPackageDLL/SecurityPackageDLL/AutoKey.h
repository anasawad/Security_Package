#ifndef AUTOKEY_H_
#define AUTOKEY_H_

#include "Polyalphabetic.h"
#include "IUtilities.h"
#include <vector>
#include <string>

class AutoKey: public Polyalphabetic, public IUtilities
{
public:	
	AutoKey();
	~AutoKey();

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
#endif //AUTOKEY_H_
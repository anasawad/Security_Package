#ifndef AUTOKEY_H_
#define AUTOKEY_H_

#include "Security_Package.h"
#include "IUtilities.h"
#include <vector>
#include <string>

class AutoKey: public Security_Package, public IUtilities
{
public:	
	AutoKey();
	~AutoKey();

	//Override virtual functions 
	virtual const string Cipher(string&, string&);
	virtual const string Cipher(string&, int&);
	virtual const string Cipher(string&, int&, int **);

private:
	//members
	char m_table[26][26];
	vector <char> m_alpha;

	//methods
	void InitTable();
	void InitAlpha();
	int MapChar(char);
	string UtilizeKey(string&,string&);
	virtual const void UtilizeText(string&);
	virtual int** UtilizeText(string&,int&);

};
#endif //AUTOKEY_H_
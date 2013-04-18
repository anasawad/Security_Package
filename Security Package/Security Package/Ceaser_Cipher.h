#ifndef CEASER_CIHPER_H_
#define CEASER_CIHPER_H_

#include <string>
#include <hash_map>
#include "IUtilities.h"
using namespace std;

class Ceaser_Chiper:public Security_Package, public IUtilities
{
public:
	Ceaser_Chiper();

	/*override the virtual functions*/
	virtual const string Cipher(string&, int&);
	virtual const string Cipher(string&, string&);
	virtual const string Cipher(string&, int&, int **);

private:

	//members
	hash_map <char, int > m_alpha;

	//methods
	void Init_Alpha();
	const void UtilizeText(string&);
};


#endif //CEASER_CIHPER_H_
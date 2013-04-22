#ifndef HILL_CIPHER_H_
#define HILL_CIPHER_H_

#include <string>
#include <hash_map>
#include "IUtilities.h"
#include "Security_Package.h"
class Hill_Cipher:public Security_Package, public IUtilities
{
public:
	Hill_Cipher();
	
	~Hill_Cipher();
	/*override the virtual functions*/
	virtual const string Cipher(string&,int&);
	virtual const string Cipher(string&,string&);
	virtual const string Cipher(string&,int&, int**);

private:
	//members
	hash_map <char, int> m_alpha;
	int**				 m_text; // text matrix
	int**				 m_key;
	int					 m_matSize;

	//methods
	void Init_Alpha();
	void m_alloc(int**, int&);
	void free_mem(int**, int&);
	virtual const void UtilizeText(string&);
	virtual int** UtilizeText(string&, int&);

	const int* VectorMul(int*, int**, int&);
};

#endif//HILL_CIPHER_H_
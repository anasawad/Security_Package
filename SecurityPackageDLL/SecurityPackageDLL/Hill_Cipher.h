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
	virtual const string Decipher(string&, string&);
	virtual const string Decipher(string&, int&);
	virtual const string Decipher(string&,int&, int**);
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

	bool Check_Nonnegative_Key(int **key , int&size);
	int gcd(int a,int b);
	bool Check_GCD_Key_Element(int**, int&);
	int Get_Determinant(int**, int);
	int Get_b(int **key, int &size);
	int** Get_Minor(int** key , int &row, int &col , int &size) ;
	int mode(int &a , int &b);
	int** Calculate_key_Inverse(int**,int&,int&);
	int calculate_factor(int &i , int &j);
	int** Get_Matrix_Transpose(int** key , int &size);
};

#endif//HILL_CIPHER_H_
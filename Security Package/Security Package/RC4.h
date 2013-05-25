#ifndef RC4_H_
#define RC4_H_


#include "Security_Package.h"
#include "IUtilities.h"

class RC4 : public Security_Package, public IUtilities
{

private:
<<<<<<< HEAD
	int m_state[256];

public:
	RC4(void);
	void Initialize();
	void KSA(string& key);/*key-scheduling algorithm*/
	virtual const string Cipher(std::string&, int&);
	virtual const string Cipher(std::string&, std::string&);
	virtual const string Cipher(std::string&, int&, int **);
	virtual const string Decipher(string &in, string& key)=0;
=======
	int State[256];
	string PRGA(int inputSize);/*pseudo-random number generation*/
	void KSA(string& key);/*key-scheduling algorithm*/
	void initialize();

public:
	RC4(void);
	
	virtual const string Cipher(std::string&, int&);
	virtual const string Cipher(std::string&, std::string&);
	virtual const string Cipher(std::string&, int&, int **);
	
	const string  DeCipher(string &in, string& key);
	
>>>>>>> RC4 Decipher completed
	virtual const void UtilizeText(string&);
	virtual int** UtilizeText(string&,int&);

};

#endif
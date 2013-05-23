#ifndef DES_H_
#define DES_H_

#include "Security_Package.h"
#include "IUtilities.h"

class DES: public Security_Package, public IUtilities
{
public:
	//Override Virtual Functions
	virtual const string Cipher(string&, int&);
	virtual const string Cipher(string&, string&);
	virtual const string Cipher(string&, int&, int **);
	virtual const string Decipher(string&, string&);
	
private:
	//members
	static int m_key[64],
		m_sBox1[4][16],
		m_sBox2[4][16],
		m_sBox3[4][16],
		m_sBox4[4][16],
		m_sBox5[4][16],
		m_sBox6[4][16],
		m_sBox7[4][16],
		m_sBox8[4][16];
	int m_keyRound[16][48],
		m_textBinaryFormat[64],
		m_textLeft[32],
		m_textRight[32],
		m_expansionTable[48],
		m_xorSubKey[48],
		m_xorLeftRight[32],
		m_permChoice2[48],
		m_permChoice1[56],
		m_initialPerm[64],
		m_substitutionTable[32],
		m_reverse[8][8],
		m_swapText[64],
		m_permTable[32],
		m_z[48],
		m_Ckey[28],
		m_Dkey[28];
	char m_finalText[1000];


	//methods
	void Initial_Permutation();
	void Permutation_Choice1();
	void Permutation_Choice2();
	void Expansion();
	void Reverse();
	//Performing XOR operation on left[32],p[32] to get xor2[32]
	void Xor_LeftRight();
	void Xor_Encrypt(int);
	void Xor_Decrypt(int);
	void Substitution();
	void Permutation();
	void Keygen();
	string Encrypt(string&);
	string Decrypt(string&);
	int* CharToBinary(char c);


	//Override Virtual Functions
	virtual const void UtilizeText(string&);
	virtual int** UtilizeText(string&,int&);
};
#endif //DES_H_
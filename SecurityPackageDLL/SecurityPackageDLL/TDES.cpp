#include "TDES.h"


TDES::TDES(void)
{
	des = new DES();
}


TDES::~TDES(void)
{
	delete des;
}

//Override virtual functions 

const string TDES::Cipher(string& text, string& notused)
{
	string s1 = des->Cipher(text,notused);
	string s2 =  des->Decipher(s1,notused);
	return  des->Cipher(s2,notused);
}
const string TDES::Decipher(string& text, string& notused)
{
	string s1 =  des->Decipher(text,notused);
	string s2 = des->Cipher(s1,notused);
	return  des->Decipher(s2,notused);
}
const string TDES::Decipher(string&, int&) {return "";}
const string TDES::Decipher(string&, int&, int **){return "";}
const string TDES::Cipher(string&, int&, int **){return "";}
const string TDES::Cipher(string&, int&){return "";}

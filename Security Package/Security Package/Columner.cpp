#include "Columnar.h"

Columner::Columner()
{

}
Columner::~Columner()
{

}


//Override Virtual Functions
const string Columner::Cipher(string &text, int &key)
{return "";}

const string Columner::Cipher(string &text, string &key)
{
	UtilizeText(text);
	string cipherText;
	int len = text.length();
	int dim;
	int value = atoi(key.c_str());
	if(len % key.length() ==0)
		dim = len/key.length();
	else
	{
		dim = (len/key.length() +1);
		text+= "x";
	}
	m_textMat.resize(dim);
	int count =0;
	for (int i =0; i < dim; i++)
	{
		m_textMat[i].resize(key.length());
		for (int j =0; j < key.length(); j++)
		{
			m_textMat[i][j]= text[count];
			count ++;
		}
	}
	int temp = value;
	while (temp != 0)
	{
		value = temp%10;
		temp /= 10;

		for (int i = dim-1; i >= 0; i--)
		{
			cipherText += m_textMat[i][value-1];
		}
	}
	reverse(cipherText.begin(),cipherText.end());
	return cipherText;
}
const string Columner::Cipher(string &, int&, int **){return "";}
const string Columner::Decipher(string&, string&){return "";}
//private Functions
const void Columner::UtilizeText(string &text)
{
	int j=0;
	string temp;
	for (int i=0; i < text.size(); i++)
	{
		if (text[i] == ' ')continue;
		temp+= tolower(text[i]);
	}
	text = temp;
}
int** Columner::UtilizeText(string &text,int &key)
{
	return NULL;
}

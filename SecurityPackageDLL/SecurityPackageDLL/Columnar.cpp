#include "Columnar.h"

Columnar::Columnar()
{
}
Columnar::~Columnar()
{
}


//Override Virtual Functions
const string Columnar::Cipher(string &text, int &key)
{return "";}

const string Columnar::Cipher(string &text, string &key)
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
const string Columnar::Cipher(string &, int&, int **){return "";}
const string Columnar::Decipher(string &text, string &key)
{
	UtilizeText(text);
	string cipherText;
	int len = text.length() / key.length();
	int value = atoi(key.c_str());
	m_textMat.resize(len);
	for(int i = 0 ; i < len ; i++)
	{
		m_textMat[i].resize(key.length());
	}
	int count =0;
	char num = '1';
	int ind ;
	for (int j =0; j < key.length(); j++)
	{
		ind = key.find(num);
		for (int i =0; i < len; i++)
		{
			m_textMat[i][ind]= text[count];
			count ++;
		}
		num++;
	}
	for (int i =0; i < len; i++)
		for (int j =0; j < key.length(); j++)
			cipherText+=m_textMat[i][j];
	return cipherText;
}
const string Columnar::Decipher(string&, int&){return "";}
const string Columnar::Decipher(string&, int&, int **){return "";}
//private Functions
const void Columnar::UtilizeText(string &text)
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
int** Columnar::UtilizeText(string &text,int &key)
{
	return NULL;
}

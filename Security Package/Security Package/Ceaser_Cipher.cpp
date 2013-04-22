#include"Security_Package.h"
#include "Ceaser_Cipher.h"

Ceaser_Chiper::Ceaser_Chiper()
{
	Init_Alpha();
}
void Ceaser_Chiper::Init_Alpha()
{
	m_alpha['a']=0;
	m_alpha['b']=1;
	m_alpha['c']=2;
	m_alpha['d']=3;
	m_alpha['e']=4;
	m_alpha['f']=5;
	m_alpha['g']=6;
	m_alpha['h']=7;
	m_alpha['i']=8;
	m_alpha['j']=9;
	m_alpha['k']=10;
	m_alpha['l']=11;
	m_alpha['m']=12;
	m_alpha['n']=13;
	m_alpha['o']=14;
	m_alpha['p']=15;
	m_alpha['q']=16;
	m_alpha['r']=17;
	m_alpha['s']=18;
	m_alpha['t']=19;
	m_alpha['u']=20;
	m_alpha['v']=21;
	m_alpha['w']=22;
	m_alpha['x']=23;
	m_alpha['y']=24;
	m_alpha['z']=25;
}

const string Ceaser_Chiper::Cipher(string &text, int &key)
{
	int cipherIdx;
	string cipher_txt;
	for (int i = 0; i < text.length(); i++)
	{
		cipherIdx   = this->m_alpha[text[i]];
		for (hash_map<char, int>::iterator it = m_alpha.begin(); it != m_alpha.end();it++)
		{
			if((*it).second == ((key+cipherIdx)%26))
			{cipher_txt += (*it).first;break;}
		}
		//cipher_txt += this->m_alpha[cipherIdx+key].second;
	}
	return cipher_txt;
}

const void Ceaser_Chiper::UtilizeText(string &text)
{
	string temp;
	for (int i = 0; i < text.length(); i++)
	{
		if(text[i] == ' ')
			continue;
		temp += tolower(text[i]);
	}
	text = temp;
}

const string Ceaser_Chiper::Cipher(string&,string&){return "";}
const string Ceaser_Chiper::Cipher(string&,int&,int**){return "";}
int** Ceaser_Chiper::UtilizeText(string&,int&){return NULL;}
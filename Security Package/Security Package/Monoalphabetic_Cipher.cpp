#include "Monoalphabetic_Cipher.h"

Monoalphabetic_Cipher::Monoalphabetic_Cipher()
{
	Init_Alpha();
}

void Monoalphabetic_Cipher::Init_Alpha()
{
	m_alpha['a']='d';
	m_alpha['b']='q';
	m_alpha['c']='e';
	m_alpha['d']='p';
	m_alpha['e']='r';
	m_alpha['f']='s';
	m_alpha['g']='f';
	m_alpha['h']='t';
	m_alpha['i']='a';
	m_alpha['j']='w';
	m_alpha['k']='x';
	m_alpha['l']='u';
	m_alpha['m']='g';
	m_alpha['n']='o';
	m_alpha['o']='b';
	m_alpha['p']='v';
	m_alpha['q']='h';
	m_alpha['r']='n';
	m_alpha['s']='c';
	m_alpha['t']='m';
	m_alpha['u']='i';
	m_alpha['v']='z';
	m_alpha['w']='l';
	m_alpha['x']='y';
	m_alpha['y']='j';
	m_alpha['z']='k';
}

const string Monoalphabetic_Cipher::Cipher(string &text, string &key)
{
	UtilizeText(text);
	string cipher_txt;
	for (int i = 0; i < text.length(); i++)
	{
		hash_map<char, char>::iterator it = m_alpha.find(text[i]);
		cipher_txt += (*it).second;
	}
	return cipher_txt;
}



const string Monoalphabetic_Cipher::Cipher(string&,int&){return "";}
const string Monoalphabetic_Cipher::Cipher(string&,int&,int**){return "";}


const void Monoalphabetic_Cipher::UtilizeText(string& txt)
{
	string temp;
	for (int i = 0; i < txt.length(); i++)
	{
		if(txt[i] == ' ')
			continue;
		temp += tolower(txt[i]);
	}
	txt = temp;
}
int** Monoalphabetic_Cipher::UtilizeText(string&,int&) {return NULL;}
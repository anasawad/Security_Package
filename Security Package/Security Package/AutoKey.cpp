#include "AutoKey.h"
using namespace std;

AutoKey::AutoKey()
{
	InitAlpha();
	InitTable();
}
AutoKey::~AutoKey()
{

}


//Override Methods
const string AutoKey::Cipher(string &text, string &key)
{
	int idx1,idx2;
	UtilizeText(text);
	string utilizedKey = UtilizeKey(text, key);
	string ciphterText;
	for (int i = 0; i < text.length(); i++)
	{
		idx1 = MapChar(text[i]);
		idx2 = MapChar(utilizedKey[i]);
		ciphterText += m_table[idx1][idx2];

	}
	return ciphterText;
}
const string AutoKey::Cipher(string&, int&){return "";}
const string AutoKey::Cipher(string&, int&, int **){return "";}

//Private methods
const void AutoKey::UtilizeText(string& text)
{
	int j=0;
	string temp;
	for (int i=0; i < text.size(); i++)
	{
		if (text[i] == ' ')continue;
		temp+= tolower(text[i]);
		if(temp[temp.size()-1] == 'j')
			temp[temp.size()-1]  = 'i';
	}
	text = temp;
}
int **AutoKey::UtilizeText(string&,int&){return NULL;}
void AutoKey::InitAlpha()
{
	m_alpha.resize(26);
	for(int i = 0; i < 26; i++)
	{
		m_alpha[i] = i + 'a';
	}
}
void AutoKey::InitTable()
{
	for(char i= 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			m_table[i][j] = m_alpha[j];
		}
		rotate(m_alpha.begin(),m_alpha.begin()+1,m_alpha.end());
	}
}
string AutoKey::UtilizeKey(string &text, string &key)
{
	int len = text.length()-key.length();
	string temp = key;
	for(int i =0 ; i < len; i++)
	{
		temp += text[i];
	}
	return temp;
}
int AutoKey::MapChar(char c)
{
	return c-97;
}

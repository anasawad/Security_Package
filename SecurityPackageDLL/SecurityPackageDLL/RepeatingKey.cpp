#include "Repeatingkey.h"
using namespace std;

RepeatingKey::RepeatingKey()
{
	Polyalphabetic::InitTable();
	Polyalphabetic::InitAlpha();
}
RepeatingKey::~RepeatingKey()
{
}

//Override Methods
const string RepeatingKey::Cipher(string &text, string &key)
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
const string RepeatingKey::Cipher(string&, int&){return "";}
const string RepeatingKey::Cipher(string&, int&, int **){return "";}
const string RepeatingKey::Decipher(string&, string&){return "";}
//Private methods
const void RepeatingKey::UtilizeText(string& text)
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
int **RepeatingKey::UtilizeText(string&,int&){return NULL;}

string RepeatingKey::UtilizeKey(string &text, string &key)
{
	int len = text.length()-key.length();
	string temp = key;
	for(int i =0 ; i < len; i++)
	{
		temp += key[i];
	}
	return temp;
}
int RepeatingKey::MapChar(char c)
{
	return c-97;
}

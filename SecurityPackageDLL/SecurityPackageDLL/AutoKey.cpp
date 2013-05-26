#include "AutoKey.h"
using namespace std;

AutoKey::AutoKey()

{
	Polyalphabetic::InitTable();
	Polyalphabetic::InitAlpha();
	/*InitAlpha();
	InitTable();*/
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
const string AutoKey::Decipher(string&, string&){return "";}

//Private methods
const void AutoKey::UtilizeText(string& text)
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
int **AutoKey::UtilizeText(string&,int&){return NULL;}
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

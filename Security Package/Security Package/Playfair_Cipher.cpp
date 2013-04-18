#include "Playfair_Cipher.h"
#include <map>
#include <stdio.h>

Playfair_Cipher::Playfair_Cipher()
{
}

Playfair_Cipher::Playfair_Cipher(string &key)
{
	Set_KeyTable(key);
}

void Playfair_Cipher::Set_KeyTable(string &key)
{
	string alpha =  "abcdefghiklmnopqrstuvwxyz";
	map<char,bool> keyTable;
	UtilizeText(key);
	int i=0,j;
	for ( j = 0; j < key.size(); j++)
	{
		if(isalpha(key[j]) && !keyTable[key[j]])
		{
			m_keyTable[i/5][i%5] = key[j];
			keyTable[key[j]] = true;
			++i;
		}
	}

	for (j = 0; j < alpha.size(); j++)
	{
		if(!keyTable[alpha[j]])
		{
			m_keyTable[i/5][i%5] = alpha[j];
			keyTable[alpha[j]]  = true;
			++i;
		}
	}
}

const void Playfair_Cipher::UtilizeText(string &text)
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

const string Playfair_Cipher::Cipher(string &text, string &key)
{
	string temp = "  ";
	string out  = "";
	bool isEqual  = 0 ;
	out.resize(text.size()*2);

	Set_KeyTable(key);
	UtilizeText(text);
	//keytable is not initialized
	if(!isalpha(m_keyTable[0][0]))
		Set_KeyTable(key);

	for (int i=0; i < text.size(); i+=2)
	{
		temp[0] = text[i];
		if(i == text.size()-1)
			temp[1] = 'x';
		else
			temp[1] = text[i+1];
		if (temp[0] == temp[1])
		{
			temp[1] = 'x';
			i--;
			isEqual = !isEqual;
		}
		temp = Get_Corresponding(temp);
		out[i+isEqual] = temp[0];
		out[i+1+isEqual] = temp[1];
	}
	return out;
}

void Playfair_Cipher::Print_KeyTable()
{
	int i,j;
	for (i=0; i<5; i++)
	{
		for (j=0; j<5; j++)
		{
			printf("%d ", m_keyTable[i][j]);
		}
		printf("\n");
	}
}

const string Playfair_Cipher::Get_Corresponding(string &text)
{
	pair<int, int> _1st, _2nd;

	string out = "  ";
	bool done = false;

	//getting corresponding indexes of the 2 characters
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(text[0] == m_keyTable[i][j])
			{
				_1st.first = i;
				_1st.second = j;
			}
			else if(text[1] == m_keyTable[i][j])
			{
				_2nd.first = i;
				_2nd.second = j;
			}
		}
	}

	if(_1st.second == _2nd.second) // same column
	{
		out[0] = m_keyTable[(_1st.first+1)%5 ][_1st.second];
		out[1] = m_keyTable[(_2nd.first+1)%5 ][_2nd.second] ;
	}
	else if(_1st.first == _2nd.first) // same row
	{
		out[0] = m_keyTable[_1st.first][ (_1st.second+1) % 5 ];
		out[1] = m_keyTable[_2nd.first][ (_2nd.second+1)%5 ] ;
	}
	else //normal
	{
		out[0] = m_keyTable[_1st.first][_2nd.second];
		out[1] = m_keyTable[_2nd.first][_1st.second];
	}

	return out;
}


const string Playfair_Cipher::Cipher(string&, int&){return"";}
const string Playfair_Cipher::Cipher(string&,int&, int**){return "";}
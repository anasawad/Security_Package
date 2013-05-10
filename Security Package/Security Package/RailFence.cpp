#include "RailFence.h"

RailFence::RailFence()
{

}
RailFence::~RailFence()
{

}


//Override Virtual Functions
const string RailFence::Cipher(string &text, int &key)
{
	UtilizeText(text);
	string cipherText;
	int len = text.length();
	int dim;
	if(len % key ==0)
		dim = len/key;
	else
	{
		dim = (len/key +1);
		text+= "!";
	}
	int count =0;
	m_textMat.resize(key);

	for (int i =0 ; i < dim; i++)
	{
		for (int j =0; j < key; j++)
		{
			m_textMat[j].resize(dim);
			if (isalpha(text[count]))
			{
				m_textMat[j][i]= text[count];
				count++;
			}
		}
	}

	for (int i =0 ; i < m_textMat.size(); i++)
	{
		for (int j =0; j < m_textMat[i].size(); j++)
		{
			cipherText += m_textMat[i][j];
		}
	}

	return cipherText;
}
const string RailFence::Cipher(string &text, string &key){return "";}
const string RailFence::Cipher(string &, int&, int **){return "";}

//private Functions
const void RailFence::UtilizeText(string &text)
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
int** RailFence::UtilizeText(string &text,int &key)
{
	return NULL;
}

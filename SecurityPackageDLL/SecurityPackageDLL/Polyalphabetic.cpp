#include "Polyalphabetic.h"

Polyalphabetic::Polyalphabetic()
{
	InitAlpha();
	InitTable();
}
Polyalphabetic::~Polyalphabetic(){}

void Polyalphabetic::InitAlpha()
{
	m_alpha.resize(TABLE_SIZE);
	for(int i = 0; i < 26; i++)
	{
		m_alpha[i] = i + 'a';
	}
}

void Polyalphabetic::InitTable()
{
	for(char i= 0; i < TABLE_SIZE; i++)
	{
		for (int j = 0; j < TABLE_SIZE; j++)
		{
			m_table[i][j] = m_alpha[j];
		}
		rotate(m_alpha.begin(),m_alpha.begin()+1,m_alpha.end());
	}
}



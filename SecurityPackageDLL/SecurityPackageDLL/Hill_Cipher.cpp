#include "hill_cipher.h"
using namespace std;

Hill_Cipher::Hill_Cipher()
{
	Init_Alpha();
}

Hill_Cipher::~Hill_Cipher()
{
	free_mem(m_key,m_matSize);
}

/*overriding functions*/
const string Hill_Cipher::Cipher(string &text, int &matrix_size, int **key)
{
	m_key  = new int*[matrix_size];
	m_alloc(m_key, m_matSize);
	m_key = key;
	string cipher_text;
	m_matSize = matrix_size;
	int len = text.size()/matrix_size;
	int *vect = new int[matrix_size];
	const int *result;
	int count = 0;

	m_text = UtilizeText(text,matrix_size);
	
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			vect[j] = m_text[j][i];
		}
		result = VectorMul(vect,m_key,matrix_size);
		count = 0;
		while(count != matrix_size)
		{
			for (hash_map<char,int>::iterator it = m_alpha.begin(); it != m_alpha.end(); it++)
			{
				if((*it).second == *(result))
				{cipher_text += (*it).first;break;}
			}
			count ++;
			++result;
		}
	}
	return cipher_text;
	
}
const string Hill_Cipher::Cipher(string&,int&)
{
	return "";
}
const string Hill_Cipher::Cipher(string&, string&)
{
	return "";
}
const string Hill_Cipher::Decipher(string&, string&){return "";}

/*Private Methods*/

const int* Hill_Cipher::VectorMul(int *vect, int** mat, int &size)
{
	int *tempArr, temp =0;
	tempArr = new int[size];
	for (int i = 0; i <size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			temp +=  (vect[j]*mat[i][j]);
		}
		tempArr[i] = temp %26;
		temp = 0;
	}
	return tempArr;
}
void Hill_Cipher::m_alloc(int **matrix, int &size)
{
	for(int i =0 ; i < size; i++)
	{
		matrix[i] = new int[size];
	}
}
void Hill_Cipher::free_mem(int** matrix, int&size)
{
	for (int i =0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete []matrix;
}
void Hill_Cipher::Init_Alpha()
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
const void Hill_Cipher::UtilizeText(string&){}
int** Hill_Cipher::UtilizeText(string& text,int& matSize)
{
	int** textMat = new int*[matSize];
	int temp = text.size() / matSize;
	m_alloc(textMat,temp);
	textMat = new int*[matSize];
	m_alloc(textMat, temp);
	int t =0;
	for(int i =0;i < temp; i++)
	{
		for (int j = 0; j < matSize; j++)
		{ 
			hash_map<char, int>::iterator it = m_alpha.find(text[t]);
			textMat[j][i] = it->second;
			t++;
		}
	}
	return textMat;
}

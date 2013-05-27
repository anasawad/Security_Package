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
const string Hill_Cipher::Decipher(string &text, int &matrix_size, int **key)
{
	string cipher_text;
	int len = text.size()/matrix_size;
	int *vect = new int[matrix_size];
	const int *result;
	int count = 0;

	bool non_negative = Check_Nonnegative_Key(key , matrix_size);
	bool gcd_check    = Check_GCD_Key_Element(key , matrix_size);
	int b             = Get_b(key , matrix_size);

	if(non_negative && gcd_check && b != -1)
	{
		int Determinant = Get_Determinant(key , matrix_size);
		int Determinant_tmp = Determinant , number =26;
		int Determinant_Mode_26 = mode(Determinant_tmp ,number);

		int** key_Inverse = Calculate_key_Inverse(key , matrix_size , b);

		m_text = UtilizeText(text,matrix_size);

		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < matrix_size; j++)
			{
				vect[j] = m_text[j][i];
			}
			result = VectorMul(vect,key_Inverse,matrix_size);
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
	else 
	{
		return "pepe";
	}
}
const string Hill_Cipher::Decipher(string&, string&){return "";}
const string Hill_Cipher::Decipher(string&, int&){return "";}

/*Private Methods*/

const int* Hill_Cipher::VectorMul(int *vect, int** mat, int &size)
{
	int *tempArr, temp =0;
	int number = 26;
	tempArr = new int[size];
	for (int i = 0; i <size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			temp +=  (vect[j]*mat[i][j]);
		}
		tempArr[i] = mode(temp ,number);
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


bool Hill_Cipher::Check_Nonnegative_Key(int **key, int &size)
{
	for( int ind_i = 0 ; ind_i < size ; ind_i++)
	{
		for(int ind_j ; ind_j < size ; ind_j++)
		{
			if(key[ind_i] <0)
				return false;
		}
	}
	return true;
}
int Hill_Cipher::gcd(int a,int b) {
	int r=1;
	if(a>b)
	{
		while ( r!=0)
		{
			r=a%b;
			a=b;
			b=r;
		}
		return a;
	}
}
bool Hill_Cipher::Check_GCD_Key_Element(int **key, int &size)
{
	int Determinant = Get_Determinant(key , size);
	for( int ind_i = 0 ; ind_i < size ; ind_i++)
	{
		for(int ind_j ; ind_j < size ; ind_j++)
		{
			if(gcd(26,Determinant) != 1)
				return false;
		}
	}
	return true;
}
int** Hill_Cipher::Get_Minor(int** key , int &row, int &col , int &size) 
{
	int** result  = new int*[size-1];
	int size_tmp = size -1;
	m_alloc(result, size_tmp);
	int x = 0 , y = 0;
	for(int i = 0 ; i< size ; i++)
	{
		if( i != row)
		{
			y =0;
			for(int j = 0 ; j< size ; j++)
			{
				if(j != col)
				{
					result[x][y] = key[i][j];
					y++;
				}
			}
			x++;
		}
	}
	return result;
}
int** Hill_Cipher:: Calculate_key_Inverse(int** key,int &size, int&b)
{
	int** result = new int* [size];
	m_alloc(result , size);
	int size_tmp = size-1 , number =26;
	int** Minor_ij;
	int temp;
	int fact,det;
	int res;
	for(int i = 0 ; i < size ; i++)
	{
		for(int j = 0 ; j < size ; j++)
		{
			Minor_ij = Get_Minor(key , i , j, size);
			det  = Get_Determinant(Minor_ij , size_tmp) ;
			fact = calculate_factor(i , j);
			res  = (b*fact*det);
			temp = mode(res, number);
			result[i][j] = mode(temp  , number);
		}
	}
	int** key_Inverse = Get_Matrix_Transpose(result , size); 
	return key_Inverse;
}
int Hill_Cipher::Get_Determinant(int **key , int size)
{
	int d = 0;       
	if (size == 1)
	{
		d = key[0][0];
	}
	else if (size == 2)
	{
		d = key[0][0] * key[1][1] - key[1][0] * key[0][1];
	}
	else
	{
		int row = 0;
		for (int c = 0; c < size; c++)
		{
			int** M = Get_Minor(key , row, c, size);
			d += (c%2 + c%2 - 1) * key[0][c] * Get_Determinant(M , size-1); 
		}
	}
	return d;
}
int Hill_Cipher::Get_b(int **key, int &size)
{
	int a,number = 26;
	int Determinant = Get_Determinant(key , size);
	for(int b = 1 ; b < 26 ; b++)
	{
		a = b*Determinant;
		if(mode( a, number) == 1)
			return b;
	}
	return -1;
}
int Hill_Cipher::mode(int &a , int &b)
{
	while( a<0 )
		a +=b;
	return a % b;
}
int Hill_Cipher::calculate_factor(int &i , int &j)
{
	if((i+j) % 2 == 0)
		return 1;
	else
		return -1;
}
int** Hill_Cipher::Get_Matrix_Transpose(int** key , int &size)
{
	int** result = new int* [size];
	m_alloc(result , size);
	for(int i = 0 ; i < size ; i++)
	{
		for(int j = 0 ; j < size ; j++)
			result[j][i] = key[i][j];
	}
	return result;
}

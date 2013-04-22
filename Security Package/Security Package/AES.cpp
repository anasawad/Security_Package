#include "AES.h"


AES::AES(void)
{
}
AES::AES(unsigned char** p_state)
{
	m_state = p_state;
}

AES::~AES(void)
{
	delete [] m_roundKeys;
	for(int index_row=0;index_row < 4 ; ++ index_row)
		delete [] m_state[index_row];
	delete m_state;
}
void AES::AddRoundkey(unsigned char** p_roundkey)
{
	if(p_roundkey)
		return ;

	for(int y=0;y<4;++ y)
		for(int x=0;x<4;++x)
			m_state[y][x] ^= p_roundkey[y][x]; // Adding key with data is equivalent to XOR
}
void AES::ShiftRows()
{
	int temp_row[3];
	for(int y=1;y<4;++ y)
	{
		/*
		Store The first y elements in the row to complete the 
		rotation process by pushing them to the back after shifting right
		the rest elements by y steps
		*/
		for(int i=0;i<y;++i)
			temp_row[i]=m_state[y][i];

		//Shifting right by y steps
		for(int x=y;x<4;++x)
			m_state[y][x-y]=m_state[y][x];

		//Pushing the temp_row elements on the back of the row to complete the shifting rows process
		int index_temp_row=0;
		for(int col_index=4-y;col_index < 4;++ col_index)
			m_state[y][col_index]=temp_row[index_temp_row ++];
	}
}
void AES::SubBytes()
{
	for(int y=0;y<4;++y)
		for(int x=0;x<4;++x)
			m_state[y][x]=S_BOX[m_state[y][x]];
}
void AES::MixColoumns()
{
	unsigned char oldState_Row_of_currentCol[4];
	for(int j=0;j<4;++j)
	{
		oldState_Row_of_currentCol[0] = m_state[0][j];
		oldState_Row_of_currentCol[1] = m_state[1][j];
		oldState_Row_of_currentCol[2] = m_state[2][j];
		oldState_Row_of_currentCol[3] = m_state[3][j];

		m_state[0][j] = PolynomialMultiplyByX(oldState_Row_of_currentCol[0],2) ^ PolynomialMultiplyByX(oldState_Row_of_currentCol[1],3) ^ oldState_Row_of_currentCol[2] ^ oldState_Row_of_currentCol[3];
		m_state[1][j] = oldState_Row_of_currentCol[0] ^ PolynomialMultiplyByX(oldState_Row_of_currentCol[1],2) ^ PolynomialMultiplyByX(oldState_Row_of_currentCol[2],3) ^ oldState_Row_of_currentCol[3];
		m_state[2][j] = oldState_Row_of_currentCol[0] ^ oldState_Row_of_currentCol[1] ^ PolynomialMultiplyByX(oldState_Row_of_currentCol[2],2) ^ PolynomialMultiplyByX(oldState_Row_of_currentCol[3],3);
		m_state[3][j] = PolynomialMultiplyByX(oldState_Row_of_currentCol[0],3) ^ oldState_Row_of_currentCol[1] ^ oldState_Row_of_currentCol[2] ^ PolynomialMultiplyByX(oldState_Row_of_currentCol[3],2);
	}
}

/*
	Polynomial Advanced Method for Multiplication
	x X f(x) = { (b6b5b4b3b2b10) if b7 =0 ,
	             (b6b5b4b3b2b10) XOR (00011011) if b7 = 1
			   }
*/
unsigned char AES::PolynomialMultiplyByX(unsigned char data,int X)
{
	return (data & 0x80 ? (data<<X)^0x1B : data<<X); 
}
const void  AES::UtilizeText(string& txt)
{

	string temp;
	for (int i = 0; i < txt.length(); i++)
	{
		if(txt[i] == ' ')
			continue;
		temp += tolower(txt[i]);
	}
	txt = temp;
	if(txt.size() < 16)
	txt.insert(0,16-txt.size(),'0');

	m_state = new unsigned char*[4];
	for(int i=0;i<4;++i)
				m_state[i]= new unsigned char[4];

	int index=0;
	for(int j=0;j<4;++j)
	{
		for(int i=0;i<4;++ i)
			m_state[i][j]=txt[index ++ ];
	}
}
int AES::RotWord(int word)
{
	int b0 = word & 0x000000FF;
	return (word>>8) | (b0 << 24);
}
int AES::SubWord(int word)
{
	int b0 = ( word & 0x000000FF );
	int b1 = ( word & 0x0000FF00 ) >> 8;
	int b2 = ( word & 0x00FF0000 ) >> 16;
	int b3 = ( word & 0xFF000000 ) >> 24;

	b0 = S_BOX[b0];
	b1 = S_BOX[b1];
	b2 = S_BOX[b2];
	b3 = S_BOX[b3];
	return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
}
void AES::StartKeyExpansion(int* p_intialRoundKey)
{
	m_roundKeys = new int[45];
	int Rcon [11];
	Rcon[1]=1;
	for(int i=2;i<11;++i)
		Rcon[i] = Rcon[i - 1] << 1; 
	
	for(int i=0;i<4;++i)
		m_roundKeys[i]=p_intialRoundKey[i];

	for(int i=4;i<45;++ i)
	{
		if(i % 4 == 0)
		{
			m_roundKeys[i] = SubWord(RotWord(m_roundKeys[i-1])) ^ Rcon[i/4];
		}
		else
		{
			m_roundKeys[i] = m_roundKeys[i - 1] ^ m_roundKeys[i - 4];  
		}
	}
}
void AES::GetRoundKey(int p_roundNUM,unsigned char** p_roundKey)
{
	int roundKey_index = p_roundNUM*4;
	int word;
	for(int index = roundKey_index,col=0;index < roundKey_index + 4 ; ++ index,++col)
	{
		word = m_roundKeys[index];
		unsigned char* byte_ptr = (unsigned char*)&word;
		p_roundKey[0][col]=byte_ptr[0];
		p_roundKey[1][col]=byte_ptr[1];
		p_roundKey[2][col]=byte_ptr[2];
		p_roundKey[3][col]=byte_ptr[3];
	}
}
const string AES::Cipher(string& ,int& ){return "";}
const string AES::Cipher(string &text, string &key)
{
	UtilizeText(text);
	unsigned char * str_key = (unsigned char *)key.c_str();
	int * key_word = (int*)str_key;
	StartKeyExpansion(key_word);

	unsigned char ** roundKey = new unsigned char*[4];
	for(int i=0;i<4;++i)
		roundKey[i]=new unsigned char[4];

	int roundNum=0;
	GetRoundKey(roundNum,roundKey);
	AddRoundkey(roundKey);
	
	while(roundNum ++ < 10 )
	{
		SubBytes();
		ShiftRows();
		MixColoumns();
		GetRoundKey(roundNum,roundKey);
		AddRoundkey(roundKey);
	}
	SubBytes();
	ShiftRows();
	GetRoundKey(roundNum,roundKey);
	AddRoundkey(roundKey);

	string cipheredText;
	for(int j=0;j<4;++j)
		for(int i=0;i<4;++i)
			cipheredText += m_state[i][j];
	
	for(int index_row=0;index_row < 4 ; ++ index_row)
		delete [] roundKey[index_row];
	delete roundKey;
	
	return cipheredText;
}
const string AES::Cipher(string&,int&,int**){return "";}
int** AES::UtilizeText(string&,int&){return NULL;}

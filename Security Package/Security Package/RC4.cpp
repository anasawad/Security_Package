#include "RC4.h"

RC4::RC4(void)
{
	Initialize();
}

void RC4::Initialize()
{
	for(int i=0; i<256; i++)
		m_state[i] = i;
}

/*
key-scheduling algorithm
*/
void RC4::KSA(string& key)
{
	int j = 0, keylen = key.size();
	for(int i=0; i<256; i++) 
	{
		j = (j + m_state[i] + key[i%keylen]) % 256;
	
		swap(m_state[i], m_state[j]);
	}
}

string RC4::PRGA(int inputSize)
{
	string keyStream(inputSize, ' ');
	int i = 0 , j = 0;
	for(int k=0; k < inputSize; k++) 
	{
		i = (i+1) % 256;
		j = (j+m_state[i]) % 256;
 
		swap(m_state[i], m_state[j]);
 
		keyStream[k] = m_state[(m_state[i]+m_state[j]) % 256];
	}

	return keyStream;
}

const string RC4::Cipher(std::string& input, std::string& key) 
{
	int sz = input.size();

	string out(sz, ' ');
	string keyStream;

	KSA(key);
	keyStream = PRGA(sz);

	int tmp;
	
	for(int i=0; i<sz; i++)
	{
		tmp = input[i] ^ keyStream[i];
		out[i] = tmp;	
	}

	return out;
}


const string RC4::Decipher(string &in, string& key)
{
	int sz = in.size();
	string out(sz, ' ');
	string keyStream;
	int tmp;

	initialize(); // State[i] = i
	KSA(key);
	keyStream = PRGA(sz);

	for(int i=0; i<in.size(); i++)
	{
		tmp = in[i] ^ keyStream[i];
		out[i] = tmp;	
	}

	return out;
}


const string RC4::Cipher(string& ,int& ){return "";}
const string RC4::Cipher(std::string&, int&, int **) {return "";}
const void RC4::UtilizeText(string&){;}
int** RC4::UtilizeText(string&,int&){return NULL;}



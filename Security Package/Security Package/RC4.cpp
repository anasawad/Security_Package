#include "RC4.h"

RC4::RC4(void)
{
	initialize();
}

void RC4::initialize()
{
	for(int i=0; i<256; i++)
		State[i] = i;
}

/*
key-scheduling algorithm
*/
void RC4::KSA(string& key)
{
	int j = 0, keylen = key.size();
	for(int i=0; i<256; i++) 
	{
		j = (j + State[i] + key[i%keylen]) % 256;
	
		swap(State[i], State[j]);
	}
}


const string RC4::Cipher(std::string& input, std::string& key) 
{
	string out(input.size()*2, ' ');
	string keyStream(input.size(), ' ');

	KSA(key);

	int i = 0 , j = 0;
	for(int k=0; k<input.size(); k++) 
	{
		i = (i+1) % 256;
		j = (j+State[i]) % 256;
 
		swap(State[i], State[j]);
 
		keyStream[k] = State[(State[i]+State[j]) % 256];
	}

	int tmp;
	
	for(i=0; i<input.size(); i++)
	{
		tmp = input[i] ^ keyStream[i];
		out[i] = tmp;	
	}

	return out;
}


const string  RC4::DeCipher(string &in, string& key)
{
	return "";
}



const string RC4::Cipher(string& ,int& ){return "";}
const string RC4::Cipher(std::string&, int&, int **) {return "";}
const void RC4::UtilizeText(string&){;}
int** RC4::UtilizeText(string&,int&){return NULL;}



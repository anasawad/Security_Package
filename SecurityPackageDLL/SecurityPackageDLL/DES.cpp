#include "DES.h"

int DES::m_key[64] ={
	0,0,0,1,0,0,1,1,
	0,0,1,1,0,1,0,0,
	0,1,0,1,0,1,1,1,
	0,1,1,1,1,0,0,1,
	1,0,0,1,1,0,1,1,
	1,0,1,1,1,1,0,0,
	1,1,0,1,1,1,1,1,
	1,1,1,1,0,0,0,1
};
int DES::m_sBox1[4][16] = 
{
	14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
	0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
	4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
	15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
};

int DES::m_sBox2[4][16] = 
{
	15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
	3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
	0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
	13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
};

int DES::m_sBox3[4][16] = 
{
	10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
	13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
	13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
	1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
};

int DES::m_sBox4[4][16]=
{
	7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
	13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
	10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
	3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
};

int DES::m_sBox5[4][16]=
{
	2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
	14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
	4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
	11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
};

int DES::m_sBox6[4][16]=
{
	12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
	10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
	9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
	4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
};

int DES::m_sBox7[4][16]=
{
	4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
	13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
	1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
	6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
};

int DES::m_sBox8[4][16]=
{
	13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
	1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
	7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
	2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
};







//Private Methods
void DES::Keygen()
{
	Permutation_Choice1();
	int i,j,k=0;
	for(i=0; i<28; i++)
	{
		m_Ckey[i]= m_permChoice1[i];
	}
	for(i=28; i<56; i++)
	{
		m_Dkey[k]=m_permChoice1[i];
		k++;
	}
	int noshift=0,round;
	for(round=1; round<=16; round++)
	{
		if(round==1||round==2||round==9||round==16)
			noshift=1;
		else
			noshift=2;
		while(noshift>0)
		{
			int t;
			t=m_Ckey[0];
			for(i=0; i<28; i++)
				m_Ckey[i]=m_Ckey[i+1];
			m_Ckey[27]=t;
			t=m_Dkey[0];
			for(i=0; i<28; i++)
				m_Dkey[i]= m_Dkey[i+1];
			m_Dkey[27]=t;
			noshift--;
		}
		Permutation_Choice2();
		for(i=0; i<48; i++)
			m_keyRound[round-1][i]= m_z[i];
	}
}

void DES::Reverse()
{
	int p=40,q=8,k1,k2,i,j;
	for(i=0; i<8; i++)
	{
		k1=p;
		k2=q;
		for(j=0; j<8; j++)
		{
			if(j%2==0)
			{
				m_reverse[i][j]= m_swapText[k1-1];
				k1=k1+8;
			}
			else if(j%2!=0)
			{
				m_reverse[i][j]=m_swapText[k2-1];
				k2=k2+8;
			}
		}
		p=p-1;
		q=q-1;
	}
}

int* DES::CharToBinary(unsigned char c)
{
	int *charInBinary = new int[8];
	int ascii = (int) c;
	int b;
	for(b=7; ascii >=1; b--)
	{
		charInBinary[b]=ascii%2;  //Converting 8-Bytes to 64-bit Binary Format
		ascii/=2;
	}
	for(; b>=0; b--) charInBinary[b]=0;
	return charInBinary;
}

void DES::Initial_Permutation()
{
	int idx = 58;
	for (int i =0 ; i< 32; i++)
	{
		m_initialPerm[i] = m_textBinaryFormat[idx-1];
		if(idx-8 > 0)
			idx -= 8;
		else
			idx += 58;
	}
	idx = 57;
	for (int i=32; i < 64; i++)
	{
		m_initialPerm[i] = m_textBinaryFormat[idx-1];
		if(idx-8 > 0)
			idx -= 8;
		else
			idx += 58;
	}
}

void DES::Permutation_Choice1()
{
	int idx = 57;
	for (int i=0; i < 28; i++)
	{
		m_permChoice1[i] = m_key[idx-1];
		if(idx-8>0)    
			idx -= 8;
		else 
			idx += 57;
	}
	idx = 63;
	for (int i = 28; i < 52; i++)
	{
		m_permChoice1[i] = m_key[idx-1];
		if(idx-8 > 0)
			idx -= 8;
		else
			idx += 55;
	}

	idx = 28;
	for (int i = 52; i < 56; i++)
	{
		m_permChoice1[i] = m_key[idx-1];
		idx -= 8;
	}
}

void DES::Expansion()
{
	int tempExp[8][6];
	int idx;
	for (int i =0; i<8; i++)
	{
		for (int j =0; j < 6; j++)
		{
			if((j!=0) || (j!=5))
			{
				idx = 4*i+j;
				tempExp[i][j] = m_textRight[idx-1];
			}
			if (j==0)
			{
				idx = 4*i;
				tempExp[i][j] = m_textRight[idx-1];
			}
			if (j == 5)
			{
				idx = 4*i+j;
				tempExp[i][j] = m_textRight[idx-1];
			}
		}

	}
	tempExp[0][0] = m_textRight[31];
	tempExp[7][5] = m_textRight[0];
	idx =0 ;
	for (int i =0; i < 8; i++)
	{
		for (int j =0; j < 6; j++)
		{
			m_expansionTable[idx] = tempExp[i][j];
			idx++;
		}
	}
}

void DES::Permutation_Choice2()
{
	int tempPerm[56];
	int idx;

	for (int i =0 ;i < 28; i++)
		tempPerm[i] = m_Ckey[i];
	for(int k=0,i=28; i<56; i++) 
		tempPerm[i]=m_Dkey[k++];

	m_z[0] =tempPerm[13];
	m_z[1] =tempPerm[16];
	m_z[2] =tempPerm[10];
	m_z[3] =tempPerm[23];
	m_z[4] =tempPerm[0];
	m_z[5] =tempPerm[4];
	m_z[6] =tempPerm[2];
	m_z[7] =tempPerm[27];
	m_z[8] =tempPerm[14];
	m_z[9] =tempPerm[5];
	m_z[10]=tempPerm[20];
	m_z[11]=tempPerm[9];
	m_z[12]=tempPerm[22];
	m_z[13]=tempPerm[18];
	m_z[14]=tempPerm[11];
	m_z[15]=tempPerm[3];
	m_z[16]=tempPerm[25];
	m_z[17]=tempPerm[7];
	m_z[18]=tempPerm[15];
	m_z[19]=tempPerm[6];
	m_z[20]=tempPerm[26];
	m_z[21]=tempPerm[19];
	m_z[22]=tempPerm[12];
	m_z[23]=tempPerm[1];
	m_z[24]=tempPerm[40];
	m_z[25]=tempPerm[51];
	m_z[26]=tempPerm[30];
	m_z[27]=tempPerm[36];
	m_z[28]=tempPerm[46];
	m_z[29]=tempPerm[54];
	m_z[30]=tempPerm[29];
	m_z[31]=tempPerm[39];
	m_z[32]=tempPerm[50];
	m_z[33]=tempPerm[46];
	m_z[34]=tempPerm[32];
	m_z[35]=tempPerm[47];
	m_z[36]=tempPerm[43];
	m_z[37]=tempPerm[48];
	m_z[38]=tempPerm[38];
	m_z[39]=tempPerm[55];
	m_z[40]=tempPerm[33];
	m_z[41]=tempPerm[52];
	m_z[42]=tempPerm[45];
	m_z[43]=tempPerm[41];
	m_z[44]=tempPerm[49];
	m_z[45]=tempPerm[35];
	m_z[46]=tempPerm[28];
	m_z[47]=tempPerm[31];
}

void DES::Xor_Encrypt(int round)
{
	for (int i=0; i<48; i++)
	{
		m_xorSubKey[i] = m_expansionTable[i] ^ m_keyRound[round-1][i];
	}
}

void DES::Xor_Decrypt(int round)
{
	for (int i=0; i<48; i++)
	{
		m_xorSubKey[i] = m_expansionTable[i] ^ m_keyRound[16-round][i];
	}
}

void DES::Substitution()
{
	int a[8][6],k=0,i,j,p,q,count=0,g=0,v;

	for(i=0; i<8; i++)
	{
		for(j=0; j<6; j++)
		{
			a[i][j]= m_xorSubKey[k++];
		}
	}

	for( i=0; i<8; i++)
	{
		p=1;
		q=0;
		k=(a[i][0]*2)+(a[i][5]*1);
		j=4;
		while(j>0)
		{
			q=q+(a[i][j]*p);
			p=p*2;
			j--;
		}
		count=i+1;
		switch(count)
		{
		case 1:
			v=m_sBox1[k][q];
			break;
		case 2:
			v=m_sBox2[k][q];
			break;
		case 3:
			v=m_sBox3[k][q];
			break;
		case 4:
			v=m_sBox4[k][q];
			break;
		case 5:
			v=m_sBox5[k][q];
			break;
		case 6:
			v=m_sBox6[k][q];
			break;
		case 7:
			v=m_sBox7[k][q];
			break;
		case 8:
			v=m_sBox8[k][q];
			break;
		}
		int d,i=3,a[4];
		while(v>0)
		{
			d=v%2;
			a[i--]=d;
			v=v/2;
		}
		while(i>=0)
		{
			a[i--]=0;
		}

		for(i=0; i<4; i++)
			m_substitutionTable[g++]=a[i];
	}

}

void DES::Permutation()
{
	m_permTable[0] =m_substitutionTable[15];
	m_permTable[1] =m_substitutionTable[6];
	m_permTable[2] =m_substitutionTable[19];
	m_permTable[3] =m_substitutionTable[20];
	m_permTable[4] =m_substitutionTable[28];
	m_permTable[5] =m_substitutionTable[11];
	m_permTable[6] =m_substitutionTable[27];
	m_permTable[7] =m_substitutionTable[16];
	m_permTable[8] =m_substitutionTable[0];
	m_permTable[9] =m_substitutionTable[14];
	m_permTable[10]=m_substitutionTable[22];
	m_permTable[11]=m_substitutionTable[25];
	m_permTable[12]=m_substitutionTable[4];
	m_permTable[13]=m_substitutionTable[17];
	m_permTable[14]=m_substitutionTable[30];
	m_permTable[15]=m_substitutionTable[9];
	m_permTable[16]=m_substitutionTable[1];
	m_permTable[17]=m_substitutionTable[7];
	m_permTable[18]=m_substitutionTable[23];
	m_permTable[19]=m_substitutionTable[13];
	m_permTable[20]=m_substitutionTable[31];
	m_permTable[21]=m_substitutionTable[26];
	m_permTable[22]=m_substitutionTable[2];
	m_permTable[23]=m_substitutionTable[8];
	m_permTable[24]=m_substitutionTable[18];
	m_permTable[25]=m_substitutionTable[12];
	m_permTable[26]=m_substitutionTable[29];
	m_permTable[27]=m_substitutionTable[5];
	m_permTable[28]=m_substitutionTable[21];
	m_permTable[29]=m_substitutionTable[10];
	m_permTable[30]=m_substitutionTable[3];
	m_permTable[31]=m_substitutionTable[24];

}

void DES::Xor_LeftRight()
{
	for (int i=0; i < 32; i++)
	{
		m_xorLeftRight[i] = m_textLeft[i]^m_permTable[i];
	}
}

const void DES::UtilizeText(string& text)
{
	string tempText;// = text;

	for (int i = 0; i < text.length(); i++)
	{
		if(text[i] == ' ')
			continue;
		tempText += tolower(text[i]);
	}
	int len = tempText.length();
	int lenRem = len%8;

	if (lenRem != 0)
		for(int j=0; j<8-lenRem; j++,len++) 
			tempText.append(" ");
	text = tempText;
}
int** DES::UtilizeText(string&,int&){return NULL;}


//Override virtual functions 

const string DES::Cipher(string& text, string& notused)
{
	string tempText;
	tempText = text;
	int len = tempText.length();

	int finalTxtIdx=0;
	UtilizeText(tempText);
	Keygen();
	int toBinaryIdx = 0, txtInBinaryIdx;

	int ascii;
	int *charInBinary = new int [8];

	for(int m=0,toBinaryIdx = 0; m<(tempText.length()/8); m++) 
	{
		txtInBinaryIdx = 0;
		for(int i=0; i<8; i++,toBinaryIdx++)
		{
			//converting text to binary 
			charInBinary = CharToBinary(tempText[toBinaryIdx]);	
			//filling m_textBinaryFormat with the whole text in binary 
			for(int k=0; k<8; k++,txtInBinaryIdx++)
				m_textBinaryFormat[txtInBinaryIdx]= charInBinary[k]; 
		}
		Initial_Permutation();

		//dividing the text into two equal parts (left, right)
		int i=0;
		for(i=0; i<64; i++)
			m_textBinaryFormat[i]=m_initialPerm[i];
		for(i=0; i<32; i++) 
			m_textLeft[i]=m_textBinaryFormat[i];
		for(; i<64; i++)
			m_textRight[i-32]=m_textBinaryFormat[i];

		//Encryption starts
		for(int round=1; round<=16; round++)
		{
			Expansion(); //expanding the m_textRight[32] to fill m_expansionTable[48]
			Xor_Encrypt(round); // XOR operation on the m_expansionTable[4], m_z[48] to fill m_subkeys[32]
			Substitution(); //substitute on m_subkeys[48] to fill m_substitutionTable[32]
			Permutation();  //permutate to fill m_permTable[32]
			Xor_LeftRight(); //XORing the m_textLeft[32] with m_permTable[32]

			//for swapping adding the right part to the left part
			for(i=0; i<32; i++)
				m_textLeft[i]= m_textRight[i];
			for(i=0; i<32; i++) 
				m_textRight[i]=m_xorLeftRight[i];
		}
		//Swapping text
		for(i=0; i<32; i++)
			m_swapText[i]= m_textRight[i];
		for(; i<64; i++) 
			m_swapText[i]=m_textLeft[i-32]; 
		Reverse();
		//get the text again from binary 
		int k = 128;
		int count =0;
		for(int i=0; i<8; i++)
		{
			for(int j=0; j<8; j++)
			{
				count = count+m_reverse[i][j]*k;
				k=k/2;
			}
			m_finalText[finalTxtIdx++]=(char)count;
			k=128;
			count=0;
		}
	}
	m_finalText[finalTxtIdx]='\0';
	return(m_finalText);
}
const string DES::Decipher(string& text, string& notused)
{
	string tempText;
	tempText = text;
	int len = tempText.length();
	int finalTxtIdx=0;
	Keygen();
	int toBinaryIdx = 0, txtInBinaryIdx;

	int ascii;

	int *charInBinary = new int [8];

	for(int m=0,toBinaryIdx = 0; m<(tempText.length()/8); m++) 
	{
		txtInBinaryIdx = 0;
		for(int i=0; i<8; i++,toBinaryIdx++)
		{
			//converting text to binary 
			unsigned char myChar = tempText[toBinaryIdx];
			charInBinary = CharToBinary(myChar);	
			//filling m_textBinaryFormat with the whole text in binary 
			for(int k=0; k<8; k++,txtInBinaryIdx++)m_textBinaryFormat[txtInBinaryIdx]= charInBinary[k]; 
		}
		Initial_Permutation();
		//dividing the text into two equal parts (left, right)
		int i=0;
		for(i=0; i<64; i++)m_textBinaryFormat[i]=m_initialPerm[i];
		for(i=0; i<32; i++) m_textLeft[i]=m_textBinaryFormat[i];
		for(; i<64; i++)m_textRight[i-32]=m_textBinaryFormat[i];

		for(int round=1; round<=16; round++)
		{
			Expansion(); //expanding the m_textRight[32] to fill m_expansionTable[48]
			Xor_Decrypt(round); // XOR operation on the m_expansionTable[4], m_z[48] to fill m_subkeys[32]
			Substitution(); //substitute on m_subkeys[48] to fill m_substitutionTable[32]
			Permutation();  //permutate to fill m_permTable[32]
			Xor_LeftRight(); //XORing the m_textLeft[32] with m_permTable[32]

			//for swapping adding the right part to the left part
			for(i=0; i<32; i++)m_textLeft[i]= m_textRight[i];
			for(i=0; i<32; i++)m_textRight[i]=m_xorLeftRight[i];
		}
		for(i=0; i<32; i++) m_swapText[i]=m_textRight[i]; 
		for(; i<64; i++) m_swapText[i]=m_textLeft[i-32]; 

		Reverse();

		//get the text again from binary 
		int k = 128;
		int count =0;
		for(int i=0; i<8; i++)
		{
			for(int j=0; j<8; j++)
			{
				count = count+m_reverse[i][j]*k;
				k=k/2;
			}
			m_finalText[finalTxtIdx++]=(char)count;
			k=128;
			count=0;
		}
	} //for loop ends here
	m_finalText[finalTxtIdx]='\0';
	char *final1=new char[1000];
	int i,j;
	for(i=0,j=tempText.length(); i<tempText.length(); i++,j++)
		final1[i]=m_finalText[j];
	final1[i]='\0';
	return(m_finalText);
}
const string DES::Cipher(string&, int&, int **){return"";}
const string DES::Cipher(string&, int&){return "";}
const string DES::Decipher(string&, int&, int **){return "";}
const string DES::Decipher(string&, int&){return "";}
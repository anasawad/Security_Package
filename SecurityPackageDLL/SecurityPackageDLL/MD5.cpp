#include"MD5.h"

MD5::MD5(void)
{

}

void MD5::calculate_Round(unsigned char Round_ind,WORD* CV, WORD* Y){

	WORD* result_vector            = new WORD[4];
	WORD* Current_T_Table          = new WORD[16];
	WORD* Current_Block            = new WORD[16];
	WORD result,tmp;
	int start_ind;
	if(Round_ind == 1)
	{
		for(int ind = 0 ; ind <16 ; ind ++){
			Current_T_Table[ind] = T_Table[(Round_ind-1)+ind];
		}
		for(int ind = 0 ; ind <16 ; ind ++){
			Current_Block[ind] = Y[P1(ind)];
		}

		for(int ind = 0 ; ind < 16 ; ind++){

	        result = F(CV[1] , CV[2] , CV[3]);
			result = Add(result , CV[0]);
			result = Add(result,Current_Block[ind]);
			result = Add(result,Current_T_Table[ind]);
			result = result << Shift_Amount[Round_ind-1][ind%4];
			result = Add(result , CV[1]);

			tmp = CV[3];
			CV[3] = CV[2];
			CV[2] = CV[1];
			CV[1] = result ;
			CV[0] = tmp;	
		}
	}
	else if(Round_ind == 2)
	{
		for(int ind = 0 ; ind <16 ; ind ++){
			Current_T_Table[ind] = T_Table[(Round_ind-1)+ind];
		}
		for(int ind = 0 ; ind <16 ; ind ++){
			Current_Block[ind] = Y[P2(ind)];
		}

		for(int ind = 0 ; ind < 16 ; ind++){

			result = G(CV[1] , CV[2] , CV[3]);
			result = Add(result , CV[0]);
			result = Add(result,Current_Block[ind]);
			result = Add(result,Current_T_Table[ind]);
			result = result << Shift_Amount[Round_ind-1][ind%4];
			result = Add(result , CV[1]);

			tmp = CV[3];
			CV[3] = CV[2];
			CV[2] = CV[1];
			CV[1] = result ;
			CV[0] = tmp;
		}
	}
	else if(Round_ind == 3)
	{
		for(int ind = 0 ; ind <16 ; ind ++){
			Current_T_Table[ind] = T_Table[(Round_ind-1)+ind];
		}
		for(int ind = 0 ; ind <16 ; ind ++){
			Current_Block[ind] = Y[P3(ind)];
		}

		for(int ind = 0 ; ind < 16 ; ind++){

			result = H(CV[1] , CV[2] , CV[3]);
			result = Add(result , CV[0]);
			result = Add(result,Current_Block[ind]);
			result = Add(result,Current_T_Table[ind]);
			result = result << Shift_Amount[Round_ind-1][ind%4];
			result = Add(result , CV[1]);

			tmp = CV[3];
			CV[3] = CV[2];
			CV[2] = CV[1];
			CV[1] = result ;
			CV[0] = tmp;
		}
	}
	else if(Round_ind == 4)
	{
		for(int ind = 0 ; ind <16 ; ind ++){
			Current_T_Table[ind] = T_Table[(Round_ind-1)+ind];
		}
		for(int ind = 0 ; ind <16 ; ind ++){
			Current_Block[ind] = Y[P4(ind)];
		}

		for(int ind = 0 ; ind < 16 ; ind++){

			result = I(CV[1] , CV[2] , CV[3]);
			result = Add(result , CV[0]);
			result = Add(result,Current_Block[ind]);
			result = Add(result,Current_T_Table[ind]);
			result = result << Shift_Amount[Round_ind-1][ind%4];
			result = Add(result , CV[1]);

			tmp = CV[3];
			CV[3] = CV[2];
			CV[2] = CV[1];
			CV[1] = result ;
			CV[0] = tmp;
		}
	}
}
void MD5::calculat_MD5_Module(WORD* CV, WORD* Y)
{
	WORD Current_Block [16];
	for(int round = 1 ; round <= 4 ; round++)
	{
		for(int i = 0 ; i < 16 ; i++)
		{
			Current_Block[i] = Y[(round-1)+i];
		}

		calculate_Round(round,CV , Current_Block);
	}
}
void MD5::Convert_To_Array_Of_Words(unsigned char* Msgfrom , WORD* Msgto , int &size)
{
	unsigned char* Msg_tmp = new unsigned char ;
	unsigned char uc_tmp;
	unsigned char* uc_ptr ;
	WORD* ui_ptr;

	for(int i = 0 ; i < size ; i+=4)
	{
		for(int j = 0 ; j < 4; j++) // 4 = 32/8
		{
			if( i+(3-j) < size){ // 0 -> 3
				uc_tmp = (unsigned char)Msgfrom[i+(3-j)];
				Msg_tmp[i+j] =  uc_tmp;
			}
		}
	}


	for(int i = 0 ; i < size/4 +1 ; i++)
	{
		uc_ptr = Msg_tmp+(i*4);
		ui_ptr = (WORD*) uc_ptr;
		Msgto[i] = *ui_ptr;
	}
}
void MD5::Convert_To_Array_of_char(string C , unsigned char* Msg)
{
	for(int i = 0 ; i < C.size() ; i++)
	{
		Msg[i] = C[i];
	}
}

const string MD5::Cipher(string&,int&,int**){return "";}
const string MD5::Cipher(string&, int&){return "";}
const string MD5::Cipher(string &Message, string &key)
{
	WORD Msg[10000];
	unsigned char byte_Msg[40000];
	WORD packet[16];
	WORD CV[4] = {0x67452301 , 0xEFCDAB89 , 0x98BADCFE, 0x10325478};
	memset(Msg , 0 , sizeof(Msg));
	memset(byte_Msg , 0 , sizeof(byte_Msg));
	//Convert_To_Array_Of_Words(Message,Msg);
	Convert_To_Array_of_char(Message,byte_Msg);
	int desired_Padding_bytes = 1;                // 1 minumum padding byte.
	int number_of_bytes = Message.size() + 8 + desired_Padding_bytes ; // 8 = number of byte per 64 bit; 

	if(number_of_bytes % 64 != 0)                 // 64 number of byte per 512 bit
	{
		desired_Padding_bytes+= (64 - (number_of_bytes % 64));
		number_of_bytes = Message.size() + 8 + desired_Padding_bytes ;
	}

	byte_Msg[Message.size()] |= 0x80;
	DWord MessageSize = Message.size();

	byte_Msg[Message.size() + desired_Padding_bytes ] = (WORD)(MessageSize >> 32); // start of size. 
	byte_Msg[Message.size() + desired_Padding_bytes+1 ] = (WORD)(MessageSize);
	for (int i = 0 ; i < 100 ; i++)
	{
		printf("%x\n" , byte_Msg[i]);
	}
	Convert_To_Array_Of_Words(byte_Msg,Msg,number_of_bytes);
	for (int i = 0 ; i < 100 ; i++)
	{
		printf("%x\n" , Msg[i]);
	}
	int number_of_words = number_of_bytes /4;
	for(int word_ind = 0 ; word_ind < number_of_words ; word_ind+=16)
	{
		int count = 0;
		for(int i = word_ind ; i < word_ind + 16 ; i++)
			packet[count++] = Message[i];
		calculat_MD5_Module(CV ,packet);
	}
	string cipher ;
	for(int i = 0 ; i < 4 ; i++)
	{
		cipher += Convert_To_Hex( CV[i]);
	}
	return cipher;
}

const string MD5::Decipher(string& , string&){return "";}
const string MD5::Decipher(string&, int&){return "";}
const string MD5::Decipher(string&, int&, int **){return "";}
string MD5::Convert_To_Hex( int number )
{
	string str;
	while(number)
	{
		str += number%16+'0';
		number /= 16;
	}
	reverse(str.begin() , str.end());
	return str;
}
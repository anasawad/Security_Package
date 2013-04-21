#include <iostream>
#include <string>
#include "Security_Package.h"
#include "Ceaser_Cipher.h"
#include "Security_Package.h"
#include "Monoalphabetic_Cipher.h"
#include "Playfair_Cipher.h"
#include "AES.h"
using namespace std;

int main ()
{
	Security_Package* ceaser[2];
	Playfair_Cipher playfair;
	Monoalphabetic_Cipher t;
	Ceaser_Chiper c1 ;
	Ceaser_Chiper c2 ;
	ceaser[0] = &c1;
	ceaser[1] = &c2;
	string s = "communication";
	int key = 8;
	string k = "playfair example";
	//cout <<ceaser[0]->Cipher(s,key) << endl;
	//cout << t.Cipher(s,k) << endl;
	cout << playfair.Cipher(s,k) << endl;
}

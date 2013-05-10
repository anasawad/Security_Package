#include <iostream>
#include <string>
#include "Security_Package.h"

#include "Ceaser_Cipher.h"
#include "Security_Package.h"
#include "Monoalphabetic_Cipher.h"
#include "Playfair_Cipher.h"
#include "AES.h"
#include "Hill_Cipher.h"
#include "AutoKey.h"
#include "RailFence.h"
#include "Columnar.h"
using namespace std;

int main ()
{
	freopen("input.in","r",stdin);
	Columner col;
	string key;
	string text;
	cin >> key;
	cin >> text;
	
	cout << col.Cipher(text, key) << endl;

	//AutoKey autokey;// = new AutoKey();
	//string key;
	//string text;
	//cin >> text >> key;
	//cout << autokey.Cipher(text, key) << endl;
	//Hill_Cipher cipher;
	//int**key;
	//int m ;
	//string text;
	//getline(cin,text);
	//cin >> m;
	//key = new int*[m];
	//for (int i = 0; i < m; i++)
	//{
	//	key[i] = new int[m];
	//}
	//for (int i =0 ;i < m; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cin >> key[i][j];
	//	}
	//}
	//cout << cipher.Cipher(text,m,key) << endl;
	//Security_Package* ceaser[2];
	//Playfair_Cipher playfair;
	//Monoalphabetic_Cipher t;
	//Ceaser_Chiper c1 ;
	//Ceaser_Chiper c2 ;
	//ceaser[0] = &c1;
	//ceaser[1] = &c2;
	//string s = "communication";
	//int key = 8;
	//string k = "playfair example";
	////cout <<ceaser[0]->Cipher(s,key) << endl;
	////cout << t.Cipher(s,k) << endl;
	//cout << playfair.Cipher(s,k) << endl;
}

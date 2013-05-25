#ifndef SEC_PACKAGE_H_
#define SEC_PACKAGE_H_

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <stdio.h>

using namespace std;

class Security_Package
{

public:
	Security_Package(){}
	
public:
	virtual const string Cipher(string&, int&)=0;
	virtual const string Cipher(string&, std::string&)=0;
	virtual const string Cipher(string&, int&, int **)=0;
	virtual const string Decipher(string &in, string& key)=0;
	virtual const string Decipher_Based_on_Previous_Ciphering() { return "";}
protected:
	//virtual ~Security_Package(){};
};
#endif
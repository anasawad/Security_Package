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
	virtual const string Cipher(std::string&, int&)=0;
	virtual const string Cipher(std::string&, std::string&)=0;
	virtual const string Cipher(std::string&, int&, int **)=0;
	virtual const string Decipher(string &in, string& key)=0;
	
protected:
	//virtual ~Security_Package(){};
};
#endif
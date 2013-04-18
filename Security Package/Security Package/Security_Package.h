#ifndef SEC_PACKAGE_H_
#define SEC_PACKAGE_H_

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <stdio.h>


class Security_Package
{

public:
	Security_Package(){}
	
public:
	virtual const std::string Cipher(std::string&, int&)=0;
	virtual const std::string Cipher(std::string&, std::string&)=0;
	virtual const std::string Cipher(std::string&, int&, int **)=0;
	
	
protected:
	//virtual ~Security_Package(){};
};
#endif
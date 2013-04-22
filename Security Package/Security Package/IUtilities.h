#ifndef IUTILITIES_H_
#define IUTILITIES_H_

#include <string>
using namespace std;
class IUtilities
{
public:
	IUtilities(){}
protected:
	virtual const void UtilizeText(string&)=0;
	virtual int** UtilizeText(string&,int&)=0;
};
#endif //IUTILITIES_H_
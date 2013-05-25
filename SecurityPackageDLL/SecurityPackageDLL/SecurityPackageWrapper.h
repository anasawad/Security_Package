#ifndef	SECURITY_PACKAGE_WRAPPER_H_
#define SECURITY_PACKAGE_WRAPPER_H_

#include "Security_Package.h"
#include "SecurityAlgorithmsFactory.h"
#include "Hill_Cipher.h"
#include <stdlib.h>
#include <string.h>
#include <msclr\marshal.h>


using namespace System;
//using namespace msclr::interop;
using namespace System::Runtime::InteropServices;   
using namespace System::Windows::Forms;
using System::Runtime::InteropServices::Marshal;
public ref class SecurityPackageWrapper
{
private:
	SecurityAlgorithmsFactory* m_algorithmFactory;
	Security_Package *m_algorithm;

	string ToString(String^);
	String^ToStringHandel(string);
	int** ToArray(array<int,2>^,int);
public:
	SecurityPackageWrapper();
	String^ Cipher(String^, String^, int);
	String^ Cipher(String^, String^, String^);
	String^ Cipher(String^, String^, int, array<int,2>^);
	String^ Decipher(String^, int);

};
#endif //SECURITY_PACKAGE_WRAPPER_H_
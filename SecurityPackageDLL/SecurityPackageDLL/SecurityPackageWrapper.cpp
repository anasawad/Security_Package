#include "SecurityPackageWrapper.h"
SecurityPackageWrapper::SecurityPackageWrapper(){}

String^ SecurityPackageWrapper::Cipher(String^ algoName, String^ text, int matSize, array<int,2>^ matrix)
{
	if (algoName == "HiLL_Cipher")
	{
		m_algorithm = SecurityAlgorithmsFactory::getInstance()->CreateAlgorithm(ToString(algoName));
		return ToStringHandel(m_algorithm->Cipher(ToString(text),matSize,ToArray(matrix,matSize)));
	}
	else
		return "";
}
String^ SecurityPackageWrapper::Cipher(String^ algoName, String^text, String^ key)
{
	if (algoName == "Monoalphabetic_Cipher" )
	{
		m_algorithm = SecurityAlgorithmsFactory::getInstance()->CreateAlgorithm(ToString(algoName));
		return ToStringHandel(m_algorithm->Cipher(ToString(text),ToString(key)));
	}
	else if(algoName == "AutoKey")
	{
		m_algorithm = SecurityAlgorithmsFactory::getInstance()->CreateAlgorithm(ToString(algoName));
		return ToStringHandel(m_algorithm->Cipher(ToString(text),ToString(key)));
	}
	else if (algoName == "Playfair_Cipher")
	{
		m_algorithm = SecurityAlgorithmsFactory::getInstance()->CreateAlgorithm(ToString(algoName));
		return ToStringHandel(m_algorithm->Cipher(ToString(text),ToString(key)));
	}
	else if(algoName == "DES")
	{
		m_algorithm = SecurityAlgorithmsFactory::getInstance()->CreateAlgorithm(ToString(algoName));
		return ToStringHandel(m_algorithm->Cipher(ToString(text),ToString(key)));
	}
	else if(algoName == "AES")
	{
		m_algorithm = SecurityAlgorithmsFactory::getInstance()->CreateAlgorithm(ToString(algoName));
		return ToStringHandel(m_algorithm->Cipher(ToString(text),ToString(key)));
	}
	else
	return "";
}

String^ SecurityPackageWrapper::Cipher(String^ algoName, String^ text, int key)
{
	if (algoName == "Ceaser_Cipher")
	{
		m_algorithm = SecurityAlgorithmsFactory::getInstance()->CreateAlgorithm(ToString(algoName));
		return ToStringHandel(m_algorithm->Cipher(ToString(text),key));
	}
	else return "";
}

String^ SecurityPackageWrapper::Decipher(String^, int)
{
	return "";
}

string SecurityPackageWrapper::ToString(String ^in)
{
	string temp ;
	for(int i = 0; i < in->Length; i++)
		temp += in[i];
	return temp;
}
String^ SecurityPackageWrapper::ToStringHandel(string in)
{
	String^ temp = gcnew String(in.c_str());
	return temp;
}
int** SecurityPackageWrapper::ToArray(array<int,2>^matrix,int size)
{
	int** tempMat = new int*[size];
	for (int i =0; i < size; i++)
		tempMat[i] = new int[size];
	for (int i = 0; i < size; i++)
	{
		for (int j =0; j < size; j++)
		{
			tempMat[i][j] = matrix[i,j];
		}
	}
	return tempMat;
}
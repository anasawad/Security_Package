#include "SecurityPackageWrapper.h"
SecurityPackageWrapper::SecurityPackageWrapper(){}

String^ SecurityPackageWrapper::Cipher(String^ algoName, String^ text, int matSize, array<int,2>^ matrix)
{
	m_algorithm = SecurityAlgorithmsFactory::getInstance()->CreateAlgorithm(ToString(algoName));
	return ToStringHandle(m_algorithm->Cipher(ToString(text),matSize,ToArray(matrix,matSize)));
}
String^ SecurityPackageWrapper::Cipher(String^ algoName, String^text, String^ key)
{
	m_algorithm = SecurityAlgorithmsFactory::getInstance()->CreateAlgorithm(ToString(algoName));
	return ToStringHandle(m_algorithm->Cipher(ToString(text),ToString(key)));
}

String^ SecurityPackageWrapper::Cipher(String^ algoName, String^ text, int key)
{
	m_algorithm = SecurityAlgorithmsFactory::getInstance()->CreateAlgorithm(ToString(algoName));
	return ToStringHandle(m_algorithm->Cipher(ToString(text),key));
}

String^ SecurityPackageWrapper::Decipher(String^ algoName,String^ text, String^ key)
{
	m_algorithm = SecurityAlgorithmsFactory::getInstance()->CreateAlgorithm(ToString(algoName));
	return ToStringHandle(m_algorithm->Decipher(ToString(text),ToString(key)));
}
String^ SecurityPackageWrapper::Decipher(String^ algoName,String^text)
{
	m_algorithm = SecurityAlgorithmsFactory::getInstance()->CreateAlgorithm(ToString(algoName));
	return ToStringHandle(m_algorithm->Decipher_Based_on_Previous_Ciphering(ToString(text)));
}

string SecurityPackageWrapper::ToString(String ^in)
{
	string temp ;
	for(int i = 0; i < in->Length; i++)
		temp += in[i];
	return temp;
}
String^ SecurityPackageWrapper::ToStringHandle(string in)
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
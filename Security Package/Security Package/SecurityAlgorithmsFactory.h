#pragma once
#include "Security_Package.h"

class SecurityAlgorithmsFactory
{
private:
	static SecurityAlgorithmsFactory* instance;
	SecurityAlgorithmsFactory(void);
	~SecurityAlgorithmsFactory(void);
public:
	Security_Package* createAlgorithm(string p_AlgoName);
	static SecurityAlgorithmsFactory* getInstance()
	{
		if(instance == NULL)
			instance = new SecurityAlgorithmsFactory();
		return instance;
	}
};


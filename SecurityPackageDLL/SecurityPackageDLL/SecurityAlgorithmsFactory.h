#pragma once
#include "Security_Package.h"

class SecurityAlgorithmsFactory
{
private:
	static SecurityAlgorithmsFactory *instance;
	SecurityAlgorithmsFactory(void);
	~SecurityAlgorithmsFactory(void);
public:
	Security_Package* CreateAlgorithm(string p_AlgoName);
	static SecurityAlgorithmsFactory* getInstance();
	
};


#ifndef POLYALPHABETIC_H_
#define POLYALPHABETIC_H_

#include "IUtilities.h"
#include "Security_Package.h"
#include <vector>
#define TABLE_SIZE 26

using namespace std;
class Polyalphabetic: public Security_Package
{
public:
	Polyalphabetic();
	~Polyalphabetic();

protected:
	int m_table[TABLE_SIZE][TABLE_SIZE];
	vector <char> m_alpha;

	void InitTable();
	void InitAlpha();
};
#endif //POLYALPHABETIC_H_
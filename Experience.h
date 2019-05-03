#pragma once
#include "Database.h"
#include <cmath>

class Experience {
private:
	int level;
	int experience;
	int maxExperience;
public:
	Experience();
	~Experience();
	Experience(int level, int exp, int maxexp);
	Experience& operator=(Experience other);
};

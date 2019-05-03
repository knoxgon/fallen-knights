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

	void setLevel(int level);
	void setExperience(int exp);
	void setMaxExperience(int maxexp);
	
	void updateExperience(int exp);
	void updateLevel();

	int getLevel()const;
	int getExperience()const;
	int getMaxExperience()const;

	void experienceControlFlow();

	int getNextExperience(int level);

	std::string convertExperienceToString(int currentLevel);

	std::string toString()const;
};
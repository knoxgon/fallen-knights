#pragma once
#include "BaseStats.h"

class UserStats : public BaseStats{
private:
	short strength;
	short intelligence;
	short endurance;

	short manaPoint;
	short maxManaPoint;

public:
	UserStats();
	virtual ~UserStats();
	UserStats(int attackPower, int defendPower, int healthPoint, int maxHP, int manaPoint, int maxMP,
		int strength, int intelligence, int endurance);

	int getStrength()const;
	int getIntelligence()const;
	int getEndurance()const;

	void setStrength(int str);
	void setIntelligence(int intel);
	void setEndurance(int endur);

	void setManaPoint(int manaPoint);
	void setMaxManaPoint(int manaPoint);

	int getManaPoint()const;
	int getMaxManaPoint()const;

	void updateManaPoint(int manavalue);
	void updateMaxManaPoint(int maxmanavalue);

	void updateStrength(int strvalue);
	void updateIntelligence(int intvalue);
	void updateEndurance(int endvalue);

	std::string toString() const;
};
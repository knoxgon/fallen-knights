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
};

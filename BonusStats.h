#pragma once

#include <vector>
#include <algorithm>

class BonusStats
{
private:
	int originalDefenseBonus;
	int defenseBonus;
	int originalHealthBonus;
	int healthBonus;
	int originalManaBonus;
	int manaBonus;
	int originalStrengthBonus;
	int strengthBonus;
	int originalIntelligenceBonus;
	int intelligenceBonus;
	int originalEnduranceBonus;
	int enduranceBonus;
	int originalAttackPowerBonus;
	int attackPowerBonus;
public:
	BonusStats();
	BonusStats(int defBonus = 0, int hpBonus = 0, int manaBonus = 0, 
		int strBonus = 0, int intelBonus = 0, int endBonus = 0, int apBonus = 0);
	~BonusStats();

	BonusStats& operator=(BonusStats& other);

};


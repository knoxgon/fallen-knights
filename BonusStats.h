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

	void setDefenseBonus(int def);
	void setHealthBonus(int hp);
	void setManaBonus(int mp);
	void setStrengthBonus(int str);
	void setIntelligenceBonus(int intel);
	void setEnduranceBonus(int end);
	void setAttackPowerBonus(int ap);

	void updateDefenseBonus(int def);
	void updateHealthBonus(int hp);
	void updateManaBonus(int mp);
	void updateStrengthBonus(int str);
	void updateIntelligenceBonus(int intel);
	void updateEnduranceBonus(int end);
	void updateAttackPowerBonus(int ap);

	int getDefenseBonus()const;
	int getHealthBonus()const;
	int getManaBonus()const;
	int getStrengthBonus()const;
	int getIntelligenceBonus()const;
	int getEnduranceBonus()const;
	int getAttackPowerBonus()const;

	int getOriginalDefenseBonus()const;
	int getOriginalHealthBonus()const;
	int getOriginalManaBonus()const;
	int getOriginalStrengthBonus()const;
	int getOriginalIntelligenceBonus()const;
	int getOriginalEnduranceBonus()const;
	int getOriginalAttackPowerBonus()const;

};


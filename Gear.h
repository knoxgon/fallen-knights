#pragma once

#include "BonusStats.h"
#include "Database.h"
#include <vector>
#include <algorithm>
#include <Windows.h>

class Gear
{
private:
	NS_GearAttributes::Rarity g_rarity;
	std::string rarity;

	std::string gearName;
	std::string gearType;

	int itemLevel;

	int originalDurability;
	int currentDurability;

	int originalMaxDurability;
	int maxDurability;

	int originalRequiredStrength;
	int requiredStrength;

	int originalRequiredIntelligence;
	int requiredIntelligence;

	int originalRequiredEndurance;
	int requiredEndurance;

	BonusStats* bonStats;

public:
	Gear();
	Gear(NS_GearAttributes::Rarity g_rarity, BonusStats* bonStats = nullptr, int itemLvl = 0,
		int currdur = 0, int maxdur = 0, int reqstr = 0, int reqint = 0, int reqend = 0);
	~Gear();

	bool operator==(const Gear& gear) {
		return this->g_rarity == gear.g_rarity
			&& this->itemLevel == gear.itemLevel;
	}
};

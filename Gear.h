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

};
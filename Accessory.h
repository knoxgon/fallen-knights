#pragma once
#include "BonusStats.h"
#include "Gear.h"
#include <sstream>

class Accessory : public Gear{
private:
	NS_AccessoryNames::Accessory_Name g_accName;
	NS_GearAttributes::AccessoryType g_accType;

public:
	Accessory();
	Accessory(NS_AccessoryNames::Accessory_Name g_accName, NS_GearAttributes::AccessoryType g_accType,
		NS_GearAttributes::Rarity g_rarity, BonusStats* bonStat, int itemLvl);
	~Accessory();

	bool operator==(const Accessory& rhs);

	void operateDefenseBonus(int def);
	void operateHealthBonus(int hp);
	void operateManaBonus(int mp);
	void operateStrengthBonus(int str);
	void operateIntelligenceBonus(int intel);
	void operateEnduranceBonus(int end);
	void operateAttackPowerBonus(int ap);

	void setAccessoryName(NS_AccessoryNames::Accessory_Name g_accName);
	void setAccessoryType(NS_GearAttributes::AccessoryType g_accType);

	NS_GearAttributes::AccessoryType getAccessoryType_ns()const;

	NS_AccessoryNames::Accessory_Name getGearName_ns() const;

	virtual void retrieveGear()const;
};

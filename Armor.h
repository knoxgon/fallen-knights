#pragma once
#include "Gear.h"
#include <string>
#include "Database.h"
#include "BonusStats.h"

class Armor : public Gear
{
private:
	NS_ArmorNames::Armor_Name g_armorName;
	NS_GearAttributes::ArmorType g_armorType;
	
	int originalDefense;
	int defense;
public:
	Armor();
	Armor(NS_ArmorNames::Armor_Name g_armorName, NS_GearAttributes::ArmorType g_armorType,
		NS_GearAttributes::Rarity g_rarity, int def = 0,
		int currdur = 0, int maxdur = 0, int reqstr = 0, int reqint = 0, int reqend = 0, 
		BonusStats* bonStat = nullptr, int itemLvl = 0);
	~Armor();

	void setArmorName(NS_ArmorNames::Armor_Name g_armorName);

	void setArmorType(NS_GearAttributes::ArmorType g_armorType);

	void setDefense(int def);

	void operateDefenseBonus(int def);
	void operateHealthBonus(int hp);
	void operateManaBonus(int mp);
	void operateStrengthBonus(int str);
	void operateIntelligenceBonus(int intel);
	void operateEnduranceBonus(int end);
	void operateAttackPowerBonus(int ap);
	
	int getDefense()const;

	int getOriginalDefense()const;

	bool operator==(const Armor& rhs);

	NS_ArmorNames::Armor_Name getGearName_ns() const;

	NS_GearAttributes::ArmorType getArmorType_ns()const;

	void updateDefense(int def);

	virtual void retrieveGear()const;
};

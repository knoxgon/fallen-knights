#include "stdafx.h"
#include "Armor.h"

Armor::Armor(){}
Armor::~Armor() {}

Armor::Armor(NS_ArmorNames::Armor_Name g_armorName, NS_GearAttributes::ArmorType g_armorType,
	NS_GearAttributes::Rarity g_rarity, int def,
	int currdur, int maxdur, int reqstr, int reqint, int reqend, BonusStats* bonStat, int itemLvl)
	: Gear(g_rarity, bonStat, itemLvl, currdur, maxdur, reqstr, reqint, reqend)
{
	this->setArmorName(g_armorName);
	this->setArmorType(g_armorType);
	this->setDefense(def);
	this->originalDefense = def;
	if (bonStat != nullptr) {
		if (bonStat->getDefenseBonus() != 0)
			this->operateDefenseBonus(bonStat->getDefenseBonus());
		if (bonStat->getHealthBonus() != 0)
			this->operateHealthBonus(bonStat->getHealthBonus());
		if (bonStat->getManaBonus() != 0)
			this->operateManaBonus(bonStat->getManaBonus());
		if (bonStat->getStrengthBonus() != 0)
			this->operateStrengthBonus(bonStat->getStrengthBonus());
		if (bonStat->getIntelligenceBonus() != 0)
			this->operateIntelligenceBonus(bonStat->getIntelligenceBonus());
		if (bonStat->getEnduranceBonus() != 0)
			this->operateEnduranceBonus(bonStat->getEnduranceBonus());
		if (bonStat->getAttackPowerBonus() != 0)
			this->operateAttackPowerBonus(bonStat->getAttackPowerBonus());
	}
}

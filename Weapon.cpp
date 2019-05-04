#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon() {}
Weapon::~Weapon() {}

Weapon::Weapon(NS_WeaponNames::Weapon_Name g_wep_name, NS_GearAttributes::WeaponClass g_wep_class,
	NS_GearAttributes::WeaponType g_wep_type, NS_GearAttributes::Rarity g_rarity, int ap, int currdur,
	int maxdur, int reqstr, int reqint, int reqend, BonusStats* bonStat, int itemLvl)
	: Gear(g_rarity, bonStat, itemLvl, currdur, maxdur, reqstr, reqint, reqend)
{
	this->setWeaponClass(g_wep_class);
	this->setWeaponType(g_wep_type);
	this->setWeaponName(g_wep_name);
	this->setAttackPower(ap);
	this->originalAttackPower = ap;
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

bool Weapon::operator==(const Weapon& rhs) {
	return this->g_wep_name == rhs.g_wep_name;
}

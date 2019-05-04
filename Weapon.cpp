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

void Weapon::setAttackPower(int ap)
{
	if (this->getItemLevel() == 0)
		this->attackPower = ap;
	if (this->getItemLevel() == 8) {
		if(ap > 0)
			this->attackPower = ap + ((this->getItemLevel() + 10) * 8);
		if (ap < 0)
			this->attackPower = ap - ((this->getItemLevel() + 10) * 8);
	}
	if (this->getItemLevel() == 9) {
		if (ap > 0)
			this->attackPower = ap + ((this->getItemLevel() + 10) * 9);
		if (ap < 0)
			this->attackPower = ap - ((this->getItemLevel() + 10) * 9);
	}
	if (this->getItemLevel() == 10) {
		if (ap > 0)
			this->attackPower = ap + ((this->getItemLevel() + 10) * 10);
		if (ap < 0)
			this->attackPower = ap - ((this->getItemLevel() + 10) * 10);
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (ap > 0)
					this->attackPower = ap + (this->getItemLevel() + 10);
				else if (ap < 0)
					this->attackPower = ap - (this->getItemLevel() + 10);
			}
		}
	}
}

void Weapon::operateDefenseBonus(int def)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setDefenseBonus(def);
	if (this->getItemLevel() == 8) {
		if (def > 0)
			this->getBonusStat()->setDefenseBonus(def + (((this->getItemLevel() + 3) * 2) + 3));
		else if (def < 0)
			this->getBonusStat()->setDefenseBonus(def - (((this->getItemLevel() + 3) * 2) + 3));
	}
	if (this->getItemLevel() == 9) {
		if (def > 0)
			this->getBonusStat()->setDefenseBonus(def + (((this->getItemLevel() + 3) * 2) + 4));
		else if (def < 0)
			this->getBonusStat()->setDefenseBonus(def - (((this->getItemLevel() + 3) * 2) + 4));
	}
	if (this->getItemLevel() == 10) {
		if (def > 0)
			this->getBonusStat()->setDefenseBonus(def + (((this->getItemLevel() + 3) * 2) + 5));
		else if (def < 0)
			this->getBonusStat()->setDefenseBonus(def - (((this->getItemLevel() + 3) * 2) + 5));
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (def > 0)
					this->getBonusStat()->setDefenseBonus(def + ((this->getItemLevel() + 3) * 2));
				else if (def < 0)
					this->getBonusStat()->setDefenseBonus(def - ((this->getItemLevel() + 3) * 2));
			}
		}
	}
}

void Weapon::operateHealthBonus(int hp)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setHealthBonus(hp);
	if (this->getItemLevel() == 8) {
		if (hp > 0)
			this->getBonusStat()->setHealthBonus(hp + ((this->getItemLevel() * this->getItemLevel()) + 11));
		else if (hp < 0)
			this->getBonusStat()->setHealthBonus(hp - ((this->getItemLevel() * this->getItemLevel()) + 11));
	}
	if (this->getItemLevel() == 9) {
		if (hp > 0)
			this->getBonusStat()->setHealthBonus(hp + ((this->getItemLevel() * this->getItemLevel()) + 12));
		else if (hp < 0)
			this->getBonusStat()->setHealthBonus(hp - ((this->getItemLevel() * this->getItemLevel()) + 12));
	}
	if (this->getItemLevel() == 10) {
		if (hp > 0)
			this->getBonusStat()->setHealthBonus(hp + ((this->getItemLevel() * this->getItemLevel()) + 15));
		else if (hp < 0)
			this->getBonusStat()->setHealthBonus(hp - ((this->getItemLevel() * this->getItemLevel()) + 15));
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (hp > 0)
					this->getBonusStat()->setHealthBonus(hp + ((this->getItemLevel() * this->getItemLevel()) + 10));
				else if (hp < 0)
					this->getBonusStat()->setHealthBonus(hp - ((this->getItemLevel() * this->getItemLevel()) + 10));
			}
		}
	}
}

void Weapon::operateManaBonus(int mp)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setManaBonus(mp);
	if (this->getItemLevel() == 8) {
		if (mp > 0)
			this->getBonusStat()->setManaBonus(mp + ((this->getItemLevel() * this->getItemLevel()) + 11));
		else if (mp < 0)
			this->getBonusStat()->setManaBonus(mp - ((this->getItemLevel() * this->getItemLevel()) + 11));
	}
	if (this->getItemLevel() == 9) {
		if (mp > 0)
			this->getBonusStat()->setManaBonus(mp + ((this->getItemLevel() * this->getItemLevel()) + 12));
		else if (mp < 0)
			this->getBonusStat()->setManaBonus(mp - ((this->getItemLevel() * this->getItemLevel()) + 12));
	}
	if (this->getItemLevel() == 10) {
		if (mp > 0)
			this->getBonusStat()->setManaBonus(mp + ((this->getItemLevel() * this->getItemLevel()) + 15));
		else if (mp < 0)
			this->getBonusStat()->setManaBonus(mp - ((this->getItemLevel() * this->getItemLevel()) + 15));
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (mp > 0)
					this->getBonusStat()->setManaBonus(mp + ((this->getItemLevel() * this->getItemLevel()) + 10));
				else if (mp < 0)
					this->getBonusStat()->setManaBonus(mp - ((this->getItemLevel() * this->getItemLevel()) + 10));
			}
		}
	}
}

void Weapon::operateStrengthBonus(int str)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setStrengthBonus(str);
	if (this->getItemLevel() == 8) {
		if (str > 0)
			this->getBonusStat()->setStrengthBonus(str + ((this->getItemLevel() * (this->getItemLevel())) + 30));
		else if (str < 0)
			this->getBonusStat()->setStrengthBonus(str - ((this->getItemLevel() * (this->getItemLevel())) + 30));
	}
	if (this->getItemLevel() == 9) {
		if (str > 0)
			this->getBonusStat()->setStrengthBonus(str + ((this->getItemLevel() * (this->getItemLevel())) + 40));
		else if (str < 0)
			this->getBonusStat()->setStrengthBonus(str - ((this->getItemLevel() * (this->getItemLevel())) + 40));
	}
	if (this->getItemLevel() == 10) {
		if (str > 0)
			this->getBonusStat()->setStrengthBonus(str + ((this->getItemLevel() * (this->getItemLevel())) + 100));
		else if (str < 0)
			this->getBonusStat()->setStrengthBonus(str - ((this->getItemLevel() * (this->getItemLevel())) + 100));
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (str > 0)
					this->getBonusStat()->setStrengthBonus(str + (((this->getItemLevel() + (this->getItemLevel())) + i) + 15));
				else if (str < 0)
					this->getBonusStat()->setStrengthBonus(str - (((this->getItemLevel() + (this->getItemLevel())) + i) + 15));
			}
		}
	}
}

void Weapon::operateIntelligenceBonus(int intel)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setIntelligenceBonus(intel);
	if (this->getItemLevel() == 8) {
		if (intel > 0)
			this->getBonusStat()->setIntelligenceBonus(intel + ((this->getItemLevel() * (this->getItemLevel())) + 10));
		else if (intel < 0)
			this->getBonusStat()->setIntelligenceBonus(intel - ((this->getItemLevel() * (this->getItemLevel())) + 10));
	}
	if (this->getItemLevel() == 9) {
		if (intel > 0)
			this->getBonusStat()->setIntelligenceBonus(intel + ((this->getItemLevel() * (this->getItemLevel())) + 20));
		else if (intel < 0)
			this->getBonusStat()->setIntelligenceBonus(intel - ((this->getItemLevel() * (this->getItemLevel())) + 20));
	}
	if (this->getItemLevel() == 10) {
		if (intel > 0)
			this->getBonusStat()->setIntelligenceBonus(intel + ((this->getItemLevel() * (this->getItemLevel())) + 50));
		else if (intel < 0)
			this->getBonusStat()->setIntelligenceBonus(intel - ((this->getItemLevel() * (this->getItemLevel())) + 50));
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (intel > 0)
					this->getBonusStat()->setIntelligenceBonus(intel + (((this->getItemLevel() + (this->getItemLevel())) + i) + 5));
				else if (intel < 0)
					this->getBonusStat()->setIntelligenceBonus(intel - (((this->getItemLevel() + (this->getItemLevel())) + i) + 5));
			}
		}
	}
}

void Weapon::operateEnduranceBonus(int end)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setEnduranceBonus(end);
	if (this->getItemLevel() == 8) {
		if (end > 0)
			this->getBonusStat()->setEnduranceBonus(end + ((this->getItemLevel() * (this->getItemLevel())) + 10));
		else if (end < 0)
			this->getBonusStat()->setEnduranceBonus(end - ((this->getItemLevel() * (this->getItemLevel())) + 10));
	}
	if (this->getItemLevel() == 9) {
		if (end > 0)
			this->getBonusStat()->setEnduranceBonus(end + ((this->getItemLevel() * (this->getItemLevel())) + 20));
		else if (end < 0)
			this->getBonusStat()->setEnduranceBonus(end - ((this->getItemLevel() * (this->getItemLevel())) + 20));
	}
	if (this->getItemLevel() == 10) {
		if (end > 0)
			this->getBonusStat()->setEnduranceBonus(end + ((this->getItemLevel() * (this->getItemLevel())) + 50));
		else if (end < 0)
			this->getBonusStat()->setEnduranceBonus(end - ((this->getItemLevel() * (this->getItemLevel())) + 50));
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (end > 0)
					this->getBonusStat()->setEnduranceBonus(end + (((this->getItemLevel() + (this->getItemLevel())) + i) + 5));
				else if (end < 0)
					this->getBonusStat()->setEnduranceBonus(end - (((this->getItemLevel() + (this->getItemLevel())) + i) + 5));
			}
		}
	}
}

void Weapon::operateAttackPowerBonus(int ap)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setAttackPowerBonus(ap);
	if (this->getItemLevel() == 8) {
		if (ap > 0)
			this->getBonusStat()->setAttackPowerBonus(ap + ((((this->getItemLevel() + 3) * 2) + 35) + 55));
		else if (ap < 0)
			this->getBonusStat()->setAttackPowerBonus(ap - ((((this->getItemLevel() + 3) * 2) + 35) + 55));
	}
	if (this->getItemLevel() == 9) {
		if (ap > 0)
			this->getBonusStat()->setAttackPowerBonus(ap + ((((this->getItemLevel() + 3) * 2) + 35) + 85));
		else if (ap < 0)
			this->getBonusStat()->setAttackPowerBonus(ap - ((((this->getItemLevel() + 3) * 2) + 35) + 85));
	}
	if (this->getItemLevel() == 10) {
		if (ap > 0)
			this->getBonusStat()->setAttackPowerBonus(ap + ((((this->getItemLevel() + 3) * 2) + 35) + 145));
		else if (ap < 0)
			this->getBonusStat()->setAttackPowerBonus(ap - ((((this->getItemLevel() + 3) * 2) + 35) + 145));
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (ap > 0)
					this->getBonusStat()->setAttackPowerBonus(ap + (((this->getItemLevel() + 3) * 2) + 35));
				else if (ap < 0)
					this->getBonusStat()->setAttackPowerBonus(ap - (((this->getItemLevel() + 3) * 2) + 35));
			}
		}
	}
}

int Weapon::getOriginalAttackPower() const
{
	return this->originalAttackPower;
}

int Weapon::getAttackPower() const
{
	return this->attackPower;
}

void Weapon::updateAttackPower(int ap)
{
	this->attackPower += ap;
}

std::string Weapon::getWeaponClass() const
{
	return this->weaponClass;
}

void Weapon::setWeaponClass(NS_GearAttributes::WeaponClass g_wep_class)
{
	this->g_wep_class = g_wep_class;
	switch (g_wep_class)
	{
	case NS_GearAttributes::WeaponClass::ONE_HANDED:
		this->weaponClass = "One-handed";
		break;
	case NS_GearAttributes::WeaponClass::TWO_HANDED:
		this->weaponClass = "Two-handed";
		break;
	}
}

NS_WeaponNames::Weapon_Name Weapon::getGearName_ns() const
{
	return this->g_wep_name;
}

void Weapon::setWeaponType(NS_GearAttributes::WeaponType g_wep_type)
{
	this->g_wep_type = g_wep_type;
	switch (g_wep_type)
	{
	case NS_GearAttributes::WeaponType::SWORD:
		this->setGearType("Sword");
		break;
	case NS_GearAttributes::WeaponType::AXE:
		this->setGearType("Axe");
		break;
	case NS_GearAttributes::WeaponType::CLUB:
		this->setGearType("Club");
		break;
	case NS_GearAttributes::WeaponType::SPEAR:
		this->setGearType("Spear");
		break;
	case NS_GearAttributes::WeaponType::DAGGER:
		this->setGearType("Dagger");
		break;
	}
}

void Weapon::setWeaponName(NS_WeaponNames::Weapon_Name g_wep_name)
{
	this->g_wep_name = g_wep_name;
	switch (g_wep_name)
	{
	case NS_WeaponNames::Weapon_Name::DAGGER_SHARD:
		this->setGearName("Shard");
		break;
	case NS_WeaponNames::Weapon_Name::DAGGER_CLEAVER:
		this->setGearName("Cleaver");
		break;
	case NS_WeaponNames::Weapon_Name::DAGGER_KUKRY:
		this->setGearName("Kukry");
		break;
	case NS_WeaponNames::Weapon_Name::DAGGER_SWORD_BREAKER:
		this->setGearName("Sword Breaker");
		break;
	case NS_WeaponNames::Weapon_Name::DAGGER_ASSASSIN_DAGGER:
		this->setGearName("Assassin Dagger");
		break;
	case NS_WeaponNames::Weapon_Name::DAGGER_STILETTO:
		this->setGearName("Stiletto");
		break;
	case NS_WeaponNames::Weapon_Name::DAGGER_MAIL_BREAKER:
		this->setGearName("Mail Breaker");
		break;
	case NS_WeaponNames::Weapon_Name::DAGGER_KNIFE:
		this->setGearName("Knife");
		break;
	case NS_WeaponNames::Weapon_Name::DAGGER_DIRK:
		this->setGearName("Dirk");
		break;
	case NS_WeaponNames::Weapon_Name::DAGGER_FINE_DAGGER:
		this->setGearName("Fine Dagger");
		break;
	case NS_WeaponNames::Weapon_Name::DAGGER_DAGGER:
		this->setGearName("Dagger");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_AXE_DEEP_SCAR:
		this->setGearName("Deep Scar");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_AXE_TOMAHAWK:
		this->setGearName("Tomahawk");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_AXE_WRIST_CUTTER:
		this->setGearName("Wrist Cutter");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_AXE_CLEAVER_AXE:
		this->setGearName("Cleaver Axe");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_AXE_MILITARY_PICK:
		this->setGearName("Military Pick");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_AXE_WARRIOR_AXE:
		this->setGearName("Warrior Axe");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_AXE_LARGE_AXE:
		this->setGearName("Large Axe");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_AXE_DOUBLE_AXE:
		this->setGearName("Double Axe");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_AXE_WOOD_CUTTER:
		this->setGearName("Wood Cutter");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_AXE_HAND_AXE:
		this->setGearName("Hand Axe");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_AXE_STONE_AXE:
		this->setGearName("Stone Axe");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_AXE_BATTLE_AXE:
		this->setGearName("Battle Axe");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_AXE_WAR_AXE:
		this->setGearName("War Axe");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_AXE_LUMBER_AXE:
		this->setGearName("Lumber Axe");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_AXE_TIMBER_AXE:
		this->setGearName("Timber Axe");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_AXE_TABAR:
		this->setGearName("Tabar");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_AXE_TWIN_AXE:
		this->setGearName("Twin Axe");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_AXE_GREAT_AXE:
		this->setGearName("Great Axe");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_AXE_BROAD_AXE:
		this->setGearName("Broad Axe");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_AXE_BONE_AXE:
		this->setGearName("Bone Axe");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_AXE_BONE_CLEAVER:
		this->setGearName("Bone Cleaver");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_TWO_HANDED_AXE_UNDEFEATABLE_BAAL:
		this->setGearName("Undefeatable Baal");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_TWO_HANDED_AXE_JURADINS_AXE:
		this->setGearName("Juradin's Axe");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_TWO_HANDED_AXE_AVEDON:
		this->setGearName("Avedon");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_TWO_HANDED_AXE_GIGANTIC_AXE:
		this->setGearName("Gigantic Axe");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_TWO_HANDED_AXE_BLADE_AXE:
		this->setGearName("Blade Axe");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_TWO_HANDED_AXE_JAVANA_AXE:
		this->setGearName("Javana Axe");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_SPEAR_LONG_SCHYTE:
		this->setGearName("Long Schyte");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_SPEAR_HARPON_SPEAR:
		this->setGearName("Harpon Spear");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_SPEAR_RAPTOR:
		this->setGearName("Raptor");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_SPEAR_GLAVE:
		this->setGearName("Glave");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_SPEAR_BARDISH:
		this->setGearName("Bardish");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_SPEAR_HALBERD:
		this->setGearName("Halberd");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_SPEAR_BILL:
		this->setGearName("Bill");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_SPEAR_HARSH_SCHYTE:
		this->setGearName("Harsh Schyte");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_SPEAR_POLE_AXE:
		this->setGearName("Pole Axe");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_TWO_HANDED_SPEAR_JURADINS_SPEAR:
		this->setGearName("Juradin's Reckless Spear");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_CLUB_IRON_IMPACT:
		this->setGearName("Iron Impact");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_CLUB_TOTAMIC_CLUB:
		this->setGearName("Totamic Club");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_CLUB_LARGE_BREAKER:
		this->setGearName("Large Breaker");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_CLUB_GIANT_MAUL:
		this->setGearName("Giant Maul");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_TWO_HANDED_CLUB_HELL_BREAKER:
		this->setGearName("Hell Breaker");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_TWO_HANDED_CLUB_JURADINS_VERDICT:
		this->setGearName("Juradin's Verdict");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_CLUB_PRIEST_MORNING_STAR:
		this->setGearName("Priest's Morning Star");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_CLUB_IRON_STAR:
		this->setGearName("Iron Star");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_CLUB_SPIKED_CLUB:
		this->setGearName("Spiked Club");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_CLUB_PRIEST_BREAKER:
		this->setGearName("Priest Breaker");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_CLUB_CRACKER:
		this->setGearName("Club Cracker");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_ONE_HANDED_CLUB_UNDEFEATABLE_LEONARD:
		this->setGearName("Undefeatable Leonard");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_ONE_HANDED_CLUB_SMITE_HAMMER:
		this->setGearName("Smite Hammer");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_ONE_HANDED_CLUB_STONE_SPLITTER:
		this->setGearName("Stone Splitter");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_ONE_HANDED_CLUB_DRAGON_TOOTH_HAMMER:
		this->setGearName("Dragon Tooth Hammer");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_ONE_HANDED_CLUB_LYCAON_HAMMER:
		this->setGearName("Lycaon Hammer");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_ONE_HANDED_CLUB_LUPUS_HAMMER:
		this->setGearName("Lupus Hammer");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_ONE_HANDED_CLUB_LOBO_HAMMER:
		this->setGearName("Lobo Hammer");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_ONE_HANDED_CLUB_SKULL_HAMMER:
		this->setGearName("Skull Hammer");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_SWORD_SHORT_BLADE:
		this->setGearName("Short Blade");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_SWORD_FLAME_SWORD:
		this->setGearName("Flame Sword");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_SWORD_SLAYER:
		this->setGearName("Slayer");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_SWORD_RAPIER:
		this->setGearName("Rapier");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_SWORD_SABRE:
		this->setGearName("Sabre");
		break;
	case NS_WeaponNames::Weapon_Name::ONE_HANDED_SWORD_FALCHION:
		this->setGearName("Falchion");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_ONE_HANDED_SWORD_JURADINS_SAPPHIRE:
		this->setGearName("Juradin's Sapphire");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_ONE_HANDED_SWORD_HANGUK_SWORD:
		this->setGearName("Hanguk Sword");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_SWORD_MIRAGE:
		this->setGearName("Mirage");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_SWORD_DESTROYER:
		this->setGearName("Destroyer");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_SWORD_FLAMBERGE:
		this->setGearName("Flamberge");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_SWORD_CLAYMORE:
		this->setGearName("Claymore");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_SWORD_WAR_SWORD:
		this->setGearName("War Sword");
		break;
	case NS_WeaponNames::Weapon_Name::TWO_HANDED_SWORD_DURANDAL:
		this->setGearName("Durandal");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_TWO_HANDED_SWORD_JURADINS_WRATH:
		this->setGearName("Juradin's Wrath");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_TWO_HANDED_SWORD_UNDEFEATABLE_WIRINIOM:
		this->setGearName("Undefeatable Wiriniom");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_DAGGER_JURADINS_SERVANT_DAGGER:
		this->setGearName("Juradin's Servant Dagger");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_DAGGER_UNDEFEATABLE_RAUM:
		this->setGearName("Undefeatable Raum");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_DAGGER_SHERION:
		this->setGearName("Sherion");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_DAGGER_DARK_VANE:
		this->setGearName("Dark Vane");
		break;
	case NS_WeaponNames::Weapon_Name::RARE_DAGGER_COLD__HEARTED_DAGGER:
		this->setGearName("Cold-Hearted Dagger");
		break;
	}
}

NS_GearAttributes::WeaponClass Weapon::getWeaponClass_ns() const
{
	return g_wep_class;
}

NS_GearAttributes::WeaponType Weapon::getWeaponType_ns() const
{
	return this->g_wep_type;
}

void Weapon::retrieveGear() const
{
	std::vector<std::string> maxim;
	if (this->getItemLevel() > 0)
		maxim.push_back(" " + this->getGearName() + "(+" + std::to_string(this->getItemLevel()) + ")");
	else
		maxim.push_back(" " + this->getGearName());
	maxim.push_back(" " + this->getWeaponClass());
	maxim.push_back(" " + this->getGearType());
	maxim.push_back(" Attack Power: " + std::to_string(this->getAttackPower()));
	if (this->getRequiredStrength() > 0)
		maxim.push_back(" Required strength: " + std::to_string(this->getRequiredStrength()));
	if (this->getRequiredIntelligence() > 0)
		maxim.push_back(" Required intelligence: " + std::to_string(this->getRequiredIntelligence()));
	if (this->getRequiredEndurance() > 0)
		maxim.push_back(" Required endurance: " + std::to_string(this->getRequiredEndurance()));
	maxim.push_back(" " + this->getGearName());
	if (this->getCurrentDurability() > 0 && this->getMaxDurability() > 0)
		maxim.push_back(" Durability: " + std::to_string(this->getCurrentDurability()) + "/" +
			std::to_string(this->getMaxDurability()));
	maxim.push_back(" (" + this->getRarity() + ")");
	if (this->getBonusStat() != nullptr) {
		if (this->getBonusStat()->getAttackPowerBonus() != 0)
			maxim.push_back("Attack Power Bonus: " + std::to_string(this->getBonusStat()->getAttackPowerBonus()));
		if (this->getBonusStat()->getDefenseBonus() != 0)
			maxim.push_back(" Defense bonus: " + std::to_string(this->getBonusStat()->getDefenseBonus()));
		if (this->getBonusStat()->getHealthBonus() != 0)
			maxim.push_back(" Health bonus: " + std::to_string(this->getBonusStat()->getHealthBonus()));
		if (this->getBonusStat()->getManaBonus() != 0)
			maxim.push_back(" Mana bonus: " + std::to_string(this->getBonusStat()->getManaBonus()));
		if (this->getBonusStat()->getStrengthBonus() != 0)
			maxim.push_back(" Strength bonus: " + std::to_string(this->getBonusStat()->getStrengthBonus()));
		if (this->getBonusStat()->getIntelligenceBonus() != 0)
			maxim.push_back(" Intelligence bonus: " + std::to_string(this->getBonusStat()->getIntelligenceBonus()));
		if (this->getBonusStat()->getEnduranceBonus() != 0)
			maxim.push_back(" Endurance bonus: " + std::to_string(this->getBonusStat()->getEnduranceBonus()));
	}

	std::vector<std::string>::iterator& longest = std::max_element(maxim.begin(), maxim.end(), UsefulLibrary::KOLibrary::compare_length);
	std::string longest_line = *longest;

	int size = longest_line.size();
	std::string wall(size + 3, '*');

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
		std::cout << wall << "\n";

	if (this->getItemLevel() > 0) {
		std::string nameWall((size + 1) - (" " + this->getGearName() + "(+" + std::to_string(this->getItemLevel()) + ")").size(), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "* ";
		if (this->ns_getRarity() == NS_GearAttributes::Rarity::UNIQUE_ITEM) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14),
				std::cout << this->getGearName() << "(+" << std::to_string(this->getItemLevel()) << ")";
		}
		else if (this->ns_getRarity() == NS_GearAttributes::Rarity::JURADIN_ITEM) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12),
				std::cout << this->getGearName() << "(+" << std::to_string(this->getItemLevel()) << ")";
		}
		else if(this->ns_getRarity() == NS_GearAttributes::Rarity::HIGH){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9),
				std::cout << this->getGearName() << "(+" << std::to_string(this->getItemLevel()) << ")";
		}
		else if (this->ns_getRarity() == NS_GearAttributes::Rarity::MEDIUM) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2),
				std::cout << this->getGearName() << "(+" << std::to_string(this->getItemLevel()) << ")";
		}
		else if (this->ns_getRarity() == NS_GearAttributes::Rarity::LOW) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8),
				std::cout << this->getGearName() << "(+" << std::to_string(this->getItemLevel()) << ")";
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15),
				std::cout << this->getGearName() << "(+" << std::to_string(this->getItemLevel()) << ")";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << nameWall << "*\n";
	}
	else {
		std::string nameWall((size + 1) - (" " + this->getGearName()).size(), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "* ";
		if (this->ns_getRarity() == NS_GearAttributes::Rarity::UNIQUE_ITEM) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14),
				std::cout << this->getGearName();
		}
		else if (this->ns_getRarity() == NS_GearAttributes::Rarity::JURADIN_ITEM) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12),
				std::cout << this->getGearName();
		}
		else if (this->ns_getRarity() == NS_GearAttributes::Rarity::HIGH) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9),
				std::cout << this->getGearName();
		}
		else if (this->ns_getRarity() == NS_GearAttributes::Rarity::MEDIUM) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2),
				std::cout << this->getGearName();
		}
		else if (this->ns_getRarity() == NS_GearAttributes::Rarity::LOW) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8),
				std::cout << this->getGearName();
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15),
				std::cout << this->getGearName();
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << nameWall << "*\n";
	}
	std::string rarityWall((size + 1) - (" (" + this->getRarity() + ")").size(), ' ');
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
		std::cout << "* ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2),
		std::cout << "(" << this->getRarity() + ")";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
		std::cout << rarityWall << "*\n";

	if (this->g_wep_type != NS_GearAttributes::WeaponType::DAGGER) {
		std::string typeClassWall((size + 1) - (" " + this->getWeaponClass() + " " + this->getGearType()).size(), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3),
			std::cout << this->getWeaponClass() + " " + this->getGearType();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << typeClassWall << "*\n";
		std::string spaceSize((size + 1), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "*" << spaceSize << "*\n";
	}
	else {
		std::string typeClassWall((size + 1) - (" " + this->getGearType()).size(), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3),
			std::cout << this->getGearType();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << typeClassWall << "*\n";
		std::string spaceSize((size + 1), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "*" << spaceSize << "*\n";
	}

	if (this->getAttackPower() > 0) {
		std::string apWall((size + 1) - (" Attack Power: " + std::to_string(this->getAttackPower())).size(), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12),
			std::cout << "Attack Power: " << std::to_string(this->getAttackPower());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << apWall << "*\n";
	}
	if (this->getCurrentDurability() > 0 && this->getMaxDurability() > 0) {
		std::string durWall((size + 1) - (" Durability: " + std::to_string(this->getCurrentDurability()) + "/" +
			std::to_string(this->getMaxDurability())).size(), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14),
			std::cout << "Durability: " << std::to_string(this->getCurrentDurability()) << "/" << std::to_string(this->getMaxDurability());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << durWall << "*\n";
	}

	if (this->getBonusStat() != nullptr) {
		if (this->getBonusStat()->getAttackPowerBonus() != 0) {
			std::string wallAttBon((size + 1) -
				(" Attack Power Bonus: " + std::to_string(this->getBonusStat()->getAttackPowerBonus())).size(), ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << "* ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10),
				std::cout << "Attack Power Bonus: " + std::to_string(this->getBonusStat()->getAttackPowerBonus());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << wallAttBon << "*\n";
		}
		if (this->getBonusStat()->getDefenseBonus() != 0) {
			std::string wallDefBon((size + 1) -
				(" Defense bonus: " + std::to_string(this->getBonusStat()->getDefenseBonus())).size(), ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << "* ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10),
				std::cout << "Defense bonus: " << std::to_string(this->getBonusStat()->getDefenseBonus());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << wallDefBon << "*\n";
		}
		if (this->getBonusStat()->getHealthBonus() != 0) {
			std::string wallHealhBon((size + 1) -
				(" Health bonus: " + std::to_string(this->getBonusStat()->getHealthBonus())).size(), ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << "* ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10),
				std::cout << "Health bonus: " << std::to_string(this->getBonusStat()->getHealthBonus());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << wallHealhBon << "*\n";
		}
		if (this->getBonusStat()->getManaBonus() != 0) {
			std::string wallManaBon((size + 1) -
				(" Mana bonus: " + std::to_string(this->getBonusStat()->getManaBonus())).size(), ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << "* ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10),
				std::cout << "Mana bonus: " << std::to_string(this->getBonusStat()->getManaBonus());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << wallManaBon << "*\n";
		}
		if (this->getBonusStat()->getStrengthBonus() != 0) {
			std::string wallStrBon((size + 1) -
				(" Strength bonus: " + std::to_string(this->getBonusStat()->getStrengthBonus())).size(), ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << "* ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10),
				std::cout << "Strength bonus: " << std::to_string(this->getBonusStat()->getStrengthBonus());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << wallStrBon << "*\n";
		}
		if (this->getBonusStat()->getIntelligenceBonus() != 0) {
			std::string wallIntBon((size + 1) -
				(" Intelligence bonus: " + std::to_string(this->getBonusStat()->getIntelligenceBonus())).size(), ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << "* ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10),
				std::cout << "Intelligence bonus: " << std::to_string(this->getBonusStat()->getIntelligenceBonus());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << wallIntBon << "*\n";
		}
		if (this->getBonusStat()->getEnduranceBonus() != 0) {
			std::string wallEndBon((size + 1) -
				(" Endurance bonus: " + std::to_string(this->getBonusStat()->getEnduranceBonus())).size(), ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << "* ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10),
				std::cout << "Endurance bonus: " << std::to_string(this->getBonusStat()->getEnduranceBonus());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << wallEndBon << "*\n";
		}
	}

	if (this->getRequiredStrength() > 0) {
		std::string strWall((size + 1) - (" Required strength: " + std::to_string(this->getRequiredStrength())).size(), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11),
			std::cout << "Required strength: " << std::to_string(this->getRequiredStrength());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << strWall << "*\n";
	}
	if (this->getRequiredIntelligence() > 0) {
		std::string intWall((size + 1) - (" Required intelligence: " + std::to_string(this->getRequiredIntelligence())).size(), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11),
			std::cout << "Required intelligence: " << std::to_string(this->getRequiredIntelligence());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << intWall << "*\n";
	}
	if (this->getRequiredEndurance() > 0) {
		std::string endWall((size + 1) - (" Required endurance: " + std::to_string(this->getRequiredEndurance())).size(), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11),
			std::cout << "Required endurance: " << std::to_string(this->getRequiredEndurance());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << endWall << "*\n";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
		std::cout << wall << '\n';
}

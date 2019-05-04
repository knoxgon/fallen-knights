#pragma once
#include "Gear.h"

class Weapon : public Gear {
private:
	NS_GearAttributes::WeaponClass g_wep_class;
	std::string weaponClass;
	NS_GearAttributes::WeaponType g_wep_type;
	NS_WeaponNames::Weapon_Name g_wep_name;
	
	int originalAttackPower;
	int attackPower;
public:
	Weapon();
	Weapon(NS_WeaponNames::Weapon_Name g_wep_name,
		NS_GearAttributes::WeaponClass g_wep_class,
		NS_GearAttributes::WeaponType g_wep_type,
		NS_GearAttributes::Rarity g_rarity, int ap = 0,
		int currdur = 0, int maxdur = 0, int reqstr = 0, int reqint = 0, int reqend = 0,
		BonusStats* bonStat = nullptr, int itemLvl = 0);

	bool operator==(const Weapon& rhs);

	~Weapon();

	void setAttackPower(int ap);

	void operateDefenseBonus(int def);

	void operateHealthBonus(int hp);

	void operateManaBonus(int mp);

	void operateStrengthBonus(int str);

	void operateIntelligenceBonus(int intel);

	void operateEnduranceBonus(int end);

	void operateAttackPowerBonus(int ap);

	int getOriginalAttackPower()const;
	int getAttackPower() const;

	void updateAttackPower(int ap);

	std::string getWeaponClass()const;

	void setWeaponName(NS_WeaponNames::Weapon_Name g_wep_name);
	void setWeaponType(NS_GearAttributes::WeaponType g_wep_type);
	void setWeaponClass(NS_GearAttributes::WeaponClass g_wep_class);
	
	NS_WeaponNames::Weapon_Name getGearName_ns() const;

	NS_GearAttributes::WeaponClass getWeaponClass_ns()const;
	NS_GearAttributes::WeaponType getWeaponType_ns()const;
	
	virtual void retrieveGear()const;
};

#include "stdafx.h"
#include "Accessory.h"

Accessory::Accessory(){}
Accessory::~Accessory(){}

bool Accessory::operator==(const Accessory & rhs)
{
	return this->g_accName == rhs.g_accName
		&& this->ns_getRarity() == rhs.ns_getRarity()
		&& this->getItemLevel() == rhs.getItemLevel();
}

Accessory::Accessory(NS_AccessoryNames::Accessory_Name g_accName, NS_GearAttributes::AccessoryType g_accType,
	NS_GearAttributes::Rarity g_rarity, BonusStats* bonStat, int itemLvl)
	: Gear(g_rarity, bonStat, itemLvl)
{
	this->setAccessoryName(g_accName);
	this->setAccessoryType(g_accType);
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

void Accessory::setAccessoryName(NS_AccessoryNames::Accessory_Name g_accName)
{
	this->g_accName = g_accName;
	switch (g_accName)
	{
	case NS_AccessoryNames::Accessory_Name::BOSS_BELT_SKELETON_BELT:
		this->setGearName("Skeleton Belt");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_BELT_GLASS_BELT:
		this->setGearName("Glass Belt");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_BELT_ELF_BELT:
		this->setGearName("Elf Belt");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_BELT_HARPYS_BELT:
		this->setGearName("Harpy's Belt");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_BELT_STRING_OF_SKULLS:
		this->setGearName("String of Skulls");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_BELT_SASH_OF_SORROWS:
		this->setGearName("Sash of Sorrows");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_BELT_KEKURI_BELT:
		this->setGearName("Kekuri Belt");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_BELT_ICE_BELT:
		this->setGearName("Ice Belt");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_BELT_JUDICIOUS_BELT:
		this->setGearName("Judicious Belt");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_PENDANT_AMULET_OF_CURSE:
		this->setGearName("Amulet of Curse");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_PENDANT_CRYSTAL_NECKLACE:
		this->setGearName("Crystal Necklace");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_PENDANT_LYCAON_PENDANT:
		this->setGearName("Lycaon Pendant");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_PENDANT_LOBO_PENDANT:
		this->setGearName("Lobo Pendant");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_PENDANT_LUPUS_PENDANT:
		this->setGearName("Lupus Pendant");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_EARRING_AGATE_EARRING:
		this->setGearName("Agate Earring");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_EARRING_ELF_METAL_EARRING:
		this->setGearName("Elf-Metal Earring");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_EARRING_MINOTAURS_EARRING:
		this->setGearName("Minotaur's Earring");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_EARRING_LILLIMES_EARRING:
		this->setGearName("Lillime's Earring");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_RING_RING_OF_THE_FELANKOR:
		this->setGearName("Ring of the Felankor");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_RING_FOVERING:
		this->setGearName("Ring of Foverin");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_RING_LEGIONNAIRE_BAND:
		this->setGearName("Legionnaire Band");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_RING_ARARAT_RING:
		this->setGearName("Ararat Ring");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_RING_SHIO_TEARS:
		this->setGearName("Shio Tears");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_RING_IMIR_RING:
		this->setGearName("Imir Ring");
		break;
	case NS_AccessoryNames::Accessory_Name::BOSS_RING_HEROS_VALOR:
		this->setGearName("Hero's Valor");
		break;
	}
}
//
//bool Accessory::operator==(const Accessory& rhs){
//	return this->g_accName == rhs.g_accName;
//}

void Accessory::operateDefenseBonus(int def)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setDefenseBonus(def);
	for (int i = 1; i <= 5; i++) {
		if (this->getItemLevel() == i) {
			if (def > 0)
				this->getBonusStat()->setDefenseBonus(def + (((this->getItemLevel() + 5) * 3) + (30 * i)));
			else if (def < 0)
				this->getBonusStat()->setDefenseBonus(def - (((this->getItemLevel() + 5) * 3) + (30 * i)));
		}
	}
}

void Accessory::operateHealthBonus(int hp)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setHealthBonus(hp);
	for (int i = 1; i <= 5; i++) {
		if (this->getItemLevel() == i) {
			if (hp > 0)
				this->getBonusStat()->setHealthBonus(hp + (((this->getItemLevel() + 5) * (this->getItemLevel() + 5) * 3) + (50 * i)));
			else if (hp < 0)
				this->getBonusStat()->setHealthBonus(hp - (((this->getItemLevel() + 5) * (this->getItemLevel() + 5) * 3) + (50 * i)));
		}
	}
}

void Accessory::operateManaBonus(int mp)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setManaBonus(mp);
	for (int i = 1; i <= 5; i++) {
		if (this->getItemLevel() == i) {
			if (mp > 0)
				this->getBonusStat()->setManaBonus(mp + (((this->getItemLevel() + 5) * (this->getItemLevel() + 5) * 3) + (50 * i)));
			else if (mp < 0)
				this->getBonusStat()->setManaBonus(mp - (((this->getItemLevel() + 5) * (this->getItemLevel() + 5) * 3) + (50 * i)));
		}
	}
}

void Accessory::operateStrengthBonus(int str)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setStrengthBonus(str);
	for (int i = 1; i <= 5; i++) {
		if (this->getItemLevel() == i) {
			if (str > 0)
				this->getBonusStat()->setStrengthBonus(str + (((this->getItemLevel() + 5) * (this->getItemLevel() + 1) * 2)));
			else if (str < 0)
				this->getBonusStat()->setStrengthBonus(str - (((this->getItemLevel() + 5) * (this->getItemLevel() + 1) * 2)));
		}
	}
}

void Accessory::operateIntelligenceBonus(int intel)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setIntelligenceBonus(intel);
	for (int i = 1; i <= 5; i++) {
		if (this->getItemLevel() == i) {
			if (intel > 0)
				this->getBonusStat()->setIntelligenceBonus(intel + (((this->getItemLevel() + 5) * (this->getItemLevel() + 1) * 2)));
			else if (intel < 0)
				this->getBonusStat()->setIntelligenceBonus(intel - (((this->getItemLevel() + 5) * (this->getItemLevel() + 1) * 2)));
		}
	}
}

void Accessory::operateEnduranceBonus(int end)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setEnduranceBonus(end);
	for (int i = 1; i <= 5; i++) {
		if (this->getItemLevel() == i) {
			if (end > 0)
				this->getBonusStat()->setEnduranceBonus(end + (((this->getItemLevel() + 5) * (this->getItemLevel() + 1) * 2)));
			else if (end < 0)
				this->getBonusStat()->setEnduranceBonus(end - (((this->getItemLevel() + 5) * (this->getItemLevel() + 1) * 2)));
		}
	}
}

void Accessory::operateAttackPowerBonus(int ap)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setAttackPowerBonus(ap);
	for (int i = 1; i <= 5; i++) {
		if (this->getItemLevel() == i) {
			if (ap > 0)
				this->getBonusStat()->setAttackPowerBonus(ap + (((this->getItemLevel() + 5) * 3) + (30 * i)));
			else if (ap < 0)
				this->getBonusStat()->setAttackPowerBonus(ap - (((this->getItemLevel() + 5) * 3) + (30 * i)));
		}
	}
}

void Accessory::setAccessoryType(NS_GearAttributes::AccessoryType g_accType)
{
	this->g_accType = g_accType;
	switch (g_accType)
	{
	case NS_GearAttributes::AccessoryType::PENDANT:
		this->setGearType("Pendant");
		break;
	case NS_GearAttributes::AccessoryType::EARRING:
		this->setGearType("Earring");
		break;
	case NS_GearAttributes::AccessoryType::RING:
		this->setGearType("Ring");
		break;
	case NS_GearAttributes::AccessoryType::BELT:
		this->setGearType("Belt");
		break;
	}
}

NS_GearAttributes::AccessoryType Accessory::getAccessoryType_ns() const
{
	return this->g_accType;
}

NS_AccessoryNames::Accessory_Name Accessory::getGearName_ns() const
{
	return this->g_accName;
}

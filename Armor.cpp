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

void Armor::setArmorName(NS_ArmorNames::Armor_Name g_armorName)
{
	switch (g_armorName)
	{
	case NS_ArmorNames::Armor_Name::FULL_PLATE_ARMOR_HELMET:
		this->setGearName("Full-Plate Helmet");
		break;
	case NS_ArmorNames::Armor_Name::FULL_PLATE_ARMOR_PAULDRON:
		this->setGearName("Full-Plate Pauldron");
		break;
	case NS_ArmorNames::Armor_Name::FULL_PLATE_ARMOR_PADS:
		this->setGearName("Full-Plate Pads");
		break;
	case NS_ArmorNames::Armor_Name::FULL_PLATE_ARMOR_GAUNTLETS:
		this->setGearName("Full-Plate Gauntlets");
		break;
	case NS_ArmorNames::Armor_Name::FULL_PLATE_ARMOR_BOOTS:
		this->setGearName("Full-Plate Boots");
		break;
	case NS_ArmorNames::Armor_Name::TAILOR_ARMOR_HELMET:
		this->setGearName("Tailor Helmet");
		break;
	case NS_ArmorNames::Armor_Name::TAILOR_ARMOR_PAULDRON:
		this->setGearName("Tailor Pauldron");
		break;
	case NS_ArmorNames::Armor_Name::TAILOR_ARMOR_PADS:
		this->setGearName("Tailor Pads");
		break;
	case NS_ArmorNames::Armor_Name::TAILOR_ARMOR_GAUNTLETS:
		this->setGearName("Tailor Gauntlets");
		break;
	case NS_ArmorNames::Armor_Name::TAILOR_ARMOR_BOOTS:
		this->setGearName("Tailor Boots");
		break;
	case NS_ArmorNames::Armor_Name::CHITIN_HELMET:
		this->setGearName("Chitin Armor Helmet");
		break;
	case NS_ArmorNames::Armor_Name::CHITIN_PAULDRON:
		this->setGearName("Chitin Armor Pauldron");
		break;
	case NS_ArmorNames::Armor_Name::CHITIN_PADS:
		this->setGearName("Chitin Armor Pads");
		break;
	case NS_ArmorNames::Armor_Name::CHITIN_GAUNTLETS:
		this->setGearName("Chitin Armor Gauntlets");
		break;
	case NS_ArmorNames::Armor_Name::CHITIN_BOOTS:
		this->setGearName("Chitin Armor Boots");
		break;
	case NS_ArmorNames::Armor_Name::CHITIN_SHELL_HELMET:
		this->setGearName("Chitin Shell Armor Helmet");
		break;
	case NS_ArmorNames::Armor_Name::CHITIN_SHELL_PAULDRON:
		this->setGearName("Chitin Shell Armor Pauldron");
		break;
	case NS_ArmorNames::Armor_Name::CHITIN_SHELL_PADS:
		this->setGearName("Chitin Shell Armor Pads");
		break;
	case NS_ArmorNames::Armor_Name::CHITIN_SHELL_GAUNTLETS:
		this->setGearName("Chitin Shell Armor Gauntlets");
		break;
	case NS_ArmorNames::Armor_Name::CHITIN_SHELL_BOOTS:
		this->setGearName("Chitin Shell Armor Boots");
		break;
	case NS_ArmorNames::Armor_Name::RARE_ARMOR_JURADINS_RAGE_HELMET:
		this->setGearName("Juradin's Rage Helmet");
		break;
	case NS_ArmorNames::Armor_Name::RARE_ARMOR_JURADINS_RAGE_PAULDRON:
		this->setGearName("Juradin's Rage Pauldron");
		break;
	case NS_ArmorNames::Armor_Name::RARE_ARMOR_JURADINS_RAGE_PADS:
		this->setGearName("Juradin's Rage Pads");
		break;
	case NS_ArmorNames::Armor_Name::RARE_ARMOR_JURADINS_RAGE_GAUNTLETS:
		this->setGearName("Juradin's Rage Gauntlets");
		break;
	case NS_ArmorNames::Armor_Name::RARE_ARMOR_JURADINS_RAGE_BOOTS:
		this->setGearName("Juradin's Rage Boots");
		break;
	case NS_ArmorNames::Armor_Name::RARE_ARMOR_KROWAZ_HELMET:
		this->setGearName("Krowaz Helmet");
		break;
	case NS_ArmorNames::Armor_Name::RARE_ARMOR_KROWAZ_PAULDRON:
		this->setGearName("Krowaz Pauldron");
		break;
	case NS_ArmorNames::Armor_Name::RARE_ARMOR_KROWAZ_PADS:
		this->setGearName("Krowaz Pads");
		break;
	case NS_ArmorNames::Armor_Name::RARE_ARMOR_KROWAZ_GAUNTLETS:
		this->setGearName("Krowaz Gauntlets");
		break;
	case NS_ArmorNames::Armor_Name::RARE_ARMOR_KROWAZ_BOOTS:
		this->setGearName("Krowaz Boots");
		break;
	case NS_ArmorNames::Armor_Name::RARE_SHIELD_JURADINS_DEFENDER:
		this->setGearName("Juradin's Defender");
		break;
	case NS_ArmorNames::Armor_Name::RARE_SHIELD_DREAD_SHIELD:
		this->setGearName("Dread Shield");
		break;
	case NS_ArmorNames::Armor_Name::RARE_SHIELD_DEFENDER_OF_THE_LORD:
		this->setGearName("Defender of The Lord");
		break;
	case NS_ArmorNames::Armor_Name::RARE_SHIELD_CHITIN_SHIELD:
		this->setGearName("Chitin Shield");
		break;
	case NS_ArmorNames::Armor_Name::RARE_SHIELD_GABS_BLESSING:
		this->setGearName("Gab's Blessing");
		break;
	case NS_ArmorNames::Armor_Name::RARE_SHIELD_SCORPION_SHIELD:
		this->setGearName("Scorpion Shield");
		break;
	case NS_ArmorNames::Armor_Name::SHIELD_PLATE_SHIELD:
		this->setGearName("Plate Shield");
		break;
	case NS_ArmorNames::Armor_Name::SHIELD_OCTAGON_SHIELD:
		this->setGearName("Octagon Shield");
		break;
	case NS_ArmorNames::Armor_Name::SHIELD_WOODEN_SHIELD:
		this->setGearName("Wooden Shield");
		break;
	}
	this->g_armorName = g_armorName;
}

bool Armor::operator==(const Armor& rhs) {
	return this->g_armorName == rhs.g_armorName;
}

void Armor::setArmorType(NS_GearAttributes::ArmorType g_armorType)
{
	this->g_armorType = g_armorType;
	switch (g_armorType)
	{
	case NS_GearAttributes::ArmorType::HELMET:
		this->setGearType("Helmet");
		break;
	case NS_GearAttributes::ArmorType::PAULDRON:
		this->setGearType("Pauldron");
		break;
	case NS_GearAttributes::ArmorType::PADS:
		this->setGearType("Pad");
		break;
	case NS_GearAttributes::ArmorType::GAUNTLETS:
		this->setGearType("Gauntlet");
		break;
	case NS_GearAttributes::ArmorType::BOOTS:
		this->setGearType("Boot");
		break;
	case NS_GearAttributes::ArmorType::SHIELD:
		this->setGearType("Shield");
		break;
	}
}

void Armor::setDefense(int def)
{
	if (this->getItemLevel() >= 0 && this->getItemLevel() <= 5)
		this->defense = def + (this->getItemLevel() * 3);
	if (this->getItemLevel() == 6)
		this->defense = def + (this->getItemLevel() * 4);
	if (this->getItemLevel() == 7)
		this->defense = def + (this->getItemLevel() * 5);
	if (this->getItemLevel() == 8)
		this->defense = def + (this->getItemLevel() * 6);
	if (this->getItemLevel() == 9)
		this->defense = def + (this->getItemLevel() * 7);
	if (this->getItemLevel() == 10)
		this->defense = def + (this->getItemLevel() * 8);
}

void Armor::operateDefenseBonus(int def)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setDefenseBonus(def);
	if (this->getItemLevel() == 8) {
		if (def > 0)
			this->getBonusStat()->setDefenseBonus(def + ((this->getItemLevel() * 2) + 30));
		else if (def < 0)
			this->getBonusStat()->setDefenseBonus(def - ((this->getItemLevel() * 2) + 30));
	}
	if (this->getItemLevel() == 9) {
		if (def > 0)
			this->getBonusStat()->setDefenseBonus(def + ((this->getItemLevel() * 2) + 40));
		else if (def < 0)
			this->getBonusStat()->setDefenseBonus(def - ((this->getItemLevel() * 2) + 40));
	}
	if (this->getItemLevel() == 10) {
		if (def > 0)
			this->getBonusStat()->setDefenseBonus(def + ((this->getItemLevel() * 2) + 50));
		else if (def < 0)
			this->getBonusStat()->setDefenseBonus(def - ((this->getItemLevel() * 2) + 50));
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (def > 0)
					this->getBonusStat()->setDefenseBonus(def + ((i * 2) + 20));
				else if (def < 0)
					this->getBonusStat()->setDefenseBonus(def - ((i * 2) + 20));
			}
		}
	}
}

void Armor::operateHealthBonus(int hp)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setHealthBonus(hp);
	if (this->getItemLevel() == 8) {
		if (hp > 0)
			this->getBonusStat()->setHealthBonus(hp + ((this->getItemLevel() * this->getItemLevel()) + 75));
		else if (hp < 0)
			this->getBonusStat()->setHealthBonus(hp - ((this->getItemLevel() * this->getItemLevel()) + 75));
	}
	if (this->getItemLevel() == 9) {
		if (hp > 0)
			this->getBonusStat()->setHealthBonus(hp + ((this->getItemLevel() * this->getItemLevel()) + 175));
		else if (hp < 0)
			this->getBonusStat()->setHealthBonus(hp - ((this->getItemLevel() * this->getItemLevel()) + 175));
	}
	if (this->getItemLevel() == 10) {
		if (hp > 0)
			this->getBonusStat()->setHealthBonus(hp + ((this->getItemLevel() * this->getItemLevel()) + 325));
		else if (hp < 0)
			this->getBonusStat()->setHealthBonus(hp - ((this->getItemLevel() * this->getItemLevel()) + 325));
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (hp > 0)
					this->getBonusStat()->setHealthBonus(hp + ((this->getItemLevel() * this->getItemLevel()) + 50));
				else if (hp < 0)
					this->getBonusStat()->setHealthBonus(hp - ((this->getItemLevel() * this->getItemLevel()) + 50));
			}
		}
	}
}

void Armor::operateManaBonus(int mp)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setManaBonus(mp);
	if (this->getItemLevel() == 8) {
		if (mp > 0)
			this->getBonusStat()->setManaBonus(mp + ((this->getItemLevel() * this->getItemLevel()) + 75));
		else if (mp < 0)
			this->getBonusStat()->setManaBonus(mp - ((this->getItemLevel() * this->getItemLevel()) + 75));
	}
	if (this->getItemLevel() == 9) {
		if (mp > 0)
			this->getBonusStat()->setManaBonus(mp + ((this->getItemLevel() * this->getItemLevel()) + 175));
		else if (mp < 0)
			this->getBonusStat()->setManaBonus(mp - ((this->getItemLevel() * this->getItemLevel()) + 175));
	}
	if (this->getItemLevel() == 10) {
		if (mp > 0)
			this->getBonusStat()->setManaBonus(mp + ((this->getItemLevel() * this->getItemLevel()) + 325));
		else if (mp < 0)
			this->getBonusStat()->setManaBonus(mp - ((this->getItemLevel() * this->getItemLevel()) + 325));
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (mp > 0)
					this->getBonusStat()->setManaBonus(mp + ((this->getItemLevel() * this->getItemLevel()) + 50));
				else if (mp < 0)
					this->getBonusStat()->setManaBonus(mp - ((this->getItemLevel() * this->getItemLevel()) + 50));
			}
		}
	}
}

void Armor::operateStrengthBonus(int str)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setStrengthBonus(str);
	if (this->getItemLevel() == 8) {
		if (str > 0)
			this->getBonusStat()->setStrengthBonus(str + ((this->getItemLevel() * (this->getItemLevel())) + 10));
		else if (str < 0)
			this->getBonusStat()->setStrengthBonus(str - ((this->getItemLevel() * (this->getItemLevel())) + 10));
	}
	if (this->getItemLevel() == 9) {
		if (str > 0)
			this->getBonusStat()->setStrengthBonus(str + ((this->getItemLevel() * (this->getItemLevel())) + 20));
		else if (str < 0)
			this->getBonusStat()->setStrengthBonus(str - ((this->getItemLevel() * (this->getItemLevel())) + 20));
	}
	if (this->getItemLevel() == 10) {
		if (str > 0)
			this->getBonusStat()->setStrengthBonus(str + ((this->getItemLevel() * (this->getItemLevel())) + 50));
		else if (str < 0)
			this->getBonusStat()->setStrengthBonus(str - ((this->getItemLevel() * (this->getItemLevel())) + 50));
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (str > 0)
					this->getBonusStat()->setStrengthBonus(str + (((this->getItemLevel() + (this->getItemLevel())) + i) + 5));
				else if (str < 0)
					this->getBonusStat()->setStrengthBonus(str - (((this->getItemLevel() + (this->getItemLevel())) + i) + 5));
			}
		}
	}
}

void Armor::operateIntelligenceBonus(int intel)
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

void Armor::operateEnduranceBonus(int end)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setEnduranceBonus(end);
	if (this->getItemLevel() == 8) {
		if (end > 0)
			this->getBonusStat()->setEnduranceBonus(end + ((this->getItemLevel() * (this->getItemLevel())) + 30));
		else if (end < 0)
			this->getBonusStat()->setEnduranceBonus(end - ((this->getItemLevel() * (this->getItemLevel())) + 30));
	}
	if (this->getItemLevel() == 9) {
		if (end > 0)
			this->getBonusStat()->setEnduranceBonus(end + ((this->getItemLevel() * (this->getItemLevel())) + 50));
		else if (end < 0)
			this->getBonusStat()->setEnduranceBonus(end - ((this->getItemLevel() * (this->getItemLevel())) + 50));
	}
	if (this->getItemLevel() == 10) {
		if (end > 0)
			this->getBonusStat()->setEnduranceBonus(end + ((this->getItemLevel() * (this->getItemLevel())) + 100));
		else if (end < 0)
			this->getBonusStat()->setEnduranceBonus(end - ((this->getItemLevel() * (this->getItemLevel())) + 100));
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (end > 0)
					this->getBonusStat()->setEnduranceBonus(end + (((this->getItemLevel() + (this->getItemLevel())) + i) + 15));
				else if (end < 0)
					this->getBonusStat()->setEnduranceBonus(end - (((this->getItemLevel() + (this->getItemLevel())) + i) + 15));
			}
		}
	}
}

void Armor::operateAttackPowerBonus(int ap)
{
	if (this->getItemLevel() == 0)
		this->getBonusStat()->setAttackPowerBonus(ap);
	if (this->getItemLevel() == 8) {
		if (ap > 0)
			this->getBonusStat()->setAttackPowerBonus(ap + ((this->getItemLevel() * 2) + 10));
		else if (ap < 0)
			this->getBonusStat()->setAttackPowerBonus(ap - ((this->getItemLevel() * 2) + 10));
	}
	if (this->getItemLevel() == 9) {
		if (ap > 0)
			this->getBonusStat()->setAttackPowerBonus(ap + ((this->getItemLevel() * 2) + 20));
		else if (ap < 0)
			this->getBonusStat()->setAttackPowerBonus(ap - ((this->getItemLevel() * 2) + 20));
	}
	if (this->getItemLevel() == 10) {
		if (ap > 0)
			this->getBonusStat()->setAttackPowerBonus(ap + ((this->getItemLevel() * 2) + 25));
		else if (ap < 0)
			this->getBonusStat()->setAttackPowerBonus(ap - ((this->getItemLevel() * 2) + 25));
	}
	if (this->getItemLevel() >= 1 && this->getItemLevel() <= 7) {
		for (int i = 1; i <= 7; i++) {
			if (this->getItemLevel() == i) {
				if (ap > 0)
					this->getBonusStat()->setAttackPowerBonus(ap + ((i * 2) + 5));
				else if (ap < 0)
					this->getBonusStat()->setAttackPowerBonus(ap - ((i * 2) + 5));
			}
		}
	}
}

int Armor::getDefense() const
{
	return this->defense;
}

int Armor::getOriginalDefense() const
{
	return this->originalDefense;
}

NS_ArmorNames::Armor_Name Armor::getGearName_ns() const
{
	return this->g_armorName;
}

NS_GearAttributes::ArmorType Armor::getArmorType_ns() const
{
	return this->g_armorType;
}

void Armor::updateDefense(int def)
{
	this->defense += def;
}

void Armor::retrieveGear() const
{
	std::vector<std::string> maxim;
	if (this->getItemLevel() > 0)
		maxim.push_back(" " + this->getGearName() + "(+" + std::to_string(this->getItemLevel()) + ")");
	else
		maxim.push_back(" " + this->getGearName());
	if (this->getDefense() != 0)
		maxim.push_back(" Defense: " + std::to_string(this->getDefense()));
	if (this->getRequiredStrength() != 0)
		maxim.push_back(" Required strength: " + std::to_string(this->getRequiredStrength()));
	if (this->getRequiredIntelligence() != 0)
		maxim.push_back(" Required intelligence: " + std::to_string(this->getRequiredIntelligence()));
	if (this->getRequiredEndurance() != 0)
		maxim.push_back(" Required endurance: " + std::to_string(this->getRequiredEndurance()));
	if (!this->getGearType().empty())
		maxim.push_back(" " + this->getGearType());
	if (this->getCurrentDurability() > 0 && this->getMaxDurability() > 0)
		maxim.push_back(" Durability: " + std::to_string(this->getCurrentDurability()) + "/" +
			std::to_string(this->getMaxDurability()));
	if (!this->getRarity().empty())
		maxim.push_back(" (" + this->getRarity() + ")");
	if (this->getBonusStat() != nullptr) {
		if (this->getBonusStat()->getAttackPowerBonus() != 0)
			maxim.push_back(" Attack Power Bonus: " + std::to_string(this->getBonusStat()->getAttackPowerBonus()));
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
		else if (this->ns_getRarity() == NS_GearAttributes::Rarity::HIGH) {
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
		std::cout << "* ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2),
		std::cout << "(" << this->getRarity() << ")";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
		std::cout << rarityWall << "*\n";


	std::string typeWall((size + 1) - (" " + this->getGearType()).size(), ' ');
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
		std::cout << "* ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3),
		std::cout << this->getGearType();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
		std::cout << typeWall << "*\n";

	std::string spaceSize((size + 1), ' ');
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
		std::cout << "*" << spaceSize << "*\n";

	if (this->getDefense() > 0) {
		std::string defWall((size + 1) - (" Defense: " + std::to_string(this->getDefense())).size(), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12),
			std::cout << "Defense: " << std::to_string(this->getDefense());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << defWall << "*\n";
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
				std::cout << "Attack Power Bonus: " << std::to_string(this->getBonusStat()->getAttackPowerBonus());
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

	if (this->getRequiredStrength() != 0) {
		std::string strWall((size + 1) - (" Required strength: " + std::to_string(this->getRequiredStrength())).size(), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11),
			std::cout << "Required strength: " << std::to_string(this->getRequiredStrength());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << strWall << "*\n";
	}
	if (this->getRequiredIntelligence() != 0) {
		std::string intWall((size + 1) - (" Required intelligence: " + std::to_string(this->getRequiredIntelligence())).size(), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11),
			std::cout << "Required intelligence: " << std::to_string(this->getRequiredIntelligence());
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
			std::cout << intWall << "*\n";
	}
	if (this->getRequiredEndurance() != 0) {
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

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

void Accessory::retrieveGear() const
{
	std::vector<std::string> maxim;
	if (this->getItemLevel() > 0)
		maxim.push_back(" " + this->getGearName() + "(+" + std::to_string(this->getItemLevel()) + ")");
	else
		maxim.push_back(" " + this->getGearName());
	if (!this->getGearType().empty())
		maxim.push_back(" " + this->getGearType());
	if (!this->getRarity().empty())
		maxim.push_back(" (" + this->getRarity() + ")");
	if (this->getBonusStat() != nullptr) {
		if (this->getBonusStat()->getAttackPowerBonus() != 0)
			maxim.push_back(" Player's Attack Bonus: " + std::to_string(this->getBonusStat()->getAttackPowerBonus()) + "%");
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

	if (this->getBonusStat() != nullptr) {
		if (this->getBonusStat()->getAttackPowerBonus() != 0) {
			std::string wallAttBon((size + 1) -
				(" Player's Attack Bonus: " + std::to_string(this->getBonusStat()->getAttackPowerBonus()) + "%").size(), ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
				std::cout << "* ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10),
				std::cout << "Player's Attack Bonus: " + std::to_string(this->getBonusStat()->getAttackPowerBonus()) + "%";
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7),
		std::cout << wall << '\n';
}

#include "stdafx.h"
#include "Gear.h"

Gear::Gear(){
	this->originalDurability = 0;
	this->originalMaxDurability = 0;
	this->originalRequiredStrength = 0;
	this->originalRequiredIntelligence = 0;
	this->originalRequiredEndurance = 0;
}

Gear::~Gear(){
	if (this->bonStats != nullptr)
		delete this->bonStats;
}

BonusStats * Gear::getBonusStat() const
{
	return this->bonStats;
}

Gear::Gear(NS_GearAttributes::Rarity g_rarity, BonusStats * bonStats, int itemLvl, 
	int currdur, int maxdur, int reqstr, int reqint, int reqend)
	: itemLevel(itemLvl), bonStats(bonStats)
{
	this->setRarity(g_rarity);
	
	this->originalDurability = currdur;
	this->setCurrentDurability(currdur);

	this->originalMaxDurability = maxdur;
	this->setMaxDurability(maxdur);
	
	this->originalRequiredStrength =reqstr;
	this->setRequiredStrength(reqstr);

	this->originalRequiredIntelligence = reqint;
	this->setRequiredIntelligence(reqint);

	this->originalRequiredEndurance = reqend;
	this->setRequiredEndurance(reqend);
}

void Gear::setRarity(NS_GearAttributes::Rarity g_rarity)
{
	switch (g_rarity)
	{
	case NS_GearAttributes::Rarity::LOW:
			this->rarity = "Low Upgrade Item";
			break;
		case NS_GearAttributes::Rarity::MEDIUM:
			this->rarity = "Medium Upgrade Item";
			break;
		case NS_GearAttributes::Rarity::HIGH:
			this->rarity = "High Upgrade Item";
			break;
		case NS_GearAttributes::Rarity::UNIQUE_ITEM:
			this->rarity = "Unique Item";
			break;
		case NS_GearAttributes::Rarity::JURADIN_ITEM:
			this->rarity = "Juradin Item";
			break;
		case NS_GearAttributes::Rarity::PREMIUM_ITEM:
			this->rarity = "Premium Item";
			break;
	}
	this->g_rarity = g_rarity;
}

void Gear::setItemLevel(int itemLevel)
{
	this->itemLevel = itemLevel;
}

void Gear::setCurrentDurability(int dur)
{
	this->currentDurability = dur + (this->getItemLevel() * 500);
}

void Gear::setMaxDurability(int dur)
{
	this->maxDurability = dur + (this->getItemLevel() * 500);
}

void Gear::setRequiredStrength(int str)
{
	if (str > 0) {
		if (this->getItemLevel() == 0)
			this->requiredStrength = str;
		else {
			for (int i = 1; i <= 10; i++)
				if (this->getItemLevel() == i) {
					this->requiredStrength = str + (this->getItemLevel() * 2);
				}
		}
	}
	else if (str == 0)
		this->requiredStrength = str;
}

void Gear::setRequiredIntelligence(int intel)
{
	if (intel > 0) {
		if (this->getItemLevel() == 0)
			this->requiredIntelligence = intel;
		else
			for (int i = 1; i <= 10; i++)
				if (this->getItemLevel() == i)
					this->requiredIntelligence = intel + (this->getItemLevel() * 2);
	}
	else if (intel == 0)
		this->requiredIntelligence = intel;
}

void Gear::setRequiredEndurance(int end)
{
	if (end > 0) {
		if (this->getItemLevel() == 0)
			this->requiredEndurance = end;
		else
			for (int i = 1; i <= 10; i++)
				if (this->getItemLevel() == i)
					this->requiredEndurance = end + (this->getItemLevel() * 2);
	}
	else if (end == 0)
		this->requiredEndurance = end;
}

void Gear::updateItemLevel(int itemLevel)
{
	this->itemLevel += itemLevel;
}

void Gear::updateCurrentDurability(int volym)
{
	if (volym + this->getCurrentDurability() > this->getMaxDurability())
		this->currentDurability = this->getMaxDurability();
	else if (volym < 0) {
	}
	else
		this->currentDurability += volym;
}

void Gear::updateMaxDurability(int volym)
{
	this->maxDurability += volym;
}

void Gear::updateRequiredStrength(int str)
{
	this->requiredStrength += str;
}

void Gear::updateRequiredIntelligence(int intel)
{
	this->requiredIntelligence += intel;
}

void Gear::updateRequiredEndurance(int end)
{
	this->requiredEndurance += end;
}

std::string Gear::getRarity() const
{
	return this->rarity;
}

NS_GearAttributes::Rarity Gear::ns_getRarity() const
{
	return this->g_rarity;
}

void Gear::setGearName(std::string gearName)
{
	this->gearName = gearName;
}

std::string Gear::getGearName() const
{
	return this->gearName;
}

void Gear::setGearType(std::string gearType)
{
	this->gearType = gearType;
}

std::string Gear::getGearType() const
{
	return this->gearType;
}

int Gear::getItemLevel() const
{
	return this->itemLevel;
}

int Gear::getCurrentDurability() const
{
	return this->currentDurability;
}

int Gear::getMaxDurability() const
{
	return this->maxDurability;
}

int Gear::getOriginalCurrentDurability() const
{
	return this->originalDurability;
}

int Gear::getOriginalMaxDurability() const
{
	return this->originalMaxDurability;
}

int Gear::getRequiredStrength() const
{
	return this->requiredStrength;
}

int Gear::getRequiredIntelligence() const
{
	return this->requiredIntelligence;
}

int Gear::getRequiredEndurance() const
{
	return this->requiredEndurance;
}

int Gear::getOriginalRequiredStrength() const
{
	return this->originalRequiredStrength;
}

int Gear::getOriginalRequiredIntelligence() const
{
	return this->originalRequiredIntelligence;
}

int Gear::getOriginalRequiredEndurance() const
{
	return this->originalRequiredEndurance;
}

std::string Gear::displaySimple() const
{
	if (this->getItemLevel() > 0)
		return this->getGearName() + "(+" + std::to_string(this->getItemLevel()) + ")";
	else
		return this->getGearName();
}

void Gear::retrieveGear() const
{
}

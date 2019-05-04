#include "stdafx.h"
#include "UserStats.h"

UserStats::UserStats()
	: BaseStats(), manaPoint(0), maxManaPoint(0), strength(0), intelligence(0), endurance(0)
{
}

UserStats::~UserStats()
{
}

UserStats::UserStats(int attackPower, int defendPower, int healthPoint, int maxHP, int manaPoint, int maxMP,
	int strength, int intelligence, int endurance)
	: BaseStats(attackPower, defendPower, healthPoint, maxHP)
{
	this->setManaPoint(manaPoint);
	this->setMaxManaPoint(maxMP);
	this->setStrength(strength);
	this->setIntelligence(intelligence);
	this->setEndurance(endurance);
}

void UserStats::setStrength(int str)
{
	if ((!(str > 255) && (str < SHRT_MAX) && (str > 0)))
		this->strength = str;
	else
		throw std::string("Bad strength value");
}

void UserStats::setIntelligence(int intel)
{
	if ((!(intel > 255) && (intel < SHRT_MAX) && (intel > 0)))
		this->intelligence = intel;
	else
		throw std::string("Bad intelligence value");
}

void UserStats::setEndurance(int endur)
{
	if ((!(endur > 255) && (endur < SHRT_MAX) && (endur > 0)))
		this->endurance = endur;
	else
		throw std::string("Bad endurance value");
}

void UserStats::setManaPoint(int mp)
{
	UsefulLibrary::KOLibrary::charestic_betweenRanges(mp, this->manaPoint, 30000, "Bad MP value");
}

void UserStats::setMaxManaPoint(int maxmp)
{
	UsefulLibrary::KOLibrary::charestic_betweenRanges(maxmp, this->maxManaPoint, 30000, "Bad MaxMP value");
}

int UserStats::getManaPoint() const
{
	return this->manaPoint;
}

int UserStats::getMaxManaPoint() const
{
	return this->maxManaPoint;
}

void UserStats::updateManaPoint(int manavalue)
{
	if ((!(this->getManaPoint() + manavalue > 30000) && (manavalue < SHRT_MAX) && (manavalue > 0)))
		this->manaPoint += manavalue;
	else
		throw std::string("Error updating MP");
}

void UserStats::updateMaxManaPoint(int maxmanavalue)
{
	if ((!(this->getMaxManaPoint() + maxmanavalue > 30000) && (maxmanavalue < SHRT_MAX) && (maxmanavalue > 0)))
		this->maxManaPoint += maxmanavalue;
	else
		throw std::string("Error updating MaxMP");
}

int UserStats::getStrength() const
{
	return this->strength;
}

int UserStats::getIntelligence() const
{
	return this->intelligence;
}

int UserStats::getEndurance() const
{
	return this->endurance;
}

void UserStats::updateStrength(int strvalue)
{
	if ((!(this->getStrength() + strvalue > 255) && (strvalue < SHRT_MAX) && (strvalue > 0)))
		this->strength += strvalue;
	else
		throw std::string("Error updating strength");
}

void UserStats::updateIntelligence(int intvalue)
{
	if ((!(this->getIntelligence() + intvalue > 255) && (intvalue < SHRT_MAX) && (intvalue > 0)))
		this->intelligence += intvalue;
	else
		throw std::string("Error updating intelligence");
}

void UserStats::updateEndurance(int endvalue)
{
	if ((!(this->getEndurance() + endvalue > 255) && (endvalue < SHRT_MAX) && (endvalue > 0)))
		this->endurance += endvalue;
	else
		throw std::string("Error updating endurance");
}

std::string UserStats::toString() const
{
	return
		BaseStats::toString() +
		"Mana: " + std::to_string(this->getManaPoint()) + "/" + std::to_string(this->getMaxManaPoint()) + "\n" +
		"Str: " + std::to_string(this->getStrength()) + "\n" +
		"Int: " + std::to_string(this->getIntelligence()) + "\n" +
		"End: " + std::to_string(this->getEndurance()) + "\n";
}
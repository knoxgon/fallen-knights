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

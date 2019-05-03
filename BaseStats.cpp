#include "stdafx.h"
#include "BaseStats.h"

BaseStats::BaseStats()
	: attackPower(0), defendPower(0), healthPoint(0), maxHealthPoint(0) {}
BaseStats::~BaseStats() {}

BaseStats::BaseStats(int attackPower, int defendPower, int healthPoint, int maxHP)
{
	this->setAttackPower(attackPower);
	this->setDefendPower(defendPower);
	this->setHealthPoint(healthPoint);
	this->setMaxHealthPoint(maxHP);
}

void BaseStats::setHealthPoint(int hp)
{
	UsefulLibrary::KOLibrary::u_charestic_betweenRanges(hp, this->healthPoint, 50000, "Bad HP value");
}

void BaseStats::setMaxHealthPoint(int maxhp)
{
	UsefulLibrary::KOLibrary::u_charestic_betweenRanges(maxhp, this->maxHealthPoint, 50000, "Bad MaxHP value");
}

void BaseStats::setAttackPower(int ap)
{
	UsefulLibrary::KOLibrary::charestic_betweenRanges(ap, this->attackPower, 10000, "Bad AP value");
}

void BaseStats::setDefendPower(int dp)
{
	UsefulLibrary::KOLibrary::charestic_betweenRanges(dp, this->defendPower, 10000, "Bad DP value");
}

int BaseStats::getHealthPoint() const
{
	return this->healthPoint;
}

int BaseStats::getMaxHealthPoint() const
{
	return this->maxHealthPoint;
}

int BaseStats::getAttackPower() const
{
	return this->attackPower;
}

int BaseStats::getDefendPower() const
{
	return this->defendPower;
}

void BaseStats::updateHealthPoint(int hpvalue)
{
	if ((!(this->getHealthPoint() + hpvalue > 50000) && (hpvalue < USHRT_MAX) && (hpvalue > 0)))
		this->healthPoint += hpvalue;
	else
		throw std::string("Error updating HP");
}

void BaseStats::updateMaxHealthPoint(int maxhpvalue)
{
	if ((!(this->getMaxHealthPoint() + maxhpvalue > 50000) && (maxhpvalue < USHRT_MAX) && (maxhpvalue > 0)))
		this->maxHealthPoint += maxhpvalue;
	else
		throw std::string("Error updating MaxHP");
}

void BaseStats::updateAttackPower(int attpower)
{
	if ((!(this->getAttackPower() + attpower > 10000) && (attpower < SHRT_MAX) && (attpower > 0)))
		this->attackPower += attpower;
	else
		throw std::string("Error updating AP");
}

void BaseStats::updateDefendPower(int defpower)
{
	if ((!(this->getDefendPower() + defpower > 10000) && (defpower < SHRT_MAX) && (defpower > 0)))
		this->defendPower += defpower;
	else
		throw std::string("Error updating DP");
}

std::string BaseStats::toString() const
{
	return "Health: " + std::to_string(this->getHealthPoint()) + "/" + std::to_string(this->getMaxHealthPoint()) + "\n" +
		"Attack: " + std::to_string(this->getAttackPower()) + "\n" +
		"Defend: " + std::to_string(this->getDefendPower()) + "\n";
}

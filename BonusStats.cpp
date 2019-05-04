#include "stdafx.h"
#include "BonusStats.h"

BonusStats::BonusStats(){
	this->originalDefenseBonus = 0;
	this->defenseBonus = 0;
	this->originalHealthBonus = 0;
	this->healthBonus = 0;
	this->originalManaBonus = 0;
	this->manaBonus = 0;
	this->originalStrengthBonus = 0;
	this->strengthBonus = 0;
	this->originalIntelligenceBonus = 0;
	this->intelligenceBonus = 0;
	this->originalEnduranceBonus = 0;
	this->enduranceBonus = 0;
	this->originalAttackPowerBonus = 0;
	this->attackPowerBonus = 0;
}

BonusStats::BonusStats(int defBonus, int hpBonus, int manaBonus, int strBonus, int intelBonus, int endBonus, int apBonus)
	: defenseBonus(defBonus), healthBonus(hpBonus), manaBonus(manaBonus), 
	strengthBonus(strBonus), intelligenceBonus(intelBonus), enduranceBonus(endBonus),
	attackPowerBonus(apBonus)
{
	this->originalDefenseBonus = defBonus;
	this->originalHealthBonus = hpBonus;
	this->originalManaBonus = manaBonus;
	this->originalStrengthBonus = strBonus;
	this->originalIntelligenceBonus = intelBonus;
	this->originalEnduranceBonus = endBonus;
	this->originalAttackPowerBonus = apBonus;
}

BonusStats::~BonusStats(){}

BonusStats & BonusStats::operator=(BonusStats & other)
{
	if (this != &other) {
		std::swap(this->defenseBonus, other.defenseBonus);
		std::swap(this->healthBonus, other.healthBonus);
		std::swap(this->manaBonus, other.manaBonus);
		std::swap(this->strengthBonus, other.strengthBonus);
		std::swap(this->intelligenceBonus, other.intelligenceBonus);
		std::swap(this->enduranceBonus, other.enduranceBonus);
		std::swap(this->attackPowerBonus, other.attackPowerBonus);
	}
	return *this;
}

void BonusStats::setDefenseBonus(int def)
{
	this->defenseBonus = def;
}

void BonusStats::setHealthBonus(int hp)
{
	this->healthBonus = hp;
}

void BonusStats::setManaBonus(int mp)
{
	this->manaBonus = mp;
}

void BonusStats::setStrengthBonus(int str)
{
	this->strengthBonus = str;
}

void BonusStats::setIntelligenceBonus(int intel)
{
	this->intelligenceBonus = intel;
}

void BonusStats::setEnduranceBonus(int end)
{
	this->enduranceBonus = end;
}

void BonusStats::setAttackPowerBonus(int ap)
{
	this->attackPowerBonus = ap;
}

void BonusStats::updateDefenseBonus(int def)
{
	this->defenseBonus += def;
}

void BonusStats::updateHealthBonus(int hp)
{
	this->healthBonus += hp;
}

void BonusStats::updateManaBonus(int mp)
{
	this->manaBonus += mp;
}

void BonusStats::updateStrengthBonus(int str)
{
	this->strengthBonus += str;
}

void BonusStats::updateIntelligenceBonus(int intel)
{
	this->intelligenceBonus += intel;
}

void BonusStats::updateEnduranceBonus(int end)
{
	this->enduranceBonus += end;
}

void BonusStats::updateAttackPowerBonus(int ap)
{
	this->attackPowerBonus += ap;
}

int BonusStats::getDefenseBonus() const
{
	return this->defenseBonus;
}

int BonusStats::getHealthBonus() const
{
	return this->healthBonus;
}

int BonusStats::getManaBonus() const
{
	return this->manaBonus;
}

int BonusStats::getStrengthBonus() const
{
	return this->strengthBonus;
}

int BonusStats::getIntelligenceBonus() const
{
	return this->intelligenceBonus;
}

int BonusStats::getEnduranceBonus() const
{
	return this->enduranceBonus;
}

int BonusStats::getAttackPowerBonus() const
{
	return this->attackPowerBonus;
}

int BonusStats::getOriginalDefenseBonus() const
{
	return this->originalDefenseBonus;
}

int BonusStats::getOriginalHealthBonus() const
{
	return this->originalHealthBonus;
}

int BonusStats::getOriginalManaBonus() const
{
	return this->originalManaBonus;
}

int BonusStats::getOriginalStrengthBonus() const
{
	return this->originalStrengthBonus;
}

int BonusStats::getOriginalIntelligenceBonus() const
{
	return this->originalIntelligenceBonus;
}

int BonusStats::getOriginalEnduranceBonus() const
{
	return this->originalEnduranceBonus;
}

int BonusStats::getOriginalAttackPowerBonus() const
{
	return this->originalAttackPowerBonus;
}

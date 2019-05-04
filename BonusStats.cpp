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

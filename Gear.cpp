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

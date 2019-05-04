#pragma once

#include "BonusStats.h"
#include "Database.h"
#include <vector>
#include <algorithm>
#include <Windows.h>

class Gear
{
private:
	NS_GearAttributes::Rarity g_rarity;
	std::string rarity;

	std::string gearName;
	std::string gearType;

	int itemLevel;

	int originalDurability;
	int currentDurability;

	int originalMaxDurability;
	int maxDurability;

	int originalRequiredStrength;
	int requiredStrength;

	int originalRequiredIntelligence;
	int requiredIntelligence;

	int originalRequiredEndurance;
	int requiredEndurance;

	BonusStats* bonStats;

public:
	Gear();
	Gear(NS_GearAttributes::Rarity g_rarity, BonusStats* bonStats = nullptr, int itemLvl = 0,
		int currdur = 0, int maxdur = 0, int reqstr = 0, int reqint = 0, int reqend = 0);
	~Gear();

	bool operator==(const Gear& gear) {
		return this->g_rarity == gear.g_rarity
			&& this->itemLevel == gear.itemLevel;
	}

	virtual BonusStats* getBonusStat()const;

	virtual void setRarity(NS_GearAttributes::Rarity g_rarity);

	virtual void setItemLevel(int itemLevel);
	
	virtual void setCurrentDurability(int dur);
	virtual void setMaxDurability(int dur);
	
	virtual void setRequiredStrength(int str);
	virtual void setRequiredIntelligence(int intel);
	virtual void setRequiredEndurance(int end);

	virtual void updateItemLevel(int itemLevel);
	
	virtual void updateCurrentDurability(int dur);
	virtual void updateMaxDurability(int dur);
	
	virtual void updateRequiredStrength(int str);
	virtual void updateRequiredIntelligence(int intel);
	virtual void updateRequiredEndurance(int end);

	virtual std::string getRarity()const;
	virtual NS_GearAttributes::Rarity ns_getRarity()const;

	virtual void setGearName(std::string gearName);
	virtual std::string getGearName()const;

	virtual void setGearType(std::string gearType);
	virtual std::string getGearType()const;

	virtual int getItemLevel()const;

	template<class __TFGEXP_____>
	__TFGEXP_____ getGearName_ns() const;

	virtual int getCurrentDurability()const;
	virtual int getMaxDurability() const;
	
	virtual int getOriginalCurrentDurability()const;
	virtual int getOriginalMaxDurability() const;

	virtual int getRequiredStrength() const;
	virtual int getRequiredIntelligence()const;
	virtual int getRequiredEndurance() const;

	virtual int getOriginalRequiredStrength() const;
	virtual int getOriginalRequiredIntelligence()const;
	virtual int getOriginalRequiredEndurance() const;


	virtual std::string displaySimple()const;

	virtual void retrieveGear()const;
};

template<class __TFGEXP_____>
inline __TFGEXP_____ Gear::getGearName_ns() const
{
	return __TFGEXP_____();
}
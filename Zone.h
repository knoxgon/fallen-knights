#pragma once
#include <string>
#include "Database.h"

class Zone
{
private:
	std::string currentZone;
	NS_Zones::AllZones zone;
	int zoneID;
	int accessLevel;
public:
	Zone();
	virtual ~Zone();
	void setCurrentZone(NS_Zones::AllZones zone);
	int getZoneID()const;
	NS_Zones::AllZones getZone_NS()const;
	int getAccessLevel()const;
	std::string getCurrentZone()const;
};

#include "stdafx.h"
#include "Zone.h"

Zone::Zone(){
	this->setCurrentZone(NS_Zones::AllZones::Moradon);
}

Zone::~Zone(){}

void Zone::setCurrentZone(NS_Zones::AllZones zone)
{
	this->zone = zone;
	this->zoneID = static_cast<int>(zone);
	switch (zone)
	{
	case NS_Zones::AllZones::Ardream:
		this->currentZone = "Ardream";
		break;
	case NS_Zones::AllZones::Ronark_Land:
		this->currentZone = "Ronark Land";
		break;
	case NS_Zones::AllZones::Moradon:
		this->currentZone = "Moradon";
		break;
	case NS_Zones::AllZones::MRDN_Folk_Village:
		this->currentZone = "Folk Village";
		break;
	case NS_Zones::AllZones::MRDN_Tale_Village:
		this->currentZone = "Tale Village";
		break;
	case NS_Zones::AllZones::MRDN_EMC_El_Morad_Castle:
		this->currentZone = "El-Morad Castle";
		break;
	case NS_Zones::AllZones::MRDN_LFRSN_Luferson_Castle:
		this->currentZone = "Luferson Castle";
		break;
	case NS_Zones::AllZones::MRDN_Lunar_Valley:
		this->currentZone = "Lunar Valley";
		break;
	case NS_Zones::AllZones::MRDN_Delos:
		this->currentZone = "Delos";
		break;
	case NS_Zones::AllZones::EMC_Asga_Village:
		this->currentZone = "Asga Village";
		break;
	case NS_Zones::AllZones::EMC_Doda_Camp:
		this->currentZone = "Doda Camp";
		break;
	case NS_Zones::AllZones::EMC_Human_Eslant:
		this->currentZone = "Human Estlant";
		break;
	case NS_Zones::AllZones::EMC_Kalluga_Valley:
		this->currentZone = "Kalluga Valley";
		break;
	case NS_Zones::AllZones::EMC_Laiba_Village:
		this->currentZone = "Laiba Village";
		break;
	case NS_Zones::AllZones::LFRSN_Belluga_Valley:
		this->currentZone = "Belluga Valley";
		break;
	case NS_Zones::AllZones::LFRSN_Raon_Camp:
		this->currentZone = "Raon Camp";
		break;
	case NS_Zones::AllZones::LFRSN_Orc_Eslant:
		this->currentZone = "Orc Eslant";
		break;
	case NS_Zones::AllZones::LFRSN_Rabia_Village:
		this->currentZone = "Rabia Village";
		break;
	case NS_Zones::AllZones::RON_Ronark_Land_Base:
		this->currentZone = "Ronark Land Base";
		break;
	case NS_Zones::AllZones::DELOS_Hell_Abyss:
		this->currentZone = "Hell Abyss";
		break;
	case NS_Zones::AllZones::DELOS_Forgotten_Temple:
		this->currentZone = "Forgotten Temple";
		break;
	case NS_Zones::AllZones::DELOS_Juradin_Mountain:
		this->currentZone = "Juradin Mountain";
		break;
	case NS_Zones::AllZones::DELOS_Krowazs_Dominion:
		this->currentZone = "Krowaz Dominion";
		break;
	case NS_Zones::AllZones::DELOS_Felankors_Lair:
		this->currentZone = "Felankor's Lair";
		break;
	case NS_Zones::AllZones::DELOS_Bifrost:
		this->currentZone = "Bifrost";
		break;
	}
}

int Zone::getZoneID() const
{
	return this->zoneID;
}

NS_Zones::AllZones Zone::getZone_NS() const
{
	return this->zone;
}

int Zone::getAccessLevel() const
{
	return this->accessLevel;
}

std::string Zone::getCurrentZone() const
{
	return this->currentZone;
}

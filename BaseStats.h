#pragma once

class BaseStats {
private:
	short attackPower;
	short defendPower;

	unsigned short healthPoint;
	unsigned short maxHealthPoint;
public:
	BaseStats();
	~BaseStats();
	BaseStats(int attackPower, int defendPower, int healthPoint, int maxHP);
	
};

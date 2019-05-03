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
	
	void setAttackPower(int ap);
	void setDefendPower(int dp);
	void setHealthPoint(int hp);
	void setMaxHealthPoint(int maxhp);

	int getAttackPower()const;
	int getDefendPower()const;
	int getHealthPoint()const;
	int getMaxHealthPoint()const;
	
	void updateAttackPower(int attpower);
	void updateDefendPower(int defpower);

	void updateHealthPoint(int hpvalue);
	void updateMaxHealthPoint(int maxhpvalue);
	
	virtual std::string toString() const;
};

#include "stdafx.h"	
#include "Experience.h"

Experience::Experience()
{
	this->experience = 0;
	this->level = 1;
	this->maxExperience = this->getNextExperience(this->level);
}

Experience::~Experience()
{
}

Experience::Experience(int level, int exp, int maxexp)
{
	this->setLevel(level);
	this->setExperience(exp);
	this->maxExperience = maxexp;
}

Experience & Experience::operator=(Experience other)
{
	if (this != &other) {
		std::swap(level, other.level);
		std::swap(experience, other.experience);
		std::swap(maxExperience, other.maxExperience);
	}
	return *this;
}

void Experience::setLevel(int level)
{
	this->level = level;
}

void Experience::setExperience(int exp)
{
	this->experience = exp;
}

void Experience::setMaxExperience(int maxexp)
{
	this->maxExperience = maxexp;
}

void Experience::updateExperience(int exp)
{
	if (exp + this->getExperience() > this->getMaxExperience()) {
		int restExp = this->getMaxExperience() - this->getExperience();
		this->level++;
		this->setExperience(0);
		this->setMaxExperience(this->getNextExperience(this->getLevel()));
		exp -= restExp;
		this->experience += exp;
	}
	else if (exp < 0){}
	else {
		this->experience += exp;
		this->experienceControlFlow();
	}
}

void Experience::experienceControlFlow() {
	if (this->getExperience() >= this->getMaxExperience()) {
		this->level++;
		this->setExperience(0);
		this->setMaxExperience(this->getNextExperience(this->getLevel()));
	}
}

void Experience::updateLevel()
{
	this->level++;
}

int Experience::getLevel() const
{
	return this->level;
}

int Experience::getExperience() const
{
	return this->experience;
}

int Experience::getMaxExperience() const
{
	return this->maxExperience;
}

int Experience::getNextExperience(int level)
{
	if (level > 90)
		return (int)std::floor(11.712*(std::pow(level + 2, 3)*std::log(level + 2) + 100) + 0.5);
	else
		return (int)std::floor((std::pow(level + 2, 3)*std::log(level + 2) + 100) + 0.5);
}

std::string Experience::convertExperienceToString(int currentLevel)
{
	return std::to_string(this->getNextExperience(currentLevel));
}

std::string Experience::toString() const
{
	return "Level: " + std::to_string(this->getLevel()) + 
		"\nExp: " + std::to_string(this->getExperience()) + '/' + std::to_string(this->getMaxExperience()) + '\n';
}

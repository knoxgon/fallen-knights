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

#include "FluVirus.h"
#include <time.h>
#include <iostream>
#include <list>

FluVirus::FluVirus()
{
	//std::cout << "flu\n";
	DoBorn();
	InitResistance();
}

FluVirus::FluVirus(int color, int resistance)
{
	this->m_color = color;
	this->m_resistance = resistance;
}

FluVirus::FluVirus(const FluVirus * flu) :Virus(flu)
{
	this->m_color = flu->m_color;
}

FluVirus::FluVirus(int color)
{
	this->m_color = color;
}


FluVirus::~FluVirus()
{
	//std::cout << "destroy Flu virus\n";
}

Virus * FluVirus::DoBorn()
{
	 LoadDNAInformation();
	// std::cout << this->m_dna;
	//std::srand(time(0));
	int result = rand() % 10;
	if (result % 2 != 0)
	{
		this->m_color = BLUE;
	}
	else
	{
		this->m_color = RED;
	}
	//std::cout << "flu\t" << this->m_color << "\n";
	return this;
}

void FluVirus::DoDie()
{
	delete this->m_dna;
}

Virus* FluVirus::DoClone()
{
	return new FluVirus(this);
}

void FluVirus::InitResistance()
{
	if (this->m_color == RED)
	{
		this->m_resistance = rand() % 11 + 10;
		return;
	}
	else
	{
		//std::srand(time(0));
		// rand() %(b-a+1)+a;
		this->m_resistance = rand() % 6 + 10;
		return;
	}
}

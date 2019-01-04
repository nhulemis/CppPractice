#include "FluVirus.h"
#include <time.h>
#include <iostream>
#include <list>

FluVirus::FluVirus()
{
}

FluVirus::FluVirus(int color, int resistance)
{
	this->m_color = color;
	this->m_resistance = resistance;
}

FluVirus::FluVirus(const FluVirus * flu)
{
	this->m_color = flu->m_color;
	this->m_resistance = flu->m_resistance;
	this->m_dna = flu->m_dna;
}

FluVirus::FluVirus(int color)
{
	this->m_color = color;
}


FluVirus::~FluVirus()
{
}

Virus * FluVirus::DoBorn()
{
	this->LoadDNAInformation();
//	std::srand(time(0));
	int result = rand() % 10;
	if (result%2 !=0)
	{
		this->m_color = BLUE;
	}
	else
	{
		this->m_color = RED;
	}
	std::cout << "flu\t" << this->m_color << "\n";
	return this;
}

void FluVirus::DoDie()
{
	
}

Virus* FluVirus::DoClone()
{
	Virus * vr = new FluVirus(this);
	return vr;
}

void FluVirus::InitResistance()
{
	if (this->m_color == RED)
	{
		std::srand(time(0));
		// rand() %(b-a+1)+a;
		this->m_resistance = rand() % 11 + 10;
		return;
	}
	else
	{
		std::srand(time(0));
		// rand() %(b-a+1)+a;
		this->m_resistance = rand() % 6 + 10;
		return;
	}
}

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

FluVirus::FluVirus(int color)
{
	this->m_color = color;
}


FluVirus::~FluVirus()
{
}

void FluVirus::DoBorn()
{
	this->LoadDNAInformation();
	std::srand(time(0));
	int result = rand() % 10;
	if (result%2==0)
	{
		this->m_color = BLUE;
	}
	else
	{
		this->m_color = RED;
	}
}

void FluVirus::DoDie()
{
}

void FluVirus::DoClone()
{

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

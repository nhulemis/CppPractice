#include "DengueVirus.h"
#include <time.h>
#include <list>
#include<string.h>
#include <iostream>



DengueVirus::DengueVirus()
{
//	std::cout << "den\n";
	DoBorn();
	InitResistance();
}

DengueVirus::DengueVirus(const DengueVirus * den)
{
	strcpy_s(this->m_protein, den->m_protein);
	this->m_dna = den->m_dna;
	this->m_resistance = den->m_resistance;

}


DengueVirus::~DengueVirus()
{
	//std::cout << "destroy Dengue virus\n";
}

Virus* DengueVirus::DoBorn()
{
	this->LoadDNAInformation();
	//std::srand(time(0));
	// rand() %(b-a+1)+a;
	int result = rand() % 3 + 1;
	//this->m_protein[0] = '\0';
	switch (result)
	{
	case 1:
		strcpy_s(this->m_protein, "NS3");
		break;
	case 2:
		strcpy_s(this->m_protein, "NS5");
		break;
	case 3:
		strcpy_s(this->m_protein, "E");
		break;
	}
	//std::cout << "den\n";
	return this;
}

void DengueVirus::DoDie()
{
	delete this->m_dna;
}

Virus* DengueVirus::DoClone()
{
	return new DengueVirus(this);
}

void DengueVirus::InitResistance()
{
	if (*this->m_protein == *NS3)
	{
		this->m_resistance = rand() % 10 + 1;
	}
	else if (*this->m_protein == *NS5)
	{
		this->m_resistance = rand() % 10 + 11;
	}
	else if (*this->m_protein == *E)
	{
		this->m_resistance = rand() % 10 + 21;
	}
}

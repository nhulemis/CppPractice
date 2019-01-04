#include "DengueVirus.h"
#include <time.h>
#include <list>
#include<string.h>
#include <iostream>



DengueVirus::DengueVirus()
{
}

DengueVirus::DengueVirus(const DengueVirus * den)
{	
	strcpy_s(this->m_protein, den->m_protein);
	this->m_dna = den->m_dna;
	this->m_resistance = den->m_resistance;

}


DengueVirus::~DengueVirus()
{
}

Virus* DengueVirus::DoBorn()
{
	this->LoadDNAInformation();
	//std::srand(time(0));
	// rand() %(b-a+1)+a;
	int result = rand() % 3 + 1;
	this->m_protein[0] = '\0';
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
	std::cout << "den\n";
	return this;
}

void DengueVirus::DoDie()
{
}

Virus* DengueVirus::DoClone()
{
	static Virus *list[2];
	list[0] = new DengueVirus(this);
	list[1] = new DengueVirus(this);
	return *list;
}

void DengueVirus::InitResistance()
{
}

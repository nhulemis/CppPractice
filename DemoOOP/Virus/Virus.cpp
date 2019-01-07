#include "Virus.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>

using namespace std;

Virus::Virus()
{
	//std::cout << "vr\n";
	
}

Virus::Virus(int m_resistance)
{
	this->m_resistance = m_resistance;
	this->m_dna = m_dna;
}

Virus::Virus(const Virus *vr)
{
	this->m_resistance = vr->m_resistance;
	this->m_dna = vr->m_dna;
}


Virus::~Virus()
{
	//delete m_dna;
	//std::cout << "destroy virus\n";
}

void Virus::LoadDNAInformation()
{
	ifstream fin;
	fin.open("ATGX.bin");
	if (fin)
	{

		this->m_dna = new char[50];
		
		fin >> this->m_dna;
		fin.close();
		return;
	}
	else
	{
		cout << "load file fail \n";	
		//return NULL;
	}
}


/*return true = virus dead
return false = virus alive*/
bool Virus::ReduceResistance(int medicine_resistance)
{
	this->m_resistance -= medicine_resistance;
	if (this->m_resistance <=0)
	{
		//cout << "destroy\n";
		//this->DoDie();
		return true;
	}
	
	return false;
}

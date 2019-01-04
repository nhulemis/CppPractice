#include "Virus.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

Virus::Virus()
{
}

Virus::Virus(int m_resistance)
{
	this->m_resistance = m_resistance;
	this->m_dna = m_dna;
}

Virus::Virus(const Virus &vr)
{
	this->m_resistance = vr.m_resistance;
	this->m_dna = vr.m_dna;
}


Virus::~Virus()
{
}

void Virus::LoadDNAInformation()
{
	ifstream fin;
	fin.open("ATGX.bin");
	if (!fin)
	{
		cout << "load file fail \n";
		return;
	}
	//cin.ignore();
	string temp;

	getline(fin, temp);

	this->m_dna = const_cast<char*>(temp.c_str());
	 
	fin.close();
}

void Virus::ReduceResistance(int medicine_resistance)
{
	if (this->m_resistance <=0)
	{
		cout << "destroy\n";
		return;
	}
	this->m_resistance -= medicine_resistance;
}

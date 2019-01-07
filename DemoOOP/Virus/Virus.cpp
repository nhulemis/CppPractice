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

Virus::Virus(const Virus &vr)
{
	this->m_resistance = vr.m_resistance;
	this->m_dna = vr.m_dna;
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
		
		//string temp;
		//getline(fin, temp);
		
		this->m_dna = new char[50];
		//this->m_dna = const_cast<char*>(temp.c_str());
		/*int a = strlen(m_dna);
		int b = temp.size();*/
		fin >> this->m_dna;
		fin.close();
		//this->m_dna[temp.size()]='\0';
		return;
	}
	else
	{
		cout << "load file fail \n";	
		//return NULL;
	}
}


/*return true = dead
return false = alive*/
bool Virus::ReduceResistance(int medicine_resistance)
{
	this->m_resistance -= medicine_resistance;
	if (this->m_resistance <=0)
	{
		//cout << "destroy\n";
		this->DoDie();
		return true;
	}
	
	return false;
}

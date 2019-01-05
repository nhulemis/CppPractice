#include "Patient.h"
#include <iostream>
#include <Windows.h>
#include <time.h>


Patient::Patient()
{
	this->m_resistance = InitResistance();
}

Patient::Patient(int stage)
{
	this->m_stage = stage;
}


Patient::~Patient()
{
	delete m_virusList;
}

int Patient::InitResistance()
{
	int resistance = rand()% 8001 + 1000;
	return resistance;
}

void Patient::DoStart()
{
	std::srand(time(0));
	// rand() %(b-a+1)+a;
	int virusRandom = rand() % 11 + 10;

	for (int i = 0; i < virusRandom; i++)
	{
		Virus *vrRand;
		int result = rand() % 10 + 1;
		//	std::cout << result << "\n";
		if (result % 2 == 0)
		{
			vrRand = new FluVirus();
		}
		else
		{
			vrRand = new DengueVirus();
		}
		vrRand = vrRand->DoBorn();
		m_virusList->push_back(vrRand);
	}
	Patient(1);
	//std::cout << m_virusList.size();
}

void Patient::TakeMedicine()
{
	int medicin_resistance = rand() % 60 + 1;
	for each (auto item in *m_virusList)
	{
		item->ReduceResistance(medicin_resistance);
	}
}

int Patient::GetStage()
{
	return this->m_stage;
}

void Patient::DoDie()
{
	//m_virusList->clear();
	delete this;	
	
}

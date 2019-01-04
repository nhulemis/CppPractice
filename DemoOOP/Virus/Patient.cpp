#include "Patient.h"
#include <iostream>
#include <Windows.h>
#include <time.h>


Patient::Patient()
{
}

Patient::Patient(int stage)
{
	this->m_stage = stage;
}


Patient::~Patient()
{
}

void Patient::InitResistance()
{
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
		m_virusList.push_back(vrRand);
	}
	std::cout << m_virusList.size();
}

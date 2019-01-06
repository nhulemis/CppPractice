#include "Patient.h"
#include <iostream>
#include <Windows.h>
#include <time.h>


Patient::Patient()
{
	this->m_resistance = InitResistance();

	m_virusList = new std::vector<Virus*>();

	DoStart();



}

Patient::Patient(int stage)
{
	this->m_stage = stage;

	this->m_resistance = InitResistance();

	m_virusList = new std::vector<Virus*>();

	DoStart();
}


Patient::~Patient()
{
	delete m_virusList;
}

int Patient::InitResistance()
{
	std::srand(time(0));
	int resistance = rand() % 8001 + 1000;
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
		//vrRand = vrRand->DoBorn();
		m_virusList->push_back(vrRand);
	}

	//std::cout << m_virusList.size();
}

void Patient::TakeMedicine(int medicin_resistance)
{
	//	std::vector<Virus*>::iterator pos = m_virusList->begin();
		//std::vector<Virus*> *tempDie = new std::vector<Virus*>();
	int i = 0;
	while (i != m_virusList->size())
	{
		auto var = m_virusList->at(i)->ReduceResistance(medicin_resistance);
		if (var)
		{
			m_virusList->erase(m_virusList->begin() + i);
		}
		else
		{
			i++;
		}
	}

	if (m_virusList->size() != 0)
	{
		std::vector<Virus*> *tempBorn = new std::vector<Virus*>();
		for each (auto var in *m_virusList)
		{
			if (dynamic_cast<FluVirus*>(var))
			{
				//FluVirus *flu = (FluVirus*)var;
				tempBorn->push_back(var->DoClone());
			}
			else if (dynamic_cast<DengueVirus*>(var))
			{
				//std::cout << "den\n";
			//	var->DoClone();
				tempBorn->push_back(var->DoClone());
				tempBorn->push_back(var->DoClone());
			}
		}

		for each (auto var in *tempBorn)
		{
			m_virusList->push_back(var);
		}
		delete tempBorn;
		std::cout<< "Virus : " << m_virusList->size();
	}
	

	if (m_virusList->size() > this->m_resistance)
	{
		std::cout << "\ndie\n";
		DoDie();
	}
}



int Patient::GetStage()
{
	return this->m_stage;
}

void Patient::DoDie()
{
	//m_virusList->clear();
	delete m_virusList;
	delete this;

}

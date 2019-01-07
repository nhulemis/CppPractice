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
	ReduceVirus(medicin_resistance);

	if (m_virusList->size() != 0)
	{
		CloneVirus();
	}

	if (m_virusList->size() > this->m_resistance)
	{
		std::cout << "\ndie\n";
		m_virusList->clear();
		DoDie();
	}
}

void Patient::TakeMedicine(std::string key, int medicin_resistance)
{
	int a = m_virusList->size()-1;
	for (int i = a ; i >= 0; i--)
	{
		if (m_virusList->at(i)->ReduceResistance(medicin_resistance))
		{
			m_virusList->erase(m_virusList->begin() + i);
		}
		else
		{
			if (dynamic_cast<FluVirus*>(m_virusList->at(i)))
			{
				//FluVirus *flu = (FluVirus*)var;
				m_virusList->push_back(m_virusList->at(i)->DoClone());
			}
			else if (dynamic_cast<DengueVirus*>(m_virusList->at(i)))
			{
				//std::cout << "den\n";
				//	var->DoClone();
				m_virusList->push_back(m_virusList->at(i)->DoClone());
				m_virusList->push_back(m_virusList->at(i)->DoClone());
			}
		}
	}
	std::cout << "Virus : " << m_virusList->size()<<"\n";
	if (m_virusList->size() > this->m_resistance)
	{
		std::cout << "\ndie\n";
		m_virusList->clear();
		DoDie();
		return;
	}if (m_virusList->size() ==0)
	{
		this->m_stage = 0;
		std::cout << "alive\n";
	}
}



int Patient::GetStage()
{
	return this->m_stage;
}

void Patient::DoDie()
{
	delete this;
	//m_virusList->clear();
	this->m_stage = 0;
	//delete m_virusList;
}

void Patient::ReduceVirus(int medicin_resistance)
{
	int i = 0;
	while (i != m_virusList->size())
	{
		auto var = m_virusList->at(i)->ReduceResistance(medicin_resistance);
		if (var)
		{
			m_virusList->erase(m_virusList->begin() + i);
			//m_virusList->at(i)->DoDie();
		}
		else
		{
			i++;
		}
	}
}

void Patient::CloneVirus()
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
	std::cout << "Virus : " << m_virusList->size();
}

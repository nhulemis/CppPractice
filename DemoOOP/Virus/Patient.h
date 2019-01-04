#pragma once
#include <list>
#include "Virus.h"
#include "DengueVirus.h"
#include "FluVirus.h"
#include <time.h>

class Patient
{
private:
	int m_resistance;
	int m_stage;
	std::list<Virus*> m_virusList;
	int InitResistance();
public:
	Patient();
	Patient(int stage);
	~Patient();
	
	void DoStart();
	void TakeMedicine();

};


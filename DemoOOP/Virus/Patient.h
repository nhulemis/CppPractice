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
public:
	Patient();
	Patient(int stage);
	~Patient();
	void InitResistance();
	void DoStart();
	void TakeMedicine();

};


#pragma once
#include <vector>
#include "Virus.h"
#include "DengueVirus.h"
#include "FluVirus.h"
#include <time.h>
#include <string>

class Patient
{
private:
	int m_resistance;
	int m_stage;
	std::vector<Virus*> *m_virusList;
	int InitResistance();
public:
	Patient();
	Patient(int stage);
	~Patient();
	
	void DoStart();
	void TakeMedicine(int medicin_resistance);
	void TakeMedicine(std::string key, int medicin_resistance);
	int GetStage();
	void DoDie();
private:
	void ReduceVirus(int medicin_resistance);
	void CloneVirus();
};


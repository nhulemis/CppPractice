#pragma once
#include <list>

class Virus
{
protected:
	int m_resistance;
	char* m_dna;

public:
	Virus();
	Virus(int m_resistance);
	Virus(const Virus &vr);
	virtual ~Virus();

public:
	void LoadDNAInformation();

	virtual	bool ReduceResistance(int medicine_resistance);

	virtual Virus *DoBorn() = 0;

	virtual void DoDie() = 0;

	virtual Virus *DoClone() = 0;

	virtual void InitResistance() = 0;

	int GetResistance() {
		return m_resistance;
	}
};


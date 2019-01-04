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
	~Virus();

public:
	void LoadDNAInformation();

	virtual	void ReduceResistance(int medicine_resistance);

	virtual void  DoBorn() = 0;

	virtual void DoDie() = 0;

	virtual Virus *DoClone() = 0;

	virtual void InitResistance() = 0;
};


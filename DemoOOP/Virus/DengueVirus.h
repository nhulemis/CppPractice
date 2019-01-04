#pragma once
#include "Virus.h"
#include <string.h>
class DengueVirus : public Virus
{
protected:
	char m_protein[4];
public:
	DengueVirus();
	DengueVirus(const DengueVirus* den);
	~DengueVirus();

	virtual  Virus* DoBorn();

	virtual void DoDie();

	virtual Virus* DoClone();

	virtual void InitResistance();
};


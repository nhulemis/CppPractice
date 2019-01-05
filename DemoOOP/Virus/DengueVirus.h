#pragma once
#include "Virus.h"
#include <string.h>
class DengueVirus : public Virus
{

protected:
	char m_protein[4];
private:
	const char NS3[4] = { 'N','S','3','\0' };
	const char NS5[4] = { 'N','S','5','\0' };
	const char E[4] = { 'E','\0',' ',' ' };
public:
	DengueVirus();
	DengueVirus(const DengueVirus* den);
	virtual ~DengueVirus();

	virtual  Virus* DoBorn();

	virtual void DoDie();

	virtual Virus* DoClone();

	virtual void InitResistance();
};


#pragma once
#include "Virus.h"
class FluVirus : public Virus
{

protected:
	int m_color;
public:	
	static const int BLUE = 0x0000ff;
	static const int RED = 0x000000;

	FluVirus();
	FluVirus(int color);
	FluVirus(int color,int resistance);
	FluVirus(const FluVirus * flu);
	
	~FluVirus();

	virtual void DoBorn();

	virtual void DoDie();

	virtual void DoClone();

	virtual void InitResistance();
	
};


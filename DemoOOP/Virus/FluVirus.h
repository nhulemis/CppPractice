#pragma once
#include "Virus.h"
class FluVirus : public Virus
{

protected:
	int m_color;
private:	
	 const int BLUE = 0x0000ff;
	 const int RED = 0x000000;
public:
	FluVirus();
	FluVirus(int color);
	FluVirus(int color,int resistance);
	FluVirus(const FluVirus * flu);
	
	virtual ~FluVirus();

	virtual Virus * DoBorn();

	virtual void DoDie();

	virtual Virus* DoClone();
	 
	virtual void InitResistance();
public:
	virtual int GetColor() {
		return m_color;
	}
	
};


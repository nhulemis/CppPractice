#pragma once
class MyPoint
{
protected:
	int mPosX;
	int mPosY;
public:
	MyPoint();
	MyPoint(int x, int y);
public:
	virtual void Display();
	void SetX(int x);
	int GetX();
	void SetY(int y);
	int GetY();
	double Distance(MyPoint p);
	~MyPoint();
};


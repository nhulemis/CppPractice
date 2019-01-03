#pragma once
class MyPoint
{

protected:
	int mPosX;
	int mPosY;
public:
	MyPoint();
	MyPoint(int x, int y);
	virtual void Display();
	void SetX(int x);
	int GetX();
	void SetY(int y);
	int GetY();
	~MyPoint();
};


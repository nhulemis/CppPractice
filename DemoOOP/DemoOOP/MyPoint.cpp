#include "MyPoint.h"
#include <iostream>

using namespace std;



MyPoint::MyPoint()
{
}


MyPoint::MyPoint(int x, int y) {
	mPosX = x;
	mPosY = y;
}

void MyPoint::Display()
{
	cout << "X : " << mPosX << "- Y : " << mPosY << endl;
}

void MyPoint::SetX(int x)
{
	this->mPosX = x;
}

int MyPoint::GetX()
{
	return this->mPosX;
}

void MyPoint::SetY(int y)
{
	this->mPosY = y;
}

int MyPoint::GetY()
{
	return this->mPosY;
}

MyPoint::~MyPoint()
{
}



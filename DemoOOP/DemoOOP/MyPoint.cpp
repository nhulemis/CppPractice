#include "MyPoint.h"
#include <iostream>

using namespace std;

int mPosX;
int mPosY;

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





MyPoint::~MyPoint()
{
}



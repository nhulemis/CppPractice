#include <iostream>
#include "MyPoint.h"

using namespace std;

int main() {
	
	MyPoint* pa = new MyPoint(1, 1);
	MyPoint* pb = new MyPoint(4, 5);

	cout << pb->Distance(*pa)<< endl;

	system("pause");
	return 0;
}
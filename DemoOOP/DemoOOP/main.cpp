#include <iostream>
#include "MyPoint.h"

using namespace std;

int main() {
	
	const MyPoint* pa = new MyPoint(1, 1);
	MyPoint* pb = new MyPoint(pa);

	cout << pb->Distance(*pa)<< endl;


	system("pause");
	return 0;
}
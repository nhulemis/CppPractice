#include <iostream>
#include "MyPoint.h"

using namespace std;

int main() {
	//MyPoint a = new MyPoint(0, 0);
	const MyPoint pa (0,0) ;
	MyPoint pb(pa);

	cout << pb.GetX()<< endl;


	system("pause");
	return 0;
}
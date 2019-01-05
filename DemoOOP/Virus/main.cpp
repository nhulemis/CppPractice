#include <iostream>
#include "Virus.h"
#include "FluVirus.h"
#include "Patient.h"


using namespace std;

int main() {

	Virus* vr = new FluVirus(0,20);
	std::cout << vr <<"\n";

	vr->DoDie();

	std::cout << vr << "\n";
	system("pause");
	return 0;
}
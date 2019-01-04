#include <iostream>
#include "Virus.h"
#include "FluVirus.h"
#include "Patient.h"


using namespace std;

int main() {

	Patient * pa = new Patient();

	Virus * den = new DengueVirus();
	den = den->DoBorn();
	den->InitResistance();
	system("pause");
	return 0;
}
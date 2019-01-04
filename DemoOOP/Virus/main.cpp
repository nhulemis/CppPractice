#include <iostream>
#include "Virus.h"
#include "FluVirus.h"

using namespace std;

int main() {

	Virus *flu = new FluVirus();

	flu->InitResistance();
	system("pause");
	return 0;
}
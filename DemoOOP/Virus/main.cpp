#include <iostream>
#include "Virus.h"
#include "FluVirus.h"
#include "Patient.h"


using namespace std;

int main() {

	Patient * pa = new Patient();

	pa->DoStart();
	/*std::srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		
		cout << rand() % 10 + 1 <<endl;
	}*/
	system("pause");
	return 0;
}
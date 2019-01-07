#include <iostream>
#include "Virus.h"
#include "FluVirus.h"
#include "Patient.h"
#include <vector>
#include <time.h>


using namespace std;

int main() {
	Patient *p = new Patient(1);
	std::srand(time(0));
	int min = 1, max = 10, medicine_resistance;
	int sc = 1, sum = 0;
	while (p->GetStage() == 1 && sc != 0)
	{
		std::cout << "\ntake medicine (0 - No ; 1 - Yes)\n";
		cin >> sc;

		if (sc == 1)
		{
			medicine_resistance = min + rand() % (int)(max - min + 1);
			p->TakeMedicine("", medicine_resistance);

		}
	}



	system("pause");
	return 0;
}
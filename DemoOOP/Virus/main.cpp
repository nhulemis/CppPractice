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

	int min = 0, max = 2, medicine_resistance;
	int sc,sum = 0;
	while (p->GetStage() == 1)
	{		
		std::cout << "\ntake medicine (0 - No ; 1 - Yes)\n";
		cin >> sc;
		//sc = 1;
		if (sc == 1)
		{
			medicine_resistance = min + rand() % (int)(max - min + 1);
			p->TakeMedicine(medicine_resistance);
		//	system("cls");
			//std::cout << sum++ << endl;
			//sum++;
		}
	}

	system("pause");
	return 0;
}
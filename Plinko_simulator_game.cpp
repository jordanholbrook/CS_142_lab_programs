/*
Matthew Steffen and Jordan Holbrook
Programmed by Pair Programming
Steffen.MatthewJ@gmail.com, holybrook@gmail.com
Section 006
Programmed in Visual Studio

Test case 1:
Input:
3 1 5 4
Result:

Test case 2:
Input:
3 2 27 8 4
Result: Passed, Tested to see if large number of chips would work

Test case 3:
3 -1 57 2 5 15 1 15 4   //Destined to fail every time.

*/

#include <iostream>
#include <string>
#include <random>
#include <iomanip>
using namespace std;

int main() {
	//Variables to use
	int option, prob, chips;
	double winnings, total, place, slot;
	bool quit = true;
	const int RANDOM_SEED = 42;
	srand(RANDOM_SEED);
	winnings = 0.0;
	total = 0.0;

	//Constants for score
	const double SLOT0 = 100.0;
	const double SLOT1 = 500.0;
	const double SLOT2 = 1000.0;
	const double SLOT3 = 0.0;
	const double SLOT4 = 10000.0;
	const double SLOT5 = 0.0;
	const double SLOT6 = 1000.0;
	const double SLOT7 = 500.0;
	const double SLOT8 = 100.0;


	//Beginning
	cout << "Welcome to the Plinko Simulator!  Enter 3 to see options." << endl;
	cout << endl;

	while (quit) {
		cout << "Enter your selection now:" << endl;
		cin >> option;
		cout << endl;

		switch (option) {
		case 1:
			cout << "*** Drop a single chip ***"<< endl << endl;
			cout << "Which slot do you want to drop the chip in (0-8)?" << endl;
			cin >> place;
			if (place < 0 || place >= 9) {
				cout << "Invalid slot." << endl;
				break;
			}
			else {
				cout << "*** Dropping chip into slot " << (int)place << " ***" << endl << endl;
				cout << "Path: [" << fixed << setprecision(1) << place;
				for (int x = 0; x < 12; ++x) {
					if (x < 12)
						cout << ", ";
					if (place == 0 || place == 8) {
						if (place == 0)
							place += 0.5;
						else
							place -= 0.5;
					}
					else {
						prob = rand() % 2;
						if (prob == 0)
							place -= 0.5;
						else
							place += 0.5;
					}
					cout << fixed << setprecision(1) << place;
				}
				cout << ']' << endl;
				switch ((int)place) {
				case 0: winnings = SLOT0;
					break;
				case 1: winnings = SLOT1;
					break;
				case 2: winnings = SLOT2;
					break;
				case 3: winnings = SLOT3;
					break;
				case 4: winnings = SLOT4;
					break;
				case 5: winnings = SLOT5;
					break;
				case 6: winnings = SLOT6;
					break;
				case 7: winnings = SLOT7;
					break;
				case 8: winnings = SLOT8;
					break;
				}
				cout << fixed << setprecision(2);
				cout << "Winnings: $" << winnings << endl;
				break;
		case 2:
			total = 0.0;
			cout << "*** Drop multiple chips ***" << endl;
			cout << "How many chips do you want to drop (>0)?" << endl << endl;
			cin >> chips;
			if (chips <= 0) {
				cout << "Invalid number of chips." << endl;
				break;
			}
			cout << "Which slot do you want to drop the chip in (0-8)?" << endl << endl;
			cin >> slot;
			if (slot < 0 || slot >= 9) {
				cout << "Invalid slot." << endl;
				break;
			}
			//Calculate the total winnings
			//for (how many chips) for (path)
			place = slot;
			for (int x = 0; x < chips; ++x) {
				place = slot;
				for (int y = 0; y < 12; ++y) {
					if (place == 0 || place == 8) {
						if (place == 0)
							place += 0.5;
						else
							place -= 0.5;
					}
					else {
						prob = rand() % 2;
						if (prob == 0)
							place -= 0.5;
						else
							place += 0.5;
					}
				}
				switch ((int)place) {
				case 0: winnings = SLOT0;
					break;
				case 1: winnings = SLOT1;
					break;
				case 2: winnings = SLOT2;
					break;
				case 3: winnings = SLOT3;
					break;
				case 4: winnings = SLOT4;
					break;
				case 5: winnings = SLOT5;
					break;
				case 6: winnings = SLOT6;
					break;
				case 7: winnings = SLOT7;
					break;
				case 8: winnings = SLOT8;
					break;
				}
				total += winnings;
			}
			}
			cout << fixed << setprecision(2);
			cout << "Total winnings on " << chips << " chips: $" << total << endl;
			cout << "Average winnings per chip: $" << total / (double)chips << endl;
			break;
		case 3:
			cout << "Menu: Please select one of the following options:\n\n1 - Drop a single chip into one slot\n2 - Drop multiple chips into one slot\n3 - Show the options menu\n4 - Quit the program\n";
			break;
		case 4:
			quit = false;
			cout << "Goodbye!";
			break;
		default:
			cout << "Invalid Selection.  Enter 3 to see options." << endl;
			break;
		}
	}
	return 0;
}
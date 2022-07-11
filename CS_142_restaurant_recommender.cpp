#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>
using namespace std;

const int NOT_FOUND = -1;

int FindInRestaurantList(vector<string> &restaurantList, string restaurantNameToFind) {
	for (int i = 0; i < (int)restaurantList.size(); ++i) {
		if (restaurantList.at(i) == restaurantNameToFind) {
			return i;
		}
	}
	// Implied Else -- We did not find the restaurant name
	return NOT_FOUND;
}

void DisplayRestaurants(const vector<string> &restaurantList) {
	// Display a vector containing the anamDisplay all restaurants
	// Display the restaurant names in their current order, on separate lines, prefaced with one tab("\t").
	cout << "Here are the current restaurants: " << endl << endl;
	for (int i = 0; i < (int)restaurantList.size(); ++i) {
		cout << endl;
		cout << '\t' << '\"' << restaurantList.at(i) << '\"' << endl;
	}

}
void AddRestaurants(vector<string> &restaurantList) { // Error with this function executes and then displays the menu too??
	string nameOfRestaurant;
	int restaurantLocation = NOT_FOUND;

	cout << "What is the name of the restaurant you want to add? " << endl;
	cin.ignore();
	getline(cin, nameOfRestaurant); // Maybe inestead of using cin use File Stream?? So inFSS??
	restaurantLocation = FindInRestaurantList(restaurantList, nameOfRestaurant);
	if (restaurantLocation == NOT_FOUND) {
		restaurantList.push_back(nameOfRestaurant);
		cout << nameOfRestaurant << " has been added. " << endl << endl;
	}
	else {
		cout << "That restaurant is already on the list, you can not add it again." << endl;
	}


}
void RemoveRestaurant(vector<string> &restaurantList) {
	string nameOfRestaurant;
	int restaurantLocation = NOT_FOUND;

	cout << "What is the name of the restaurant you want to remove? " << endl;
	cin.ignore();
	getline(cin, nameOfRestaurant);
	restaurantLocation = FindInRestaurantList(restaurantList, nameOfRestaurant);
	if (restaurantLocation == NOT_FOUND) {
		cout << "That restaurant is not on the list, you can not remove it." << endl;

	}
	else {
		restaurantList.erase(restaurantList.begin() + restaurantLocation);
		cout << nameOfRestaurant << " has been removed. " << endl << endl;
	}



}
void CutRestaurantList(vector<string> &restaurantList) {
	int numToCutList;

	cout << "How many restaurants should be taken from the top and put on the bottom ? " << endl;
	cout << endl << endl;
	cin >> numToCutList;

	while (cin.fail() == true || (numToCutList < 0 && numToCutList > restaurantList.size())) { // This should fail if it is not an integer
		cout << "The cut number must be between 0 and " << restaurantList.size() << endl;
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "How many restaurants should be taken from the top and put on the bottom ? " << endl;
		cout << endl << endl;
		cin >> numToCutList;
	}
	for (int i = 0; i < numToCutList; ++i) {
		restaurantList.push_back(restaurantList.at(i));
	}
	for (int i = 0; i < numToCutList; ++i) {
		restaurantList.erase(restaurantList.begin());
	}
}

bool PowerOfTwo(int numToCheck) {

	if (float(log2(numToCheck)) == log2(numToCheck)) {
		return true;
	}
	else {
		return false;

	}

}




void ShuffleRestaurantList(vector<string> &restaurantList) {
	vector<string> restaurantList1stHalf;
	vector<string> restaurantList2ndHalf;
	vector<string> restaurantListNew;
	int numToCheck = 0;

	numToCheck = restaurantList.size();
	if (PowerOfTwo(numToCheck)) {


		for (int i = restaurantList.size() / 2; i < restaurantList.size(); ++i) { // Filling up the 2nd Half Vector
			//restaurantList2ndHalf.at(0) = restaurantList.at(i);
			restaurantList2ndHalf.push_back(restaurantList.at(i));
		}
		for (int i = 0; i < restaurantList.size() / 2; ++i) { // Filling up the 1st half vector
			//restaurantList1stHalf.at(0) = restaurantList.at(i);
			restaurantList1stHalf.push_back(restaurantList.at(i));
		}
		for (int i = 0; i < restaurantList1stHalf.size(); ++i) { // Adding the 1st and 2nd halves into a new vector
			restaurantListNew.push_back(restaurantList2ndHalf.at(i));
			restaurantListNew.push_back(restaurantList1stHalf.at(i));
		}

		for (int i = 0; i < restaurantListNew.size(); ++i) { // Setting the old vector equal to the new vector
			restaurantList.at(i) = restaurantListNew.at(i);
		}
	}
	else {
		cout << "The current tournament size " << "( " << numToCheck << ")" << " is not a power of two (2, 4, 8. . .)." << endl;
		cout << "A shuffle is not possible. Please add or remove restaurants. " << endl;
	}
}
// Things this function needs to do
	/* Display two restaurant names
	ask the user which they prefer
	user choose 1 or 2
	error check the user unput check
	if not a 1 or 2 then reprompt for user input check
	and check if the number of restaurants is a power of two  CHECK*/
string GetUserPreference(string firstString, string secondString) {

	int userTournamentPreference;

	cout << "Type \"1\" if you prefer " << firstString << " or" << endl; // I need to get the teams into vectors and display them
	cout << "type \"2\" if you prefer " << secondString << endl;
	cout << "Choice: ";
	cin >> userTournamentPreference;


	while (cin.fail() == true || (userTournamentPreference < 1 || userTournamentPreference > 2)) { // This should fail if it is not an integer
		cout << "Invalid choice " << endl;
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "Type \"1\" if you prefer " << firstString << " or" << endl;
		cout << "type \"2\" if you prefer " << secondString << endl;
		cout << "Choice: ";
		cin >> userTournamentPreference;

	}
	return (userTournamentPreference == 1) ? firstString : secondString;
}
void BattleFunction(vector<string> restaurantList) {
	if (!PowerOfTwo(restaurantList.size())) {
		cout << "The current tournament size " << "(" << restaurantList.size() << ")" << " is not a power of two (2, 4, 8. . .)." << endl;
		cout << "A battle is not possible. Please add or remove restaurants. " << endl;
		return;
	}

	vector<string> winnersList;
	int round = 1;

	while (restaurantList.size() > 1) {
		cout << "Round: " << round << endl << endl;

		for (int i = 0; i < restaurantList.size(); i += 2) {
			string firstString = restaurantList.at(i);
			string secondString = restaurantList.at(i + 1);

			string choice = GetUserPreference(firstString, secondString);
			winnersList.push_back(choice);
		}

		restaurantList = winnersList;
		winnersList.clear();
		round++;
	}

	cout << "The winning restaurant is " << restaurantList.at(0) << "." << endl;
}
/*string BattleFunction(vector<string> &restaurantList) {
	string a;
	string b;


	if (restaurantList.size() == 2) {
		a = restaurantList.at(0);
		b = restaurantList.at(1);
	}
	else {
		vector<string> restaurantList1stHalf;
		vector<string> restaurantList2ndHalf;
		vector<string> restaurantListNew;

		for (int i = restaurantList.size() / 2; i < restaurantList.size(); ++i) { // Filling up the 2nd Half Vector
			//restaurantList2ndHalf.at(0) = restaurantList.at(i);
			restaurantList2ndHalf.push_back(restaurantList.at(i));
		}
		for (int i = 0; i < restaurantList.size() / 2; ++i) { // Filling up the 1st half vector
			//restaurantList1stHalf.at(0) = restaurantList.at(i);
			restaurantList1stHalf.push_back(restaurantList.at(i));
		}
		a = BattleFunction(restaurantList1stHalf);
		b = BattleFunction(restaurantList2ndHalf);
	}
	int userTournamentPreference;
	cout << "Round: " << /* some number formula *//*  endl << endl << endl; // How do I determine the number of rows to display?
	cout << "Type \"1\" if you prefer " << a << " or" << endl; // I need to get the teams into vectors and display them
	cout << "type \"2\" if you prefer " << b << endl;
	cin >> userTournamentPreference;

	while (cin.fail() == true || (userTournamentPreference < 1 || userTournamentPreference > 2)) { // This should fail if it is not an integer
		cout << "Invalid choice " << endl;
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "Type \"1\" if you prefer " << a << " or" << endl;
		cout << "type \"2\" if you prefer " << b << endl;
		cin >> userTournamentPreference;
	}
	if (userTournamentPreference == 1) {
		cout << "Winner is:" << a << endl;
		return a;
	}
	else if (userTournamentPreference == 2) {
		cout << "Winner is: " << b << endl;
		return b;
	}

}*/

		/*for (int i = 0; i < restaurantList1stHalf.size(); ++i) { // Adding the 1st and 2nd halves into a new vector
			restaurantListNew.push_back(restaurantList2ndHalf.at(i));
			restaurantListNew.push_back(restaurantList1stHalf.at(i));
		}

		for (int i = 0; i < restaurantListNew.size(); ++i) { // Setting the old vector equal to the new vector
			restaurantList.at(i) = restaurantListNew.at(i);
		} 
	} */


		/*vector<string> restaurantList1stRound;
		vector<string> restaurantList2ndRound;
		vector<string> restaurantListFinalRound;
		int numToCheck = 0;*/


		/*  numToCheck = restaurantList.size();
		if (PowerOfTwo(numToCheck)) {
			int userTournamentPreference;

			cout << "Round: " << /* some number formula *//*  endl << endl << endl; // How do I determine the number of rows to display?
			cout << "Type \"1\" if you prefer " << "Super Taqueria" << " or" << endl; // I need to get the teams into vectors and display them
			cout << "type \"2\" if you prefer " << "Burger Supreme" << endl;
			cin >> userTournamentPreference;

			while (cin.fail() == true || (userTournamentPreference < 1 || userTournamentPreference > 2)) { // This should fail if it is not an integer
				cout << "Invalid choice " << endl;
				cin.clear();
				cin.ignore(1000, '\n');

				cout << "Type \"1\" if you prefer " << "Super Taqueria" << " or" << endl;
				cout << "type \"2\" if you prefer " << "Burger Supreme" << endl;
				cin >> userTournamentPreference;
			} 
			*/
			// do something cool


		//}
		/*else {
			cout << "The current tournament size " << "(" << numToCheck << ")" << " is not a power of two (2, 4, 8. . .)." << endl;
			cout << "A battle is not possible. Please add or remove restaurants. " << endl;
		}
	}
}*/


void PrintMenu() {


	cout << "Please select one of the following options: " << endl << endl;

	cout << endl;
	cout << "quit - Quit the program " << endl;
	cout << "display - Display all restaurants " << endl;
	cout << "add - Add a restaurant" << endl;
	cout << "remove - Remove a restaurant " << endl;
	cout << "cut - \"Cut\" the list of restaurants" << endl;
	cout << "shuffle - \"Shuffle\" the list of restaurants " << endl;
	cout << "battle - Begin the tournament " << endl;
	cout << "options - Print the options menu " << endl;
	cout << endl;

	cout << endl;



}


int main() {
	// Variables
	vector<string> restaurantList;
	string userInput;
	string userMenuOption;
	bool quitMenu = true;


	// Part 1 OutPut the Menu
	cout << "Welcome to the restaurant battle!  Enter \"options \" to see options. " << endl << endl;

	while (quitMenu) {


		cout << "Enter your selection: " << endl;

		cin >> userMenuOption;


		if (userMenuOption == "quit") { // Quit Option
			cout << "Goodbye!" << endl;
			quitMenu = false;

		}
		else if (userMenuOption == "display") {
			DisplayRestaurants(restaurantList);
		}
		else if (userMenuOption == "add") {
			AddRestaurants(restaurantList);
		}
		else if (userMenuOption == "remove") {
			
			RemoveRestaurant(restaurantList);
		}
		else if (userMenuOption == "cut") {
			CutRestaurantList(restaurantList);

		}
		else if (userMenuOption == "shuffle") {
			ShuffleRestaurantList(restaurantList);

		}
		else if (userMenuOption == "battle") {
			BattleFunction(restaurantList);

		}
		else if (userMenuOption == "options") {
			PrintMenu();
		}
		else {
			cout << "Invalid Selection" << endl;
			PrintMenu();
		}

	}










	return 0;
}
/* Jordan Holbrook, Section 6, holybrook@gmail.com
Main Lab 2 

Test case 1:
Input: Number of people: 303, Tip%: 15%
Expected output: Number of Pizzas: 43 Large and 2 Small Total Cost: $743
*/

#include <iostream>
#include <cmath>                   
using namespace std;

int main() {
   int numLargePizza = 0; // integer variables
   int numMedPizza = 0;
   int numSmallPizza = 0;
   int numGuests = 0;
   int numGuestLeft = 0;
   
   int sizeLarge = 20; // Pizza Size in inches
   int sizeMedium = 16;
   int sizeSmall = 12;
   
   double priceLargePizza = 14.68; // non-integer variables, Price of Pizza in $US
   double priceMedPizza = 11.48;
   double priceSmallPizza = 7.28; 
   double tipPercentage = 0.0; // Tip percentage of bill
   
   double totalCostPizza = 0.0;
   double totalCostall = 0.0;
   double totalAreabought = 0.0; // Total amount of Pizza bought
   double totalAreaeaten  = 0.0; // Total amount of Pizza consumed
   
   const double PI = 3.14159265; // Constant Variables
   const int NUM_FED_LARGE = 7;
   const int NUM_FED_MED = 3;
   const int NUM_TO_GET_RADIUS = 2;
   const double NUM_PERCENTAGE = 100.0;
 
   cout << "Please enter the number of guests: ";     // Statement 1, Program Start
   cin >> numGuests;
   cout << endl;
    
   numLargePizza = numGuests / NUM_FED_LARGE;
   numGuestLeft = numGuests % NUM_FED_LARGE;
   numMedPizza = numGuestLeft / NUM_FED_MED;
   numSmallPizza = numGuestLeft % NUM_FED_MED;
   
   
   cout << numLargePizza << " large pizzas, " << numMedPizza << " medium pizzas, " << "and " << numSmallPizza; 
   cout << " small pizzas will be needed." << endl;
   cout << endl;
   
   totalAreabought = ((sizeLarge / NUM_TO_GET_RADIUS) * (sizeLarge / NUM_TO_GET_RADIUS) * PI) * numLargePizza +
                     ((sizeMedium / NUM_TO_GET_RADIUS) * (sizeMedium / NUM_TO_GET_RADIUS) * PI) * numMedPizza +
                     ((sizeSmall / NUM_TO_GET_RADIUS) * (sizeSmall / NUM_TO_GET_RADIUS) * PI) * numSmallPizza;
   totalAreaeaten = totalAreabought / numGuests;
   
   
   cout << "A total of " << totalAreabought << " square inches of pizza will be purchased " << "(";    //Statement 2
   cout << totalAreaeaten << " per guest)." <<  endl; 
   cout << endl;
   
   totalCostPizza = ((numLargePizza * priceLargePizza) + (numMedPizza * priceMedPizza) + 
                     (numSmallPizza * priceSmallPizza));

   cout << "Please enter the tip as a percentage (i.e. 10 means 10%): ";    //Statement 3
   cin >> tipPercentage;
   cout << endl;
   
   totalCostall = totalCostPizza + (totalCostPizza * (tipPercentage / NUM_PERCENTAGE));
  
   cout << "The total cost of the event will be: " << "$" << round(totalCostall) << endl; 
   
   
  
// Program End

   return 0;
}
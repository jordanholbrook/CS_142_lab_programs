/* Jordan Holbrook, Section 6, 

CS 142 Lab 3, holybrook@gmail.com
Test case 1:

Test Case 2:

Test Case 3:

*/

#include <iostream>
using namespace std;
#include <cctype>


int main() {
  /*  Part 1 Prompt the user to input the initial text to be edited. See the examples below for exact I/O format. 
You will enter just one line of text. Use getline to put the text into a string variable. 
Strings can be any characters, numbers, punctuation, etc. Then print out the string.*/ 
   string userInput;
   
   
   cout << "Welcome to the Simple Editor. Enter a string to be edited: " << endl;
   getline(cin, userInput);
   cout << userInput << endl;


/* Part 2 Output "Do you want to make this string a sentence (y/n)? ". If yes:*/
   string userInput2;
   int lastIndex;
   char lastChar;

   cout << "Do you want to make this string a sentence (y/n)? " << endl;
   cin >> userInput2;
   cin.ignore();
   if (userInput2 == "y") {
      userInput.at(0) = toupper(userInput.at(0));
     
      lastIndex = userInput.size() - 1;
      lastChar  = userInput.at(lastIndex);

      if ( (lastChar != '.') && (lastChar != '!') && (lastChar != '?') ) {
         userInput.append(".");
         
      }  
      
      cout << userInput << endl;
   }
/* Part 3 Output "Do you want to insert more text into your current text (y/n)? " If yes,

    Output "Enter text to be inserted: ". Use getline to get text.
    Output "Enter position where text is to be inserted: ". Get position using cin.
    Insert the text and print out the updated string. */
   string userInput3;
   string userInput4;
   int positionPreference; 
   
   cout << "Do you want to insert more text into your current text (y/n)? " << endl;
   cin >> userInput3;
   cin.ignore();
   
   if (userInput3 == "y") {
      
      cout << "Enter text to be inserted: " << endl;
      getline(cin, userInput4);
      cout << "Enter position where text is to be inserted: " << endl;
      cin >> positionPreference;
      cin.ignore();
      
      if ((positionPreference < 0)||(positionPreference > userInput.size())){
         cout << "No change made. Position must be non-negative and not exceed";
         cout << userInput.size() << " , the length of the current text." << endl;
      }
      else {
      cout << userInput.insert(positionPreference, " " + userInput4);
      }
   }
   
   
   string userInput7;
   string userInput8;
  /* Part 4  Output  If they enter anything other than "find" or "copy",
  just continue to the end of the program.*/ 
   cout << "If you would like to find/replace or copy/paste, enter find or copy: " << endl;
   
   string userInput5;
   getline(cin, userInput5);
   if (userInput5 == "find") {
      
      cout << "Enter substring to find: " << endl;
     
      string userInput6;
      getline(cin, userInput6);
      int lengthInput6 = userInput6.size();
      int positionInput6 = userInput.find(userInput6);
      
      
      cout << "Do you want to find if/where the substring occurs, delete it,";
      cout << "or replace it (find, delete, replace)? " << endl;
      
      string userInput7;
      getline(cin, userInput7);
      
      
      if  (userInput7 == "find") {
         if (userInput.find(userInput6) != string::npos) {
            cout << userInput6 << " was found at position " << positionInput6 << "." << endl;
         }
         else {
            cout << userInput6 << " was not found." << endl;
         }  
      }
      if (userInput7 == "delete") {
         if (userInput.find(userInput6) != string::npos) {
             userInput.erase(positionInput6, lengthInput6);
         }
         else {
            cout << userInput6 << " was not found. No change made. " << endl;
         }
      }  
      if (userInput7 == "replace") {
         if (userInput.find(userInput6) != string::npos) {
                  cout << "Enter replacement string:" << endl;
                  getline(cin, userInput8);
                  userInput.replace(userInput.find(userInput6), lengthInput6, userInput8);
         }
         else {
            cout << userInput6 << " was not found. No change made. " << endl;
         }
      }
               
      
   }    
   
   
   
   
   else if (userInput5 == "copy") {
      cout << "Enter position and length of text to be copied, and position for paste: " << endl;
      
      int positionCopy;
      int lengthStringCopy;
      int positionStringPaste;
      
      cin >> positionCopy; 
      cin.ignore();
      cin >> lengthStringCopy;
      cin.ignore();
      cin >> positionStringPaste;
      cin.ignore();
      
      
      if ((positionCopy < 0) || (positionCopy >= userInput.size()) || (positionStringPaste > userInput.size()) 
      || (lengthStringCopy > userInput.size()) || (positionStringPaste < 0) || (lengthStringCopy < 0) || 
       (positionCopy + lengthStringCopy > userInput.size())) {
         cout << "Values entered do not support copy/paste." << endl;
      }
      else {
         string copiedText;
         copiedText = userInput.substr(positionCopy, lengthStringCopy);
         userInput.insert(positionStringPaste, copiedText);
      }   
   }         
            
            
            
            
            
   
   cout << "Final text is" << endl;
   cout << userInput << endl;
   
   
   
   
   return 0;
}
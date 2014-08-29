#include <iostream>

using namespace std;

int main ()
{
 /*Declare and initialize variables */
 int insertedCoin = 0; /*Coin value inserted by user.  Valid amounts include: 5, 10, 25 and 0 for "no input case"*/
 int userBalance = 0; /*Total value of coins inserted by user. Beverages cost 150*/
 char userChoice = '0'; /*Valid options include: A, B, C, D and 0 for "no choice" case*/
 bool vend = 0;  /*0 == FALSE and 1 == TRUE*/

 for (int i = 0;true;)
 {/*Infinite loop to check/handle user input.*/
  if(userBalance < 150)
  {/* Not enough cash yet */
   cout << "Insert coin. Current balance is: " << userBalance << endl;
   cin >> insertedCoin;

   switch (insertedCoin)
   {
   case 1:
	   userBalance += 1;
	   break;
   case 5:
	   userBalance += 5;
	   break;
   case 10:
	   userBalance += 10;
	   break;
   case 25:
	   userBalance += 25;
	   break;
   default:
	   cout << "keeping yur bad coin, w00t\n";
   }

 /*Student: write code to handle coin insert here. Be sure to check for valid amounts and add to userBalance if correct.
   If invalid coin, print out "keeping your bad coin, w00t!" and remember to use continue if not valid and re-initialize
   the appropriate values.*/
  }

  else
  {/*If user has provided enough change, i.e. $1.50, check choice, otherwise ask for more */
   cout << "Enough cash input.  What type of drink do you want?" << endl;
   cin >> userChoice;
   
   switch (userChoice)
   {
    case 'A':
	case 'B':
	case 'C':
	case 'D':
     cout << "Vending " << userChoice << ". Thank you!" << endl;
     vend = 1;
     break;    
	default:
		cout << "That's not a valid choice!\n";
		break;
 /*Student: complete to handle other cases. For default print, "That's not a valid choice!\n" and use continue to
   restart the asking process.*/
   }

  }

  if(vend == 1)
  {/*Beverage vended, reset variables, and exit for teaching purposes*/
   if(userBalance > 150)
   {/*Too much money!*/
    userBalance = userBalance - 150; /*Deduct beverage cost*/
    cout << "Thank you for the tip! I can use an extra " << userBalance << " cents." << endl;

    /*This break added to stop the program for teaching purposes*/
    break;
   }
   else
   {
    cout << "No tip?!?";
    /*This break added to stop the program for teaching purposes*/
    break;
   }

   /*reset variables*/
   userBalance = 0;
   userChoice = '0';
   vend = false;
  }
 }
 return 0;
} 
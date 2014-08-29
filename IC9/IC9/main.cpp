//Brandon Pollack
//2375-4365
#include <iostream>
#include <cmath>
#define ERROR -1
#define EMPTY 0
#define FORWARD 1
#define BACKWARD 2
#define UPWARD 3
using namespace std;

int handleRobotMotion(int curDir, double curSpeed, int userDir, double userSpeed); /*routine to translate user input to robot motion. replies with status*/

int main()
{
 int robotDirection = FORWARD; /*assumed for example*/
 double robotSpeed = 10.0; /*assumed for example*/
 int directionInput = EMPTY; /*for user input*/
 double speedInput = EMPTY; /*for user input*/
 int robotStatus = EMPTY; /*catches the value returned upon input handle*/
 

 /*Take in user input*/
 cout << "Please provide a direction: 1 for forward, 2 for backward, 3 for upward" << endl;
 cin >> directionInput;
 cout << "Please provide a speed" << endl;
 cin >> speedInput;

 robotStatus = handleRobotMotion(robotDirection,robotSpeed,directionInput,speedInput);

 if(robotStatus == ERROR)
 {/* provide status to the user */
  cout << "Input not accepted" << endl;
 } else {
  cout << "Input accepted" << endl;
 }
 return 0;
} /*code snippet concluded for simplicity*/

int handleRobotMotion(int curDir, double curSpeed, int userDir, double userSpeed)
{/*Code to handle the user input for robot motion*/
 if(curDir == userDir)
 {/*if the same direction, different parameters*/
  if(abs(curSpeed-userSpeed)<=10)
  {/*if the change in speed is not too extreme in the same direction*/
   cout << "Completed correctly" << endl;
   return userDir;
  } else { /*Speed Change too fast in same direction*/
   cout << "Too fast!" << endl;
   return ERROR;
  }
 } else { /*different direction, different rules*/
  if(abs(curSpeed-userSpeed)<=5)
  {/*if the change in speed is not too extreme for the different direction*/
   cout << "Completed correctly for diff" << endl;
   return userDir;
  } else {
   cout << "Too fast for diff!" << endl;
   return ERROR;
  }
 }
}

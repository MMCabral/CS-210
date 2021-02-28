#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#include <string>
// clear screen function.
 void ClearScreen()
    {
    cout << string( 100, '\n' );
    }

//storing total seconds
	time_t total_seconds=time(0);
//
//	//getting values of seconds, minutes and hours
	struct tm* ct=localtime(&total_seconds);

// function used to display menu
void DisplayMenu(){

	cout << "**************************" << endl;
	cout << "* 1-Add One Hour         *" << endl;
	cout << "* 2-Add One Minute       *" << endl;
	cout << "* 3-Add One Second       *" << endl;
	cout << "* 4-Exit Program         *" << endl;
	cout << "**************************" << endl;
}
// function to gather local time and display it in both clock format
void ShowBothClocks (int hours, int minutes, int seconds){

// variable used to store 24 hour clock format
	int clock24Hours;
	string str;

	// conditional to determine whether time is in AM or PM.
	//converting it into 12 hour format
	if(hours>=12) {
		str="P M";
	}
	else {
		str="A M";
	}


	clock24Hours = hours;
	hours=hours>12?hours-12:hours;

// below is how the two clock formats are displayed and the clear screen function
	// is used to make sure costumer has a clean display.
		ClearScreen();
		cout << "**************************\t" << "**************************" << endl;
		cout << "*      12-Hour Clock     *\t" << "*      24-Hour Clock     *" << endl;
		cout << "*      ";
		cout << (hours<10?"0":"") << hours <<":" << (minutes<10?"0":"")
				<< minutes << ":" << (seconds<10?"0":"") << seconds << " " << str;
		cout << "      *\t" << "*        ";
		cout << (clock24Hours<10?"0":"") << clock24Hours <<":" << (minutes<10?"0":"")
				<< minutes << ":" << (seconds<10?"0":"") << seconds << " ";
		cout << "       *" << endl;
		cout << "**************************\t" << "**************************" << endl;
}


int main () {
	// declared variables that are used in main function.
	int hours;
	int minutes;
	int seconds;
	int costumerInput;
	int choice = 0;
	seconds=ct->tm_sec;
	minutes=ct->tm_min;
	hours=ct->tm_hour;
// calls to display both clock formats.
	ShowBothClocks(hours, minutes, seconds);

		while (choice != 4) {
			// user is put into while loop to determine how they want to adjust their time.
			cout << "Do you wish to alter the time?" << endl;
			cout << "Press 1 for yes and any other key for no." << endl;
			cin >> costumerInput;
//			conditional used to start loop and gather input from costumer.
			if (costumerInput == 1){
					DisplayMenu();
			}
			else {
					seconds += 1;
					system("pause");
					return main();
			}
//			Switch statement used to control main menu and gather user input.
				cin >> choice;
				switch(choice){
					case 1:
//						each case has conditionals to check if input is appropriate and fix it accordingly.
						hours = hours + 1;
						if (hours > 23){
							hours = 00;
						}
						ShowBothClocks(hours, minutes, seconds);
						break;
					case 2:
						minutes = minutes + 1;
						if (minutes > 59){
							minutes = minutes % 60;
						}
						ShowBothClocks(hours, minutes, seconds);
						break;
					case 3:
						seconds = seconds + 1;
						if (seconds > 59){
							seconds = seconds % 60;
						}
						ShowBothClocks(hours, minutes, seconds);
						break;
					case 4:
//						case four is used to end the program and default is used to make sure user inputs
						// an appropriate number.
						cout << "Exit Program" << endl;
						break;
					default:
						cout << "choose another input";
						break;
					}
		}
	return 0;
}

///////////////////////////////////////////////
// Software Engineering Final Project
// Calorie Intake Calculator 
///////////////////////////////////////////////

#include "CalorieIntake.h"	// include definition of class CalorieIntake	
#include <iomanip>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

// Program using CalorieIntake class 
int main()
{
	// declare and initialize variables 
	string calculate = "yes";	// variable representing whether or not the calculator should be used; used as a guard in the while-loop
	string measurementSystem = "";	// both standard US and metric system options for calculator
	string gender = "";	
	int age = 0;
	int weight = 0;
	int tempWeight = 0;  // stores raw weight value, before it has been converted to kg (only in US measurement system)
	int height = 0;
	int tempHeight = 0;	// stores raw height value, before it has been converted to cm (only in US measurement system)
	int feet = 0;	
	int inches = 0;
	int activityLevel = 0;	// activity level 1-5; represents how active the user is each week (how much exercise per week)
	int caloriesToMaintainWeight = 0;	// how many calories the user should intake per day to maintain their current weight
	int caloriesToLoseWeight = 0;	// how many calories the user should intake per day to lose weight 

	// execute while-loop until user no longer wants to calculate their recommended calorie intake 
	while (calculate == "yes" || calculate == "Yes" || calculate == "YES") {
		cout << "Welcome to the Calorie-Intake Calculator!\n" << endl;

		// prompt user to input desired measurement system to use 
		cout << "Would you like to use standard (US) or metric units for your calculation? Type \"US\" or \"metric\": ";
		getline(cin, measurementSystem);
		while ((measurementSystem != "US") && (measurementSystem != "metric")) {	// check that valid measurement system has been input
			cout << "Please type either \"US\" or \"metric\" to indicate which measurement system to use: "; 
			getline(cin, measurementSystem);
		}
		
		// prompt user to input their gender
		cout << "\nPlease enter your gender (\"male\" or \"female\"): ";
		getline(cin, gender);
		while ((gender != "male") && (gender != "female")) {	// check that valid gender has been input
			cout << "Please type either \"male\" or \"female\" to indicate your gender: ";
			getline(cin, gender);
		}

		// prompt user to input their gender
		cout << "\nPlease enter your age: ";
		cin >> age;
		while (cin.fail() || age < 0) {
			if (cin.fail()) {	// execute if user enters invalid input (e.g. letters instead of numbers, negative age)
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Please enter your age: ";  
			cin >> age;
		}

		// execute if standard US measurement system was chosen
		if (measurementSystem == "US") {
			// prompt user to input their weight (pounds units)
			cout << "\nPlease enter your weight (lbs): ";
			cin >> tempWeight;
			while (cin.fail() || tempWeight < 0) {
				if (cin.fail()) {	// execute if user enters invalid input (e.g. letters instead of numbers, negative weight)
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << "Please enter your weight (lbs): ";
				cin >> tempWeight;
			}
			tempWeight = tempWeight / 2.2;	// convert inputted weight from lbs to kg

			// prompt user to input their height (feet/inches units)
			cout << "\nPlease enter your height (e.g. if your height is 5 feet 9 inches, type \"5 9\"): ";
			cin >> feet >> inches;
			while (cin.fail() || feet < 0 || inches < 0) {
				if (cin.fail()) {	// execute if user enters invalid input (e.g. letters instead of numbers, negative feet or inches)
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << "Please enter your height (e.g. if your height is 5 feet 9 inches, type \"5 9\"): ";
				cin >> feet >> inches;
			}
			tempHeight = (feet * 12) + inches;	// convert inputted height to inches
			tempHeight = tempHeight * 2.54;	// convert height from inches to cm
		}

		// execute if metric measurement system was chosen
		else {
			// prompt user to input their weight (kg units)
			cout << "\nPlease enter your weight (kg): ";
			cin >> tempWeight;
			while (cin.fail() || tempWeight < 0) {
				if (cin.fail()) {	// execute if user enters invalid input (e.g. letters instead of numbers, negative weight)
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << "Please enter your weight (kg): ";
				cin >> tempWeight;
			}

			// prompt user to input their height (cm units)
			cout << "\nPlease enter your height (cm): ";
			cin >> tempHeight;
			while (cin.fail() || tempHeight < 0) {
				if (cin.fail()) {	// execute if user enters invalid input (e.g. letters instead of numbers, negative height)
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				cout << "Please enter your height (cm): ";
				cin >> tempHeight;
			}
		}
		weight = tempWeight;
		height = tempHeight;

		// descriptions of the 5 activity levels (amount of exercise per week)
		cout << "\nThe list below describes five activity levels: \n" << endl;
		cout << "1: Sedentary lifestyle" << endl;
		cout << "2: Slightly active lifestyle" << endl;
		cout << "3: Moderately active lifestyle" << endl;
		cout << "4: Active lifestyle" << endl;
		cout << "5: Very active lifestyle\n" << endl;

		// prompt user to input their activity level
		cout << "\nPlease enter your activity level (between 1 and 5), based on the list above: ";
		cin >> activityLevel;
		while (cin.fail() || activityLevel < 1 || activityLevel > 5) {
			if (cin.fail()) {	// execute if user enters invalid input (e.g. letters instead of numbers, activity level < 1 or > 5)
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Please enter your activity level (between 1 and 5), based on the list above: ";
			cin >> activityLevel;
		}

		// declare an object of type CalorieIntake using gender, age, weight (kg), height (cm), and activity level (between 1 and 5)
		CalorieIntake calculator(gender, age, weight, height, activityLevel);

		// compute number of calories that the user should input per day to maintain their current weight
		caloriesToMaintainWeight = calculator.calculateCalories();	

		// compute number of calories that the user should input per day to lose weight 
		// lose weight by intaking 80% of calories per day needed to maintain current weight
		caloriesToLoseWeight = caloriesToMaintainWeight * 0.8;

		// output calculation results to user
		cout << "\nYou should consume " << caloriesToMaintainWeight << " calories per day to maintain your current weight." << endl;
		cout << "You should consume " << caloriesToLoseWeight << " calories per day to lose weight." << endl;

		// prompt user to indicate if they'd like to use the calculator again or exit the program
		cout << "\nIf you'd like to use the calculator again, type \"yes\", or type any other key to exit: ";

		// discard characters in input (all characters until new line '\n' is reached); this is done so future "getline()" function will be executed 
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, calculate);	// store user input in variable practice
		if (calculate == "yes" || calculate == "Yes" || calculate == "YES") {
			cout << "\n\n";
		}
	}
	return 0;
}
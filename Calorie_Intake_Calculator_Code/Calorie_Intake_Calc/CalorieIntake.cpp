///////////////////////////////////////////////
// Software Engineering Final Project
// Calorie Intake Calculator 
///////////////////////////////////////////////

#include "CalorieIntake.h"	// include definition of class CalorieIntake

// constructor initializes private data members representing the user's gender, age, weight, height, and activity level
CalorieIntake::CalorieIntake(string userGender, int userAge, int userWeight, int userHeight, int userActivityLevel)
	: gender(userGender), age(userAge), weight(userWeight), height(userHeight), activityLevel(userActivityLevel)
{
	// empty body
}	// end CalorieIntake constructor 

// method returns the user's gender
string CalorieIntake::getGender() const {
	return gender;
}

// method returns the user's age
int CalorieIntake::getAge() const {
	return age;
}

// method returns the user's weight 
int CalorieIntake::getWeight() const {
	return weight;
}

// method returns the user's height
int CalorieIntake::getHeight() const {
	return height;
}

// method returns the user's activity level
int CalorieIntake::getActivityLevel() const {
	return activityLevel;
}

// method calculates and returns the number of calories that the user should intake per day to maintain their current weight
int CalorieIntake::calculateCalories() {
	int BMR = 0;	// BMR = basal metabolic rate
	int TEE = 0;	// TEE = total energy expenditure; the number of calories burned per day based on user's BMR and activity level
	
	// Mifflin-St Jeor Equation used to calculate BMR (different equation for males and females)
	if (getGender() == "male") {
		BMR = (10 * getWeight()) - (5 * getAge()) + (6.25 * getHeight()) + 5;
	}
	else {
		BMR = (10 * getWeight()) - (5 * getAge()) + (6.25 * getHeight()) - 161;
	}
	TEE = calculateTotalEnergyExpenditure(BMR, getActivityLevel());
	return TEE;
}	

// method calculates total energy expenditure, based on the user's calculated BMR and inputted activity level
int CalorieIntake::calculateTotalEnergyExpenditure(int BMR, int activityLevel) const {
	int TEE = 0;
	if (activityLevel == 1) {
		TEE = BMR * 1.2;
	}
	else if (activityLevel == 2) {
		TEE = BMR * 1.375;
	}
	else if (activityLevel == 3) {
		TEE = BMR * 1.55;
	}
	else if (activityLevel == 4) {
		TEE = BMR * 1.725;
	}
	else {
		TEE = BMR * 1.9;
	}
	return TEE;
}
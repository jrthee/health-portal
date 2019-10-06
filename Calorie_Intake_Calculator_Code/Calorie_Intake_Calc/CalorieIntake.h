#pragma once

///////////////////////////////////////////////
// Software Engineering Final Project
// Calorie Intake Calculator 
///////////////////////////////////////////////

#include <iostream>
#include <string>
using std::string;

// Declarations of CalorieIntake class member functions and member data
class CalorieIntake
{
public:
	explicit CalorieIntake(string, int, int, int, int);	
	string getGender() const;	
	int getAge() const;	
	int getWeight() const;	
	int getHeight() const;	
	int getActivityLevel() const;
	int calculateCalories(void);
	int calculateTotalEnergyExpenditure(int, int) const;
private:
	string gender = "";
	int age = 0;
	int weight = 0;
	int height = 0;	
	int activityLevel = 0;
};	// end class CalorieIntake
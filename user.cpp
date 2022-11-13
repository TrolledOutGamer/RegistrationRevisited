// Setup
#include "user.h"

// Default Constructor
user::user() {}

// Overloaded Constructor
user::user(string nameRef, string passwordRef, string majorRef, int creditsRef, string yearLevelRef, vector <course> courseListRef)
{
	name = nameRef;
	password = passwordRef;
	major = majorRef;
	credits = creditsRef;
	yearLevel = yearLevelRef;
	courseList = courseListRef;
}

// Setting New Values
void user::setName(string newName) { name = newName; }
void user::setPassword(string newPassword) { password = newPassword; }
void user::setMajor(string newMajor) { major = newMajor; }
void user::setCredits(int newCredits) { credits = newCredits; }
void user::setYearLevel(string newYearLevel) { yearLevel = newYearLevel; }
void user::setCourseList(vector <course> newCourseList) { courseList = newCourseList; }

// Getting Values
string user::getName() { return name; }
string user::getPassword() { return password; }
string user::getMajor() { return major; }
int user::getCredits() { return credits; }
string user::getYearLevel() { return yearLevel; }
vector <course> user::getCourseList() { return courseList; }
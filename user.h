// Setup
#ifndef USER_H
#define USER_H
#include <vector>
#include <string>
using namespace std;

// Course Struct
struct course
{
	string courseName;
	int creditVal;
	bool taken;
};

// User Class
class user
{
	public:
		// Data Members
		string name;
		string password;
		string major;
		int credits;
		string yearLevel;
		vector <course> courseList;

		// Default Constructor
		user();

		// Overloaded Constructor
		user(string nameRef, string passwordRef, string majorRef, int creditsRef, string yearLevelRef, vector <course> courseListRef);

		// Setting New Values
		void setName(string newName);
		void setPassword(string newPassword);
		void setMajor(string newMajor);
		void setCredits(int newCredits);
		void setYearLevel(string newYearLevel);
		void setCourseList(vector <course> newCourseList);

		// Getting Values
		string getName();
		string getPassword();
		string getMajor();
		int getCredits();
		string getYearLevel();
		vector <course> getCourseList();
};

#endif
/*
HackUTD IX
Prompt: Use technology to design a creative solution to a problem that your community currently faces (State Farm)
Team Members: Omar Ahmad, Saad Makda, Affan Khan, Syed Shah
*/

// Setup
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

// Function to Create User from Input
user createUser()
{
	// Variables
	string filename;
	user newUser;

	// Opening the User File
	cout << "Please input your UTD Student ID: ";
	cin >> filename;
	cout << "\n==============================================================" << endl;
	filename += ".txt";
	ifstream inFile;
	inFile.open(filename);

	// Reading Info from the File
	string temp;

	// Obtaining Name
	getline(inFile, temp);
	newUser.setName(temp);

	// Obtaining Password
	getline(inFile, temp);
	newUser.setPassword(temp);

	// Obtaining Major
	getline(inFile, temp);
	newUser.setMajor(temp);

	// Obtaining Core Credits
	getline(inFile, temp);
	newUser.setCredits(stoi(temp));

	// Obtaining Course List
	vector <course> courseList;
	while (!inFile.eof())
	{
		course newCourse;
		getline(inFile, temp, ',');
		newCourse.courseName = temp;
		getline(inFile, temp, ',');
		newCourse.creditVal = stoi(temp);
		getline(inFile, temp);
		newCourse.taken = stoi(temp);
		courseList.push_back(newCourse);
	}
	newUser.setCourseList(courseList);

	// Returing the Newly Created User
	return newUser;
}

// Function to Calculate Total Credits and Year Level
void calcCredits(user* newUser)
{
	// Variables
	int totalCredits = newUser->getCredits();
	vector <course> newCourseList = newUser->getCourseList();

	// Loop to Add Up All Credits Taken
	for (int i = 0; i < newCourseList.size(); i++)
	{
		if (newCourseList[i].taken == 1)
		{
			totalCredits += newCourseList[i].creditVal;
		}
	}
	newUser->setCredits(totalCredits);

	// Logic to Determine Year Level
	if (totalCredits < 30 && totalCredits >= 0)
	{
		newUser->setYearLevel("Freshman");
	}
	else if (totalCredits < 60 && totalCredits >= 30)
	{
		newUser->setYearLevel("Sophomore");
	}
	else if (totalCredits < 90 && totalCredits >= 60)
	{
		newUser->setYearLevel("Junior");
	}
	else if (totalCredits < 120 && totalCredits >= 90)
	{
		newUser->setYearLevel("Senior");
	}
}

// Function to Prevent Repeats
void repeatCheck(vector <course> courseList, vector <course>* possibleCourses, course newCourse)
{
	int count = 0;
	for (int h = 0; h < courseList.size(); h++)
	{
		if (newCourse.courseName == courseList[h].courseName)
		{
			count++;
		}
	}
	if (count == 0)
	{
		possibleCourses->push_back(newCourse);
	}
}

// Function to Determine Possible Courses
vector <course> possibleCourses(user newUser)
{
	// Variables
	int count = 0;
	vector <course> possibleCourses;
	vector <course> takenCourses;
	vector <course> allCourses = newUser.getCourseList();

	// Logic to Determine Possible Courses
		// Extracting Taken Courses
	for (int i = 0; i < allCourses.size(); i++)
	{
		if (allCourses[i].taken == 1)
		{
			takenCourses.push_back(allCourses[i]);
		}
	}
		// Checking Possible Courses
	for (int i = 0; i < takenCourses.size(); i++)
	{
		if (takenCourses[i].courseName == "MATH 2413")
		{
			course newCourse;
			newCourse.courseName = "MATH 2414";
			newCourse.creditVal = 4;
			newCourse.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse);
		}
		if (takenCourses[i].courseName == "MATH 2417")
		{
			course newCourse;
			newCourse.courseName = "MATH 2419";
			newCourse.creditVal = 4;
			newCourse.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse);
		}
		if (takenCourses[i].courseName == "MATH 2413" || takenCourses[i].courseName == "MATH 2417")
		{
			course newCourse;
			newCourse.courseName = "PHYS 2325";
			newCourse.creditVal = 3;
			newCourse.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse);
			course newCourse2;
			newCourse2.courseName = "PHYS 2125";
			newCourse2.creditVal = 1;
			newCourse2.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse2);
			course newCourse3;
			newCourse3.courseName = "MATH 2418";
			newCourse3.creditVal = 4;
			newCourse3.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse3);
		}
		if (takenCourses[i].courseName == "CS 1336")
		{
			course newCourse;
			newCourse.courseName = "CS 1337";
			newCourse.creditVal = 3;
			newCourse.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse);
		}
		if (takenCourses[i].courseName == "MATH 2414" || takenCourses[i].courseName == "MATH 2419")
		{
			for (int j = 0; j < takenCourses.size(); j++)
			{
				if (takenCourses[j].courseName == "PHYS 2325")
				{
					course newCourse;
					newCourse.courseName = "PHYS 2326";
					newCourse.creditVal = 3;
					newCourse.taken = 0;
					repeatCheck(takenCourses, &possibleCourses, newCourse);
					course newCourse2;
					newCourse2.courseName = "PHYS 2126";
					newCourse2.creditVal = 1;
					newCourse2.taken = 0;
					repeatCheck(takenCourses, &possibleCourses, newCourse2);
				}
			}
		}
		if (takenCourses[i].courseName == "CS 1337")
		{
			course newCourse;
			newCourse.courseName = "CS 2336";
			newCourse.creditVal = 3;
			newCourse.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse);
			course newCourse2;
			newCourse2.courseName = "CS 2337";
			newCourse2.creditVal = 3;
			newCourse2.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse2);
		}
		if (takenCourses[i].courseName == "CS 2336" || takenCourses[i].courseName == "CS 2337")
		{
			course newCourse;
			newCourse.courseName = "CS 3377";
			newCourse.creditVal = 3;
			newCourse.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse);
		}
		if (takenCourses[i].courseName == "RHET 1302" && (newUser.getYearLevel() == "Junior" || newUser.getYearLevel() == "Senior"))
		{
			course newCourse;
			newCourse.courseName = "ECS 3390";
			newCourse.creditVal = 3;
			newCourse.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse);
		}
		if (takenCourses[i].courseName == "CS 3305")
		{
			course newCourse;
			newCourse.courseName = "CS 4384";
			newCourse.creditVal = 3;
			newCourse.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse);
		}
		if (takenCourses[i].courseName == "CS 3345")
		{
			course newCourse;
			newCourse.courseName = "CS 4347";
			newCourse.creditVal = 3;
			newCourse.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse);
		}
		if (takenCourses[i].courseName == "MATH 2414" || takenCourses[i].courseName == "MATH 2419")
		{
			for (int j = 0; j < takenCourses.size(); j++)
			{
				if (takenCourses[j].courseName == "CS 2305")
				{
					course newCourse;
					newCourse.courseName = "CS 3341";
					newCourse.creditVal = 3;
					newCourse.taken = 0;
					repeatCheck(takenCourses, &possibleCourses, newCourse);
					course newCourse2;
					newCourse2.courseName = "CS 3305";
					newCourse2.creditVal = 3;
					newCourse2.taken = 0;
					repeatCheck(takenCourses, &possibleCourses, newCourse2);
				}
			}
		}
		if (takenCourses[i].courseName == "CS 2336" || takenCourses[i].courseName == "CS 2337")
		{
			for (int j = 0; j < takenCourses.size(); j++)
			{
				if (takenCourses[j].courseName == "CS 2305")
				{
					course newCourse;
					newCourse.courseName = "CS 3345";
					newCourse.creditVal = 3;
					newCourse.taken = 0;
					repeatCheck(takenCourses, &possibleCourses, newCourse);
				}
			}
		}
		if (takenCourses[i].courseName == "CS 1337")
		{
			for (int j = 0; j < takenCourses.size(); j++)
			{
				if (takenCourses[j].courseName == "CS 2305")
				{
					course newCourse;
					newCourse.courseName = "CS 2340";
					newCourse.creditVal = 3;
					newCourse.taken = 0;
					repeatCheck(takenCourses, &possibleCourses, newCourse);
				}
			}
		}
		if (takenCourses[i].courseName == "PHYS 2326")
		{
			for (int j = 0; j < takenCourses.size(); j++)
			{
				if (takenCourses[j].courseName == "CS 2340")
				{
					course newCourse;
					newCourse.courseName = "CS 4341";
					newCourse.creditVal = 3;
					newCourse.taken = 0;
					repeatCheck(takenCourses, &possibleCourses, newCourse);
					course newCourse2;
					newCourse2.courseName = "CS 4141";
					newCourse2.creditVal = 1;
					newCourse2.taken = 0;
					repeatCheck(takenCourses, &possibleCourses, newCourse2);
				}
			}
		}
		if (takenCourses[i].courseName == "CS 2336" || takenCourses[i].courseName == "CS 2337")
		{
			for (int j = 0; j < takenCourses.size(); j++)
			{
				if (takenCourses[j].courseName == "CS 2305")
				{
					course newCourse;
					newCourse.courseName = "CS 3354";
					newCourse.creditVal = 3;
					newCourse.taken = 0;
					repeatCheck(takenCourses, &possibleCourses, newCourse);
				}
			}
		}
		if (takenCourses[i].courseName == "CS 3305")
		{
			for (int j = 0; j < takenCourses.size(); j++)
			{
				if (takenCourses[j].courseName == "CS 3345")
				{
					course newCourse;
					newCourse.courseName = "CS 4349";
					newCourse.creditVal = 3;
					newCourse.taken = 0;
					repeatCheck(takenCourses, &possibleCourses, newCourse);
				}
			}
		}
		if (takenCourses[i].courseName == "CS 3345")
		{
			for (int j = 0; j < takenCourses.size(); j++)
			{
				if (takenCourses[j].courseName == "CS 3354")
				{
					course newCourse;
					newCourse.courseName = "CS 4485";
					newCourse.creditVal = 4;
					newCourse.taken = 0;
					repeatCheck(takenCourses, &possibleCourses, newCourse);
					course newCourse2;
					newCourse2.courseName = "CS 3162";
					newCourse2.creditVal = 1;
					newCourse2.taken = 0;
					repeatCheck(takenCourses, &possibleCourses, newCourse2);
				}
			}
		}
		if (takenCourses[i].courseName == "CS 2336")
		{
			for (int j = 0; j < takenCourses.size(); j++)
			{
				if (takenCourses[j].courseName == "CS 2305")
				{
					for (int k = 0; k < takenCourses.size(); k++)
					{
						if (takenCourses[k].courseName == "CS 2340")
						{
							course newCourse;
							newCourse.courseName = "CS 4337";
							newCourse.creditVal = 3;
							newCourse.taken = 0;
							repeatCheck(takenCourses, &possibleCourses, newCourse);
						}
					}
				}
			}
		}
		if (takenCourses[i].courseName == "CS 2340")
		{
			for (int j = 0; j < takenCourses.size(); j++)
			{
				if (takenCourses[j].courseName == "CS 3377")
				{
					for (int k = 0; k < takenCourses.size(); k++)
					{
						if (takenCourses[k].courseName == "CS 3345")
						{
							course newCourse;
							newCourse.courseName = "CS 4348";
							newCourse.creditVal = 3;
							newCourse.taken = 0;
							repeatCheck(takenCourses, &possibleCourses, newCourse);
						}
					}
				}
			}
		}
		if (newUser.getCredits() == 0 && i == takenCourses.size() - 1)
		{
			course newCourse;
			newCourse.courseName = "UNIV 1010";
			newCourse.creditVal = 0;
			newCourse.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse);
			course newCourse2;
			newCourse2.courseName = "ECS 1100";
			newCourse2.creditVal = 3;
			newCourse2.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse2);
			course newCourse3;
			newCourse3.courseName = "CS 1200";
			newCourse3.creditVal = 2;
			newCourse3.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse3);
			course newCourse4;
			newCourse4.courseName = "CS 1336";
			newCourse4.creditVal = 3;
			newCourse4.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse4);
			course newCourse5;
			newCourse5.courseName = "CS 1136";
			newCourse5.creditVal = 1;
			newCourse5.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse5);
			course newCourse6;
			newCourse6.courseName = "MATH 2413";
			newCourse6.creditVal = 4;
			newCourse6.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse6);
			course newCourse7;
			newCourse7.courseName = "MATH 2417";
			newCourse7.creditVal = 4;
			newCourse7.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse7);
			course newCourse8;
			newCourse8.courseName = "CS 2305";
			newCourse8.creditVal = 3;
			newCourse8.taken = 0;
			repeatCheck(takenCourses, &possibleCourses, newCourse8);
		}
	}

	// Returning the Vector of Possible Courses
	return possibleCourses;
}

// Function to Store the Possible Courses to a File
void storeCourses(vector <course> possibleCourses, string filename)
{
	// Opening the File
	ofstream outFile;
	outFile.open(filename);

	// Writing to File
	for (int i = 0; i < possibleCourses.size(); i++)
	{
		outFile << possibleCourses[i].courseName << endl;
	}

	// Closing the File
	outFile.close();
}

// Function to Display Info to Console
void displayInfo(user newUser, vector <course> possibleCourses)
{
	// Displaying Name, Major, Credits and Year
	cout << "Your name is " << newUser.getName() << " and you are a " << newUser.getMajor();
	cout << " major. You currently have " << newUser.getCredits() << " credits and are a " << newUser.getYearLevel() << ".\n" << endl;

	// Displaying the Courses the User Can Take
	cout << "You can take the following courses next semester:\n==============================================================\n" << endl;
	for (int i = 0; i < possibleCourses.size(); i++)
	{
		cout << possibleCourses[i].courseName << endl;
	}
}

// Main Function
int main()
{
	// Creating a New User
	user currentUser = createUser();

	// Calculating Credits and Year Level
	calcCredits(&currentUser);

	// Making List of Possible Courses
	vector <course> possible = possibleCourses(currentUser);

	// Exporting Possible Courses to File
	string filename = currentUser.getName() + ".txt";
	storeCourses(possible, filename);

	// Displaying to Console
	displayInfo(currentUser, possible);

	// Program Completion
	cout << "\n\nProgram Completed" << endl;
	return 0;
}
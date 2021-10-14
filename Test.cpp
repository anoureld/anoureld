///////////////////////////////////////////////
// 
// Team 1 (Mark Lunstead, Nick Lyons, Maher Noureldine)
// CSE 687 Object-Oriented Design, Fall 2021, section M400, Professor Scott Roueche
// Project 1 - Single-User Test Harness, due date 10/19
// 
// Test.cpp
//  - definition file for Test abstract class (implementation of member functions)
//  - initializes static data member countOfTests to zero (shared class-wide variable)
//  - defines 33 functions (excludes 3 pure virtual from the 36 total declared in the header file):
//     - 1) default constructor (initialization for data members testID, testDate,
//          testTime, testShortName, testLongName, userID, testResult, testSummaryLine,
//          testSummaryRecord, TestDetailRecord)
//     - 2) virtual destructor
//     - 3)-14) getter functions for each of the data members
//     - 15)-26) setter functions for each of the data members
//     - 27) an increment function for static data member countOfTests
//     - 28) a decrement function for static data member countOfTests
//     - 29) a combined setter function for date and time
//     - 30) a function to print summary test info (including result) as a single line (for use in table output)
//     - 31) a function to print summary test info (WITHOUT result) as a single line (for use in table output)
//     - 32) a function to print summary test info (including result) in record format
//     - 33) a virtual function to reset all the data members to default values
// 
///////////////////////////////////////////////

// preprocessing directives, to include header files for 1) various sections of the C++ standard library, and 2) programmer-defined custom classes
//  - these files contain function prototypes for the related functions that form each portion of the library, and for the custom classes
#include <ctime> // functions that manipulate the time and date
#include <iomanip> // functions that manipulate streams of data i.e. formatting
#include <iostream> // functions for standard input and output
#include <sstream> // functions that perform input and output from/to strings in memory
#include "Test.h" // definition of abstract class Test

// using declarations, which identify usage of specific standard library functions to allow keywords (alone) to be used in the code
using std::ostringstream; // class name for ostringstream objects (from sstream.h)
using std::cout; // object name for the standard output stream (from iostream.h)
using std::cin; // object name for the standard input stream (from iostream.h)
using std::setw; // parameterized stream manipulator, sets field width for output (from iomanip.h)

// declare and initialize shared (class-wide) counter of all Test objects
int Test::countOfTests = 0;

// default constructor
//  - note: testDate and testTime are initialized by default constructors
//    for Date and Time classes respectively
Test::Test()
	: testShortName{ "BLANK" }, testLongName{ "BLANK"}, userID{ 0 },
	testResult{ 0 }, testSummaryLine{ "BLANK" }, testSummaryRecord{ "BLANK" },
	testDetailRecord{ "BLANK" }
{
	// increment count of Test objects, set entry ID to next value
	countOfTests++;
	setTestID(countOfTests);
}

// destructor
Test::~Test()
{
	decrementCountOfTests();
}

// the following functions are PUBLIC
//  - there are no private functions in this class

// setter function for static data member countOfTests
void Test::setCountOfTests(int count)
{
	countOfTests = count;
}

// getter function for data member countOfTests
int Test::getCountOfTests()
{
	return countOfTests;
}

// increment function for static data member countOfTests
void Test::incrementCountOfTests()
{
	countOfTests++;
}

// decrement function for static data member countOfTests
void Test::decrementCountOfTests()
{
	countOfTests--;
}

// setter function for data member testID
void Test::setTestID(int TID)
{
	testID = TID;
}

// getter function for data member testID
int Test::getTestID()
{
	return testID;
}

// setter function for date and time
//  - only allows setting with current system date and time
void Test::setTestDateAndTime()
{
	// define current date/time based on current system value
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);

	// set testDate and testTime as current system value
	testDate.setDate(1 + newtime.tm_mon, newtime.tm_mday, 1900 + newtime.tm_year);
	testTime.setTime(newtime.tm_hour, newtime.tm_min, newtime.tm_sec);
}

// setter function for data member testDate
void Test::setTestDate(Date date)
{
	testDate = date;
}

// getter function for data member testDate
Date Test::getTestDate()
{
	return testDate;
}

// setter function for data member testTime
void Test::setTestTime(Time time)
{
	testTime = time;
}

// getter function for data member testTime
Time Test::getTestTime()
{
	return testTime;
}

// setter function for data member testShortName
void Test::setTestShortName(string sName)
{
	testShortName = sName;
}

// getter function for data member testShortName
string Test::getTestShortName()
{
	return testShortName;
}

// setter function for data member testLongName
void Test::setTestLongName(string lName)
{
	testLongName = lName;
}

// getter function for data member testLongName
string Test::getTestLongName()
{
	return testLongName;
}

// setter function for data member userID
void Test::setUserID(int UID)
{
	userID = UID;
}

// getter function for data member userID
int Test::getUserID()
{
	return userID;
}

// setter function for data member testResult
void Test::setTestResult(bool result)
{
	testResult = result;
}

// getter function for data member testResult
bool Test::getTestResult()
{
	return testResult;
}

// setter function for data member testSummaryLine
void Test::setTestSummaryLine(string summLine)
{
	testSummaryLine = summLine;
}

// getter function for data member testSummaryLine
string Test::getTestSummaryLine()
{
	return testSummaryLine;
}

// setter function for data member testSummaryLineNoResult
void Test::setTestSummaryLineNoResult(string summLineNoResult)
{
	testSummaryLineNoResult = summLineNoResult;
}

// getter function for data member testSummaryLineNoResult
string Test::getTestSummaryLineNoResult()
{
	return testSummaryLineNoResult;
}

// setter function for data member testSummaryRecord
void Test::setTestSummaryRecord(string summRec)
{
	testSummaryRecord = summRec;
}

// getter function for data member testSummaryRecord
string Test::getTestSummaryRecord()
{
	return testSummaryRecord;
}

// setter function for data member testDetailRecord
void Test::setTestDetailRecord(string detRec)
{
	testDetailRecord = detRec;
}

// getter function for data member testDetailRecord
string Test::getTestDetailRecord()
{
	return testDetailRecord;
}

// virtual function to print the test summary on a single line
void Test::toStringTestSummaryLine()
{
	ostringstream output;

	// declare temp variables to hold date and time (for conversion to strings)
	Date tempDate = testDate;
	Time tempTime = testTime;

	// output key data members in a single row as a string to to data member testSummaryLine
	//  - formatting is intended to match header row (with column headings) that is printed in calling program
	output << "\t" << setw(8) << getTestID() << setw(25) << getTestShortName() << setw(8) << getUserID()
		<< setw(12) << tempDate.toString() << setw(12) << tempTime.toUniversalString()
		<< setw(13) << (getTestResult() ? "Passed" : "Failed") << "\n";
	testSummaryLine = output.str();
}

// virtual function to print the test summary (without result, date or time) on a single line 
void Test::toStringTestSummaryLineNoResult()
{
	ostringstream output;

	// output key data members in a single row as a string to to data member testSummaryLine
	//  - formatting is intended to match header row (with column headings) that is printed in calling program
	output << "\t" << setw(8) << getTestID() << setw(25) << getTestShortName() << setw(8) << getUserID() << "\n";
	testSummaryLineNoResult = output.str();
}

// virtual function to print the test summary as a record
void Test::toStringTestSummaryRecord()
{
	// declare temp variables to hold date and time (for conversion to strings)
	Date tempDate = getTestDate();
	Time tempTime = getTestTime();

	// output key data members in record format as a string to data member testSummaryRecord
	ostringstream output;
	output << "\n\tTest summary:\n" // print header
		<< "\n\t   Test ID: " << getTestID() << "\n" // display the test ID
		<< "\t   Test Name: " << getTestShortName() << "\n" // display the test short name
		<< "\t   User ID: " << getUserID() << "\n" // display the userid
		<< "\t   Test date: " << tempDate.toString() << "\n" // display the test date
		<< "\t   Test time: " << tempTime.toUniversalString() << "\n" // display the test time
		<< "\t   Test result: " << (getTestResult() ? "PASSED" : "FAILED") << "\n"; // diplay the test result
	testSummaryRecord = output.str();
}

// virtual function to re-initialize all fields on the test object (e.g. for use when drafting a new object)
void Test::reInitializeTest()
{
	setTestID(0);
	Date tempDate; // create new temp Date object, default initialization is 1/1/1900
	setTestDate(tempDate); // use temp object to re-initialize data member entryDate
	Time tempTime; // create new temp Time object, default initialization is 00:00:00
	setTestTime(tempTime); // use temp object to re-initialize data member entryTime
	setTestShortName("BLANK");
	setTestLongName("BLANK");
	setUserID(0);
	setTestResult(0);
}

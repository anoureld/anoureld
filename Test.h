///////////////////////////////////////////////
// 
// Team 1 (Mark Lunstead, Nick Lyons, Maher Noureldine)
// CSE 687 Object-Oriented Design, Fall 2021, section M400, Professor Scott Roueche
// Project 1 - Single-User Test Harness, due date 10/19
// 
// Test.h
//  - header file for Test abstract class (declaration of data members and member functions)
//  - purpose - base class for all simulated test objects that will be executed by the test harness
//  - 12 private data members: testID, testDate, testTime, testShortName, testLongName, userID,
//    testResult, countOfTests, testSummaryLine, testSummaryLineNoResult, testSummaryRecord, and testDetailRecord
//     - countOfTests is a static counter of test objects (shared class-wide)
//  - 36 member functions:
//     - a default constructor
//     - a virtual destructor
//     - getter functions for each of the 12 data members
//     - setter functions for each of the 12 data members
//     - an increment function for static data member countOfTests
//     - a decreement function for static data member countOfTests
//     - a combined setter function for date and time
//     - a pure virtual function to enter additional details of the test
//        - these are defined and implemented in the various classes derived from this base class
//     - a function to print summary test info (including result) as a single line (for use in table output)
//     - a function to print summary test info (WITHOUT result) as a single line (for use in table output)
//     - a function to print summary test info (including result) in record format
//     - a pure virtual function to print detailed test info in record format
//        - implementation will be defined in each of the derived classes, to account for
//          different output parameters for different tests
//     - a virtual function to reset all the data members to default values
//     - a pure virtual function to override the function operator (= makes this class a functor)
//        - implementation will be defined in each of the derived classes, to account for
//          different output parameters for different tests
//  - when an object of this class is declared, default initializations are as follows:
//     - testID is assigned by incrementing a static integer variable (countOfTests) and
//       is unique for each object of the class
//     - testDate and entryTime are initialized to x and y by the default constructors
//       for the Date and Time classes, respectively
//     - customerAccountNumber and entryAmount are set with real values when objects of any derived classes are created
//     - userID is set to zero
//     - testResult is set to false (i.e. test fails)
//     - testShortName and testLongName are set to BLANK
//     - testSummaryLine, testSummaryRecord, and testDetailRecord are set to BLANK
// 
///////////////////////////////////////////////

#ifndef TEST_H // include guard line 1
#define TEST_H // include guard line 2

// preprocessing directives, to include header files for 1) various sections of the C++ standard library, and 2) programmer-defined custom classes
//  - these files contain function prototypes for the related functions that form each portion of the library, and for the custom classes
#include <string> // definition of class string and related functions
#include "Date.h" // definition of class Date
#include "Time.h" // definition of class Time

// using declarations, which identify usage of specific standard library functions to allow keywords (alone) to be used in the code
using std::string; // class name for string objects (from string.h)

class Test
{

public:

	// default constructor
	Test();

	// destructor
	virtual ~Test();

	// setter function for static data member countOfTest
	static void setCountOfTests(int count);

	// getter function for data member countOfTests
	static int getCountOfTests();

	// increment function for static data member countOfTests
	static void incrementCountOfTests();

	// decrement function for static data member countOfTests
	static void decrementCountOfTests();

	// setter function for data member testID
	void setTestID(int TID);

	// getter function for data member testID
	int getTestID();

	// setter function for date and time
	void setTestDateAndTime();

	// setter function for data member testDate
	void setTestDate(Date date);

	// getter function for data member testDate
	Date getTestDate();

	// setter function for data member testTime
	void setTestTime(Time time);

	// getter function for data member testTime
	Time getTestTime();

	// setter function for data member testShortName
	void setTestShortName(string sName);

	// getter function for data member testShortName
	string getTestShortName();

	// setter function for data member testLongName
	void setTestLongName(string lName);

	// getter function for data member testLongName
	string getTestLongName();

	// setter function for data member userID
	void setUserID(int UID);

	// getter function for data member userID
	int getUserID();

	// setter function for data member testResult
	void setTestResult(bool result);

	// getter function for data member testResult
	bool getTestResult();

	// setter function for data member testSummaryLine
	void setTestSummaryLine(string summLine);

	// getter function for data member testSummaryLine
	string getTestSummaryLine();

	// setter function for data member testSummaryLineNoResult
	void setTestSummaryLineNoResult(string summLine);

	// getter function for data member testSummaryLineNoResult
	string getTestSummaryLineNoResult();

	// setter function for data member testSummaryRecord
	void setTestSummaryRecord(string summRec);

	// getter function for data member testSummaryRecord
	string getTestSummaryRecord();

	// setter function for data member testDetailRecord
	void setTestDetailRecord(string detRec);

	// getter function for data member testDetailRecord
	string getTestDetailRecord();

	// pure virtual function to enter the details of the test
	virtual void enterTestDetails() = 0;

	// function to print the summary test results on a single line (for table output)
	void toStringTestSummaryLine();

	// function to print the summary test results on a single line (for table output)
	void toStringTestSummaryLineNoResult();

	// function to print summary test results in record format
	void toStringTestSummaryRecord();

	// pure virtual function to print detailed test results in record format
	//  - will be defined in derived classes
	virtual void toStringTestDetailRecord() = 0;

	// virtual function to re-initialize all fields on the test object
	virtual void reInitializeTest();

	// pure virtual function to override function operator (= makes this class a functor)
	//  - will be defined in derived classes
	virtual bool operator()(void) = 0;

private:

	// data members
	static int countOfTests; // static (shared class-wide variable) counter of test objects
	int testID; // test ID (unique reference number)
	Date testDate; // date that the test was last executed
	Time testTime; // time that the test was last executed
	string testShortName; // short name for this test
	string testLongName; // long name for this test (i.e. brief functional description)
	int userID; // customer account number (to which invoice will be billed)
	bool testResult; // result of test (true = test passed, false = test failed)
	string testSummaryLine; // one line string of text, giving summary of test and result
	string testSummaryLineNoResult; // one line string of text, giving summary of test WITHOUT result
	string testSummaryRecord; // multiple-line string, giving summary of test and result
	string testDetailRecord; // multiple-line string, giving detailed test output

}; // end class Test

#endif // end include guard
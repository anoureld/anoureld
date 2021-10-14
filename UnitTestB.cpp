///////////////////////////////////////////////
// 
// Team 1 (Mark Lunstead, Nick Lyons, Maher Noureldine)
// CSE 687 Object-Oriented Design, Fall 2021, section M400, Professor Scott Roueche
// Project 1 - Single-User Test Harness, due date 10/19
// 
// UnitTestB.cpp
//  - definition file for UnitTestB class (implementation of member functions)
//  - defines 15 functions:
//     - 1) initialization constructor (allows setting testShortName and userID (both from base class Test)
//          as well as testPassOrFail (flag to indicate what should be the simulated test result)
//     - 2) an overloaded initialization constructor, allows setting of testShortName, userID, and
//          testPassOrFail as per constructor above, PLUS allows setting of the three integer test outputs
//     - 3) destructor
//     - 4)-7) getter functions for each of the data members
//     - 8)-11) setter functions for each of the data members
//     - 12) a virtual function to enter test details (was declared as pure virtual in base class Test)
//     - 13) a virtual function to print the test reference info (and summary result) in record format
//     - 14) a virtual function to reset all the data members to default values
//     - 15) a function operator override (= makes this class a functor)
// 
///////////////////////////////////////////////

// preprocessing directives, to include header files for 1) various sections of the C++ standard library, and 2) programmer-defined custom classes
//  - these files contain function prototypes for the related functions that form each portion of the library, and for the custom classes
#include <iostream> // functions for standard input and output
#include <sstream> // functions that perform input and output from/to strings in memory
#include "UnitTestB.h" // definition of class UnitTestA

// using declarations, which identify usage of specific standard library functions to allow keywords (alone) to be used in the code
using std::cout; // object name for the standard output stream (from iostream.h)
using std::cin; // object name for the standard input stream (from iostream.h)
using std::ostringstream; // class name for ostringstream objects (from sstream.h)

// initialization constructor
UnitTestB::UnitTestB(string sName, int UID, bool passOrFailFlag)
	: testPassOrFailFlag{ passOrFailFlag }, testOutput01{ 0 }, testOutput02{ 0 },
	testOutput03{ 0 }
{
	setTestShortName(sName);
	setUserID(UID);
	toStringTestSummaryLineNoResult(); // populate text string with short test description info
}

// overloaded initialization constructor
UnitTestB::UnitTestB(string sName, int UID, bool passOrFailFlag, int param01,
	int param02, int param03)
	: testPassOrFailFlag{ passOrFailFlag }, testOutput01{ param01 }, testOutput02{ param02 },
	testOutput03{ param03 }
{
	setTestShortName(sName);
	setUserID(UID);
	toStringTestSummaryLineNoResult(); // populate text string with short test description info
}

// destructor
UnitTestB::~UnitTestB()
{
	// no custom functions to perform
}

// The following functions are PUBLIC

// Setter function for simulated test result flag
void UnitTestB::setTestPassOrFailFlag(bool passOrFailFlag)
{
	testPassOrFailFlag = passOrFailFlag;
}

// Getter function for simulated test result flag
bool UnitTestB::getTestPassOrFailFlag()
{
	return testPassOrFailFlag;
}

// Setter function for test output parameter 01
void UnitTestB::setTestOutput01(int param01)
{
	testOutput01 = param01;
}

// Getter function for test output parameter 01
int UnitTestB::getTestOutput01()
{
	return testOutput01;
}

// Setter function for test output parameter 02
void UnitTestB::setTestOutput02(int param02)
{
	testOutput02 = param02;
}

// Getter function for test output parameter 02
int UnitTestB::getTestOutput02()
{
	return testOutput02;
}

// Setter function for test output parameter 03
void UnitTestB::setTestOutput03(int param03)
{
	testOutput03 = param03;
}

// Getter function for test output parameter 03
int UnitTestB::getTestOutput03()
{
	return testOutput03;
}

// function to enter the test details
// - was declared as pure virtual in base class Test
void UnitTestB::enterTestDetails()
{
	// Declare temp variables used to hold user input and to perform input checking
	string userInputText;
	bool userInputBool;
	int userInputInt;
	
	// Ask user for test long name
	cout << "\n\tEnter long name for test (= brief description): ";
	cin >> userInputText;
	setTestLongName(userInputText);

	// Ask user whether simulation will result in pass or fail
	cout << "\n\tDo you want the simulation to result in pass or fail";
	cout << "\n\t(Enter positive integer for pass, zero for fail): ";
	cin >> userInputBool;
	testPassOrFailFlag = userInputBool;

	// Ask user for test output parameters, set related data members
	cout << "\n\tInput test output parameter 01 (integer): ";
	cin >> userInputInt;
	testOutput01 = userInputInt; // set parameter 01
	cout << "\n\tInput test output parameter 02 (integer): ";
	cin >> userInputInt;
	testOutput02 = userInputInt; // set parameter 02
	cout << "\n\tInput test output parameter 03 (integer): ";
	cin >> userInputInt;
	testOutput03 = userInputInt; // set parameter 03

} // end function enterTestDetails

// function to print detailed test results in record format
//  - was declared as pure virtual in base class Test
void UnitTestB::toStringTestDetailRecord()
{
	// declare temp variables to hold date and time (for conversion to strings)
	Date tempDate = getTestDate();
	Time tempTime = getTestTime();

	// output key data members in record format as a string to data member testDetailRecord
	ostringstream output;
	output << "\n\tTest summary:\n" // print header
		<< "\n\t   Test ID: " << getTestID() << "\n" // display the test ID
		<< "\t   Test Name: " << getTestShortName() << "\n" // display the test short name
		<< "\t   User ID: " << getUserID() << "\n" // display the userid
		<< "\t   Test date: " << tempDate.toString() << "\n" // display the test date
		<< "\t   Test time: " << tempTime.toUniversalString() << "\n" // display the test time
		<< "\t   Test result: " << (getTestResult() ? "PASSED" : "FAILED") << "\n" // diplay the test result
		<< "\t   Test outputs:\n" // header for test output details
		<< "\t      Output 01: " << getTestOutput01() << "\n" // display output parameter 01
		<< "\t      Output 02: " << getTestOutput02() << "\n" // display output parameter 02
		<< "\t      Output 03: " << getTestOutput03() << "\n"; // display output parameter 03
	setTestDetailRecord(output.str());
}

// virtual function to re-initialize all fields on the test object
//  - was declared as virtual in base class Test (this is an override)
void UnitTestB::reInitializeTest()
{
	Test::reInitializeTest(); // re-initialize data members defined in base class Test
	testPassOrFailFlag = false;
	testOutput01 = 0;
	testOutput02 = 0;
	testOutput03 = 0;
}

// Function operator override (= makes this class a functor)
//  - simulates test execution
//  - executes any operations needed to produce or modify the outputs
//  - populates the output strings from the test (that will be displayed by the test harness)
//  - also throws exceptions that will be caught by the test harness
bool UnitTestB::operator()(void)
{
	// set date and time as per system clock to indicate when test was performed
	setTestDateAndTime();

	if (testPassOrFailFlag) // test passed
	{
		setTestResult(true); // set test result = passed
	}
	else // test failed
	{
		// throw exceptions
		// TBD

		setTestResult(false); // set test result = failed
	}

	// create output strings (that will be displayed by the test harness)
	toStringTestSummaryLine(); // populates data member testSummaryLine
	toStringTestSummaryRecord(); // populates data member testSummaryRecord
	toStringTestDetailRecord(); // populates data member testDetailRecord

	// return test result
	return getTestResult();
}

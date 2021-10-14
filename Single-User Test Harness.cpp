///////////////////////////////////////////////
// 
// Team 1 (Mark Lunstead, Nick Lyons, Maher Noureldine)
// CSE 687 Object-Oriented Design, Fall 2021, section M400, Professor Scott Roueche
// Project 1 - Single-User Test Harness, due date 10/19
// 
// Single-User Test Harness.cpp
//  - DOCUMENTATION TO BE ADDED
// 
// To complete:
//   1. Consolidate redundant display functions (test library, test sequence, test output)
//   2. Move all testLibrary and testSequence management functions to separate TestHarness object and document
//   3. Add exception throws to UnitTestA and UnitTestB
//   4. Add exception catches to executeTestSequence function (currently in top-level file)
//   5. Finish coding mid-level and low-level outputs in executeTestSequence function (currently in top-level file)
//   6. Complete documentation of top-level file
// 
///////////////////////////////////////////////

// preprocessing directives, to include header files for 1) various sections of the C++ standard library, and 2) programmer-defined custom classes
//  - these files contain function prototypes for the related functions that form each portion of the library, and for the custom classes
#include <iomanip> // functions that manipulate streams of data i.e. formatting
#include <iostream> // functions for standard input and output
#include <string> // definition of class String
#include <vector> // definition of class Vector
#include "UnitTestA.h" // definition of class UnitTestA
#include "UnitTestB.h" // definition of class unitTestB

// using declarations, which identify usage of specific standard library functions to allow keywords (alone) to be used in the code
using std::cout; // object name for the standard output stream (from iostream.h)
using std::cin; // object name for the standard input stream (from iostream.h)
using std::string; // class name for string objects (from string.h)
using std::vector; // class name for vector objects (from vector.h)
using std::setw; // parameterized stream manipulator, sets field width for output (from iomanip.h)
using std::fixed; // non-parameterized stream manipulator, indicates that floating point values should be output in fixed-point format (vs scientific notation) (from iomanip.h)

// function prototype, to print the menu of available program options (for user to select)
void printMenu();

// function prototype, to display the current test library
void viewTestLibrary(vector<Test*>& testLibrary, int& testLibraryCounter, int& currentUID);

// function prototype, to display the current test sequence
void viewTestSequence(vector<Test*>& testSequence, int& testSequenceCounter, int& currentUID);

// function prototype, to void the current test sequence
void voidTestSequence(vector<Test*>& testSequence, int& testSequenceCounter, int& currentUID);

// function prototype, to enter a new test sequence
void inputTestSequence(vector<Test*>& testLibrary, int testLibraryCounter, vector<Test*>& testSequence, int& testSequenceCounter, int& currentUID);

// Function prototype, to execute the test sequence
void executeTestSequence(vector<Test*>& testSequence, int& testSequenceCounter, int& currentUID, int& outputLevel);

int main()
{
	// Print out header describing purpose of program and giving guidance to user
	cout << "\n-----------------------------------------------------------------------------------------------";
	cout << "\nSingle-User Test Harness";
	cout << "\n";
	cout << "\n\tEnables testing of multiple different software packages";
	cout << "\n\t  - packages are defined as callable objects, providing test outputs in common format";
	cout << "\n\tPackages are first written (as classes), declared (as objects), and entered into a test library";
	cout << "\n\t  - this is done in code (i.e. not directly user-enabled)";
	cout << "\n\tUser can select packages from the library for entry into a test sequence";
	cout << "\n\tUser can request execution of the test sequence with three different levels of output:";
	cout << "\n\t  1) summary results only";
	cout << "\n\t  2) summary results plus any exceptions thrown";
	cout << "\n\t  3) detailed results (e.g. key test parameters) plus any exceptions thrown";
	cout << "\n-----------------------------------------------------------------------------------------------\n";

	// declare a single user ID to represent the single user
	int currentUID{ 1 };

	// declare a vector of Test objects
	//  - this is the "test library" of available tests
	vector<Test*> testLibrary(20);

	// declare a temp variable to store the count of test objects
//  - this is held in a static int variable in Test class but have added this to ease use in main program
//    and to ease the reading of the main program code
	int testLibraryCounter{ 0 };

	// declare a vector of Test object pointers and a related counter
	//  - this is the "test sequence" to be executed by the harness
	vector<Test*> testSequence(20);
	int testSequenceCounter = 0;

	// define callable test objects
	UnitTestA module1v1("Module 1 v1.0", currentUID, false, true, false, true, false); // module 1 v1.0 fails
	UnitTestA module1v2("Module 1 v1.1", currentUID, true, true, true, true, true); // module 2 v1.1 passes
	UnitTestB module2v1("Module 2 v1.0", currentUID, false, 23, 58, 12345); // module 2 v1.0 fails
	UnitTestB module2v2("Module 2 v1.1", currentUID, false, 23, 64, 40302); // module 2 v1.1 fails
	UnitTestB module2v3("Module 2 v1.2", currentUID, true, 23, 64, 21001); // module 2 v1.2 passes

	// load test objects into library and increment library counter
	testLibrary[1] = &module1v1;
	testLibrary[2] = &module1v2;
	testLibrary[3] = &module2v1;
	testLibrary[4] = &module2v2;
	testLibrary[5] = &module2v3;
	testLibraryCounter = 5;

	// declare variables to hold user input
	int desiredAction{ 0 };
	int outputLevel{ 0 };

	do
	{
		// ask user for desired action
		cout << "\nPlease choose desired action (enter action number (or 0 for menu) then hit <return>): ";
		cin >> desiredAction;

		switch (desiredAction)
		{
		case 0: // print menu of available actions
			printMenu();
			break;

		case 1: // view the current test sequence

			viewTestLibrary(testLibrary, testLibraryCounter, currentUID);
			break;

		case 2: // view the current test sequence

			viewTestSequence(testSequence, testSequenceCounter, currentUID);
			break;

		case 3: // enter a new test sequence (NOTE: this action voids the current test sequence)

			voidTestSequence(testSequence, testSequenceCounter, currentUID);
			inputTestSequence(testLibrary, testLibraryCounter, testSequence, testSequenceCounter, currentUID);
			break;

		case 4: // execute the test sequence and show only summary results

			outputLevel = 1;
			executeTestSequence(testSequence, testSequenceCounter, currentUID, outputLevel);
			break;

		case 5: // execute the test sequence and show summary results and exceptions thrown (if any)

			outputLevel = 2;
			cout << "\n\t(THIS OPTION HAS NOT YET BEEN CODED)\n"; // TEMPORARY WARNING MESSAGE
			// executeTestSequence(testSequence, testSequenceCounter, currentUID, outputLevel);
			break;

		case 6: // execute the test sequence and show detailed results and exceptions thrown (if any)

			outputLevel = 3;
			cout << "\n\t(THIS OPTION HAS NOT YET BEEN CODED)\n"; // TEMPORARY WARNING MESSAGE
			// executeTestSequence(testSequence, testSequenceCounter, currentUID, outputLevel);
			break;

		case 7: // exit the program

			// Confirm the program will end
			cout << "\n\nProgram ended\n";

			break;

		default: // handling for invalid input

			cout << "\n\t\tInvalid input - please try again";
			break;

		} // end switch for user selection of desired function

	} while (desiredAction != 7);

} // end main function

// function to print the menu of available program options (for user to select)
void printMenu()
{
	cout << "\n\tActions available:";
	cout << "\n\t   1 - Display the current test library";
	cout << "\n\t   2 - Display the current test sequence";
	cout << "\n\t   3 - Create a new test sequence (NOTE: this voids the current test sequence)";
	cout << "\n\t   4 - Execute test sequence and show summary results only";
	cout << "\n\t   5 - Execute test sequence and show summary results along with exceptions thrown (if any)";
	cout << "\n\t   6 - Execute test sequence and show detailed results along with exceptions thrown (if any)";
	cout << "\n\t   7 - Exit the program\n";
}

// Function to display the current test library
void viewTestLibrary(vector<Test*>& testLibrary, int& testLibraryCounter, int& currentUID)
{
	cout << "\n\tCurrent test library:\n"; // print table heading
	cout << "\n\t" << setw(8) << "TestID" << setw(25) << "TestShortName" << setw(8) << "UserID"
		<< "\n\n"; // print column headings
	if (0 == testLibraryCounter) // if test library is empty
	{
		cout << "\t  (No tests in library)\n"; // print error message
	}
	else // test library is not empty
	{
		if (currentUID >= 1) // real userID is used to choose this option, to print only entries booked to that account
		{
			for (int i = 1; i <= testLibraryCounter; i++)  // iterate through complete list of entries
			{
				if (currentUID == testLibrary[i]->getUserID()) // only print the entry details if booked to this account
				{
					cout << testLibrary[i]->getTestSummaryLineNoResult();
				}
			}
		}
		else // dummy userID of less than 1 is used to choose this option, to print ALL entries
		{
			for (int i = 1; i <= testLibraryCounter; i++)  // iterate through complete list of entries
			{
				cout << testLibrary[i]->getTestSummaryLineNoResult();
			}

		} // end if statement checking if real user

	} // end if statement checking if testLibrary is empty

} // end function displayTestLibrary

// Function to display the current test sequence
void viewTestSequence(vector<Test*>& testSequence, int& testSequenceCounter, int& currentUID)
{
	cout << "\n\tCurrent test sequence:\n"; // print table heading
	cout << "\n\t" << setw(8) << "TestID" << setw(25) << "TestShortName" << setw(8) << "UserID"
		<< "\n\n"; // print column headings
	if (0 == testSequenceCounter) // if test sequence is empty
	{
		cout << "\t  (No tests in current sequence)\n"; // print error message
	}
	else // test sequence is not empty
	{
		if (currentUID >= 1) // real userID is used to choose this option, to print only entries booked to that account
		{
			for (int i = 1; i <= testSequenceCounter; i++)  // iterate through complete list of entries
			{
				if (currentUID == testSequence[i]->getUserID()) // only print the entry details if booked to this account
				{
					cout << testSequence[i]->getTestSummaryLineNoResult();
				}
			}
		}
		else // dummy userID of less than 1 is used to choose this option, to print ALL entries
		{
			for (int i = 1; i <= testSequenceCounter; i++)  // iterate through complete list of entries
			{
				cout << testSequence[i]->getTestSummaryLineNoResult();
			}

		} // end if statement checking if real user

	} // end if statement checking if test sequence is empty

} // end function viewTestSequence

// Function to void the current test sequence
void voidTestSequence(vector<Test*>& testSequence, int& testSequenceCounter, int& currentUID)
{
	// Reset test sequence vector
	for (int i = 1; i <= testSequenceCounter; i++)
	{
		testSequence[i] = nullptr;
	}
	// Reset test sequence counter
	testSequenceCounter = 0;
}

// Function to enter a new test sequence
void inputTestSequence(vector<Test*>& testLibrary, int testLibraryCounter, vector<Test*>& testSequence, int& testSequenceCounter, int& currentUID)
{
	if (0 == testLibraryCounter) // if test library is empty
	{
		cout << "\n\tNo tests in library - aborting test sequence selection\n"; // print error message
	}
	else // test library is not empty
	{
		// Show currently available tests
		cout << "\n\tCurrent test library (you will select from these tests):\n"; // print table heading
		cout << "\n\t" << setw(8) << "TestID" << setw(25) << "TestShortName" << setw(8) << "UserID"
			<< "\n\n"; // print column headings
		for (int i = 1; i <= testLibraryCounter; i++)  // iterate through complete list of entries
		{
			cout << testLibrary[i]->getTestSummaryLineNoResult();
		}

		// Declare temp variable used to hold user input
		int userInputTestID{ 1 };

		// Ask user for tests in sequence
		while (0 != userInputTestID)
		{
			cout << "\n\tInput number of test to be added to the new sequence";
			cout << "\n\t(enter zero to end sequence input): ";
			cin >> userInputTestID;
			if (0 == userInputTestID) // test if user wishes to end sequence entry
			{
				cout << "\n\tTest sequence input ended\n";
			}
			else
			{
				if (0 > userInputTestID || testLibraryCounter < userInputTestID) // test for invalid input
				{
					cout << "\n\t\tInvalid input - try again\n"; // print error message if so
				}
				else // input is valid
				{
					testSequenceCounter++; // increment test sequence counter
					testSequence[testSequenceCounter] = testLibrary[userInputTestID]; // add test to sequence
					// Display current sequence
					cout << "\n\tCurrent test sequence is:\n"; // print table heading
					cout << "\n\t" << setw(8) << "TestID" << setw(25) << "TestShortName" << setw(8) << "UserID"
						<< "\n\n"; // print column headings
					for (int i = 1; i <= testSequenceCounter; i++)  // iterate through complete list of entries
					{
						cout << testSequence[i]->getTestSummaryLineNoResult();
					}
				}

			} // end if statement checking for valid input

		} // end while loop requesting test sequence input

	} // end if statement checking if test library is empty

} // end function inputTestSequence

// Function to execute the test sequence
void executeTestSequence(vector<Test*>& testSequence, int& testSequenceCounter, int& currentUID, int& outputLevel)
{
	if (0 == testSequenceCounter) { // if test sequence is empty
		cout << "\n\tNo tests in current sequence - aborting test sequence execution\n"; // print error message
	}
	else // test sequence is not empty
	{
		// execute tests
		//  - NOTE: NEED TO ADD TRY-CATCH BLOCK FOR EXCEPTIONS THROWN BY THE TEST OBJECTS
		for (int i = 1; i <= testSequenceCounter; i++)  // iterate through complete list of entries
		{
			bool tempOutput;
			tempOutput = (*testSequence[i])(); // execute callable test object
		}

		// display test results
		if (1 == outputLevel) // print only summary test output
		{
			cout << "\n\tSummary test results are:\n"; // print sub-table heading
			cout << "\n\t" << setw(8) << "TestID" << setw(25) << "TestShortName" << setw(8) << "UserID"
				<< setw(12) << "TestDate" << setw(12) << "TestTime" << setw(13) << "TestResult" << "\n\n"; // print column headings
			if (currentUID >= 1) // real account number is used to choose this option, to print only entries booked to that account
			{
				for (int i = 1; i <= testSequenceCounter; i++)  // iterate through complete list of entries
				{
					if (currentUID == testSequence[i]->getUserID()) // only print the entry details if booked to this account
					{
						cout << testSequence[i]->getTestSummaryLine();
					}
				}
			}
			else // dummy account number of less than 1 is used to choose this option, to print ALL entries
			{
				for (int i = 1; i <= testSequenceCounter; i++)  // iterate through complete list of entries
				{
					cout << testSequence[i]->getTestSummaryLine();
				}
			}
		} // end if statement selecting output level 1

		// NEED TO ADD CODE FOR OUTPUT LEVEL 2

		// NEED TO ADD CODE FOR OUTPUT LEVEL 3

	} // end if statement checking for empty test sequence

} // end function executeTestSequence
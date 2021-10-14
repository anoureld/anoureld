///////////////////////////////////////////////
// 
// Team 1 (Mark Lunstead, Nick Lyons, Maher Noureldine)
// CSE 687 Object-Oriented Design, Fall 2021, section M400, Professor Scott Roueche
// Project 1 - Single-User Test Harness, due date 10/19
// 
// UnitTestA.h
//  - header file for UnitTestA class (declaration of data members and member functions)
//  - purpose - simulated test program that will be executed by the test harness
//  - 5 private data members:
//     - testPassOrFail (input flag, sets whether test will pass or fail)
//     - testOutput01, testOutput02, testOutput03, testOutput04 (simulated test outputs, all booleans)
//  - 17 member functions:
//     - an initialiation constructor allowing user to set testShortName, userID, and testPassOrFailFlag
//     - an overloaded initialization constructor allower user to set testShortName, userID, testPassOrFailFlag,
//       and the four boolean test outputs
//     - a virtual destructor
//     - setter and getter functions for each of the 5 data members
//     - a virtual function to enter test details (was declared as pure virtual in base class Test)
//     - a virtual function to print the test reference info (and summary result) in record format
//     - a virtual function to reset all the data members to default values
//     - a function operator override (= makes this class a functor)
//        - when object is called, simulated test is run (= string outputs are created, that will be
//          displayed by the test harness) and single boolean is returned to indicate whether
//          the simulated test passed (= true) or failed (= false)
// 
///////////////////////////////////////////////

#ifndef UNITTESTA_H // include guard line 1
#define UNITTESTA_H // include guard line 2

// preprocessing directives, to include header files for 1) various sections of the C++ standard library, and 2) programmer-defined custom classes
//  - these files contain function prototypes for the related functions that form each portion of the library, and for the custom classes
#include "Test.h" // definition of abstract class Test

class UnitTestA : public Test
{

public:

	// initialization constructor
	UnitTestA(string sName, int UID, bool passOrFailFlag);

	// overloaded initialization constructor
	UnitTestA(string sName, int UID, bool passOrFailFlag, bool param01,
		bool param02, bool param03, bool param04);

	// destructor
	~UnitTestA();

	// Setter function for simulated test result flag
	void setTestPassOrFailFlag(bool passOrFailFlag);

	// Getter function for simulated test result flag
	bool getTestPassOrFailFlag();

	// Setter function for test output parameter 01
	void setTestOutput01(bool param01);

	// Getter function for test output parameter 01
	bool getTestOutput01();

	// Setter function for test output parameter 02
	void setTestOutput02(bool param02);

	// Getter function for test output parameter 02
	bool getTestOutput02();

	// Setter function for test output parameter 03
	void setTestOutput03(bool param03);

	// Getter function for test output parameter 03
	bool getTestOutput03();

	// Setter function for test output parameter 04
	void setTestOutput04(bool param04);

	// Getter function for test output parameter 04
	bool getTestOutput04();

	// function to enter the test details
	// - was declared as pure virtual in base class Test
	virtual void enterTestDetails();

	// function to print detailed test results in record format
	//  - was declared as pure virtual in base class Test
	virtual void toStringTestDetailRecord();

	// virtual function to re-initialize all fields on the test object
	//  - was declared as virtual in base class Test
	virtual void reInitializeTest() override;

	// Function operator override (= makes this class a functor)
	//  - was declared as pure virtual in base class Test
	//  - simulates test execution
	//  - executes any operations needed to produce or modify the outputs
	//  - populates the output strings from the test (that will be displayed by the test harness)
	//  - also throws exceptions that will be caught by the test harness
	//  - returns true for test passed, false for test failed
	virtual bool operator()(void) override;

private:

	// data members
	bool testPassOrFailFlag; // flag to determine output of simulated test
	bool testOutput01; // dummy test output parameter (to display to user following test)
	bool testOutput02; // dummy test output parameter (to display to user following test)
	bool testOutput03; // dummy test output parameter (to display to user following test)
	bool testOutput04; // dummy test output parameter (to display to user following test)

}; // end class UnitTest

#endif // end include guard
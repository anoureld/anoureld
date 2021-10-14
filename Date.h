///////////////////////////////////////////////
// 
// Team 1 (Mark Lunstead, Nick Lyons, Maher Noureldine)
// CSE 687 Object-Oriented Design, Fall 2021, section M400, Professor Scott Roueche
// Project 1 - Single-User Test Harness, due date 10/19
// 
// Date.h
//  - header file for Date class (declaration of data members and member functions)
//  - purpose - holds day/month/year, can return a string showing that date in mm/dd/yyyy format
//  - 3 private data members, all held as unsigned integers: month, day, and year
//  - 1 public data member, monthsPerYear, which is a static constant held as an unsigned int
//    (shared class-wide)
//  - 5 member functions:
//     - a default constructor which sets month, day, year to 1/1/1900
//     - an initialiation constructor that allows setting of all three data members
//     - a destructor (just default)
//     - a single setter function for all three data members
//     - a function to return the data in text string format mm/dd/yyyy
//  - when an object of this class is declared, by default the month, day, and year
//    are set to 1/1/1900 (January 1st, 1900)
// 
///////////////////////////////////////////////

#ifndef DATE_H // include guard line 1
#define DATE_H // include guard line 2

// preprocessing directives, to include header files for 1) various sections of the C++ standard library, and 2) programmer-defined custom classes
//  - these files contain function prototypes for the related functions that form each portion of the library, and for the custom classes
#include <string> // definition of class string and related functions

// using declarations, which identify usage of specific standard library functions to allow keywords (alone) to be used in the code
using std::string;  // class name for string objects (from string.h)

class Date
{
public:

	// public data member (static constant shared with all objects of the class)
	static const unsigned int monthsPerYear{ 12 }; // months in a year

	// default constructor
	Date();

	// initialization constructor
	Date(unsigned int mn, unsigned int dy, unsigned int yr);

	// destructor
	~Date();
	
	// function to set the date
	void setDate(unsigned int mn, unsigned int dy, unsigned int yr);

	// function to return a date string in month/day/year format
	string toString() const;

private:

	// data members
	unsigned int month; // 1-12 (January-December)
	unsigned int day; // 1-31 based on month
	unsigned int year; // any year

}; // end class Date

#endif // end include guard

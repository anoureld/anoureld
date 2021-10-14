///////////////////////////////////////////////
// 
// Team 1 (Mark Lunstead, Nick Lyons, Maher Noureldine)
// CSE 687 Object-Oriented Design, Fall 2021, section M400, Professor Scott Roueche
// Project 1 - Single-User Test Harness, due date 10/19
// 
// Date.cpp
//  - definition file for Date class (implementation of member functions)
//  - defines 5 functions:
//     - 1) a default constructor
//     - 2) an initialization constructor (for data members month, day, year)
//     - 3) a destructor
//     - 4) a single combined setter function for day, month, and year
//     - 5) a function to return the date as a text string in mm/dd/yyyy format
// 
///////////////////////////////////////////////

// preprocessing directives to include header files for 1) various sections of the C++ standard library, and 2) programmer-defined custom classes
//  - these files contain function prototypes for the related functions that form each portion of the library, and for the custom classes
#include <sstream> // functions that perform input and output from/to strings in memory
#include "Date.h" // definition of class Date

// using declarations, which identify usage of specific standard library functions to allow keywords (alone) to be used in the code
using std::ostringstream; // class name for ostringstream objects (from sstream.h)

// default constructor
Date::Date()
    : month{ 1 }, day{ 1 }, year{ 1900 } {
}

// initialization constructor
Date::Date(unsigned int mn, unsigned int dy, unsigned int yr)
    : month{ mn }, day{ dy }, year{ yr } {
}

// destructor
Date::~Date()
{
    // (no custom actions to perform)
}

void Date::setDate(unsigned int mn, unsigned int dy, unsigned int yr)
{
    month = mn;
    day = dy;
    year = yr;
}

// print Date object in form month/day/year
string Date::toString() const {
    ostringstream output;
    output << month << '/' << day << '/' << year;
    return output.str();
}

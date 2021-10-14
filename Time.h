///////////////////////////////////////////////
// 
// Team 1 (Mark Lunstead, Nick Lyons, Maher Noureldine)
// CSE 687 Object-Oriented Design, Fall 2021, section M400, Professor Scott Roueche
// Project 1 - Single-User Test Harness, due date 10/19
// 
// Time.h
//  - header file for Time class (declaration of data members and member functions)
//  - purpose - holds hour/minute/second, can return a string showing that time in HH:MM:SS
//       in either Universal time (24 hour) format or Standard time (12 hour format)
//        - standard time string that is returned also includes an AM/PM identifier
//  - 3 private data members, all held as unsigned integers: hour, minutes, and seconds
//  - 9 member functions:
//     - a default constructor which sets month, day, year to 00:00:00 (= 12 midnight)
//     - an initialiation constructor that allows setting of all three data members
//     - a destructor (just default)
//     - a single combined setter function for day, month, and year
//     - getter functions for each of the three data members
//     - a function to return the time in Universal format - hh:mm:ss as a text string
//     - a function to return the time in standard format - hh:mm:ss as a text string
//  - when an object of this class is declared, by default the hours, minutes, and seconds
//    are all set to zero (= 12 midnight)
// 
///////////////////////////////////////////////

#ifndef TIME_H // include guard line 1
#define TIME_H // include guard line 2

// preprocessing directives, to include header files for 1) various sections of the C++ standard library, and 2) programmer-defined custom classes
//  - these files contain function prototypes for the related functions that form each portion of the library, and for the custom classes
#include <string> // definition of class string and related functions

// using declarations, which identify usage of specific standard library functions to allow keywords (alone) to be used in the code
using std::string; // class name for string objects (from string.h)

class Time {

public:

	// default constructor
	Time();

	// initialization constructor
	Time(int hr, int min, int sec);

	// destructor
	~Time();

	// set hour, minute, and second all at onece
	void setTime(int hr, int min, int sec);

	// get value of hour
	unsigned int getHour() const;

	// get value of minute
	unsigned int getMinute() const;

	// get value of second
	unsigned int getSecond() const;

	// function to return string showing time in 24-hour format
	std::string toUniversalString() const;

	// function to return string showing time in 12-hour format
	std::string toStandardString() const;

private:

	// data members
	unsigned int hour; // 0 - 23 (24-hour clock format)
	unsigned int minute; // 0 - 59
	unsigned int second; // 0 - 59

}; // end class Time

#endif // end include guard

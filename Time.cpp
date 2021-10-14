///////////////////////////////////////////////
// 
// Team 1 (Mark Lunstead, Nick Lyons, Maher Noureldine)
// CSE 687 Object-Oriented Design, Fall 2021, section M400, Professor Scott Roueche
// Project 1 - Single-User Test Harness, due date 10/19
// 
// Time.cpp
//  - definition file for Time class (implementation of member functions)
//  - defines 9 functions:
//     - 1) a default constructor
//     - 2) an initialization constructor (for data members hour, minute, and second)
//     - 3) a destructor
//     - 4) a single combined setter function for all three data members
//     - 5-7) getter functions for each of the three data members
//     - 8) a function to return the time in Universal format - hh:mm:ss as a text string
//     - 9) a function to return the time in standard format - hh:mm:ss as a text string
// 
///////////////////////////////////////////////

// preprocessing directives, to include header files for 1) various sections of the C++ standard library, and 2) programmer-defined custom classes
//  - these files contain function prototypes for the related functions that form each portion of the library, and for the custom classes
#include <iomanip> // functions for standard input and output
#include <sstream> // functions that perform input and output from/to strings in memory
#include "Time.h" // definition of class Time

// using declarations, which identify usage of specific standard library functions to allow keywords (alone) to be used in the code
using std::ostringstream; // class name for ostringstream objects (from sstream.h)
using std::setfill; // parameterized stream manipulator, specifies fill character used for output to fixed width fields (if needed) (from iomanip.h)
using std::setw; // parameterized stream manipulator, sets field width for output (from iomanip.h)

// default constructor
Time::Time()
    : hour{ 0 }, minute{ 0 }, second{ 0 } {
}

// initialization constructor
//  - calls member function setTime to set variables;
//  - default values are 0 (see class definition)
Time::Time(int hr, int min, int sec) {
    setTime(hr, min, sec);
}

// destructor
Time::~Time()
{
    // no custom functions to perform
}

// set values of hour, minute, and second all at once
void Time::setTime(int hr, int min, int sec) { // note Time& return
    hour = hr;
    minute = min;
    second = sec;
}

// get value of hour
unsigned int Time::getHour() const
{
    return hour;
}

// get value of minute
unsigned int Time::getMinute() const
{
    return minute;
}

// get value of second
unsigned int Time::getSecond() const
{
    return second;
}

// return Time as a string in universal-time format (HH:MM:SS)
string Time::toUniversalString() const {
    ostringstream output;
    output << setfill('0') << setw(2) << getHour() << ":"
        << setw(2) << getMinute() << ":" << setw(2) << getSecond();
    return output.str();
}

// return Time as string in standard-time format (HH:MM:SS AM or PM)
string Time::toStandardString() const {
    ostringstream output;
    output << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
        << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2)
        << getSecond() << (hour < 12 ? " AM" : " PM");
    return output.str();
}

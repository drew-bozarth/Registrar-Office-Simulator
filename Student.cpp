/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 5 - Student.cpp */

/*
This is the .cpp file for Student
*/

//includes the Student.h file
#include "Student.h"

/*
Function: Student()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
//sets member variables to 0
Student::Student(){
  arrival = 0;
  windowTime = 0;
  waitTime = 0;
}

/*
Function: Student()
Return: none
Parameters: int a, int w (overloaded constructor)
Exceptions: none
*/
//sets the member variable arrival time and windowTime to the parameter inputs
Student::Student(int a, int w){
  arrival = a;
  windowTime = w;
}

/*
Function: ~Student()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
Student::~Student(){
  arrival = 0;
  windowTime = 0;
}

/*
Function: printStudent()
Return: string
Parameters: none
Exceptions: none
*/
//prints out the Student stats
string Student::printStudent(){
  string s;
  s += "Arrival Time: ";
  s += arrival;
  s += "\nTime waiting: ";
  s += waitTime;
  s += "Time needed at window: ";
  s += windowTime;
}
/*
Function: getArrival()
Return: int
Parameters: none
Exceptions: none
*/
//returns the arrival time of the student
int Student::getArrival(){
  return arrival;
}
/*
Function: getWindowTime()
Return: int
Parameters: none
Exceptions: none
*/
//returns the window time of the student
int Student::getWindowTime(){
  return windowTime;
}
/*
Function: updateWaitTime()
Return: none
Parameters: int wait
Exceptions: none
*/
//sets the waitTime to the parameter input
void Student::updateWaitTime(int wait){
  waitTime = wait;
}

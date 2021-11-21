/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 5 - Student.h */

/*
This is the .h file for Student
*/

//these are the header guards
#ifndef STUDENT_H
#define STUDENT_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
#include <string>
//standard namespace libaray in C++
using namespace std;

class Student{
public:
  Student();
  Student(int a, int w);
  ~Student();
  string printStudent();
  void updateWaitTime(int wait);
  int getArrival();
  int getWindowTime();
  void setWindowTime();
  int arrival;
  int windowTime;
  int waitTime;
private:


};
//end of the header guards
#endif

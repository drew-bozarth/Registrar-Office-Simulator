/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 5 - Window.h */

/*
This is the .h file for Window
*/

//these are the header guards
#ifndef WINDOW_H
#define WINDOW_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
#include <string>
//includes the Student.h Class
#include "Student.h"
//standard namespace libaray in C++
using namespace std;

class Window{
public:
  Window();
  ~Window();
  bool isAvailable();
  void setWindowBusy(Student *s1);
  void emptyWindow();
  void setIdleTime();
  int getIdleTime();
  int getOccupiedTime();
  int getEntryTime();
  int occupiedTime;
  int entryTime;
  int idleTime;
  bool isWindowEmpty;
private:

};
//end of the header guards
#endif

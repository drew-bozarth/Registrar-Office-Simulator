/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 5 - Simulation.h */

/*
This is the .h file for Simulation
*/

//these are the header guards
#ifndef SIMULATION_H
#define SIMULATION_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
//includes the ListInterface template class, and the Student.h, Window.h, and FileProcessor.h files
#include "ListInterface.h"
#include "Student.h"
#include "Window.h"
#include "FileProcessor.h"
//standard namespace libaray in C++
using namespace std;

class Simulation{

public:
  Simulation();
  ~Simulation();
  void simulate(string file);
  void calcStudent(MyList<int> *students);
  void calcWindows(MyList<int> *windows);
private:
  MyList<int> *idleTimes;
  MyList<int> *waitTimes;
};
//end of the header guards
#endif

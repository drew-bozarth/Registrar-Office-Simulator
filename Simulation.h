#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <exception>
#include "ListInterface.h"
#include "Student.h"
#include "Window.h"
#include "FileProcessor.h"
using namespace std;

class Simulation{

public:
  Simulation();
  ~Simulation();
  void simulate(string file);
private:
  MyList<int> *idleTimes;
  MyList<int> *waitTimes;
};
#endif

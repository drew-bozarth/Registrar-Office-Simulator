#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <exception>
#include <string>
using namespace std;

class Student{
  //add more setters and getters to variables
public:
  Student();
  Student(int a, int w);
  ~Student();
  string printStudent();
  void updateWaitTime();
  int getArrival();
  int getWindowTime();
  void setWindowTime();
private:
  int arrival;
  int windowTime;
  int waitTime;

};
#endif

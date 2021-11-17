#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <exception>
#include <string>
using namespace std;

class Student{
  public:
    Student();
    Student(int a, int w);
    ~Student();
    int getArrival();
    int getWindowTime();
  private:
    int arrival;
    int windowTime;
    int exitTime;
    int waitTime;
};
#endif

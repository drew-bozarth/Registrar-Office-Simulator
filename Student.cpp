#include "Student.h"

Student::Student(){
  arrival = 0;
  windowTime = 0;
  exitTime = 0;
  waitTime = 0;
};

Student::Student(int a, int w){
  arrival = a;
  windowTime = w;
};

Student::~Student(){
  arrival = 0;
  windowTime = 0;
  exitTime = 0;
};

int Student::getArrival(){
  return arrival;
};

int Student::getWindowTime(){
  return windowTime;
};

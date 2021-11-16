#include "Student.h"

Student::Student(){
  arrival = 0;
  windowTime = 0;
  // exitTime = 0;
  waitTime = 0;
}

Student::Student(int a, int w){
  arrival = a;
  windowTime = w;
}

Student::~Student(){
  arrival = 0;
  windowTime = 0;
  // exitTime = 0;
}

string Student::printStudent(){
  string s;
  s += "Arrival Time: ";
  s += arrival;
  s += "\nTime waiting: ";
  s += waitTime;
  s += "Time needed at window: ";
  s += windowTime;
}
int Student::getArrival(){
  return arrival;
}

int Student::getWindowTime(){
  return windowTime;
}

void Student::updateWaitTime(){
  ++waitTime;
}

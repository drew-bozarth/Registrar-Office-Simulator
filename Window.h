#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <exception>
#include <string>
#include "Student.h"

class Window{
public:
  Window();
  Window(Student s1);
  ~Window();
  bool isAvailable();
  void setWindowBusy();
  void emptyWindow();
  void setIdleTime();
  int getIdleTime();
  Student* getStudent();
private:
  Student newStudent;
  // int totalWindows;
  int idleTime;
  bool isWindowEmpty;
};

#endif

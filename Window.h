#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <exception>
#include <string>
#include "Student.h"

class Window{
public:
  Window();
  ~Window();
  bool isAvailable();
  void fillWindow(Student s1);
  void emptyWindow();
  void setIdleTime();
  int getIdleTime();
private:
  Student student;
  int totalWindows;
  int idleTime;
  bool isWindowfull;
}

#endif

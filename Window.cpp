#include "Window.h"

//when implementing window, create a double pointer array and initialize
Window::Window(){}

Window::Window(Student s1){
  newStudent = s1;
}

Window::~Window(){}

bool Window::isAvailable(){
return (!isWindowfull);
}

void Window::fillWindow(Student s1){
idleTime = 0;
isWindowfull = true;
}

void Window::emptyWindow(){
  isWindowfull = false;
  setIdleTime();
}

void Window::setIdleTime(){
  ++idleTime;
}

int Window::getIdleTime(){
  return idleTime;
}

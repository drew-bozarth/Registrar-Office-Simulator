#include "Window.h"

Window::Window(){}

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

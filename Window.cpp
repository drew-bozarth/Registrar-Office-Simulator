#include "Window.h"

//when implementing window, create a double pointer array and initialize
Window::Window(){}

Window::Window(Student s1){
  newStudent = s1;
}

Window::~Window(){}

bool Window::isAvailable(){
return (isWindowEmpty);
}

void Window::setWindowBusy(){
idleTime = 0;
isWindowEmpty = false;
}

void Window::emptyWindow(){
  isWindowEmpty = true;
  setIdleTime();
}

void Window::setIdleTime(){
  ++idleTime;
}

int Window::getIdleTime(){
  return idleTime;
}

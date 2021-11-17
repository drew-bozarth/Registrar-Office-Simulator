#include "Window.h"

//when implementing window, create a double pointer array and initialize
Window::Window(){}

// Window::Window(Student s1){
// }

Window::~Window(){}

bool Window::isAvailable(){
return (isWindowEmpty);
}

void Window::setWindowBusy(Student *s1){
idleTime = 0;
isWindowEmpty = false;
// newStudent = s1;
// occupiedTime = s1->windowTime;
}

void Window::emptyWindow(){
  occupiedTime = 0;
  isWindowEmpty = true;
  setIdleTime();
}

void Window::setIdleTime(){
  ++idleTime;
}

int Window::getIdleTime(){
  return idleTime;
}

int Window::getOccupiedTime(){
  return occupiedTime;
}

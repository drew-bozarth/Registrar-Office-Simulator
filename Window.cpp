/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 5 - Window.cpp */

/*
This is the .cpp file for Window
*/

//includes the Window.h file
#include "Window.h"

/*
Function: Window()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
//sets member variables
Window::Window(){
  idleTime = 0;
  isWindowEmpty = true;
}

/*
Function: ~Window()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
Window::~Window(){}

/*
Function: isAvailable()
Return: bool
Parameters: none
Exceptions: none
*/
//returns a bool checking if the window is available
bool Window::isAvailable(){
  return (isWindowEmpty);
}

/*
Function: setWindowBusy()
Return: none
Parameters: Student *s1
Exceptions: none
*/
//occupies the window with the student parameter
void Window::setWindowBusy(Student *s1){
  idleTime = 0;
  isWindowEmpty = false;
  occupiedTime = s1->windowTime;
  entryTime = s1->arrival;
}

/*
Function: emptyWindow()
Return: none
Parameters: none
Exceptions: none
*/
//empties the window
void Window::emptyWindow(){
  occupiedTime = 0;
  isWindowEmpty = true;
  setIdleTime();
}

/*
Function: getOccupiedTime()
Return: int
Parameters: none
Exceptions: none
*/
//returns an int of the occupiedTime
int Window::getOccupiedTime(){
  return occupiedTime;
}
/*
Function: getEntryTime()
Return: int
Parameters: none
Exceptions: none
*/
//returns an int of the entry time
int Window::getEntryTime(){
  return entryTime;
}
/*
Function: setIdleTime()
Return: none
Parameters: none
Exceptions: none
*/
//increments the idle time by 1
void Window::setIdleTime(){
  ++idleTime;
}
/*
Function: getIdleTime()
Return: int
Parameters: none
Exceptions: none
*/
//returns an int of the idle time
int Window::getIdleTime(){
  return idleTime;
}

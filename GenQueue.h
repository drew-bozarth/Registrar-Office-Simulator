/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 5 - GenQueue.h */

/*
This is a template class for a Queue
*/

//these are the header guards
#ifndef GENQUEUE_H
#define GENQUEUE_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
//includes the ListInterface template Class
#include "ListInterface.h"
//standard namespace libaray in C++
using namespace std;

/*
Template Class: GenQueue
*/
template <class T>
class GenQueue{
  public:
    GenQueue(); //default constructor
    virtual ~GenQueue(); //destructor

    //core functions
    //make it as a pointer?
    void insert(T data); //aka enqueue()
    T remove(); //aka dequeue()

    //aux functions
    T peek(); //aka front()
    bool isEmpty();
    unsigned int getSize(); //unsigned because it will never be negative
    void printQueue();

  private:
    MyList<T> *myList;
    unsigned int mSize;
    unsigned int numElements;
};

/*
Function: GenQueue()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
//creates a new list and sets member variables to 0
template <class T>
GenQueue<T>::GenQueue(){
  myList = new MyList<T>();
  mSize = 0;
  numElements = 0;
}

/*
Function: ~GenQueue()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
template <class T>
GenQueue<T>::~GenQueue(){
  delete myList;
}

/*
Function: insert()
Return: none
Parameters: T data
Exceptions: none
*/
//inserts the data to the back of the queue
template <class T>
void GenQueue<T>::insert(T data){
  myList->append(data);
}

/*
Function: remove()
Return: T
Parameters: none
Exceptions: none
*/
//removes and returns the data from the front of the queue
template <class T>
T GenQueue<T>::remove(){
  if(myList->isEmpty()){
    throw runtime_error("queue is empty remove");
  }

  return myList->removeFront();
}

/*
Function: peek()
Return: T
Parameters: none
Exceptions: none
*/
//returns the data from the front of the queue without removing it
template <class T>
T GenQueue<T>::peek(){
  if (myList->isEmpty()){
    throw runtime_error("queue is empty peek");
  }
  return myList->viewFront();
}

/*
Function: isEmpty()
Return: bool
Parameters: none
Exceptions: none
*/
//returns a bool checking if the list is empty
template <class T>
bool GenQueue<T>::isEmpty(){
  return (myList->isEmpty());
}

/*
Function: getSize()
Return: unsigned int
Parameters: none
Exceptions: none
*/
//returns an int of the size of the queue
template <class T>
unsigned int GenQueue<T>::getSize(){
  return (myList->getSize());
}

/*
Function: printQueue()
Return: none
Parameters: none
Exceptions: none
*/
//prints out the queue
template <class T>
void GenQueue<T>::printQueue(){
  myList->print();
}

//end of the header guards
#endif

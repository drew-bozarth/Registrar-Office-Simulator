/* Drew Bozarth
2373658
dbozarth@chapman.edu
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
//includes the DoublyLinkedList template Class
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
    void insert(T data); //aka enqueue()
    T remove(); //aka dequeue()
    void insertPriQueue(T data);

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

template <class T>
GenQueue<T>::GenQueue(){
  // cout << "in queue constructor" << endl;
  myList = new MyList<T>();
  mSize = 0;
  numElements = 0;
}

template <class T>
GenQueue<T>::~GenQueue(){

}

template <class T>
void GenQueue<T>::insert(T data){
  myList->append(data);
  // cout << data << ", inserted." << endl;
}

template <class T>
T GenQueue<T>::remove(){
  if(myList->isEmpty()){
    throw runtime_error("queue is empty");
  }

  return myList->removeFront();
}

template <class T>
void GenQueue<T>::insertPriQueue(T data){
  //not necessary for this assignment
}

template <class T>
T GenQueue<T>::peek(){
  if (myList->isEmpty()){
    throw runtime_error("queue is empty");
  }
  return myList->viewFront();;
}

template <class T>
bool GenQueue<T>::isEmpty(){
  return (myList->isEmpty());
}

template <class T>
unsigned int GenQueue<T>::getSize(){
  return (myList->getSize());
}

template <class T>
void GenQueue<T>::printQueue(){
  myList->print();
}


#endif

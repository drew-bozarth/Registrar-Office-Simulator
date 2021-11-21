/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 5 - ListInterface.h */


#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
//includes the DoublyLinkedList template Class
#include "LinkedList.h"
//standard namespace libaray in C++
using namespace std;

/*
Template Class: ListInterface
*/
template <class T>
class ListInterface{
  public:
    // ListInterface(); //default constructor
    // virtual ~ListInterface(); //destructor

    virtual void append(T item){};
    virtual void prepend(T item){};
    // virtual void insertAfterSorted(ListNode<T>* currentItem, ListNode<T>* insertItem){};
    virtual T remove(T item){};
    virtual T removeFront(){};
    virtual int search(T item){};
    virtual void print(){};
    virtual void printReverse(){};
    // virtual void sort(){};
    // virtual void sortInsert(ListNode<T>* curr);
    virtual bool isEmpty(){};
    virtual unsigned int getLength(){};
};

template <class T>
class MyList : public ListInterface<T>
{
  public:
    // ListInterface();
    // ~ListInterface();
    MyList();
    ~MyList();
    void append(T item);
    void prepend(T item);
    void insertAfter(ListNode<T>* currentItem, ListNode<T>* insertItem);
    T remove(T item);
    T removeFront();
    int search(T item);
    T viewFront();
    void print();
    void printReverse();
    void sort();
    bool isEmpty();
    unsigned int getLength();
  private:
    DoublyLinkedList<T> *myLinkedList;
};

template <class T>
MyList<T>::MyList(){
  myLinkedList = new DoublyLinkedList<T>();
}

template <class T>
MyList<T>::~MyList(){
  delete myLinkedList;
}

template <class T>
void MyList<T>::append(T item) {
  // cout << "in append" << endl;
  myLinkedList->insertBack(item);
}

template <class T>
void MyList<T>::prepend(T item) {
  myLinkedList->insertFront(item);
}

template <class T>
void MyList<T>::insertAfter(ListNode<T>* currentItem, ListNode<T>* insertItem) {
  myLinkedList->insertAfter(currentItem, insertItem);
}

template <class T>
T MyList<T>::remove(T item) {
  return myLinkedList->removeNode(item);
}

template <class T>
int MyList<T>::search(T item) {
  return myLinkedList->find(item);
}

template <class T>
T MyList<T>::viewFront() {
  return myLinkedList->getFront();
}

template <class T>
void MyList<T>::print() {
  bool printLink = false;
  myLinkedList->printList(printLink);
}

template <class T>
void MyList<T>::printReverse() {
  // not necessary for this assignment
}

template <class T>
void MyList<T>::sort() {
  myLinkedList->sort();
}

template <class T>
bool MyList<T>::isEmpty() {
  return (myLinkedList->isEmpty());
}

template <class T>
unsigned int MyList<T>::getLength() {
  return myLinkedList->getSize();
}

template <class T>
T MyList<T>::removeFront(){
  return myLinkedList->removeFront();
}


#endif

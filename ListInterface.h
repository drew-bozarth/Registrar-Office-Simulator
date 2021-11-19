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
    virtual void insertAfter(T currentItem, T insertItem){};
    virtual T remove(T item){};
    virtual T search(T item){};
    virtual void print(){};
    virtual void printReverse(){};
    virtual void sort(){};
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
    void insertAfter(T currentItem, T insertItem);
    T remove(T item);
    T removeFront();
    T search(T item);
    T viewFront();
    void print();
    void printReverse();
    void sort();
    void sortInsert(ListNode* curr);
    bool isEmpty();
    unsigned int getLength();
  private:
    DoublyLinkedList<T> *myLinkedList;
    DoublyLinkedList<T> *sortedList;
};

template <class T>
MyList<T>::MyList(){
  myLinkedList = new DoublyLinkedList<T>();
}

template <class T>
MyList<T>::~MyList(){
  delete myLinkedList;
  delete sortedList;
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
void MyList<T>::insertAfter(T currentItem, T insertItem) {
  // need this
}

template <class T>
T MyList<T>::remove(T item) {
  return myLinkedList->removeNode(item);
}

template <class T>
T MyList<T>::search(T item) {
  return myLinkedList->find(item);
}

template <class T>
T MyList<T>::viewFront() {
  return myLinkedList->front->data;
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
  sortedList = new DoublyLinkedList<T>();
  ListNode *current = myLinkedList->front;
  ListNode *next = NULL;

  while (current != NULL){
    next = current->next;

    sortInsert(current);
    current = next;
  }
}

template <class T>
void MyList<T>::sortInsert(ListNode *curr){
  ListNode* sortedCurrent = sortedList->front;
  ListNode* sortedNext = NULL;

  if (sortedList->front == NULL){
    sortedList->append(curr);
    return;
  }
  else if (curr->data < sortedCurrent->data){
    sortedList->prepend(curr);
    return;
  }

  while (sortedCurrent->next != NULL && curr->data < sortedCurrent->data){
    sortedNext = sortedCurrent->next;
    sortedCurrent = sortedNext;
  }
  sortedList->insertAfter(curr, sortedCurrent);
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

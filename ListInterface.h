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
    ListInterface(); //default constructor
    virtual ~ListInterface(); //destructor

    virtual void append(DoublyLinkedList<T> list, T item) const = 0;
    virtual void prepend(DoublyLinkedList<T> list, T item) const = 0;
    virtual void insertAfter(DoublyLinkedList<T> list, T currentItem, T insertItem) const = 0;
    virtual T remove(DoublyLinkedList<T> list, T item) const = 0;
    virtual T search(DoublyLinkedList<T> list, T item) const = 0;
    virtual void print(DoublyLinkedList<T> list) const = 0;
    virtual void printReverse(DoublyLinkedList<T> list) const = 0;
    virtual void sort(DoublyLinkedList<T> list) const = 0;
    virtual bool isEmpty(DoublyLinkedList<T> list) const = 0;
    virtual unsigned int getLength(DoublyLinkedList<T> list) const = 0;
};

template <class T>
class MyList : public ListInterface<T>
{
  public:
    ListInterface();
    ~ListInterface();

    void append(T item) const;
    void prepend(T item) const;
    void insertAfter(T currentItem, T insertItem) const;
    T remove(T item) const;
    T removeFront() const;
    T search(T item) const;
    void print() const;
    void printReverse() const;
    void sort() const;
    bool isEmpty() const;
    unsigned int getLength() const;
  private:
    DoublyLinkedList<T> *myLinkedList;
};

template <class T>
MyList<T>::ListInterface(){
  myLinkedList = new DoublyLinkedList<T>();
}

template <class T>
MyList<T>::~ListInterface(){
}

template <class T>
void MyList<T>::append(T item) const{

}

template <class T>
void MyList<T>::prepend(T item) const{

}

template <class T>
void MyList<T>::insertAfter(T currentItem, T insertItem) const{

}

template <class T>
T MyList<T>::remove(T item) const{

}

template <class T>
T MyList<T>::search(T item) const{

}

template <class T>
void MyList<T>::print() const{

}

template <class T>
void MyList<T>::printReverse() const{

}

template <class T>
void MyList<T>::sort() const{

}

template <class T>
bool MyList<T>::isEmpty() const{

}

template <class T>
unsigned int MyList<T>::getLength() const{

}


#endif

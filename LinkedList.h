/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 5 - LinkedList.h */

/*
This is a template class for a Doubly LinkedList
*/

//these are the header guards
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
//standard namespace libaray in C++
using namespace std;

/*
Template Class: ListNode
*/
template <class T>
class ListNode{
  public:
    ListNode();
    ListNode(T d);
    virtual ~ListNode();
    ListNode *next;
    ListNode *prev;
    T data;
};

/*
Function: ListNode()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
template <class T>
ListNode<T>::ListNode(){

}

/*
Function: ListNode(T d)
Return: none
Parameters: T d (Type is T for the template class)
Exceptions: none
*/
template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

/*
Function: ~ListNode()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
template <class T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
}


/*
Template Class: DoublyLinkedList
*/
template <class T>
class DoublyLinkedList{
  private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;
  public:
    DoublyLinkedList();
    virtual ~DoublyLinkedList();

    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    T removeNode(T value);
    T find(T value);
    bool isEmpty();
    unsigned int getSize();
    void printList(bool isPrintLink);
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  front = NULL;
  back = NULL;
  size = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  //guess what?? build some character and research
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d){

  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty()){
    back = node;
  }
  else{
    //it is not empty
    node->next = front;
    front->prev = node;
  }
  front = node;
  ++size;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){

  ListNode<T> *node = new ListNode<T>(d);
  if(isEmpty()){
    front = node;
  }
  else{
    //it is not empty
    node->prev = back;
    back->next = node;
  }
  back = node;
  ++size;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
  if (isEmpty()){
    throw runtime_error("list is empty!!");
  }

  ListNode<T> *temp = front;

  if(front->next == NULL){
    //only one node in the list and it's the front node
    back = NULL;
  }
  else{
    //more than one node in the list
    front->next->prev = NULL;
  }

  front = front->next;
  temp->next = NULL;
  T data = temp->data;
  --size;
  delete temp;

  return data;
}

template <class T>
T DoublyLinkedList<T>::removeBack(){
  if (isEmpty()){
    throw runtime_error("list is empty!!");
  }

  ListNode<T> *temp = back;

  if (back->prev = NULL){
    //only one node in the list
    front = NULL;
  }
  else{
    //more than one node in the list
    back->prev->next = NULL;
  }

  back = back->prev;
  temp->prev = NULL;
  T data = temp->data;
  --size;
  delete temp;

  return data;
}

template <class T>
T DoublyLinkedList<T>::removeNode(T value){

  if (isEmpty()){
    throw runtime_error("list is empty");
  }

  //we can leverage the find method to decide whether we continue or not
  ListNode<T> *curr = front;
  while(curr->data != value){
    curr = curr->next;
    if(curr == NULL){
      return -1;
    }

  }

  //but we make it here, we found the value
  //we found it, let's proceed to remmove it

  if (curr == front){
    front = curr->next;
    front->prev = NULL;
  }
  if (curr == back){
    back = curr->prev;
    back->next = NULL;
  }
  if (curr != front && curr != back){
    //listnode is between front and back
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }
  curr->next = NULL;
  curr->prev = NULL;
  T data = curr->data;
  --size;

  delete curr;

  return data;
}

template <class T>
T DoublyLinkedList<T>::find(T value){
  int pos = -1;
  ListNode<T> *curr = front;

  while (curr != NULL){
    ++pos;
    if(curr->data == value){
      break;
    }
    curr = curr->next;
  }
  if (curr == NULL)
    pos = -1;

  return pos;
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return (size == 0);
}

template <class T>
void DoublyLinkedList<T>::printList(bool printLink)
{
    ListNode<T> *curr = front;
    while(curr != 0){
       if(curr == front){
         cout << "{FRONT}: ";
       }
       else if(curr == back){
         cout << "{REAR}: ";
       }
       if(printLink)
        cout << "[ PREV: " << curr->prev << " || " << curr->data << " || NEXT: " << curr->next << " ] ";
      else
        cout << "[ " << curr->data << " ] ";
       curr = curr->next;
       if(curr != 0){
         cout << " ==> ";
       }
    }
    cout << endl;
}




#endif

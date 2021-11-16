/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 5 - main.cpp */

/*
Main file for Assignment5
*/

//these statements include the user defined files into this file to be used
#include "GenQueue.h"
#include "FileProcessor.h"
// standard namespace library in C++
using namespace std;
/*
Function: main
Return: int (returns a 0 or -1 based on if the main method runs correctly)
Parameters: int (argc, number of command line arguments), char** (argv, array of char pointers which is pretty much an array of the command line arguments)
Exceptions: none
*/
int main(int argc, char** argv){
  // GenQueue<int> *gq = new GenQueue<int>();
  // gq->insert(1);
  // gq->insert(6);
  // gq->insert(7);
  // gq->insert(3);
  // gq->insert(9);
  // gq->remove();
  // gq->printQueue();
  //example code from class
  /*
  int capacity = 5;
  MyWindow **wind = new Window*[capacity];

  for (int i =0; i < capacity; ++i){
    wind[i] = new MyWindow(new Student(i+1));
  }

  wind[0]->setWindowBusy();
  wind[0]->updateIdleTime();
  wind[0]->updateIdleTime();
  wind[0]->updateIdleTime();
  wind[0]->updateIdleTime();

  cout << wind[0]->getIdleTime() << endl;
  cout << wind[1]->getIdleTime() << endl;
  cout << wind[2]->getIdleTime() << endl;

  cout << "Student " << wind[0]->getStudent()->getTimeNeeded() << endl;

  delete [] wind;
  */



  FileProcessor *fp = new FileProcessor();
  if(argc > 1){
    string userFilePath = argv[1];
    fp->processFile(userFilePath);
    cout << fp->totalWindows << endl;
    // fp->ticks->printQueue();
    // fp->queue->printQueue();
  }
  else {
    throw runtime_error("Invalid command line arguments!");
    return -1;
  }
  delete fp;
//
// delete gq;
  return 0;
}

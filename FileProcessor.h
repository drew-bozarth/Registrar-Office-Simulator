/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 5 - FileProcessor.h */

/*
This is the .h file for FileProcessor
*/

//these are the header guards
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <fstream>
#include <exception>
//includes the GenQueue.h template class, and Window.h and Student.h files
#include "GenQueue.h"
#include "Window.h"
#include "Student.h"
//standard namespace libaray in C++
using namespace std;

class FileProcessor{

  public:
    FileProcessor();
    ~FileProcessor();
    void processFile(string inputFilePath);
    GenQueue<Student*> *queue;
    int totalWindows;
};
//end of the header guards
#endif

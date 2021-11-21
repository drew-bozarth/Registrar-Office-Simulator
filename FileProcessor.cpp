/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 5 - FileProcessor.cpp */

/*
This is the .cpp file for FileProcessor
*/

//this statement includes the FileProcessor.h file
#include "FileProcessor.h"

/*
Function: FileProcessor()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
//creates a new queue of students
FileProcessor::FileProcessor(){
queue = new GenQueue<Student*>();
totalWindows = 0;
}

/*
Function: FileProcessor()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
FileProcessor::~FileProcessor(){
  delete queue;
}

/*
Function: processFile()
Return: void
Parameters: string inputFilePath
Exceptions: none
*/
//opens the file and stores the corresponding information given by the input file
//it creates student objects and stores them in the queue
void FileProcessor::processFile(string inputFilePath){
  string fileLine;
  ifstream input (inputFilePath);

  if (input.is_open()){
    int capacity;
    string str;
    getline(input,str);
    cout << str << endl;
    totalWindows = stoi(str);

    int numStudents;
    int clockTick;
    while ( getline(input,fileLine) ){
        clockTick = stoi(fileLine);
        getline(input,str);
        numStudents = stoi(str);
        for (int i = 0; i < numStudents; ++i){
          getline(input,str);
          int windTime = stoi(str);
          Student *s1 = new Student(clockTick, windTime);
          queue->insert(s1);
        }
    }
    input.close();
  }
  else {
    throw runtime_error("Could not open input file!");
  }
}

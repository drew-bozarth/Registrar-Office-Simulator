/* Drew Bozarth
2373658
dbozarth@chapman.edu
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
FileProcessor::FileProcessor(){
queue = new GenQueue<Student*>();
// ticks = new GenQueue<int>();
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
// delete ticks;
}

/*
Function: processFile()
Return: void
Parameters: string inputFilePath
Exceptions: none
*/
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
        // cout << fileLine << endl;
        // cout << endl;
        clockTick = stoi(fileLine);
        cout << "clock tick: " << clockTick << endl;
        getline(input,str);
        numStudents = stoi(str);
        cout << "Number of students: " << numStudents << endl;
        for (int i = 0; i < numStudents; ++i){
          getline(input,str);
          cout << "wait time: " << str << endl;
          int windTime = stoi(str);
          Student *s1 = new Student(clockTick, windTime);
          // ticks->insert(clockTick);
          queue->insert(s1);
        }
    }
    input.close();
  }
  else {
    throw runtime_error("Could not open input file!");
  }
}

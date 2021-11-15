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
queue = new GenQueue<Student>();
totalWindows = 0;
}

/*
Function: FileProcessor()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
FileProcessor::~FileProcessor(){

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
    capacity = stoi(str);
    totalWindows = capacity;
    Window **wind = new Window*[capacity];
    // for (int i =0; i < capacity; ++i){
    //   wind[i] = new Window(new Student(i+1));
    // }
    int numStudents;
    int clockTick;
    while ( getline(input,fileLine) ){
        cout << fileLine << endl;
        cout << endl;
        clockTick = stoi(fileLine);
        getline(input,str);
        numStudents = stoi(str);
        for (int i = 0; i < numStudents; ++i){
          getline(input,str);
          int windTime = stoi(str);
          queue->insert(new Student(clockTick, windTime));
        }
    }
    input.close();
  }
  else {
    throw runtime_error("Could not open input file!");
  }
}

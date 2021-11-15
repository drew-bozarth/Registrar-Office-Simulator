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
    while ( getline(input,fileLine) ){
        cout << fileLine << endl;
        cout << endl;
    }
    input.close();
  }
  else {
    throw runtime_error("Could not open input file!");
  }
}

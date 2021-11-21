/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 5 - main.cpp */

/*
Main file for Assignment5
*/

//these statements include the user defined files into this file to be used
#include "GenQueue.h"
#include "FileProcessor.h"
#include "Simulation.h"
#include "ListInterface.h"
// standard namespace library in C++
using namespace std;
/*
Function: main
Return: int (returns a 0 or -1 based on if the main method runs correctly)
Parameters: int (argc, number of command line arguments), char** (argv, array of char pointers which is pretty much an array of the command line arguments)
Exceptions: none
*/
//the main method creates an instance of the Simulation class, then checks that there are
// the correct command line arguments given. if so, it will run the simulate method and input
// the command line argument which should be the file path. 
int main(int argc, char** argv){
  Simulation *sim = new Simulation();
  if(argc > 1){
    string userFilePath = argv[1];
    sim->simulate(userFilePath);
  }
  else {
    throw runtime_error("Invalid command line arguments!");
    return -1;
  }
  delete sim;
  return 0;
}

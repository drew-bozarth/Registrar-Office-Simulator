/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 5 - Simulation.cpp */

/*
This is the .cpp file for Simulation
*/

//includes the Simulation.h file
#include "Simulation.h"

/*
Function: Simulation()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
//creates two new lists for window idle times and student wait times
Simulation::Simulation(){
  idleTimes = new MyList<int>();
  waitTimes = new MyList<int>();
};

/*
Function: ~Simulation()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
//deletes the two lists
Simulation::~Simulation(){
  delete idleTimes;
  delete waitTimes;
};

/*
Function: calcStudent()
Return: none
Parameters: MyList<int> *students
Exceptions: none
*/
//takes in a list of ints which is student wait times, then calculates and prints the necessary stats
void Simulation::calcStudent(MyList<int> *students){
  double mean;
  int total = 0;
  int numStudents;
  int median;
  int max = 0;
  int over10 = 0;
  int current;
  students->sort();
  numStudents = students->getLength();
  for (int i = 0; i < numStudents; ++i){
    current = students->removeFront();
    if (current >= 10){
      ++over10;
    }
    if (current > max){
      max = current;
    }
    total += current;
    students->append(current);
  }
  for (int i = 0; i < numStudents/2; ++i){
    current = students->removeFront();
    students->append(current);
  }
  median = current;
  mean = (double)total / (double)numStudents;
  cout << "Mean Student wait time: " << mean << " minutes" << endl;
  cout << "Median Student wait time: " << median << " minutes" << endl;
  cout << "Longest Student wait time: " << max << " minutes" << endl;
  cout << "Number of Student wait times exceeding 10 minutes: " << over10 << endl;
};

/*
Function: calcWindowsr()
Return: none
Parameters: MyList<int> *windows
Exceptions: none
*/
//takes in a list of ints which is window idle times, then calculates and prints the necessary stats
void Simulation::calcWindows(MyList<int> *windows){
  double mean;
  int max = 0;
  int total = 0;
  int over5;
  int numIdles = windows->getLength();
  int current;
  for (int i = 0; i < numIdles; ++i){
   current = windows->removeFront();
   total += current;
   if (current >= 5)
     ++over5;
   if (current > max)
      max = current;
  }
  mean = (double)total / (double)numIdles;
  cout << "Mean Window idle time: " << mean << " minutes" << endl;
  cout << "Longest Window idle time: " << max << " minutes" << endl;
  cout << "Number of Window idle times exceeding 5 minutes: " << over5 << endl;
};

/*
Function: simulate()
Return: none
Parameters:string file
Exceptions: none
*/
//takes in the file path as parameter, creates a FileProcessor object then enters the file path into the processFile method
// this function runs the whole simulation, so it keeps track of the queue of students, the windows, and it will
// run the simulation over a clock tick, and constantly updates the window idle and occupied times, as well as student
// times and it will run until all of the students are removed from the queue, and all of the windows are empty, meaning
// there are no students left waiting and no students are still doing stuff at any windows. After the simulation is ran,
// the calculate Windows and Students methods are called to print out the stats.
void Simulation::simulate(string File){
  FileProcessor *fp = new FileProcessor();
  Student *currStu;
  int capacity;
  int minute = 0;
  int number = 0;
  int wait;
  int currTick = 0;
  fp->processFile(File);
  capacity = fp->totalWindows;
  Window **wind = new Window*[capacity];
  //this loop creates and fills the Window array with window objects
  for (int i =0; i < capacity; ++i){
    wind[i] = new Window();
  }
  //boolean value to check if all windows are empty after the queue is empty
  bool allWindowsEmpty = false;
  //this loop runs while there are still students in the queue
  while(!fp->queue->isEmpty()){
    //the loop goes to each window, checks if its availble, also checks if there is a student and if their arrival tick is equal to the current tick or not
    // and it will act corresponding to the conditions
    for (int i = 0; i < capacity; ++i){
      if (fp->queue->isEmpty()){
        if (wind[i]->isAvailable()){
          wind[i]->setIdleTime();
        }
        else{
          if (currTick == wind[i]->getEntryTime() + wait + wind[i]->getOccupiedTime()){
            wind[i]->emptyWindow();
          }
        }
        continue;
      }
      currStu = fp->queue->peek();
      number = currStu->getArrival();
        if (wind[i]->isAvailable()){
          if (number <= currTick){
            wind[i]->setWindowBusy(fp->queue->remove());
            wait = currTick - number;
            waitTimes->append(wait);
          }
          else {
            wind[i]->setIdleTime();
          }
        }
        else{
          if (currTick == wind[i]->getEntryTime() + wait + wind[i]->getOccupiedTime()){
            wind[i]->emptyWindow();
          }
        }
      }
      ++currTick;
  }
  //after the queue is empty, there could still be students currently at the windows, so we
  // need to continue the simulation until all of the windows are not occupied
  while (!allWindowsEmpty){
    //temporarily set this to true
    allWindowsEmpty = true;
    //this for loop checks all the windows, and will set the bool back to false if a window is occupied
    for (int j = 0; j < capacity; ++j){
      if (!wind[j]->isAvailable())
        allWindowsEmpty = false;
    }
    //if all of the windows are empty, we can exit the while loop
    if (allWindowsEmpty)
      continue;
    //otherwise, we must go through each window and continue iterating through ticks and updating the windows 
    for (int k = 0; k < capacity; ++k){
      if (wind[k]->isAvailable()){
        wind[k]->setIdleTime();
      }
      else{
        if (currTick == wind[k]->getEntryTime() + wait + wind[k]->getOccupiedTime()){
          wind[k]->emptyWindow();
        }
      }

    }
    ++currTick;
  }
  // once the queue is empty, and the windows are all empty, we iterate through to add the window idle times to a list
  for (int m = 0; m < capacity; ++m){
    idleTimes->append(wind[m]->getIdleTime());
  }
  //then we run the calculate methods on the list of student wait times and window idle times
  calcStudent(waitTimes);
  calcWindows(idleTimes);

  delete fp;
};

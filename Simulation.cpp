#include "Simulation.h"

Simulation::Simulation(){
  idleTimes = new MyList<int>();
  waitTimes = new MyList<int>();
};

Simulation::~Simulation(){
  delete idleTimes;
  delete waitTimes;
};

string Simulation::calcStudent(MyList<int> *students){
int mean;
int total = 0;
int numStudents;
int median;
int max;
int over10;
int current;
students->sort();
numStudents = students->getLength();
for (int i = 0; i < numStudents; ++i){
  current = students->removeFront();
  if (current >= 10){
    ++over10;
  }
  total += current;
  students->append(current);
}
for (int i = 0; i < numStudents/2; ++i){
  current = students->removeFront();
  students->append(current);
}
median = current;
mean = total/numStudents;
};

string Simulation::calcWindows(MyList<int> *windows){
int mean;
int max;
int over5;
};

void Simulation::simulate(string File){
  FileProcessor *fp = new FileProcessor();
  int capacity;
  int minute = 0;
  int number = 0;
  int wait;
  int currTick = 0;
  fp->processFile(File);
  capacity = fp->totalWindows;
  Window **wind = new Window*[capacity];
  for (int i =0; i < capacity; ++i){
    wind[i] = new Window();
  }
  while(!fp->queue->isEmpty()){
  currTick = queue->peek->getArrival();
  if (currTick == minute){
  ++number;
  wind[number](queue->remove());
  } else {
    for (int i = 0; i < capacity; ++i){
      if (wind[i]->isEmpty()){
      wind[i]->updateIdleTime();}
    }
      ++minute;
  }
  //   while (minute == currTick){
  //     //we will remove from both queues until the next clock tick arrives and add both to a student object
  //
  //   }
    //fill required windows
    //add idle times to empty windows
    //before idle time is reset for the window add to idleTimes list
  }
  //once the time of a student needed at the window is completed add wait time for student to waitTimes list
  delete fp;
}

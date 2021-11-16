#include "Simulation.h"

Simulation::Simulation(){
  idleTimes = new MyList<int>();
  waitTimes = new MyList<int>();
};

Simulation::~Simulation(){
  delete idleTimes;
  delete waitTimes;
};

void Simulation::calcStudent(MyList<int> *students){
int mean;
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
  } if (current > max){
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
mean = total/numStudents;
cout << "Mean wait time: " << mean << "minutes" << endl;
cout << "Median wait time: " << median << "minutes" << endl;
cout << "Longest Wait time: " << max << "minutes" << endl;
cout << "Number of wait Times exceeding 10 minutes: " << over10 << endl;
};

string Simulation::calcWindows(MyList<int> *windows){
int mean;
int max = 0;
int total = 0;
int over5;
int numIdles = windows->getLength();
int current;
for (int i = 0; i < numIdles; ++i){
 current = windows->removeFront();
 total += current;
 if (curr >= 5)
   ++over5;
 if (curr > max)
    max = curr;
mean = total/numIdles;
cout << "Mean Idle time: " << mean << "minutes" << endl;
cout << "Longest Idle time: " << max << "minutes" << endl;
cout << "Number of Idle Times exceeding 5 minutes: " << over5 << endl;
};

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
  for (int i =0; i < capacity; ++i){
    wind[i] = new Window();
  }
  while(!fp->queue->isEmpty()){
  currStu = queue->peek();
  currTick = currStu->getArrival();
  if (currTick == minute){
    ++number;
    if (number >= capacity){
      continue;
    }
    wind[number].setWindowBusy(queue->remove());
  } else {
    for (int i = 0; i < capacity; ++i){
      if (wind[i].isEmpty()){
      wind[i].updateIdleTime();}
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

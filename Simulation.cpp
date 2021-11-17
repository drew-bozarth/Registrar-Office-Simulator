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

void Simulation::calcWindows(MyList<int> *windows){
int mean;
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
  currStu = fp->queue->peek();
  number = currStu->getArrival();
  for (int i = 0; i < capacity; ++i){
    if (number >= currTick){
      if (wind[i]->isAvailable()){
      idleTimes->append(wind[i]->getIdleTime());
      wind[number]->setWindowBusy(fp->queue->remove());
      wait = currTick - number;
      waitTimes->append(wait);
    }
    } else {
      if (wind[i]->isAvailable()){
      wind[i]->setIdleTime();
      }
    }
    if (currTick == wind[i]->getStudent()->getArrival() + wait + wind[i]->getStudent()->getWindowTime()){
      wind[i]->emptyWindow();
    }
  }
      ++currTick;
  }
  delete fp;
};

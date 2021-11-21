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
  // students->sort();
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
  mean = total/numStudents;
  cout << "Mean Student wait time: " << mean << "minutes" << endl;
  cout << "Median Student wait time: " << median << "minutes" << endl;
  cout << "Longest Student wait time: " << max << "minutes" << endl;
  cout << "Number of Student wait times exceeding 10 minutes: " << over10 << endl;
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
  cout << "Mean Window idle time: " << mean << "minutes" << endl;
  cout << "Longest Window idle time: " << max << "minutes" << endl;
  cout << "Number of Window idle times exceeding 5 minutes: " << over5 << endl;
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
  cout << "Past file processor" << endl;
  capacity = fp->totalWindows;
  Window **wind = new Window*[capacity];
  cout << "Array made" << endl;
  for (int i =0; i < capacity; ++i){
    wind[i] = new Window();
  }
  cout << "Array filled" << endl;
  while(!fp->queue->isEmpty()){
    // cout << "in while loop" << endl;
    // currStu = fp->queue->peek();
    // number = currStu->getArrival();
    // cout << "Student retrieved: " << number << endl;
    cout << "Current tick: " << currTick << endl;
    for (int i = 0; i < capacity; ++i){
      if (fp->queue->isEmpty()){
        // if (wind[i]->isAvailable()){
        //   cout << "Idle increased" << endl;
        //   wind[i]->setIdleTime();
        // } else {
        //   if (currTick == wind[i]->getEntryTime() + wait + wind[i]->getOccupiedTime()){
        //     wind[i]->emptyWindow();
        //     cout << "window emptied" << endl;
        //   }
        // }
        continue;
      }
      currStu = fp->queue->peek();
      number = currStu->getArrival();
      // cout << "in for loop" << endl;
        if (wind[i]->isAvailable()){
          if (number <= currTick){
            idleTimes->append(wind[i]->getIdleTime());
            wind[i]->setWindowBusy(fp->queue->remove());
            wait = currTick - number;
            waitTimes->append(wait);
            cout << "Window filled" << endl;
          }
          else {
            cout << "Idle increased" << endl;
            wind[i]->setIdleTime();
          }
        }
        else{
          cout << "window occupied" << endl;
          if (currTick == wind[i]->getEntryTime() + wait + wind[i]->getOccupiedTime()){
            wind[i]->emptyWindow();
            cout << "window emptied" << endl;
          }
        }
      }
      ++currTick;
  }

  delete fp;
};

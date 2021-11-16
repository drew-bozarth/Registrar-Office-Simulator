#include "Simulation.h"

Simulation::Simulation(){
  idleTimes = new MyList<int>();
  waitTimes = new MyList<int>();
};

Simulation::~Simulation(){
  delete idleTimes;
  delete waitTimes;
};

void simulate(string File){
  FileProcessor *fp = new FileProcessor();
  int capacity;
  int minute = 0;
  int Tick;
  int wait;
  int currTick;
  fp->processFile(File);
  capacity = fp->totalWindows;
  Window **wind = new Window*[capacity];
  for (int i =0; i < capacity; ++i){
    wind[i] = new Window();
  }
  while(!fp->queue->isEmpty()){
    currTick = fp->ticks->peek();
    while (minute == currTick){
      //we will remove from both queues until the next clock tick arrives and add both to a student object

    }
    //fill required windows
    //add idle times to empty windows
    //before idle time is reset for the window add to idleTimes list
  }
  //once the time of a student needed at the window is completed add wait time for student to waitTimes list
  delete fp;
}

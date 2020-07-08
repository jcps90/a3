#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <csignal>
#include <string>
#include <cmath>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

using namespace std;

///////CountDown//////////////////

class CountDown{
    private:
    	int countDownTimer;
        void mainCountdown();
    public:
        CountDown(int);
        void run();       
};

void CountDown::mainCountdown(){             //main countdown
    while(countDownTimer != 0){              //runs while cd has not reached zero
    sleep(1);
    cout << countDownTimer << "\n";
    if(countDownTimer == 5){
            raise(SIGINT);
    }
    countDownTimer--;
    }
    cout << "count down over!" << "\n";
    //raise(SIGINT);                         //once 0 is reached raises the terminate flag
}

 CountDown::CountDown(int a){
    countDownTimer = a;
}
// calls signal to watchout for a SIGTERM signal and calls the private function
// mainCountdown to begin keeping track of the timer.
void CountDown::run(){                                 //prog runner
    //signal(SIGTERM,);                                //terminate flag
    cout << "got into run() " << "\n";
    mainCountdown();                                   //countdown funciton
}


//////WallClock/////////////////
class WallClock{

    public: 
        WallClock(int);
        void runClock();
    private:
    	int wallClockTimer; //either 1 second or 60 seconds
        void myClock();
};

WallClock::WallClock(int b){
   	wallClockTimer = b;
}

void WallClock::myClock(){                   //wallclock printer
    time_t my_time = time(NULL); 
    printf("%s", ctime(&my_time));
    sleep(wallClockTimer);
}

void WallClock :: runClock(){
    //signal(SIGTERM);
    while(true){
    myClock();
    }
}
    
///////////////Alarm///////////////////
class Alarm{
    public:
   	    Alarm(int);
        void runAlarm();
    private: 
    	int alarmTime;
        void alarmCD();
};

Alarm::Alarm(int c){
    	alarmTime = c;
}

void Alarm :: alarmCD(){                                 //Alarm function                     
    while(alarmTime != 0){                               //while countdown has not
    sleep(1);                                            //1 second wait
    alarmTime--;                                         //reduce countdown by 1
    }
    cout << "ALARM!\n";                                             //once countdown reaches 0 print an alarm
}   

void Alarm:: runAlarm(){
    //signal(SIGTERM);
    alarmCD();
}

//////////MainThread//////////////
class MainThread{
    private:
        int countdownTime;
        int wallclockTime;
        int alarmTime;
        typedef void * (*CLASSFUNCPTR) (void *);
        void signalHandler(int);
        void createThreads();
    public:
        MainThread(int arr[]);
        void startThreads();
};

MainThread::MainThread(int arr[]){ //Constructor
    cout << "\n Constructor: arr = \n" << arr[0] << "\n" << arr[1] << "\n"<< arr[2] << "\n"; //take this out before submitting!!!!
    countdownTime = arr[0];
    wallclockTime = arr[1];
    alarmTime = arr[2];
}
void MainThread::signalHandler(int signum){
    if(signum = SIGINT){
        cout << "I GOT THE SIGNAL! " << signum << "\n";
    }
}

void MainThread::createThreads(){
    cout << "\n createThreads: arr = \n" << countdownTime << "\n" << wallclockTime << "\n"<< alarmTime << "\n"; //take this out before submitting!!!!
    
    //create pointers to each class using a constructor with the user inputs passed through
    CountDown * countdownTPtr = new CountDown(countdownTime);
    WallClock * wallclockTPtr = new WallClock(wallclockTime);
    Alarm * alarmTPtr = new Alarm(alarmTime);
    cout << "pointers made!" << "\n";

    //create thread IDs for each thread that will run operations of each respective class
    pthread_t countDownID;
    pthread_t wallClockID;
    pthread_t alarmID; 
    cout << "thread IDs made!" << "\n";

    int threadOne = pthread_create(&countDownID, NULL, (CLASSFUNCPTR) &CountDown::run,countdownTPtr);
    int threadTwo = pthread_create(&wallClockID, NULL, (CLASSFUNCPTR) &WallClock::runClock,wallclockTPtr);//create wallclockThread w/ wallclockTime
    int threadThree = pthread_create(&alarmID, NULL, (CLASSFUNCPTR) &Alarm::runAlarm,alarmTPtr);//create alarmThread w/ alarmTime;
    pthread_join(countDownID, NULL);
    pthread_join(wallClockID, NULL);
    pthread_join(alarmID, NULL);
    cout << "threads created!" << "\n";
}
void MainThread::startThreads(){
    signal(SIGINT, signalHandler);
    createThreads();
}


///////////////////////////////////
///////////////Main////////////////
///////////////////////////////////

typedef void * (*CLASSFUNCPTR) (void *);
int userVal[3];
int chk;
int check(int);

int main(int argc, char *argv[]){

// Switch case verifies how many command line arguments have been input
// and sets default values. It will also make a call to check to verify
// that the 2nd argument is only a 1 or a 60. Once the check is cleared,
// it will copy those values into the array.
switch(argc){

    case 1: // %mot 
        cout << "case 1" << "\n"; //take this out before submitting!!!!
        userVal[0] = 25;
        userVal[1] = 1;
        userVal[2] = 17;
        break;
    case 2: // %mot arg
        cout << "case 2" << "\n"; //take this out before submitting!!!!
        userVal[0] = atoi(argv[1]);
        userVal[1] = 1;
        userVal[2] = 17;
        break;
    case 3: // %mot arg arg
        cout << "case 3" << "\n"; //take this out before submitting!!!!
        chk = check(atoi(argv[2]));
        userVal[0] = atoi(argv[1]);
        userVal[1] = atoi(argv[2]);
        userVal[2] = 17;
        break;
    case 4: // %mot arg arg arg
        cout << "case 4" << "\n"; //take this out before submitting!!!!
        chk = check(atoi(argv[2]));
        userVal[0] = atoi(argv[1]);
        userVal[1] = atoi(argv[2]);
        userVal[2] = atoi(argv[3]);
        break;
}

cout << "argc = " << argc << "\n userVal = \n" << userVal[0] << "\n" << userVal[1] << "\n"<< userVal[2] << "\n"; //take this out before submitting!!!!

///^^^^^^^^^^^EVERYTHING HERE IS CORRECT^^^^^^^^^^^^^^^^^^///

MainThread * mainTPtr = new MainThread(userVal); // create class object pointer with object constructed using userVal.

pthread_t mainThreadId; // create thread ID

int threadZero = pthread_create(&mainThreadId, NULL, (CLASSFUNCPTR) &MainThread::startThreads,mainTPtr); // create thread using ThreadID, cast Class function as a void * (*) void * type, pass class object pointer
pthread_join(mainThreadId, NULL);
cout << "DONE" << "\n";
return 0;
}

//checks that the input int is either a 1 or 60, if not, it will output an error and exit the program
int check(int interval){
    if(interval == 1){                        					//if the interval does not eaual 1 or 60 return an error        
        return 0;
    }else if(interval == 60){
        return 0;
    }else{
        cout << "Input for 2nd argument must be either 1 or 60" << "\n";
        exit(0);
    }
}

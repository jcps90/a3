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
/*
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

void WallClock::myClock(){
                       //wallclock printer
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


void MainThread::startThreads(){
    createThreads();
}
*/



///////////////////////////////////
///////////////Main////////////////
///////////////////////////////////
int userVal[3];
int chk;


void mtSignalHandler(int signum){
    if(signum == SIGINT){
        raise(SIGTERM);
    }
}

void signalHandler(int signum){
    if(signum == SIGTERM){
        cout << "SIGNUM=" << signum << "\n";
        exit(signum);
    }
}

void * countDown(void *arg){
    signal(SIGTERM, signalHandler);
    
    for(int countDownTimer = (intptr_t)arg; countDownTimer != 0;  countDownTimer--){              //runs while cd has not reached zero
        sleep(1);
        //cout << countDownTimer << "\n";
        }

    cout << "count reached zero!" << "\n";
    raise(SIGINT);                         //once 0 is reached raises the terminate flag
}

void * wallClock(void *arg){             
    signal(SIGTERM, signalHandler);

    int wallClockTimer = (intptr_t)arg;
    while(true){
        //int wallClockTimer = arg;
        time_t my_time = time(NULL); 
        printf("%s", ctime(&my_time));
        sleep(wallClockTimer);
    }
}

void * alarm(void *arg){

    signal(SIGTERM, signalHandler);
    int alarmTime = (intptr_t)arg;
    while(alarmTime != 0){                                   //while countdown has not
        sleep(1);                                            //1 second wait
        alarmTime--;                                         //reduce countdown by 1
        }
    cout << "ALARM!\n";
}

void * createSubThreads(void *arg){

    pthread_t countDownID;
    pthread_t wallClockID;
    pthread_t alarmID;
     
    signal(SIGINT, mtSignalHandler);
    int threadOne = pthread_create(&countDownID, NULL,  countDown, (void *) arg);
    int threadTwo = pthread_create(&wallClockID, NULL, wallClock, (void *) userVal[1]);//create wallclockThread w/ wallclockTime
    int threadThree = pthread_create(&alarmID, NULL,  alarm, (void *) userVal[2]);//create alarmThread w/ alarmTime;
    pthread_join(countDownID, NULL);
    pthread_join(wallClockID, NULL);
    pthread_join(alarmID, NULL);

}

void createMainThread(){
    pthread_t mainThreadID;
    //this is the main thread
    int threadZero = pthread_create(&mainThreadID, NULL, createSubThreads, (void *) userVal[0]);
    pthread_join(mainThreadID, NULL);
    cout << "threads created!" << "\n";
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


int main(int argc, char *argv[]){

// Switch case verifies how many command line arguments have been input
// and sets default values. It will also make a call to check to verify
// that the 2nd argument is only a 1 or a 60. Once the check is cleared,
// it will copy those values into the array.
switch(argc){

    case 1: // %mot 
        userVal[0] = 25;
        userVal[1] = 1;
        userVal[2] = 17;
        break;
    case 2: // %mot arg
        userVal[0] = atoi(argv[1]);
        userVal[1] = 1;
        userVal[2] = 17;
        break;
    case 3: // %mot arg arg
        chk = check(atoi(argv[2]));
        userVal[0] = atoi(argv[1]);
        userVal[1] = atoi(argv[2]);
        userVal[2] = 17;
        break;
    case 4: // %mot arg arg arg
        chk = check(atoi(argv[2]));
        userVal[0] = atoi(argv[1]);
        userVal[1] = atoi(argv[2]);
        userVal[2] = atoi(argv[3]);
        break;
    }

createMainThread();
return 0;
}


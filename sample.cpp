#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <time.h> 


//possibly use for Wall Clock
/*
int main() 
{ 
      for(int i = 0; i < 25; i++){
        time_t my_time = time(NULL);
        printf("%s", ctime(&my_time));
        sleep(1);
        }
    return 0; 
}*/


//possibly use for Alarm Clock
/*
int main(){
    for (int i = 0; i < 5; i++){
        time_t my_time = time(NULL);
        printf("%s", ctime(&my_time));
        sleep(1);
    }
    printf("ALARM!\n");
    return 0;
}*/


int main(){
    for (int i = 0; i<5; i++){
        time_t my_time = time(NULL);
        printf("%s", ctime(&my_time));
        sleep(1);
    }
    exit(0);
    printf("EVERYBODY STOP!");
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
  int i = 1;
  if (i != 1 || i != 60){
    cout<< "problem\n" << endl;
  }
  else{
      cout<< "no problem\n" << endl;
  }
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
  int i = 2;
  
  
  switch(i){
      case 1:
      cout << "correct input" << "\n";
      break;
      
      case 60:
      cout << "correct input" << "\n";
      break;
      
      default:
      cout << "input invalid" << "\n";
  }

}
-------------------------------------------------------------------
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <unistd.h> 
#include <iostream>
#include <string>

using namespace std;


void check(int interval){
    if(interval != 1 || interval != 60){                        //if teh interval does not eaual 1 or 60 return an error        
        cout<< "Only acceptable input is 1 second or 60 seconds\n" << endl;        //error message
    }
}

void myClock(){                                                 //clock printout function
    time_t my_time = time(NULL); 
    printf("%s", ctime(&my_time));
    sleep(1);
}
-------------------------------
void alarm(int countdown){                                     //Alarm function
// signal reciever here
    sleep(countdown);                                          //sleep for given time
    cout<< "ALARM!";                                           //once countdown reaches 0 print an alarm
}
---------------------------------

void run(int time){                              //function for main countdown and interval printout
        while( time != 0){                                      //while time has not reached 0 run the loop
            sleep(1);                                           //waits one second                   
            time--;                                             //subtract 1 from the time to signify 1 second passing
        }//while
            //send signal to stop program
}

void printOne(){
    cout << "One second have passed.\n" << endl; //if 60 seconds passed print message         
}
void printSixty(){
    cout << "60 seconds have passed.\n" << endl; //if 60 seconds passed print message         
}
------------------------------------------------------------------------------------





%mot 10 3  

mainthread def def def
mainthread val def def
mainthread val val def
mainthread val val val


MainThread{

typedef void * (*CLASSFUNCPTR) (void *);

int arg1 = 25;
int arg2 = 1;
int arg3 = 17;

/////////IGNORE
Mainthread(){

	Countdown * count = new Countdown;
	Wallclock * wall = new Wallclock;
	Alarm * alarm = new Alarm;
  pthread_t children[3];
}
/////////IGNORE

void termAll(int signum){
	if(signum = SIGINT){
  	exit(0);
	}
}


MainThread(int userArgs[]){

	signal(SIGINT, termAll);
  pthread_t children[3];

	int thread1 = pthread_create(&children[0], NULL, (CLASSFUNPTR) &Countdown::runClock, (void*)userArgs[0]); 
	int thread2 = pthread_create(&children[1], NULL, (CLASSFUNPTR) &Wall::runWallClock, (void*)userArgs[1]);
	int thread3 = pthread_create(&children[2], NULL, (CLASSFUNPTR) &Alarm::runAlarm, (void*)userArgs[2]);
  
}







createThreads(){
	int thread1 = pthread_create(&children[0], NULL, (CLASSFUNPTR) &Countdown::runClock, (void*)arg1); 
	int thread2 = pthread_create(&children[1], NULL, (CLASSFUNPTR) &Wall::runWallClock, (void*)arg2);
	int thread3 = pthread_create(&children[2], NULL, (CLASSFUNPTR) &Alarm::runAlarm, (void*)arg3);

}

void setArg1(int a);
void setArg2(int b);
void setArg3(int c);

}





int main(int argc, char *argv[]){

	inputchecks();
  //
  //
  //
  // all checks are good
  
  Mainthread mainThread; //arg1 = 25, arg2 = 1, arg3 = 17
  
  if(argv[0]){
  mainThread.setArg1(argv[0])
  }
  if(argv[1]){
  mainThread.setArg2(argv[1])
  }
  if(argv[2]){
  mainThread.setArg3(argv[2])
  }
  
  //
  int thread0 = pthread_create(&children[0], NULL, (CLASSFUNPTR) &MainThread::MainThread, (void*)arg1);
  
  mainThread.createThreads();
}
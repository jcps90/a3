#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <unistd.h>

using namespace std;

class MainThread{
    private:
        typedef void * (*CLASSFUNCPTR) (void *);
};

/*
MainThread::MainThread(void){

}


class CountDown{

};

class WallClock{

    void myClock(int i){
        time_t my_time = time(NULL); 
        printf("%s", ctime(&my_time));
        sleep(i);
    }


    void runClock(){
        //signal receiver()
        myClock();
    }

};

class Alarm{

    void alarm(int countdown){                                     //Alarm function                     
        while(countdown != 0){                                     //while countdown has not
        sleep(1);                                              //1 second wait
        countdown--;                                           //reduce countdown by 1
        }
        cout << "ALARM!";                                             //once countdown reaches 0 print an alarm
}

};*/

int userVal[3];

int main(int argc, char *argv[]){

switch(argc){

    case 1: // %mot 
        cout << "case 1" << "\n";
        userVal[0] = 25;
        userVal[1] = 1;
        userVal[2] = 17;
        break;
    case 2: // %mot arg
        cout << "case 2" << "\n";
        userVal[0] = atoi(argv[1]);
        userVal[1] = 1;
        userVal[2] = 17;
        break;
    case 3: // %mot arg arg
        cout << "case 3" << "\n";
        userVal[0] = atoi(argv[1]);
        userVal[1] = atoi(argv[2]);
        userVal[2] = 17;
        break;
    case 4: // %mot arg arg arg
        cout << "case 4" << "\n";
        userVal[0] = atoi(argv[1]);
        userVal[1] = atoi(argv[2]);
        userVal[2] = atoi(argv[3]);
        break;
        
}

cout << "argc = " << argc << "\n userVal = \n" << userVal[0] << "\n" << userVal[1] << "\n"<< userVal[2] << "\n";
}



/*
void check(int *interval){
    if(interval != 1 || interval != 60){//if teh interval does not eaual 1 or 60 return an error        
        cout << "Only acceptable input is 1 second or 60 seconds\n" << endl;        //error message
    }
}*/

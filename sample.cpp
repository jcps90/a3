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
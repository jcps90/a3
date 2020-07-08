README.md Authors: Juan Pina-Sanz, Mikhail Mineev

Users: cssc2147, cssc2160

Class: CS 570, Summer 2020

Assignment 3

Filename: README

File Manifest: Makefile main.cpp 

Run on Class Account cssc2147

Compile Instructions: Compile using make

Operation Instructions: After compiling run the msh file with 3 numbers spaced out (ex: ./msh 23 1 2) if no numbers are entered                           then the default entrees of 25 1 17 is used.

Design Description: We first create 4 threads.
                    The Main thread is responsible for recieving and sending signals.
                    One Worker is responsible for the Overall countdown, which after reaching the end will raise a flag for the                       main thread.
                    One Worker thread is responsible for printing the clock , either 1 or 60 seconds.
                    The last worker thread is responsible for printing out an ALARM after the inputed time has run out.
                    
The first number after mot is the overall countdown, after it runs out the program ends
The second number after mot can be either 1 or 60, any other input causes an error. This tells the program to print the clock every 1 or 60 seconds.
The last number is a one time alarm which will print after the entered time in seconds passes.
If the Overall countdown ends before one or both other threads run then the program terminates without them running.
                    
Mikhail Mineev made the countdown, wallClock, and alram.
Juan Pina-Sanz made the main and the threads.
Both worked on the comments and README



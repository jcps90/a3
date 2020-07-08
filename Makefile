########################################################
#
# Authors: Juan Pina-Sanz, Mikhail Mineev
# Users: cssc2147, cssc2160
# Class: CS 570, Summer 2020
# Assignment 3
# Filename: Makefile
#
#######################################################
EXEC = mot
CC=g++
$(EXEC):
	$(CC) -o $(EXEC) main.cpp -lpthread 
	rm -f *.o
clean:
	rm -f *.o core a.out mot $(EXEC)
####################[ EOF: Makefile ]###################
###############################################################
# Program:
#     Assignment 02, STACK
#     Brother Jones, CS235
# Author:
#      Devin Cenatiempo
# Summary:
#     <put a description here>
# Time:
#     <how long did it take to complete this program>?
#     Hours (Unsimplified): 13:20 to #:## + #:## to #:##
###############################################################

##############################################################
# The main rule
##############################################################
a.out: stack.h assignment02.o infix.o stack.o
g++ -o a.out assignment02.o infix.o  stack.o
tar -cf assignment02.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment02.o : the driver program
#      infix.o        : the logic for the infix --> postfix program
##############################################################
assignment02.o: stack.h stack.cpp infix.h assignment02.cpp
g++ -c assignment02.cpp

stack.o: stack.h stack.cpp
g++ -c stack.cpp

infix.o: stack.h stack.cpp infix.h infix.cpp
g++ -c infix.cpp

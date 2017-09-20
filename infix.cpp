/***********************************************************************
 * Module:
 *    Week 02, Stack
 *    Brother Jones, CS 235
 * Author:
 *    Devin Cenatiempo and Daniel Van Orman
 * Summary:
 *    This program will implement the testInfixToPostfix()
 *    and testInfixToAssembly() functions
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK
#include "infix.h"     // for INFIX
using namespace std;

//   https://content.byui.edu/file/fddcd57e-77ee-4853-a5ec-d787dd07d047/1/Ponder/235.02.Ponder.html

/*****************************************************
 * CONVERT INFIX TO POSTFIX
 * Convert infix equation "5 + 2" into postfix "5 2 +"
 *****************************************************/
string convertInfixToPostfix(const string & infix)
{
   string postfix;
   postfix = "we still need to build this algorithm";
   
   //Order: (), ^, * / %, + -
   
   /*FOR iInfix 0 .. infix.size() – 1
    SWITCH infix[iInfix]
    CASE number or variable
    postfix[iPostfix++] infix[iInfix]
    CASE (
    stack.push(infix[iInfix])
    CASE )
    WHILE stack.top() ≠ ( postfix[iPostfix++] stack.top() stack.pop()
    stack.pop() DEFAULT
    WHILE !stack.empty() &&
    infix[iInfix] ≤ stack.top()  here ≤ understands the order of operations
    postfix[iPostfix++] stack.top()
    stack.pop(); stack.push(infix[iInfix])
    WHILE not stack.empty()
    postfix[iPostfix++] stack.top()
    stack.pop()
    */
   
   return postfix;
}

/*****************************************************
 * CONVERT STRING TO STACK
 * Convert each word or number in a string
 * into a stack, for better processing.
 *****************************************************/
custom::stack <char> convertStringToStack(const string & string)
{
   custom::stack<char> stack;
   
   // loops through the string, processing each word
   
   // if word is a space, do not put it into the stack
   
   return stack;
}

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";
   
   do
   {
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);
      
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
            
      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << "\t\tpostfix: " << postfix << endl << endl;
      }
   }
   while (input != "quit");
}

/**********************************************
 * CONVERT POSTFIX TO ASSEMBLY
 * Convert postfix "5 2 +" to assembly:
 *     LOAD 5
 *     ADD 2
 *     STORE VALUE1
 **********************************************/
string convertPostfixToAssembly(const string & postfix)
{
   string assembly;
   
   return assembly;
}

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";
   
   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);
      
      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << convertPostfixToAssembly(postfix);
      }
   }
   while (input != "quit");
   
}


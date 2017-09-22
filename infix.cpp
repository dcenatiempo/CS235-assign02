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
#include <cctype>      // for isalpha isdigit isspace
#include <sstream>     // for stringstream
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using std::stringstream;
using std::cerr;
//using namespace std;
using namespace custom;

//   https://content.byui.edu/file/fddcd57e-77ee-4853-a5ec-d787dd07d047/1/Ponder/235.02.Ponder.html

/*******************************************
 * DISPLAY
 * Display the contents of the stack. We will
 * assume that T is a data-type that has the
 * insertion operator defined.
 *******************************************/
template <class T>
ostream & operator << (ostream & out, stack <T> rhs) throw (const char *)
{
   // we need to make a copy of the stack that is backwards
   stack <T> backwards;
   while (!rhs.empty())
   {
      backwards.push(rhs.top());
      rhs.pop();
   }
   
   // now we will display this one
   out << "{ ";
   while (!backwards.empty())
   {
      out << backwards.top() << ' ';
      backwards.pop();
   }
   out << '}';
   
   return out;
   }




/*****************************************************
 * IS CHARACTER: ( ) ^ * / % + -
 * Checks to see if character is one of these operators
 *****************************************************/
bool isOperator (const char a) {
   char operators[] = "()^*/%+-";
   for (int i = 0; i < 8; i++) {
      if (a == operators[i])
         return true;
   }
   return false;
}

/*****************************************************
 * CONVERT STRING TO STACK
 * Convert each word or number in a string
 * into a stack, for better processing.
 *****************************************************/
custom::stack <string> convertStringToStack(const string str)
{
   
   custom::stack <string> tempStack;
   custom::stack <string> revStack;
   int i = 0;
   // traverse through the string, processing each word
   while ( i < str.length() ) {
      if ( isspace( str[i]) ) {
         i++;
      }
      else if ( isalpha( str[i] ) ) {
         string tempString;
         stringstream ss;
         //push variable to stack
         for ( ; i < str.length() && isalpha( str[i] ); i++ ){
            ss << str[i];
         }
         ss >> tempString;
         tempStack.push( tempString );
      }
      else if ( ( str[i] == '-' && isdigit( str[i+1] ) ) || isdigit( str[i] ) ) {
         string tempString;
         stringstream ss;
         //push number to stack
         ss << str[i];
         i++;
         for ( ; i < str.length() && ( isdigit( str[i] ) || str[i] == '.'); i++ ){
            ss << str[i];
         }
         ss >> tempString;
         tempStack.push( tempString );
      }
      else if ( isOperator( str[i]) ){
         string tempString;
         stringstream ss;
         // push operator to stack
         ss << str[i];
         ss >> tempString;
         tempStack.push( tempString );
         i++;
      }
      else cerr << "Invalid Infix";
   }
   cout << tempStack;
   int size = tempStack.size();
   for (int i = 0; i < size; i++) {
      revStack.push (tempStack.top());
      tempStack.pop();
   }
   cout << revStack;
   return revStack;
}

/*****************************************************
 * CONVERT INFIX TO POSTFIX
 * Convert infix equation "5 + 2" into postfix "5 2 +"
 *****************************************************/
string convertInfixToPostfix(const string infix)
{
   string postfix;
   custom::stack <string> reverseInfix( convertStringToStack(infix) );
   //custom::stack <string> tempStack;
   //cout << reverseInfix;

   
   
   //Order: (), ^, * / %, + -
   
   //for ( int i = 0; i < reverseInfix.size(); i++) {
      
            
   //   }
   /*
    FOR iInfix <- 0 .. infix.size() – 1
      SWITCH infix[iInfix]
         CASE number or variable
            postfix[iPostfix++] <- infix[iInfix]
         CASE (
            stack.push(infix[iInfix])
         CASE )
            WHILE stack.top() ≠ (
               postfix[iPostfix++] <- stack.top()
               stack.pop()
            stack.pop()
         DEFAULT
            WHILE !stack.empty() &&
                  infix[iInfix] ≤ stack.top() <- here ≤ understands the order of operations
               postfix[iPostfix++] <- stack.top()
               stack.pop();
            stack.push(infix[iInfix])
      WHILE not stack.empty()
         postfix[iPostfix++] <- stack.top()
         stack.pop()
    */
   
   return postfix;
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

   /*
   postfixToAssembly(postfix, size)
      FOR i = 0 .. size – 1
         IF postfix[i] is a number or variable
            stack.push(postfix[i])
         ELSE
            rhs <- stack.top()
            stack.pop()
            lhs <- stack.top()
            stack.pop()
            variable <- nextVariable++  <- Creates new variable names for later use
            IF lhs.isVariable
               assembly += “LOD ” + lhs
            ELSE
               assembly += “SET ” + lhs
            assembly += postfix[i] + rhs
            assembly += “SAV ” + variable
    
            stack.push(variable)
      RETURN stack.top()
    */
   return "need to complete algorithm";//assembly;
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


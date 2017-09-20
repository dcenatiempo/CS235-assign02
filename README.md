# CS 235 Assignment 02: Stacks & Infix to Postfix
The second programming assignment will be to implement the stack data structure and use it to convert an infix mathematical expression (4 + 8 * 3) into a postfix one (4 8 3 * +).
## Stack
Create a class encapsulating the notion of a stack. This will work exactly like the `std::stack` class. Of course, any data-type will need to be supported, so your class will be a template class. It will need to be defined in its own header file (`stack.h`). The class name must be `stack`.

Your class will need to support the following operations:
* **Constructors**: Default constructor (create a stack with zero elements in it), a non-default constructor (taking a capacity value as a parameter), and the copy constructor. If there is insufficient memory to allocate a new buffer, then the following exception is thrown: `ERROR: Unable to allocate a new buffer for Stack.`
* **Destructor**: When finished, the class should delete all the allocated memory.
* **operator=**: Assignment operator. This method takes a stack as a parameter and copies all the elements to `this`. If the current buffer size is sufficient, not allocation is made. If the current buffer size is not sufficient, enough space is allocated to accomodate the new data. If there is insufficient memory to allocate a new buffer, then the following exception is thrown: `ERROR: Unable to allocate a new buffer for stack`. It also returns `*this` by-reference as all assignment operators should.
* **empty()**: Test whether the stack is empty. This method takes no parameters and returns a Boolean value.
* **size()**: Return the stack size. This method takes no parameters and returns an integer value.
* **clear()**: Clear the contents. This method takes no parameters and returns nothing. Note that you do not need to free the allocated memory; just set the size member variable to zero.
* **push()**: Adds an element to the stack. This method takes a single parameter (the element to be added to the end of the stack) and has no return value. Note that if the stack is full, then the capacity will be doubled. In the case of an allocation error, the following c-string exception will be throw:
`ERROR: Unable to allocate a new buffer for Stack`
* **pop()**: Removes an element from the end of the stack, serving to reduce the size by one. Note that if the stack is already empty, the stack remains unchanged.
* **top()**: Returns the element currently at the end of the stack. There are two versions of this method: one that returns the element by-reference so the element can be changed through the `top()` method. The second version returns the element by-value or const by-reference so this is not changed. If the stack is currently empty, the following exception will be thrown:
`ERROR: Unable to reference the element from an empty stack`
Note that the only way to access elements in a stack is through the `top()` method. This means that there is no iterator for stack.

## Driver Program
A driver program is provided. This file (`/home/cs235/week02/assignment02.cpp`) will pound-include your header file (`stack.h`) and expect a template class stack to be defined therein. This program will exercise your class, filling the container with user input and displaying the results. As with previous assignments, a makefile will be provided (`/home/cs235/week02/makefile`). A header file (`infix.h`) will be provided and an implementation file (`infix.cpp`) as well. You will need to create a stack header file (`stack.h`).

## Infix to Postfix
In addition to passing the four test functions for the stack class, you will also need to use the stack class to implement a program to convert an infix expression (4 + 8 * 3) into a postfix expression (4 8 3 * +). There is a discussion on this in chapter 2 of the textbook. Note that you will need to handle the following operators:

1. `()` The parentheses are the highest level of the order of operations.
2. `^` The exponent operator comes immediately after the parentheses. Note that the algorithm in the textbook cannot handle the exponent operator properly. You will need to handle this case.
3. `* / %` Multiplication, division, and modulus are after the exponent operator. They are at the same level of the order of operations.
4. `+ -` Addition and subtraction are after multiplication, division, and modulus.
Your 'convertInfixToPostfix()' function will prompt the user for an infix equation and display the postfix version of the same. The following is an example of the output, with underline text as user input:

```Enter an infix equation.  Type "quit" when done.
infix > 2 + 5
        postfix:  2 5 +

infix > (5.0 / 9.0) * (fahrenheit - 32)
        postfix:  5.0 9.0 / fahrenheit 32 - *

infix > 1 + 2 * 3 ^ 4
        postfix:  1 2 3 4 ^ * +

infix > quit
```

A few hints that may come in handy when implementing this part of the assignment:

- There is a tab character immediately before postfix.
- When displaying the postfix notation, there is a space before every operator, variable, and number.
- Variable names with more than one letter must be supported. According the syntax for the C Programming Language, variable names are made up of letters and digits; the first character must be a letter. The underscore counts as a letter.
- Numbers may include more than one digit. A number may start with a decimal and may not have more than one decimal.
- You may wish to work through a few examples in the textbook.
- You may wish to create a class to turn the input line into a collection of tokens in an effort to simplify this problem.
To get full credit for this program, you must use your own stack class. If your class does not work, use the standard template library `std::stack` from `#include <stack>`. If you do this, you will loose points for the first half of the assignment, but not the second.

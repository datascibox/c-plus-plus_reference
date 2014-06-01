##The Problem
We are going to work on making our own classes with private data members and special accessors. We are going to build a Stack class, a common data structure with well known accessors.

##Some Background
Our Stack will be a data structure that stores char. A Stack analogy is a stack of dishes.
Things you can do to this stack of dishes:  
• you can "look at" that top dish (is it clean)?  
• you can add a dish to the top of the stack, push it on  
• you can take a dish from the top of the stack, pop it off  
• you can test to see if the stack is empty (so you don't try to take a dish off  
the stack if there is not one there)

##Your Tasks
We are going to make a Stack class with these characteristics and use it to solve a simple problem.

##The Class
The Stack class will have as its underlying data member a vector<char> called stack (lower case). This is a private data member, which will represent the stack. Since the vector is private, you cannot access it from a main program using the class.

##Interface, stack.h file
• Stack. constructor, no args, default constructor  
• char top(). member function. Returns the char at the top of the stack. Does not change the stack.  
• void push(char). member function. no return. Places the char argument on the top of the stack.  
• void pop(). member function. no return. takes the top char off of the stack.  
• bool empty(). member function. returns true if the stack is empty, false otherwise.  
• ostream& operator<<(ostream &out, Stack &s). This is a friend function   
   (not a member). This is not a normal stack operator, but it is useful to print out the contents of the stack for debugging purposes.

##Implementation, stack.cpp
Essentially, the vector represents the stack where the last element in the vector is the top. Useful vector methods:  
• push_back(char) : push a character to the end of the vector  
• pop_back():removethelastelementfromthevector  
• empty() : is the vector empty  

##Test
There are lots of tasks that can be accomplished by a stack (as well as other methods). For example:
• you can reverse a string by pushing the individual character on to the stack and then top/pop them off  
￼￼￼￼
• you can count whether brackets are balanced, that there are as many left bracket '{' as right bracket '}' ,  
  by pushing when you encounter a left and popping when you encounter a right. If the stack is empty at the end of input, they were balanced. If not:
  o if there are left brackets left at the end of the input, too many left brackets o if the stack comes up empty before the end of input, too may right brackets.

There is a main program that does the reverse of a string using our string class, your job is to write the paren matcher using your Stack class. Some details:  
• open a file for reading  
• get a line  
• for each character in the line:  
     o if the character is a '{', push that on the stack o if the character is a '}', pop the stack  
• put appropriate checks in for empty stack  
• report the results. if failure, what was wrong, too many '}' or too many '{' .  


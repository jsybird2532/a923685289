#include <stdio.h>
#include <string.h>
#include "stack.h"

Stack stack;

Stack registers[26];

void main(void) {

  int run = 1; // This variable will always be equal to 1 while the user hasn't entered the q command

  Stack = &newStack();

  for(int i = 0; i < 26; i++)
  {
    registers[i] = &newStack();
  }

  char input[];   // Character input char * 
  int index = 0;  // The index of input currently being worked with by the parser
  while(run) {
    input = scan();
    while(index < strlen(input) && run == 1)
    {
      if(isdigit(input[index]))
      {
	int elementLength = 0; // The length of the integer being parsed
	while(isdigit(input[index]))
	{
	  intLength++;
	  index++;
	}
	int *temp = malloc(sizeof(int));
	*temp = 0;  
	for(int i = 0; i < intLength; i++)
	{
	  *temp = *temp * 10;
	  *temp = *temp + atoi(input[index + i - intLength]);
	}
	push(stack,/*Casting*/temp);
      }
  
      else if(input[index] == ' ')
      {
	index++;
      }

      else if(isalpha(input[index]))
      {	
	switch (input[index]) {

	  case 's':
	    if(input[index+1] == 'r')
	    {
	      index++;
	      /* doSomething with string sr */
	    }
	    break;

	  case 'l':
	    if(input[index+1] == 'r')
	    {
	      index++;
	      /* doSomething with string lr */
	    }
	    break;

	  case 'S':
	    if(input[index+1] == 'r')
	    {
	      index++;
	      /* doSomething with string Sr */
	    }
	    break;

	  case 'L':
	    if(input[index+1] == 'r')
	    {
	      index++;
	      /* doSomething with string Lr */
	    }
	    break;

          case 'p':
	    /* doSomething with string p */
	    break;

          case 'c':
	    /* doSomething with string c */
	    break;
      
	  case 'd':
	    /* doSomething with string d */
	    break;

	  case 'r':
	    /* doSomething with string r */
	    break;

	  case 'n':
	    /* doSomething with string n */
	    break;

	  case 'f':
	    /* doSomething with string f */
	    break;

	  case 'x':
	    /* doSomething with string x */
	    break;

          case 'q':
	    run = 0;
	    break;
        }
        index++;
      }

      else
      {
	switch(input[index]) {

	  case '+':
	    push(stack,/*Casting*/&(/*Casting*/ *pop(stack) + *pop(stack)));
	    break;

	  case '-':
	    push(stack,/*Casting*/&(/*Casting*/ -1 * *pop(stack) + *pop(stack)));
	    break;

	  case '*':
	    push(stack, /*Casting*/&(/*Casting*/ *pop(stack) * *pop(stack)));
	    break;

	  case '/':
	    int temp1 = *pop(stack);  // temporary variable to store top stack value
	    int temp2 = *pop(stack);  // temporary variable to store 2nd stack value

	    push(stack, /*Casting*/&(/*Casting*/ temp2 / temp1);
	    break;

	  case '%':
	    int temp1 = *pop(stack);  // temporary variable to store top stack value
	    int temp2 = *pop(stack);  // temporary variable to store 2nd stack value

	    push(stack, /*Casting*/&(/*Casting*/ temp2 % temp1);
	    break;

	  case '=':
            /* doSomething with string = */
	    break;

	  case '<':
	    /* doSomething with string < */
	    break;

          case '>':
	    /* doSomething with string > */
	    break;

	  case '[':
	    /* doSomething with string [ until delimiter ] */
	    break;
	}
      }
    } 
  }
}
	

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "stack.h"

int main(void) {
	printf("Hi, this program compiles"); 
	Stack s = newStack();
	printf("Empty? %d\n", isEmpty(&s));
	char* s1 = "how are you\n"; 
	push(&s,"String 1\n");
	printf("%s", (char*)(s->val));
	push(&s, s1);
	printf("%s", (char*)(s->val));
//	pop(&s);
//	printf("%s", (char*)(s->val));
	printf("Full? %d\n", isFull(&s));
	printf("Empty? %d\n", isEmpty(&s));
	int numElements = getNumElements(&s);
	printf("%d", numElements);
	destroy(&s);
}
 




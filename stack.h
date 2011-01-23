typedef struct {
	void *val; 
 struct	Node *next; 
} Node; 

Node *newNode(void *newval, Node *succ)
{ 
	Node *newN = malloc( sizeof(Node)); 
	*newN = (Node){newval, succ};
	return newN; 
} 

typedef Node *Stack; // calling convention: Stack s = &newStack(); 

#define STACK_SIZE 1

Stack newStack (void) 
{
	return (Stack)newNode(NULL, NULL); 
}


int getNumElements(Stack *stack)
{
	int size = 0;
	Node *top = *stack;
	if (top->next == NULL) {
		return 0; 
	} 
	else { 
		while (top->next != NULL) {
			top = (Node*)top->next;
			size++; 
		}
		return size; 
	} 
} 


int isEmpty(Stack *stack) {
	if (getNumElements(stack) == 0)
		return 1;
	else 
		return 0;
}

int isFull(Stack *stack) {
	if (getNumElements(stack) >= STACK_SIZE)
		return 1;
	else 
		return 0;
}


void push( Stack *stack, void *value) 
{
	if (isFull(stack)) {
		printf("dc: Stack full");
	}
	else {
		*stack = newNode( value, *stack ); 
	}
} 

void *pop(Stack *stack )
{
  Node *top = *stack;
  if (isEmpty(stack)) {
	printf("dc: stack empty");
	return NULL; 
  } 
  else { 
	  void *answer = top->val; 
	  *stack = (Stack)top-> next;
	  free(top);
	  return answer; 
  }
} 

void empty(Stack *stack) {
	while (!isEmpty(stack))
		pop(stack);
} 

int destroy(Stack *stack) {
	empty(stack);
	free(*stack); 
}



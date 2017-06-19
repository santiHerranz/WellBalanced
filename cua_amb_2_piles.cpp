#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    int top_inx;
} pila_t;

typedef struct {
    pila_t *pushes;
    pila_t *pops;
} cua_t;

//this initializes the stack to a specific size;
void initStack(pila_t *stack, size_t size) {
    stack->size = size;
    stack->data = (int*) malloc(size*sizeof(int));
    stack->top_inx = -1;
}

//this checks if a stack is empty.  Since it is implemented in
//an array, emptiness will be represented with a negative top index
//orphaned data is ignored since the space will never be looked at
int isEmpty(pila_t *stack) {
    if (stack->top_inx < 0) return 1;
    else return 0;
}

//this decrements the stack's top index and returns the value
//decrementing the index allows pushing to that location.
int pop(pila_t *stack) {
    if (isEmpty(stack)) return 0;
    return stack->data[stack->top_inx--];
}

//increment the top index and push a new variable in that spot
void push(pila_t *stack, int a) {
    if ((stack->top_inx+1) < (int) stack->size) {
        stack->data[++stack->top_inx] = a;
    }
    else {
        printf("Error, no space in stack!");
    }
}

//non-destructive check of the top element in the stack
int peek(pila_t *stack) {
    if (isEmpty(stack)) {
        printf("No data in stack.\n");
    }
    return stack->data[stack->top_inx];
}

//initializes a queue by initializing two stacks
void initQueue(cua_t *queue, size_t size) {
    queue->pushes = (pila_t*) malloc(sizeof(pila_t));
    initStack(queue->pushes, size);
    queue->pops = (pila_t*) malloc(sizeof(pila_t));
    initStack(queue->pops, size);
}

//handles stack operations to add an element to the back of the queue
void enqueue(cua_t *queue, int a) {
    push(queue->pushes, a);
}

//handles stack operations to remove from the queue
int dequeue(cua_t *queue) {
    if (isEmpty(queue->pops)) {
        //move all elements from the pushes stack to the pops stack
        //if the pops stack is empty.
        while(!isEmpty(queue->pushes)) {
            push(queue->pops, pop(queue->pushes));
        }
    }
    return pop(queue->pops);
}

int peekQueue(cua_t *queue) {
    return peek(queue->pops);
}

//simple test program
void queueUsingTwoStacks() {


    pila_t *my_stack = (pila_t*) malloc(sizeof(pila_t));

    cua_t *my_queue = (cua_t*) malloc(sizeof(cua_t));
    initQueue(my_queue, 20);

    for (int i = 2; i < 10; i++) {
        enqueue(my_queue, i*10);
    }

    printf("%d\n", dequeue(my_queue));

    enqueue(my_queue, 20);
    enqueue(my_queue, 13);

    for (int i = 0; i < 10; i++) {
        int DQ = dequeue(my_queue);
        if (DQ)
            printf("%d\n", DQ);
        else
            printf("No data in queue.\n");
    }


}
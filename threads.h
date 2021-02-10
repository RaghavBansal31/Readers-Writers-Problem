#include "q.h"

#define SIZE 1024

#include<malloc.h>


TCB_t *RunQ;



void start_thread(void (*function)(void))

{

	void *stackP = malloc(SIZE);

	TCB_t *NewItem;

	NewItem=malloc(sizeof(struct TCB_t));

	init_TCB(NewItem, function, stackP, SIZE);

	AddQueue(&RunQ, NewItem);

}



void run()

{

	ucontext_t parent;

	getcontext(&parent);

	swapcontext(&parent, &(RunQ->context));

}



void yield()

{
	ucontext_t parent;

	getcontext(&parent);

	RotateQ(&RunQ);

	swapcontext(&parent,&(RunQ->context));

}

void start_thread1(void)
{}
	
void yield1(void)
{}

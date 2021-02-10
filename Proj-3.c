
#include<stdio.h>

#include "threads.h"

#include<malloc.h>

// semaphores ques
struct Semaphores
{
   struct Semaphores *prev;

   struct Semaphores *next;

   int G;

};
// Semaphores
typedef struct Semaphores *Pointer;

   Pointer DelQ;

	 Pointer ReadyQ;

   Pointer BufferQ;

   void Init_BufferQ(void)
       {

           BufferQ=NULL;

        }

   Pointer Get(void)
   {
         Pointer TNode;

         TNode=(Pointer)malloc(sizeof(struct Semaphores));

         return(TNode);
   }

// del queue
void Init_DelQ(void)
     {

         DelQ=NULL;

      }
// ready queue
void Init_ReadyQ(void)
		{
        ReadyQ=NULL;

         }


void AddQueues(Pointer *tem,int d)

{
         Pointer NewNode,local;

             NewNode=Get();

           NewNode->prev=NULL;

           NewNode->next=NULL;

             NewNode->G=d;

          if(*tem==NULL)

           *tem=NewNode;

           else
    {
         for(local=*tem;local->next!=NULL;local=local->next);

         local->next=NewNode;
     }
}




void Display(Pointer *tem)

{
              Pointer local;

             if(*tem==NULL)

             printf("]nQueue is empty");
else

{
              for(local=*tem;local!=NULL;local=local->next)

              printf(" %d ",local->G);
}

}

int DeleteQueues(Pointer *tem)
{
          Pointer p;

           int a;

           if(*tem==NULL)
{
           printf("\n Queue is already Empty\n");

           return(0);
}

else

{
           p=*tem;

          *tem=p->next;

           a=p->G;

           return(a);
}

}

struct semaphore

{
       int value;

         Pointer SemQ;
}Sem;

// one of the mentioned function in assignemnt 1
void Init_Semaphore(int a)

{

         Sem.value=a;

         Sem.SemQ=NULL;
}
// initialization

int pt[100],ct[100];
int i=0;
int R,W,B,N;

void PS(void)
{
Sem.value=Sem.value-1;
}

void V(void)
{
Sem.value=Sem.value+1;
}

void RotateQueue(Pointer *tem)
{
int a;

a=ReadyQ->G;

ReadyQ=ReadyQ->next;

AddQueues(&ReadyQ,a);
}

void DeleteReadyQ(void)
{
ReadyQ=ReadyQ->next;
}

void Reader(int,int);

void Writer(int,int);

void yields(void)
{
if(ReadyQ!=NULL)
{
	if((ReadyQ->G<0) && R>0)
    	{

    	}
	else if((ReadyQ->G>0) && W>0)
	{

	}
}

}
// intialing the queues of R and W
int RQ[40];

int WQ[40];

int main()
{
      int k=0,m,g,Wr=1,f=0,r=0,wc=0,RW=1;

			Init_BufferQ();

       Init_ReadyQ();


        Init_DelQ();

       scanf("%d,%d",&R,&W);

      Init_Semaphore(B);

          g=(R+W)-1;

while(k<=g)
          {
        scanf("%d",&m);

             if(m>0)

{
            RQ[r]=m;

            r=r+1;
}
else if(m<0 && Wr==1)

{
RQ[r]=m;

r=r+1;

Wr=0;

}
else if(m<0 && Wr==0)

{
WQ[wc]=m;

wc=wc+1;

}
AddQueues(&ReadyQ,m);

k=k+1;
}


while(f<r)
{
     if(RQ[f]>0)

     {
	for(RW=1;RW<=2;RW++)

	{
		k=f;

		while(RQ[k]>0 && k<r)

		{
			Reader(RQ[k],RW);

			k=k+1;

		}

	}
	f=k;

     }
     if(RQ[f]<0)

	Writer(RQ[f],f);

f=f+1;

}


for(k=0;k<wc;k++)

Writer(WQ[k],k);


return(1);

}
// reader func
void Reader(int id, int RW)

{
	if(RW==1)

	{
    	  printf("\nThis is the %d th reader reading value i = %d for the first time\n",id,i);
	}

	if(RW==2)

	{
    	  printf("\nThis is the %d th reader reading value i = %d for the second time\n",id,i);
	}


}
// writer func
void Writer(int id , int pos)

{

int RW=1;

i=-(id);

while(RW<=2)

{
	if(RW==1)

	{
    	printf("\nThis is the %d th writer writing value i = %d\n",-(id),i);
	}

	if(RW==2)

	{
    	printf("\nThis is the %d th writer verifying value i = %d\n",-(id),i);
	}
RW=RW+1;

}
}

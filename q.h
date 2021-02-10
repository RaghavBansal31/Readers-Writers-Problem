#include <stdlib.h>

#include "TCB.h"


void AddQueue(struct TCB_t **head, struct TCB_t *item);

struct TCB_t *DelQueue(struct TCB_t **head);

void RotateQ(struct TCB_t **head);


void AddQueue(struct TCB_t **head, struct TCB_t *item)

{
if(head==NULL)

{

  *head = item;

   item->next=item;

   item->prev=item;
}
else
{
   item->next=*head;

   item->prev=(*head)->prev;

   ((*head)->prev)->next=item;

   *head=item;
}
}



struct TCB_t *DelQueue(struct TCB_t **head)
{

  TCB_t *item;

  if(*head==NULL)

  return(*head);

  else
{
  item=*head;

  *head=(*head)->next;
  
  return(item);
}
}



void RotateQ(struct TCB_t **head)

{

	*head=(*head)->next;

}

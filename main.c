#include<stdio.h>
#include<stdlib.h>

typedef enum{TRUE,FALSE} Boolean;

typedef struct node{
  char entry;
  struct node *next;
}Node;

typedef struct{
 int count;
 Boolean full;
 Node *front;
 Node *rear;
}Queue;

void CreatQueue(Queue *q){
 q->count=0;
 q->full=FALSE;
 q->front=q->rear=NULL;
}

Boolean IsQueueEmpty(Queue *q){
 return (q->front==NULL && q->rear==NULL);
}

Boolean IsQueueFull(Queue *q){
 return (q->full);
}

void insert(char x, Queue *q){
 Node *np;
 np=(Node *)malloc(sizeof(Node));

 if(np==NULL){
    printf("not enough memory...");
    q->full=TRUE;
 }else{
   np->entry=x;
   np->next=NULL;

   if(IsQueueEmpty(q)){
    q->front=q->rear=np;
   }else{
     q->rear->next=np;
     q->rear=np;
   }
 }
 q->count++;
}

void Remove(char *x,Queue *q){
 Node *np;

 if(IsQueueEmpty(q)){
    printf("Cannot remove from empty queue...");
 }else{
   q->count--;
  *x=q->front->entry;
  np=q->front;
  q->front=q->front->next;
  np=q->front;

  if(q->front==NULL){
    q->rear=NULL;
  }

  free(np);
 }

}

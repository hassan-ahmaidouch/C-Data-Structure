#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};

struct queue{ 
 struct node *front;
 struct node *rear;
};


void create_queue(struct queue *q)
{
 q -> rear = NULL;
 q -> front = NULL;
}

void insert(struct queue *q,int val){
 struct node *ptr;
 ptr = (struct node*)malloc(sizeof(struct node));
 ptr -> data = val;
 if(q -> front == NULL){
 q->front = ptr;
 q->rear = ptr;
 q->front->next = q->rear->next = NULL;
 }

 else{
 q->rear->next = ptr;
 q->rear = ptr;
 q->rear->next = NULL;
 }

}

void delete_element(struct queue *q){

 struct node *ptr;
 ptr = q -> front;
 if(q -> front == NULL)
 printf("\n UNDERFLOW");
 else
 {
 q->front = q->front->next;
 printf("\n The value being deleted is : %d", ptr -> data);
 free(ptr);
 }
}



int main(){
struct queue *q = (struct queue *)malloc(sizeof(struct queue)); // Allocate memory for q

 create_queue(q); // Pass the allocated queue to initialize it
 insert(q,10);
 insert(q,5);

    return 0;
}
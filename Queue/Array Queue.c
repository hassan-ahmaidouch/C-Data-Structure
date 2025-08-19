#include<stdio.h>

#define MAX 10
int queue[MAX];
int front=-1,rear=-1;

void insert(){
 int num;
 printf("\n Enter the number to be inserted in the queue : ");
 scanf("%d", &num);
 if(rear == MAX-1)
 printf("\n OVERFLOW");
 else if(front == -1 && rear == -1)
 front = rear = 0 ;
 else
 rear++;
 queue[rear] = num;
}

int delete_element(){
 int val;
 if(front == -1 || front>rear)
 {
 printf("\n UNDERFLOW");
 return -1;
 }
 else
 {
 val = queue[front];
 front++;
 
 
 return val;
 }
}

void display()
{
 int i;
 printf("\n");
 if(front == -1 || front > rear)
 printf("\n QUEUE IS EMPTY");
 else
 {
 for(i = front;i <= rear;i++)
 printf("\t %", queue[i]);
 }
}

int main(){


    
    return 0;
}
#include<stdio.h>
#define MAX 4
int stack_arr[MAX];
int top = -1;

void push(int stack_arr[],int val){
 if (top == 3){
    printf("satck overflow");
 }
 else
 {
  top++;
  stack_arr[top] = val;
 }
}



int pop(int stack_arr[]){
 int data ; 

 if(top == -1)
 {
  printf("\n STACK UNDERFLOW");
  return -1;
 }
 else
 {
  data = stack_arr[top];
  top--;

    return data ; 
 }

}


int peek(int stack_arr[])
 {
  if(top == -1)
  {
  printf("\n STACK IS EMPTY");
  return -1;
  }
  else
  return (stack_arr[top]);
}



void print(){
    int i ; 
    if(top == -1){
        printf("stack underflow ");
        return ;
 }
 for(i=top;i>=0;i--){
    printf("%d",stack_arr[i]);
 }
}


int main(){


int data; 

   push(stack_arr,2);
   push(stack_arr,3);
   push(stack_arr,4);
   push(stack_arr,5);
    data = pop(stack_arr);
   data = pop(stack_arr);
    print();
    printf("la valeur de top est : %d",peek(stack_arr));

    return 0 ;
}
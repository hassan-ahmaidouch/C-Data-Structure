
#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *next ;
};


struct node* createLinkedList(int n) {
    struct node* top = NULL;
    struct node* ptr = NULL;
    int value, i;

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if (top == NULL) {
            top = newNode;  // First node becomes the start
        } 
        else {
            ptr->next = newNode;  // Add node to the end of the list
        }
        ptr = newNode;  // Move temp to the new last node
    }
    return top;
}

void push_linked_liste(struct node *top){
   int val ;
   struct node *newnode = (struct node *)malloc(sizeof(struct node));
   printf("saisir la data de la node :");
   scanf("%d",&val);
   newnode->data = val;
   if(top == NULL){
      newnode->next = NULL;
      top = newnode;
   }

   else{
      newnode->next = top;
      top = newnode;
   }
}

void pop_linked_liste(struct node *top){

   struct node *ptr = NULL;
   if(top ==NULL){
      printf("STACK UNDERFLOW !");
   }
   else{
      ptr = top ; 
      top = top->next ; 
      
      free(ptr);
   }

}

void peek_linked_liste(struct node *top){
   
   if(top == NULL){
      printf("the stack is empty  ou la pile est vide");
   }
   else{
      printf("la valeur de sommet est : %d",top->data);
   }
}


int main(){
   int n;
   printf("entrer le nombre de nodes aue vous voulez ?");
   scanf("%d",&n);
  struct node *top = createLinkedList(n);





   return 0;
}

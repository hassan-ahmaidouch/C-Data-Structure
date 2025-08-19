#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a linked list
struct node* createLinkedList(int n) {
    struct node* start = NULL;
    struct node* ptr = NULL;
    int value, i;

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;  // First node becomes the start
        } 
        else {
            ptr->next = newNode;  // Add node to the end of the list
        }
        ptr = newNode;  // Move temp to the new last node
    }
    return start;
}



//DISPLAY : 
/*void display(struct node *start){

 struct node *ptr;
 ptr = start;
 while(ptr != NULL)
 {
 printf("\t %d", ptr -> data);
 ptr = ptr -> next;
 }

}*/




//SEARCH A VALUE : 
/*void search(struct node* start ){
 int value ; 
 int *pos; 
 struct node *ptr ; 
 ptr = start; 
 while(ptr != NULL){
    if(value ==  ptr->data){
    pos = ptr;
     printf("the position of value is : %p",pos);
     return; 
        
    }
    else{
        ptr=ptr->next;
    }
    
 }
 printf("the postion is not found");

}



*/



// INSERT IN THE BEGINING :
 void insert_in_beg(struct node *start){
//newnode creation : 
struct node *newnode = (struct node *)malloc(sizeof(struct node *));
// Vérifier si l'allocation a réussi
    if (new_node == NULL) {
        printf("Échec de l'allocation de mémoire\n");
        return;
    }
newnode->data = 5; 
newnode->next = NULL; 

// now insert in the begining

newnode->next = start ; 
start = newnode;


}


        // INSERT AFTER A LINKED LISTE :

struct node *insert_after(struct node *start)
{
 struct node *new_node, *ptr, *preptr;
 int num, val;
 printf("\n Enter the data : ");
 scanf("%d", &num);
 printf("\n Enter the value after which the data has to be inserted : ");
 scanf("%d", &val);
 new_node = (struct node *)malloc(sizeof(struct node));
 new_node -> data = num;
 ptr = start;
 preptr = ptr;
 while(preptr -> data != val)
 {
 preptr = ptr;
 ptr = ptr -> next;
 }
 preptr -> next=new_node;
 new_node -> next = ptr;
 return start;
}



        // INSERT BEFORE A LINKED LISTE 

struct node *insert_before(struct node *start)
{
 struct node *new_node, *ptr, *preptr;
 int num, val;
 printf("\n Enter the data : ");
 scanf("%d", &num);
 printf("\n Enter the value before which the data has to be inserted : ");
 scanf("%d", &val);
 new_node = (struct node *)malloc(sizeof(struct node));
 new_node -> data = num;
 ptr = start;
 while(ptr -> data != val)
 {
preptr = ptr;
 ptr = ptr -> next;
 }
 preptr -> next = new_node;
 new_node -> next = ptr;
 return start;
}



// INSERT AT THE END OF THE LINKED LIST 
void insert_at_end(struct node *start){

struct node *ptr = NULL ;
ptr = start; 
struct node *newnode = (struct node *)malloc(sizeof(struct node *));
// Vérifie si l'allocation a réussi
    if (newnode == NULL) {
        printf("Overflow\n");
        return;
    }
newnode->data = 2; 
newnode->next = NULL ; 
while(ptr->next != NULL){
    ptr = ptr->next ;
}

ptr->next = newnode; 


}





// DELETE IN THE BEGINING:
void delete_in_the begining(struct node *start){

struct node *ptr ; 
ptr = start ; 

if(start == NULL){
    printf("the linked list is empty or the linked list dosen't existe "); // alpha

}
else{
    start = start->next ; 
    free(ptr);
}

}


          // DELETE AFTER :
struct node *delete_after(struct node *start) 
{
 struct node *ptr, *preptr;
 int val;
 printf(“\n Enter the value after which the node has to deleted : “);
 scanf(“%d”, &val);
 ptr = start;
 preptr = ptr;
 while(preptr -> data != val)
 {
 preptr = ptr;
 ptr = ptr -> next;
 }
 preptr -> next=ptr -> next;
 free(ptr);
 return start;
}

          


// DELETE  AT THE END : 
void delet_at_end(struct node *start){

struct node *ptr ; 
ptr = start ; 

if(start == NULL){
    printf("the linked list is empty or doesn't exist ");

}
else{
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr = NULL;

}


}





int main(){
  int n ; 


  printf("How many nodes do you want to create? ");
    scanf("%d", &n);
    struct Node* start = createLinkedList(n);
    


  return 0;
}
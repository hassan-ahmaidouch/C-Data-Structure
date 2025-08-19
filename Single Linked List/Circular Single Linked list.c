//INSERT NODE IN CIRCLE LINKED LISTE AT THE BEGINING ; 

void insert_cir_beg(struct node *start){

struct node *ptr ;
struct node *newnode;
newnode =(struct node *)malloc(sizeof(struct node *));
// Vérifie si l'allocation a réussi
    if (newnode == NULL) {
        printf("Overflow\n");
        return;
    }
    newnode->data = 4;
    newnode->next = start;
 ptr = start;
while(ptr ->next != start){

ptr = ptr->next;

}
ptr->next = newnode ; 
start = newnode ; 

}




//INSERT AT THE END : 
void insert_end_circ(struct node *start){
    struct node *ptr = NULL; 
    
    struct node *newnode = NULL;
newnode = (struct node *)malloc(sizeof(struct node *));
// Vérifie si l'allocation a réussi
    if (newnode == NULL) {
        printf("Overflow\n");
        return;
    }
    newnode->data = 4;
    newnode->next = NULL; 
   ptr = start ;
  while(ptr->next != start){
    ptr = ptr->next; 

  }

ptr->next = newnode ; 
newnode->next = start ; 

}





//DELET IN THE BEGINING :
void delete_beg(struct node *start){

struct node *ptr ; 
ptr = start ; 

if(start == NULL){
    print("underfolow or circular linked liste is empty or circular lined liste doesn't exist");
}
while(ptr->next != start){
    ptr = ptr->next ; 

}
ptr->next = start->next;
start = NULL; 
start = ptr->next;
  

}





 //DELETE AT END OF CIRCULAR LINKED LIST : 
void delete_end(struct node *start){

struct node *ptr ;
struct node *preptr;  
ptr = start ; 

if(start == NULL){
    print("underfolow or circular linked liste is empty or circular lined liste doesn't exist");
}
while(ptr->next != start){
    preptr = ptr;
    ptr = ptr->next ; 

}
preptr->next = start; 
free(ptr); //or ptr = NULL
  


}


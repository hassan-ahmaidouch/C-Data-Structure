
#include<stdio.h>
#include<stdlib.h>

struct node{
int data ;
struct node *prev;
struct node *next; 
};

// Function to create a doubly circular linked list with n nodes
struct node *createDoublyCircularLinkedList(int n) {
    struct node* start = NULL;
    struct node* ptr = NULL;
    int value, i;

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return start;
        }

        newNode->data = value;
        newNode->next = start; // here is the difference between creating a single double liked list and circular linked liste
        newNode->prev = ptr;  // Previous pointer points to the last node

        if (start == NULL) {
            start = newNode;  // First node becomes the start
        } else {
            ptr->next = newNode;  // Link last node to the new node
        }
        ptr = newNode;  // Move ptr to the new last node
    }
    return start;
}

void printDoublyCircularLinkedList(struct node* start) {
    struct node* ptr = start;
    printf("Doubly Linked List: ");
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while (ptr != start);

    printf("\n");

}

struct node *insert_beg(struct node *start)
{
 struct node *new_node, *ptr;
 int num;
 printf("\n Enter the data : ");
 scanf("%d", &num);
 new_node = (struct node *)malloc(sizeof(struct node));
 new_node-> data = num;
 ptr = start;
 while(ptr -> next != start){
 ptr = ptr -> next;
 }
 new_node -> prev = ptr;
 ptr -> next = new_node;
 new_node -> next = start;
 start -> prev = new_node;
 start = new_node;
 return start;
}


struct node *insert_end(struct node *start)
{
 struct node *ptr, *new_node;
 int num;
 printf("\n Enter the data : ");
 scanf("%d", &num);
 new_node = (struct node *)malloc(sizeof(struct node));
 new_node -> data = num;
 ptr = start;
 while(ptr -> next != start)
 ptr = ptr -> next;
 ptr -> next = new_node;
 new_node -> prev = ptr;
 new_node -> next = start;
 start-> prev = new_node;
 return start;
}


struct node *delete_beg(struct node *start)
{
 struct node *ptr;
 ptr = start;
 while(ptr -> next != start)
 ptr = ptr -> next;
 ptr -> next = start -> next;
 start->next->prev = ptr ;
 free(start);
 start = ptr->next;
 return start;
}


struct node *delete_end(struct node *start)
{
 struct node *ptr;
 ptr=start;
 while(ptr -> next != start)
 ptr = ptr -> next;
 ptr -> prev -> next = start;
 start -> prev = ptr -> prev;
 free(ptr);
 return start;
}


int main(){

 int n;
    printf("How many nodes do you want to create? ");
    scanf("%d", &n);
    struct node* start = createDoublyCircularLinkedList(n);
    printDoublyCircularLinkedList(start);

    return 0;
}
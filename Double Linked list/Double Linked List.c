#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Function to create a doubly linked list with n nodes
struct node *createDoublyLinkedList(int n) {
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
        newNode->next = NULL;
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

// Function to print the doubly linked list

void printDoublyLinkedList(struct node* start) {
    struct node* ptr = start;
    printf("Doubly Linked List: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

}

// Function that insert in the begining :
struct node *insert_beg(struct node *start)
{
 struct node *new_node;
 int num;
 printf("\n Enter the data : ");
 scanf("%d", &num);
 new_node = (struct node *)malloc(sizeof(struct node));
 new_node -> data = num;
 start -> prev = new_node;
 new_node -> next = start;
 new_node -> prev = NULL;
 start = new_node;
 return start;
}

// function that insert at the end 
struct node *insert_end(struct node *start)
{
 struct node *ptr, *new_node;
 int num;
 printf("\n Enter the data : ");
 scanf("%d", &num);
 new_node = (struct node *)malloc(sizeof(struct node));
 new_node -> data = num;
 ptr=start;
 while(ptr -> next != NULL)
 ptr = ptr -> next;
 ptr -> next = new_node;
 new_node -> prev = ptr;
 new_node -> next = NULL;
 return start;
}


// fucntion that insert after 
struct node *insert_after(struct node *start)
{
 struct node *new_node, *ptr;
 int num, val;
 printf("\n Enter the data : ");
 scanf("%d", &num);
 printf("\n Enter the value after which the data has to be inserted : ");
 scanf("%d", &val);
 new_node = (struct node *)malloc(sizeof(struct node));
 new_node -> data = num;
 ptr = start;
 while(ptr -> data != val)
 ptr = ptr -> next;
 new_node -> prev = ptr;
 new_node -> next = ptr -> next;
 ptr -> next -> prev = new_node;
 ptr -> next = new_node;
 return start;
}

// function that insert before 
struct node *insert_before(struct node *start)
{
 struct node *new_node, *ptr;
 int num, val;
 printf("\n Enter the data : ");
 scanf("%d", &num);
 printf("\n Enter the value before which the data has to be inserted : ");
 scanf("%d", &val);
 new_node = (struct node *)malloc(sizeof(struct node));
 new_node -> data = num;
 ptr = start;
 while(ptr -> data != val)
 ptr = ptr -> next;
 new_node -> next = ptr;
 new_node -> prev = ptr-> prev;
 ptr -> prev -> next = new_node;
 ptr -> prev = new_node;
 return start;
}

// function that delete in the begining 

struct node *delete_beg(struct node *start)
{
 struct node *ptr;
 ptr = start;
 start = start -> next;
 start -> prev = NULL;
 free(ptr);
 return start;
}

// function that delete at the end 
struct node *delete_end(struct node *start)
{
 struct node *ptr;
 ptr = start;
 while(ptr -> next != NULL)
 ptr = ptr -> next;
 ptr -> prev -> next = NULL;
 free(ptr);
 return start;
}

//function that delete after 
struct node *delete_after(struct node *start)
{
 struct node *ptr, *temp;
 int val;
 printf("\n Enter the value after which the node has to deleted : ");
 scanf("%d", &val);
 ptr = start;
 while(ptr -> data != val)
 ptr = ptr -> next;
 temp = ptr -> next;
 ptr -> next = temp -> next;
 temp -> next -> prev = ptr;
 free(temp);
 return start;
}

//function that delete before
struct node *delete_before(struct node *start)
{
 struct node *ptr, *temp;
 int val;
 printf("\n Enter the value before which the node has to deleted : ");
 scanf("%d", &val);
 ptr = start;
 while(ptr -> data != val){
 ptr = ptr -> next;
 }
 temp = ptr -> prev;
 ptr -> prev = temp -> prev;
 temp -> prev -> next = ptr;
 
 free(temp);
 return start;
}


int main() {

    int n;
    printf("How many nodes do you want to create? ");
    scanf("%d", &n);

    struct node* start = createDoublyLinkedList(n);

    // Print the doubly linked list
    printDoublyLinkedList(start);
    start = insert_beg(start);
    printDoublyLinkedList(start);
    start = insert_end(start);
      printDoublyLinkedList(start);
    start = insert_after(start);
       printDoublyLinkedList(start);

    return 0;
}
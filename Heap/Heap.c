#include <stdio.h>

// Maximale Size Of Heap
#define MAX_SIZE 100

// define array for heap
int heap[MAX_SIZE];
int N = 0;



// Fonction that insert in the heap
void insertIntoHeap(int val) {
    
    N = N + 1;
    int pos = N;

    
    heap[N] = val;

    
    while (pos > 1) {

        int par = pos / 2; 

        
        if (heap[pos] <= heap[par]) {
            
            break;
        } else {
           
            int temp = heap[pos];
            heap[pos] = heap[par];
            heap[par] = temp;

            pos = par; 
        }
    }

    
}


// Fonction that delete value from heap
void heapify(int heap[], int n) {
    int last = heap[n]; 
    n=n-1;
    int ptr = 1, left = 2, right = 3;

   
    heap[ptr] = last; 

    while (left <= n) { 
        
        if (heap[ptr] >= heap[left] && ( heap[ptr] >= heap[right])) {
            break; 
        }

        
        if (heap[right] <= heap[left]) {
            
            int temp = heap[ptr];
            heap[ptr] = heap[left];
            heap[left] = temp;
            ptr = left;
        } 
        
        else {
            
            int temp = heap[ptr];
            heap[ptr] = heap[right];
            heap[right] = temp;
            ptr = right;
        }

        
        left = 2 * ptr;
        right = left + 1;
    }
}


void printHeap() {
    printf("Heap: ");
    for (int i = 1; i <= N; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int n = 5;
    insertIntoHeap(10);
    insertIntoHeap(20);
    insertIntoHeap(15);
    insertIntoHeap(30);
    insertIntoHeap(25);

    printHeap(); 

    heapify(heap, n);

    printHeap();

    return 0;
}

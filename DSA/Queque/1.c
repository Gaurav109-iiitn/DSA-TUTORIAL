#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Queue structure definition
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* newNode(int new_data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = new_data;
    node->next = NULL;
    return node;
}

// Function to initialize the queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to add an element to the queue
void enqueue(struct Queue* q, int new_data) {
    struct Node* new_node = newNode(new_data);
    if (isEmpty(q)) {
        q->front = q->rear = new_node;
        printQueue(q);
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
    printQueue(q);
}

// Function to remove an element from the queue
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return;
    }
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    printQueue(q);
}

// Function to print the current state of the queue
void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Current Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code to test the queue implementation
int main() {
    struct Queue* q = createQueue();

    // Enqueue elements into the queue
    enqueue(q, 10);
    enqueue(q, 20);

    // Dequeue elements from the queue
    dequeue(q);
    dequeue(q);

    // Enqueue more elements into the queue
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Dequeue an element from the queue (this should print 30)
    dequeue(q);
    
    return 0;
}
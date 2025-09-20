#include <stdio.h>
#include <stdlib.h>

#define priority 5   

struct node {
    int data;
    struct node* next;
};

struct Queue {
    struct node* front;
};

struct node* Node(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Queue* create() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    return q;
}

void enqueue(struct Queue* q, int data) {
    struct node* temp = Node(data);

    if (q->front == NULL || data < q->front->data) {
        temp->next = q->front;
        q->front = temp;
    }

    else if (data <= priority) {
        struct node* curr = q->front;
        while (curr->next != NULL && curr->next->data < data){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
    else {
        struct node* curr = q->front;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is underflow\n");
        return;
    }
    struct node* temp = q->front;
    printf("Dequeued element is %d\n", temp->data);
    q->front = q->front->next;
    free(temp);
}

void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* q = create();

    enqueue(q, 9);
    enqueue(q, 1);
    enqueue(q, 4);
    enqueue(q, 2);
    enqueue(q, 8);

    display(q);

    dequeue(q);
    display(q);

    return 0;
}

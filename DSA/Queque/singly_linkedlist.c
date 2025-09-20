#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct Queue{
    struct node* front,* rear;
};

struct node* Node(int data){
struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->next=NULL;
return temp;
}

struct Queue* create(){
    struct Queue* temp=(struct Queue*)malloc(sizeof(struct Queue));
    temp->front=temp->rear=NULL;
    return temp;
}

void enqueue(struct Queue* q,int data){
struct node* temp=Node(data);
if(q->rear==NULL){
    q->front=q->rear=temp;
}
q->rear->next=temp;
q->rear=temp;
}

void dequeue(struct Queue* q){
    if(q->front==NULL){
    printf("Queue is underflow\n");
    return;
    }
    struct node* temp=q->front;
    printf("dequeued element is %d\n",temp->data);
    q->front=q->front->next;
    if(q->front==NULL)
    q->rear=NULL;
    free(temp);
}

 void display(struct Queue* q){
    if(q->front==NULL)
    printf("Queue is empty\n");
    struct node* temp=q->front;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
printf("\n");
 }

int main(){
    struct Queue* q=create();
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    display(q);
    dequeue(q);
    display(q);
    return 0;
}   
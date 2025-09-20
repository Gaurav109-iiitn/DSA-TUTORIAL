#include<stdio.h>
#define size 8
int queue[size],front=-1,rear=-1;

void enqueue(int value){
    if(rear==size-1){
        printf("queue is overflow\n");
    }
    else{
        if(front==-1 ) front=0;
        queue[++rear]=value;
    }
}

void dequeue()
{
if(front==-1 || front>rear){
    printf("queue is underflow\n");
}
else{
    printf("dequeued element is %d\n",queue[front++]);
}
}
void display(){
    if(front==-1 || front>rear){
        printf("queue is empty\n");

    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
    
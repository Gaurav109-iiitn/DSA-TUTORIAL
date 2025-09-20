#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* head=NULL;
struct node* create(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int data;
    printf("enter data");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=temp;
        temp->prev=tail;
    }
    return head;
}
struct node* insertion(int pos){
    if(pos<1){
        printf("not available position");
    }
    struct node* temp=NULL;
    temp=create();
}
   
void print(){
    struct node* temp=head;
    while(temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->next;
    }
}
int main(){
int n,pos;
printf("enter details");
scanf("%d %d",&pos,&n);
for(int i=0;i<n;i++){
head=create();
}
print();
head=insertion(pos);
printf("\n");
print();
return 0;
}
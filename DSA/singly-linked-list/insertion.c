#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
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
    if(head==NULL){
        head=temp;
    return head;
    }
    else{
        struct node* tail=NULL;
        tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=temp;
    }
    return head;
}
void print(struct node* head){
    struct node* temp=NULL;
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
struct node* deletion(int pos){
struct node* temp=(struct node*)malloc(sizeof(struct node));
temp=head;
if(pos<1){
    printf("not applicable");
}
else if(pos==1){
    temp=head->next;
    free(head);
    head=temp;
    return head;
}
else{
    struct node* temp1=NULL;
    struct node* temp2=NULL;
    temp1=head;
    for(int i=1;i<pos-1;i++){
        temp1=temp1->next;
    }
    temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);
}
return head;
}
struct node* insertion(int pos){
    struct node* temp=NULL;
    temp=create();
    if(pos<1){
        printf("not inserted at that position");
    }
    else if(pos==1){
        temp->next=head;
        head=temp;
        return head;
    }
    else{
        struct node* curr=head;
        for(int i=1;i<pos-1;i++){
            curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=temp;
    }
    return head;
}
struct node* modify(int pos){

    struct node* temp=NULL;
    temp=head;
    int data;
    printf("enter data");
    scanf("%d",&data);
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    temp->data=data;
    
    return head;
}
// struct node* reverse_list(int pos){
//  struct node* prev=NULL, *curr=head, *next=NULL;
//  struct node* tail=head;
//  for(int i=0;curr!=NULL&&i<pos;i++){
//     next=curr->next;
//     curr->next=prev;
//     prev=curr;
//     curr=next;
//  }
//  tail->next=curr;
//  head=prev;
//  return head;
// }
struct node* reverse_list(int pos){
    struct node* prev=NULL, *curr=head, *next=NULL;
    for(int i=0;curr!=NULL&&i<pos;i++){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    while(prev->next!=NULL){
        prev=prev->next;
    }
    prev->next=curr;
    return head;
}
int main(){
    int n,pos;
    printf("enter details");
    scanf("%d %d",&n,&pos);
    for(int i=0;i<n;i++){
        head=create();
    }
    print(head);
    printf("\n");
    // head=insertion(pos);
    // head=deletion(pos);
    // head=modify(pos);
    head=reverse_list(pos);
    print(head);
    return 0;
}
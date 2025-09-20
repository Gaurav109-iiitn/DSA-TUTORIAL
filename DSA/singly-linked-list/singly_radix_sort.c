#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;

struct node* create(struct node* head,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct node* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
    }
    return head;
}

void pr(struct node* head){
    struct node* r=head;
    while(r!=NULL){
        printf("%d\t",r->data);
        r=r->next;
    }
    printf("\n");
}

int mx(struct node* h1){
    struct node* temp=h1;
    int mx=temp->data;
    while(temp!=NULL){
        if(temp->data>mx){
            mx=temp->data;
        }
        temp=temp->next;
    }
    int k=0;
    while(mx>0){
        k++;
        mx/=10;   
    }
    return k;
}

struct node* sort1(struct node* h1){
    struct node* temp=h1;
    while(temp!=NULL){ 
        struct node* temp1=temp->next;
        while(temp1!=NULL){
            if(temp->data>temp1->data){
                int tem=temp->data;
                temp->data=temp1->data;
                temp1->data=tem;
            }
        temp1=temp1->next;
        }
        temp=temp->next;
    }
    return h1;
}
struct node* radix_sort(struct node* h1){
    int k=mx(h1);
    int divisor=1;
    for(int i=0;i<k;i++){
        h1 = sort1(h1);
        divisor *= 10;
    }
    return h1;
}

int main(){
    int n,data;
    printf("enter n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter data: ");
        scanf("%d",&data);
        head=create(head,data);
    }
    printf("Original list:\n");
    pr(head);
    head=radix_sort(head);
    printf("Sorted list:\n");
    pr(head);
    return 0;
}
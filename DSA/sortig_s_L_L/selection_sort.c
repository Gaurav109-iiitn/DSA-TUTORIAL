#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
struct node* create(struct node* h1,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(h1==NULL){
        return temp;
    }
    else{
        struct node* curr=h1;
    while(curr->next!=NULL){
    curr=curr->next;
    }
    curr->next = temp;
    }
    return h1;
}
struct node* sort(struct node* h1,int n){
    struct node* temp = h1;
    while (temp != NULL) {
        struct node* min = temp;
        struct node* temp1 = temp->next;
        while (temp1 != NULL) {
            if (temp1->data < min->data) {
                min = temp1;
            }
            temp1 = temp1->next;
        }
        // Swap data
        if (min != temp) {
            int t = temp->data;
            temp->data = min->data;
            min->data = t;
        }
        temp = temp->next;
    }
    return h1;
}

void pr(struct node* h){
    struct node* temp=h;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    int n,data;
    printf("enter n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    printf("enter data:");
    scanf("%d",&data);
    head=create(head,data);
    }
    pr(head);
    head=sort(head,n);
    pr(head);
    return 0;
}
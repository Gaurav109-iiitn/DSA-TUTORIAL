#include<stdio.h>
#include<stdlib.h>
struct node{
    int coe;
    int exp;
    struct node* next;
};
struct node* head=NULL;
struct node* head1=NULL;
struct node* create(struct node* h1){
    int coe, exp;
    printf("enter details: ");
    scanf("%d %d", &coe, &exp);
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->coe = coe;
    temp->exp = exp;
    temp->next = NULL;
    if (h1 == NULL) {
        h1 = temp;
    }
    else {
        struct node* curr = h1;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
    return h1;
}

void display(struct node* h1){
    struct node* temp=h1;
    while(temp!=NULL){
        printf("%dx^%d",temp->coe,temp->exp);
        if(temp->next!=NULL){
            printf("+");
        }
        temp=temp->next;
    }
}
struct node* simplify(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
    struct node* prev=temp;
    struct node* curr=temp->next;
    while(curr!=NULL){
    if(temp->exp==curr->exp){
    temp->coe += curr->coe;
    prev->next = curr->next;
    free(curr);
    curr = prev->next;   
    }
    else{
    prev=curr;
    curr=curr->next;
    }
    }
    temp=temp->next;
    }
    return head;
}
int main(){
    int n;
    printf("enter n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        head=create(head);
    }
    display(head);
    head=simplify(head);
    printf("\n");
    display(head);
    return 0;
}

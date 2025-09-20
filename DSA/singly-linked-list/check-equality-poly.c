#include<stdio.h>
#include<stdlib.h>
struct node{
    int coe;
    int exp;
    struct node* next;
};
struct node* head1=NULL;
struct node* head2=NULL;
struct node* create(struct node* h1,int coe,int exp){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->coe=coe;
    temp->exp=exp;
    temp->next=NULL;
    if(h1==NULL || h1->exp<exp){
        temp->next=h1;
        h1=temp;
        return h1;
    } 
    else{
     struct node* curr=h1;
     struct node* prev=NULL;
     while(curr!=NULL && curr->exp>=exp){
        if(curr->exp==exp){
            curr->coe+=coe;
            free(temp);
            return h1;
        }
        prev=curr;
        curr=curr->next;
     }
     temp->next=prev->next;
     prev->next=temp;
    }
    return h1;
} 
void check(struct node* h1, struct node* h2) {
    struct node* temp = h1;
    struct node* temp1 = h2;
    while (temp != NULL && temp1 != NULL) {
        if (temp->exp != temp1->exp || temp->coe != temp1->coe) {
            printf("both are not equal\n");
            return;
        }
        temp = temp->next;
        temp1 = temp1->next;
    }
    if (temp == NULL && temp1 == NULL) {
        printf("both polynomial are equal\n");
    } else {
        printf("both are not equal\n");
    }
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
int main(){
    int n1,n2,coe,exp;
    printf("enter n1");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        printf("enter coefficient and exponent");
        scanf("%d %d",&coe,&exp);
        head1=create(head1,coe,exp);
    }
     printf("enter n2");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        printf("enter coefficient and exponent");
        scanf("%d %d",&coe,&exp);
        head2=create(head2,coe,exp);
    }
    display(head1);
    printf("\n");
    display(head2);
    printf("\n");
    check(head1,head2);
return 0;
}
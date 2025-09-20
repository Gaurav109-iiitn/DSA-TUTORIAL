#include<stdio.h>
#include<stdlib.h>
struct node{
    int coe;
    int exp;
    struct node* next;
};
struct node* head1=NULL;
struct node* head2=NULL;
struct node* head3=NULL;
struct node* create(struct node* head,int coe, int exp){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->coe=coe;
    temp->exp=exp;
    temp->next=NULL;
    if(head==NULL || head->exp<exp){
     temp->next=head;
     head=temp;
     return head;
    }
    else{
        struct node* curr=head;
        struct node* prev=NULL;
        while(curr!=NULL && curr->exp>=exp){
            if(curr->exp==exp){
                curr->coe+=coe;
                free(temp);
                return head;
            }
            prev=curr;
            curr=curr->next;
        }
        temp->next=prev->next;
        prev->next=temp;
    }
    return head;
}
struct node* add(struct node* h1,struct node* h2){
    struct node* result=NULL;
    while(h1!=NULL){
        result=create(result,h1->coe,h1->exp);
        h1=h1->next;
    }
    while(h2!=NULL){
        result=create(result,h2->coe,h2->exp);
        h2=h2->next;
    }
    return result;
}
void pr(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%dx^%d",temp->coe,temp->exp);
        if(temp->coe>0 && temp->next!=NULL){
            printf("+");
        }
        temp=temp->next;
    }
}
int main(){
    int n1,n2;
    int coe,exp;
    printf("enter details 1\n");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
    printf("enter coefficient and exponent\n");
    scanf("%d %d",&coe,&exp);
        head1=create(head1,coe,exp);
    }
     printf("enter details 2\n");
     scanf("%d",&n2);
    for(int j=0;j<n2;j++){
        printf("enter coefficient and exponent\n");
    scanf("%d %d",&coe,&exp);
        head2=create(head2,coe,exp);
    }
    pr(head1);
    printf("\n");
    pr(head2);
    printf("\n");
    head3=add(head1,head2);
    pr(head3);
    return 0;
}
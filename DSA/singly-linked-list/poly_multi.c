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
struct node* create(struct node* head,int coe,int exp){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->coe=coe;
    temp->exp=exp;
    temp->next=NULL;
    if(head==NULL || head->exp<exp){
        temp->next=head;
        head=temp;
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
struct node* multi(struct node* h1,struct node* h2)
{
struct node* t1=h1;
struct node* t2=h2;
while(t1!=NULL){
    while(t2!=NULL){
        head3=create(head3,t1->coe*t2->coe,t1->exp+t2->exp);
        t2=t2->next;
    }
    t1=t1->next;
}
return head3;
}
void display(struct node* head){
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
    int n1,n2,coe,exp;
    printf("enter n");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        printf("enter coefficient and exponent for 1");
        scanf("%d %d",&coe,&exp);
        head1=create(head1,coe,exp);
    }
     printf("enter n2");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        printf("enter coefficient and exponent for 1");
        scanf("%d %d",&coe,&exp);
        head2=create(head2,coe,exp);
    }
    head3=multi(head1,head2);
    display(head1);
    printf("\n");
    display(head2);
    printf("\nmultiplication of two polynomials\n");
    display(head3);
    return 0;

}
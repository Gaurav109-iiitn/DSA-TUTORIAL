#include<stdio.h>
#include<stdlib.h>
struct node{
    int coe;
    int exp;
    struct node* next;
};
struct node* head=NULL;
struct node* create(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    int coe,exp;
    printf("enter coefficient and exponent: ");
    scanf("%d %d",&coe,&exp);
    temp->coe=coe;
    temp->exp=exp;
    temp->next=NULL;
    if(head==NULL || head->exp<exp){
        temp->next=head;
        head=temp;
    }
    else{
        struct node* curr=head;
        while(curr->next!=NULL&& curr->next->exp>=exp){
        if(curr->exp==exp){
            curr->coe+=coe;
            free(temp);
            return head;
        }
           curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=temp;
return head;
    }
}
void print(struct node* head){
    struct node* curr=head;
    while(curr!=NULL){
        printf("%dx^%d ",curr->coe,curr->exp);
      
        if(curr->coe>0 && curr->next!=NULL)
        printf(" + ");
          curr=curr->next;
    }
    printf("\n");
}
    
int main(){
int n;
printf("enter no of terms");
scanf("%d",&n);
for(int i=0;i<n;i++){
    head=create();
}
print(head);
    return 0;
}
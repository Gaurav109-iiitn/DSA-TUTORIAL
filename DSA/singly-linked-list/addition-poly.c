#include<stdio.h>
#include<stdlib.h>
struct node{
    int coe;
    int exp;
    struct node* next;
};
struct node* head=NULL;
struct node* create(int coe,int exp){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->coe=coe;
    temp->exp=exp;
    temp->next=NULL;
    return temp;
}
struct node* insert(struct node* head,int coe,int exp){
    struct node* temp=create(coe,exp);
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
void display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%dx^%d",temp->coe,temp->exp);
        if(temp->next!=NULL){
            printf("+");
        }
        temp=temp->next;
    }
}
struct node* input(){
    int n,coe,exp;
    struct node* head = NULL;
    printf("enter number of terms: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("enter coefficient and exponent: ");
        scanf("%d %d", &coe, &exp);
        head = insert(head, coe, exp);
    }
    return head;
}
struct node* add(struct node* p1,struct node* p2){
    struct node* result=NULL;
    while(p1!=NULL){
        result=insert(result,p1->coe,p1->exp);
        p1=p1->next;
        }
        while(p2!=NULL){
        result=insert(result,p2->coe,p2->exp);
        p2=p2->next;
        }
        return result;
    }
int main(){
      printf("enter first polynomial\n");
      struct node* poly1=input();
      printf("enter 2nd polynoial\n");
      struct node* poly2=input();
      printf("first polynomial\n");
      display(poly1);
      printf("\n 2nd polynomial\n");
      display(poly2);
      printf("\n");
      printf("sum:");
      struct node* sum=add(poly1,poly2);
      display(sum);
      return 0;

}
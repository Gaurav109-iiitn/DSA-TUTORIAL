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
struct node* count(struct node* head,int n){
    if(head==NULL || n==0) return head;

    struct node* temp=head->next;

 int mx =temp->data;
while(temp!=NULL){
    if(mx<temp->data){
        mx=temp->data;
    }
    temp=temp->next;
}

int* a=(int*)malloc(n*sizeof(int));
temp=head;

for(int i=0;i<n && temp!=NULL;i++){
    a[i]=temp->data;
    temp=temp->next;
}

int* freq=(int*)calloc(mx+1,sizeof(int));
for(int i=0;i<n;i++){
    freq[a[i]]++;
}
for(int i=1;i<=mx;i++){
    freq[i]+=freq[i-1];
}
int* out=(int*)malloc(n*sizeof(int));
for(int i=n-1;i>=0;i--){
    out[freq[a[i]]-1]=a[i];
    freq[a[i]]--;
}
temp=head;
for(int i=0;i<n && temp!=NULL;i++){
temp->data=out[i];
temp=temp->next;
}
free(a);
free(out);
free(freq);
return temp;
}
void pr(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
int main(){
    int n;
    printf("enter n\n");
    scanf("%d",&n);
    printf("enter details");
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        head=create(head,data);
    }
    pr(head);
    printf("\n");
    count(head,n);
    pr(head);
    return 0;
}

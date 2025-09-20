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

void count_sort(int a[],int r[],int n){
    if(n==0) return;
int mx=a[0];
for(int i=0;i<n;i++){
    if(mx<a[i]){
        mx=a[i];
    }
}
int* freq=(int*)calloc(mx+1,sizeof(int));
for(int i=0;i<n;i++){
    freq[r[i]]++;
}
for(int i=1;i<=mx;i++){
    freq[i]+=freq[i-1];
}
int* out=(int*)malloc(n*sizeof(int));
for(int i=n-1;i>=0;i--){
    out[freq[r[i]]-1]=a[i];
    freq[r[i]]--;
}
for(int i=0;i<n;i++){
    a[i]=out[i];
}
free(freq);
free(out);
}


struct node* radix_sort(struct node* h,int n){
    struct node* temp=h;
    int mx=temp->data;
    int* a=(int*)malloc(n*sizeof(int));
     int* b=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n&&temp!=NULL;i++){
        a[i]=temp->data;
        b[i]=temp->data;
        if(mx<temp->data){
            mx=temp->data;
        }
        temp=temp->next;
    }
    int digit=0;
    while(mx>0){
        digit++;
        mx/=10;
    }
int divisor=1;
for(int i=0;i<digit;i++){
    int* rem=(int*)malloc(n*sizeof(int));
    for(int j=0;j<n;j++){
        rem[j]=(a[j]/divisor)%10;
    }
   count_sort(b,rem,n);
   for(int j=0;j<n;j++){
    a[j]=b[j];
   }
   free(rem);
   divisor*=10;
}
temp=head;
for(int i=0;i<n;i++){
    temp->data=b[i];
    temp=temp->next;
}
free(a);
free(b);
return h; 
}


void print(struct node* h){
    struct node* temp=h;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

int main(){
    int n;
    printf("enter n\t");
    scanf("%d",&n);
     for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        head=create(head,data);
    }
print(head);
printf("\n");
head=radix_sort(head,n);
print(head);
    return 0;
}
